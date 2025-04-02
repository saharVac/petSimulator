#include <cctype>
#include <iostream>
#include <string>
using namespace std;

const int MAX_PETS = 10;

void addPet();
void removePet();
void viewPets();

//* Requirement #1: Read in and store your data in a meaningful way.
//* Solution: Defining and using a dynamic array of animal structs.
struct Animal {
  string name;
  int age;
  int happinessPercentage;
  int happinessThresholdPercentage;
  int happinessDecrementTimeMinutes;
  int satiationPercentage;
  int satiationThresholdPercentage;
  int satiationDecrementTimeMinutes;
};
// - iterate over selectionOptions.txt, store data in the animal struct array.

//* Requirement #2: Provide interactions for the user that utilizes the data.
//* Solution: Function to prompt user with action menu (add, remove, view...).
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

    if (choice == "A" || choice == "ADD" || choice == "ADD PET")
      addPet();
    else if (choice == "R" || choice == "REMOVE" || choice == "REMOVE PET")
      removePet();
    else if (choice == "V" || choice == "VIEW" || choice == "VIEW PETS")
      viewPets();
    else if (choice == "Q" || choice == "QUIT")
      break;
    else
      cout << "Invalid Response. Please input one of the following options:"
           << endl;
  }
}

void addPet() { cout << "Add Pet" << endl; }
// - function to handle adding pet: taking in name for pet
void removePet() { cout << "Remove Pet" << endl; }
// - function to handle removing pet

//* Requirement #3: Basic output to the user in response to their interactions.
//* Solution: Function to display pet list.
void viewPets() { cout << "View Pets" << endl; }
// - function to display pet list

int main() {
  // Defines dynamic array of animal struct to hold data.
  Animal* pets = new Animal[MAX_PETS];
  // for (int i = 0; i < MAX_PETS; i++)
  // {
  //   pets[i].
  // }

  // Opens the action menu.
  actionMenu(pets);
  // Game loop

  return 0;
}