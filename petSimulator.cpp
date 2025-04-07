#include <cctype>
#include <iostream>
#include <string>
using namespace std;

// Global vars
int currentPets = 0;
const int MAX_PETS = 10;

//* Requirement #1: Read in and store your data in a meaningful way.
//  Solution: Defining and using a dynamic array of animal structs.
//* Requirement #2: Provide interactions for the user that utilizes the data.
//  Solution: Functions to add / remove pets from the dynamic array.
//* Requirement #3: Basic output to the user in response to their interactions.
//  Solution: Function to print the contents of the dynamic array.

//* - TODO: iterate over selectionOptions.txt, store data in the dynamic array.

struct Animal {
  string name;
  // int age;
  // int happinessPercentage;
  // int happinessThresholdPercentage;
  // int happinessDecrementTimeMinutes;
  // int satiationPercentage;
  // int satiationThresholdPercentage;
  // int satiationDecrementTimeMinutes;
};

void actionMenu(Animal*);
void addPet(Animal*);
void removePet(Animal*);
void viewPets(Animal*);
void quitProgram(Animal*);

// @brief Prompts the user with an action menu (add, remove, view...).
// @param pets Dynamic array of Animal structs.
void actionMenu(Animal* pets) {
  string choice;
  cout << "Welcome. Please input one of the following options:" << endl;
  while (true) {
    cout << "- Add Pet" << endl
         << "- Remove Pet" << endl
         << "- View Pets" << endl
         << "- Quit" << endl;
    getline(cin, choice);

    // Converts string to uppercase
    for (int i = 0; i < choice.size(); i++) choice[i] = toupper(choice[i]);

    // Action menu
    if (choice == "A" || choice == "ADD" || choice == "ADD PET")
      addPet(pets);
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
void addPet(Animal* pets) {
  if (currentPets >= 10)
    cout << "Pets at capacity! Please remove a pet first." << endl;
  else {
    pets[currentPets].name = "Pet #" + to_string(1 + currentPets);
    // cout << pets[currentPets].name << endl;  //* Debug
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
    for (int i = 0; i < currentPets; i++) cout << pets[i].name << endl;
  }
}

// @brief Deallocates the dynamic array and quits the program.
// @param pets Dynamic array of Animal structs.
void quitProgram(Animal* pets) {
  delete[] pets;
  exit(1);
}

int main() {
  // Defines dynamic array of animal struct to hold data.
  Animal* pets = new Animal[MAX_PETS];
  for (int i = 0; i < MAX_PETS; i++) {
    pets[i].name = "null";
  }

  actionMenu(pets);
  // Game loop

  return 0;
}