#include <cctype>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// Global vars
int currentPets = 0;
const int MAX_PETS = 10;
const int NUM_ANIMAL_OPTIONS = 15;

//* Requirement #1: Read in and store your data in a meaningful way.
//  Solution: Defining and using a dynamic array of animal structs.
//* Requirement #2: Provide interactions for the user that utilizes the data.
//  Solution: Functions to add / remove pets from the dynamic array.
//* Requirement #3: Basic output to the user in response to their interactions.
//  Solution: Function to print the contents of the dynamic array.

struct Animal {
  string name;
  string animalName;
  int age;
  int happinessPercentage;
  int happinessThresholdPercentage;
  int happinessDecrementTimeMinutes;
  int satiationPercentage;
  int satiationThresholdPercentage;
  int satiationDecrementTimeMinutes;
};

void actionMenu(Animal*);
void addPet(Animal*, Animal*);
void removePet(Animal*);
void viewPets(Animal*);
void quitProgram(Animal*);

// @brief Declars dynamic array of animal options to choose from, reading in the data from "selectionOptions.txt" file.
Animal* readAnimalOptions() {
    Animal* animalChoices = new Animal[NUM_ANIMAL_OPTIONS];
  
    ifstream file("selectionOptions.txt");
    if (!file) {
      cerr << "Error opening selectionOptions.txt" << endl;
      return nullptr;
    }
  
    string line;
    getline(file, line); // Skip header
  
    for (int i = 0; i < NUM_ANIMAL_OPTIONS && getline(file, line); i++) {
      stringstream ss(line);
      string token;
  
      getline(ss, animalChoices[i].name, ',');
      ss >> ws;
  
      getline(ss, token, ',');
      animalChoices[i].happinessThresholdPercentage = stoi(token);
  
      getline(ss, token, ',');
      animalChoices[i].happinessDecrementTimeMinutes = stoi(token);
  
      getline(ss, token, ',');
      animalChoices[i].satiationThresholdPercentage = stoi(token);
  
      getline(ss, token, ',');
      animalChoices[i].satiationDecrementTimeMinutes = stoi(token);
    }
  
    file.close();
    return animalChoices;
  }

// @brief Prompts the user with an action menu (add, remove, view...).
// @param pets Dynamic array of Animal structs.
void actionMenu(Animal* pets, Animal* animalChoices) {
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
      quitProgram(pets);
    else
      cout << "Invalid Response. Please input one of the following options:"
           << endl;
  }
}

// @brief Adds a pet to the dynamic array.
// @param pets Dynamic array of Animal structs.
void addPet(Animal* pets, Animal* animalChoices) {
  if (currentPets >= MAX_PETS)
    cout << "Pets at capacity! Please remove a pet first." << endl;
  else {
    // display animal choices for pet adoption
    // input verification over via do while loop
    int choice;
    bool takingInAdnimalChoice = true;
    do {
        cout << "Which animal would you like to adopt?" << endl;
        if (animalChoices != nullptr) {
            for (int i = 0; i < NUM_ANIMAL_OPTIONS; i++) {
            cout << i+1 << ". " << animalChoices[i].name << endl
                << ": Happiness Threshold - " << animalChoices[i].happinessThresholdPercentage << endl
                << ", Happiness Decrement Time (min/1%) - " << animalChoices[i].happinessDecrementTimeMinutes << endl
                << ", Satiation Threshold - " << animalChoices[i].satiationThresholdPercentage << endl
                << ", Satiation Decrement Time (min/1%) - " << animalChoices[i].satiationDecrementTimeMinutes << endl << endl;
            }
            }
        cout << "Choice (number): ";
        cin >> choice;
        
        if (choice >= 1 && choice <= NUM_ANIMAL_OPTIONS) {
            takingInAdnimalChoice = false;
        } else {
            cout << choice << " is not an option! Try Again." << endl;
        }
    } while (takingInAdnimalChoice);

    // re-index choice, since wanted to start visual list at index 1
    choice -= 1;
    
    cout << animalChoices[choice].name << " chosen! Please enter what you'd like to name it: ";
    string petName;
    cin >> petName;
    cin.ignore();

    pets[currentPets].name = petName;
    pets[currentPets].animalName = animalChoices[choice].name;
    pets[currentPets].age = 0;
    pets[currentPets].happinessPercentage = 80;
    pets[currentPets].happinessDecrementTimeMinutes = animalChoices[choice].happinessDecrementTimeMinutes;
    pets[currentPets].happinessThresholdPercentage = animalChoices[choice].happinessThresholdPercentage;
    pets[currentPets].satiationPercentage = 80;
    pets[currentPets].satiationThresholdPercentage = animalChoices[choice].satiationThresholdPercentage;
    pets[currentPets].satiationDecrementTimeMinutes = animalChoices[choice].satiationDecrementTimeMinutes;

    // message to show user pet successfully added
    cout << "Added " << pets[currentPets].animalName << " " << pets[currentPets].name << "!" << endl << endl;
    currentPets++;
  }
}

// @brief Removes a pet from the dynamic array.
// @param pets Dynamic array of Animal structs.
void removePet(Animal* pets) {
  if (currentPets <= 0)
    cout << "No pets remaining! Please add a pet first." << endl;
  else {
    currentPets--;
    pets[currentPets].name = "null";
  }
}

// @brief Prints the dynamic array.
// @param pets Dynamic array of Animal structs.
void viewPets(Animal* pets) {
  if (currentPets == 0)
    cout << "You have no pets!" << endl;
  else {
    cout << "You have the following pets:" << endl;
    for (int i = 0; i < currentPets; i++) cout << pets[i].animalName << " - " << pets[i].name << endl;
    cout << endl;
  }
}

// @brief Deallocates the dynamic array and quits the program.
// @param pets Dynamic array of Animal structs.
void quitProgram(Animal* pets) {
  delete[] pets;
  cout << endl << "Goodbye!" << endl;
  exit(1);
}

int main() {

  Animal* animalChoices = readAnimalOptions();
    
  // Defines dynamic array of animal struct to hold pet data.
  Animal* pets = new Animal[MAX_PETS];
  for (int i = 0; i < MAX_PETS; i++) {
    pets[i].name = "null";
  }

  cout << "Welcome to the pet simulator game!" << endl << endl;

  actionMenu(pets, animalChoices);
  // Game loop

  return 0;
}