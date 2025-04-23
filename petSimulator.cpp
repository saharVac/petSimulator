//* Requirement #1: Read in and store your data in a meaningful way.
//  Solution: Defining and using a dynamic array of animal structs.
//* Requirement #2: Provide interactions for the user that utilizes the data.
//  Solution: Functions to add / remove pets from the dynamic array.
//* Requirement #3: Basic output to the user in response to their interactions.
//  Solution: Function to print the contents of the dynamic array.

#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Animal.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include "Omnivore.h"

using namespace std;

#pragma region  // Global Variables
int currentPets = 0;
const int MAX_PETS = 10;            // Marks the maximum # of pets you can own.
const int NUM_ANIMAL_OPTIONS = 15;  // Marks the total number of animal types.
#pragma endregion


Animal** readAnimalOptions();
void actionMenu(Animal**, Animal**);
void addPet(Animal**, Animal**);
void removePet(Animal**);
void viewPets(Animal**);
void quitProgram(Animal**, Animal**);
#pragma endregion

// @brief Reads in data from a text file to declare a dynamic array of Animal
// struct options.
// @return Dynamic array of Animal struct options.
Animal** readAnimalOptions() {
  Animal** animalChoices = new Animal*[NUM_ANIMAL_OPTIONS];

  // Protection if file doesn't exist.
  ifstream file("selectionOptions.txt");
  if (!file) {
    cerr << "Error opening selectionOptions.txt" << endl;
    return nullptr;
  }

  string line;
  getline(file, line);  // Skip header

  for (int i = 0; i < NUM_ANIMAL_OPTIONS && getline(file, line); i++) {

    stringstream ss(line);
    string token;

    string name;
    getline(ss, name, ',');
    ss >> ws;  // Discards any leading whitespace

    getline(ss, token, ',');
    int happinessPercentage = stoi(token);

    getline(ss, token, ',');
    int happinessDecrementTimeMinutes = stoi(token);

    getline(ss, token, ',');
    int satiationPercentage = stoi(token);

    getline(ss, token, ',');
    int satiationDecrementTimeMinutes = stoi(token);
    
    // extract last token (animal category)
    getline(ss, token, ',');
    string category = token;

    if (category == "Carnivore"){
      animalChoices[i] = new Carnivore(name, "Carnivore", 0, happinessPercentage, 50, happinessDecrementTimeMinutes, satiationPercentage, 50, 10);
    } else if (category == "Herbivore") {
      animalChoices[i] = new Herbivore(name, "Herbivore", 0, happinessPercentage, 50, happinessDecrementTimeMinutes, satiationPercentage, 50, 10);
    } else if (category == "Omnivore") {
      animalChoices[i] = new Omnivore(name, "Omnivore", 0, happinessPercentage, 50, happinessDecrementTimeMinutes, satiationPercentage, 50, 10);
    } else {
      cout << "Unknown animal category: '" << category << "'" << endl;
    }
  }

  file.close();
  return animalChoices;
}

// @brief Prompts the user with an action menu (add, remove, view...).
// @param pets Dynamic array of Animal structs.
// @param animalChoices Dynamic array of Animal struct options.
void actionMenu(Animal* pets[], Animal* animalChoices[]) {
  string choice;
  cout << "Please input one of the following options:" << endl;
  while (true) {
    cout << "- Add Pet (A)" << endl
         << "- Remove Pet (R)" << endl
         << "- View Pets (V)" << endl
         << "- Quit (Q)" << endl
         << endl
         << "Choice: ";
    getline(cin, choice);

    // Converts string to uppercase
    for (int i = 0; i < choice.size(); i++) choice[i] = toupper(choice[i]);

    // Action menu
    if (choice == "A" || choice == "ADD" || choice == "ADD PET")
      addPet(pets, animalChoices);
    else if (choice == "R" || choice == "REMOVE" || choice == "REMOVE PET")
      removePet(pets);
    else if (choice == "V" || choice == "VIEW" || choice == "VIEW PETS")
      viewPets(pets);
    else if (choice == "Q" || choice == "QUIT")
      quitProgram(pets, animalChoices);
    else
      cout << "Invalid Response. Please input one of the following options:"
           << endl;
  }
}

// @brief Adds a user-chosen pet to the dynamic array.
// @param pets Dynamic array of Animal structs.
// @param animalChoices Dynamic array of Animal struct options.
void addPet(Animal* pets[], Animal* animalChoices[]) {
  if (currentPets >= MAX_PETS)
    cout << "Pets at capacity! Please remove a pet first." << endl;
  else {
    // Display animal options for adoption.
    int choice;
    bool takingInAnimalChoice = true;
    // TODO - Remove do-while OR reimplement input verification inside.
    // TODO - Implement cancel functionality (press 0).
    do {
      cout << "Which animal would you like to adopt?" << endl;
      if (animalChoices != nullptr) {
        for (int i = 0; i < NUM_ANIMAL_OPTIONS; i++) {
          Animal* currentAnimal = animalChoices[i];
          cout << i + 1 << ". " << currentAnimal->getName() << ":" << endl;
          cout << "- Happiness Threshold - "
               << currentAnimal->getHappinessThresholdPercentage() << endl;
          cout << "- Happiness Decrement Time (min/1%) - "
               << currentAnimal->getHappinessDecrementTimeMinutes() << endl;
          cout << "- Satiation Threshold - "
               << currentAnimal->getSatiationThresholdPercentage() << endl;
          cout << "- Satiation Decrement Time (min/1%) - "
               << currentAnimal->getSatiationDecrementTimeMinutes() << endl
               << endl;
        }
      }
      // Input verification.
      while (takingInAnimalChoice) {
        cout << "Choice (number): ";
        cin >> choice;

        if (choice >= 1 && choice <= NUM_ANIMAL_OPTIONS)
          takingInAnimalChoice = false;
        else
          cout << choice << " is not an option! Try Again." << endl << endl;
      }
    } while (takingInAnimalChoice);

    // Re-index choice (starts visual list at index 1).
    choice -= 1;

    cout << animalChoices[choice]->getName() << " chosen! Please enter what you'd like to name it: ";
    string petName;
    cin >> petName;
    cin.ignore();

    if(dynamic_cast<Carnivore*>(animalChoices[choice]) != nullptr) {
      pets[currentPets] = new Carnivore(petName, animalChoices[choice]->getAnimalName(), 0, 80, 50, animalChoices[choice]->getHappinessDecrementTimeMinutes(), 80, 50, animalChoices[choice]->getSatiationDecrementTimeMinutes());
    } else if(dynamic_cast<Herbivore*>(animalChoices[choice]) != nullptr) {
      pets[currentPets] = new Herbivore(petName, animalChoices[choice]->getAnimalName(), 0, 80, 50, animalChoices[choice]->getHappinessDecrementTimeMinutes(), 80, 50, animalChoices[choice]->getSatiationDecrementTimeMinutes());
    } else if(dynamic_cast<Omnivore*>(animalChoices[choice]) != nullptr) {
      pets[currentPets] = new Omnivore(petName, animalChoices[choice]->getAnimalName(), 0, 80, 50, animalChoices[choice]->getHappinessDecrementTimeMinutes(), 80, 50, animalChoices[choice]->getSatiationDecrementTimeMinutes());
    }

    // Notify user that pet was successfully added.
    cout << "Added " << pets[currentPets]->getAnimalName() << " " << pets[currentPets]->getName() << "!" << endl << endl;
    currentPets++;
  }
}

// @brief Removes a pet from the dynamic array.
// @param pets Dynamic array of Animal structs.
void removePet(Animal* pets[]) {
  // TODO - Implement removal choice, like in addPet().
  if (currentPets <= 0)
    cout << "No pets remaining! Please add a pet first." << endl;
  else {
    currentPets--;
    pets[currentPets]->setName("null");
  }
}

// @brief Prints the dynamic array.
// @param pets Dynamic array of Animal structs.
void viewPets(Animal* pets[]) {
  if (currentPets == 0)
    cout << "You have no pets!" << endl;
  else {
    cout << "You have the following pets:" << endl;
    for (int i = 0; i < currentPets; i++)
      cout << pets[i]->getAnimalName() << " - " << pets[i]->getName() << endl;
      // Uncomment once ready to implement a Happiness and Hunger bar:
      // cout << pets[i].getAnimalName() << " - " << pets[i].getName() << " Hunger: " << hungerBar << " Happiness: " << happinessBar << endl;
    cout << endl;
  }
}

// @brief Deallocates the dynamic arrays and quits the program.
// @param pets Dynamic array of Animal structs.
// @param animalChoices Dynamic array of Animal struct options.
void quitProgram(Animal* pets[], Animal* petOptions[]) {
  delete[] pets;
  delete[] petOptions;
  cout << endl << "Goodbye!" << endl;
  exit(1);
}

int main() {
  // Dynamic arrays of animal structs.
  // Hold pet data and animal options respectively.
  Animal** pets = new Animal*[MAX_PETS];
  Animal** animalChoices = readAnimalOptions();

  for (int i = 0; i < MAX_PETS; i++) {
    pets[i] = nullptr;
  }

  // TODO - Give the game a name?
  cout << "Welcome to the pet simulator game!" << endl << endl;

  actionMenu(pets, animalChoices);

  return 0;
}