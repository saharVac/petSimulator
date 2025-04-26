//* Requirement #1: Read in and store your data in a meaningful way.
//  Solution: Defining and using a dynamic array of animal structs.
//* Requirement #2: Provide interactions for the user that utilizes the data.
//  Solution: Functions to add / remove pets from the dynamic array.
//* Requirement #3: Basic output to the user in response to their interactions.
//  Solution: Function to print the contents of the dynamic array.

#include "Carnivore.h"
#include "Herbivore.h"
#include "Omnivore.h"

using namespace std;

#pragma region  // Global Variables
int currentPets = 0;
const int MAX_PETS = 10;            // Marks the maximum # of pets you can own.
const int NUM_ANIMAL_OPTIONS = 15;  // Marks the total number of animal types.
#pragma endregion

#pragma region  // Function Declarations
void updateData(/*Animal**, Animal**, */ int*);
Animal** readAnimalOptions();
void actionMenu(Animal**, Animal**, int[]);
void addPet(Animal**, Animal**);
void removePet(Animal**);
void viewPets(Animal**);
void feedPets(Animal**, int[]);
void playPets(Animal**);
void quitProgram(Animal**, Animal**);
#pragma endregion

// @brief Reads data from file to set pets, inventory, etc.
// @param pets Dynamic array of Animal objects.
// @param petOptions Dynamic array of Animal object options.
// @param inventory Pointer to an array of ints.
void updateData(/*Animal* pets[], Animal* petOptions[], */ int* inventory) {
  // TODO - Updates values according to time passed between sessions.
  // TODO - Return pets[]?

  // Protection if file doesn't exist.
  ifstream file("dataFile.txt");
  if (!file) {
    cerr << "Error opening selectionOptions.txt" << endl;
  }

  string line;
  getline(file, line);  // Skip header
  getline(file, line);
  stringstream ss(line);
  ss >> ws;  // Discards any leading whitespace

  // Fill inventory array.
  for (int i = 0; i < 3; i++) {
    string token;
    getline(ss, token, ',');
    inventory[i] = stoi(token);
  }

  file.close();
}

// @brief Reads data from a text file to declare a dynamic array of Animals
// object options.
// @return Dynamic array of Animal object options.
Animal** readAnimalOptions() {
  // Protection if file doesn't exist.
  ifstream file("selectionOptions.txt");
  if (!file) {
    cerr << "Error opening selectionOptions.txt" << endl;
    return nullptr;
  }

  Animal** petOptions = new Animal*[NUM_ANIMAL_OPTIONS];

  string line;
  getline(file, line);  // Skip header

  for (int i = 0; i < NUM_ANIMAL_OPTIONS && getline(file, line); i++) {
    stringstream ss(line);
    string token;

    string species;
    getline(ss, species, ',');
    ss >> ws;  // Discards any leading whitespace

    getline(ss, token, ',');
    int funThreshold = stoi(token);

    getline(ss, token, ',');
    int funDecayTime = stoi(token);

    getline(ss, token, ',');
    int foodThreshold = stoi(token);

    getline(ss, token, ',');
    int foodDecayTime = stoi(token);

    getline(ss, token, ',');
    string diet = token;

    if (diet == "Carnivore") {
      petOptions[i] =
          new Carnivore("null", species, 0, 100, funThreshold, funDecayTime,
                        100, foodThreshold, foodDecayTime, diet);
    } else if (diet == "Herbivore") {
      petOptions[i] =
          new Herbivore("null", species, 0, 100, funThreshold, funDecayTime,
                        100, foodThreshold, foodDecayTime, diet);
    } else if (diet == "Omnivore") {
      petOptions[i] =
          new Omnivore("null", species, 0, 100, funThreshold, funDecayTime, 100,
                       foodThreshold, foodDecayTime, diet);
    } else {
      cout << "Unknown animal category: '" << diet << "'" << endl;
    }
  }

  file.close();
  return petOptions;
}

// @brief Prompts the user with an action menu (add, remove, view...).
// @param pets Dynamic array of Animal objects.
// @param petOptions Dynamic array of Animal object options.
void actionMenu(Animal* pets[], Animal* petOptions[], int inventory[]) {
  string choice;
  cout << "Please input one of the following options:" << endl;
  while (true) {
    cout << "- Add Pet (A)" << endl
         << "- Remove Pet (R)" << endl
         << "- View Pets (V)" << endl
         << "- Feed Pet (F)" << endl
         << "- Play with Pet (P)" << endl
         << "- Quit (Q)" << endl
         << endl
         << "Choice: ";
    getline(cin, choice);

    // Converts string to uppercase
    for (int i = 0; i < choice.size(); i++) choice[i] = toupper(choice[i]);

    // Action menu
    if (choice == "A" || choice == "ADD" || choice == "ADD PET")
      addPet(pets, petOptions);
    else if (choice == "R" || choice == "REMOVE" || choice == "REMOVE PET")
      removePet(pets);
    else if (choice == "V" || choice == "VIEW" || choice == "VIEW PETS")
      viewPets(pets);
    else if (choice == "F" || choice == "FEED" || choice == "FEED PET")
      feedPets(pets, inventory);
    else if (choice == "P" || choice == "PLAY" || choice == "PLAY WITH PET")
      playPets(pets);
    else if (choice == "Q" || choice == "QUIT")
      quitProgram(pets, petOptions);
    else
      cout << "Invalid Response. Please input one of the following options:"
           << endl;
  }
}

// @brief Adds a chosen pet to the dynamic array.
// @param pets Dynamic array of Animal objects.
// @param petOptions Dynamic array of Animal object options.
void addPet(Animal* pets[], Animal* petOptions[]) {
  if (currentPets >= MAX_PETS)
    cout << "Pets at capacity! Please remove a pet first." << endl << endl;
  else {
    // Display animal options for adoption.
    int choice;
    bool takingInAnimalChoice = true;
    do {
      cout << "Which animal would you like to adopt? Input 0 to cancel."
           << endl;
      if (petOptions != nullptr) {
        for (int i = 0; i < NUM_ANIMAL_OPTIONS; i++) {
          Animal* currentAnimal = petOptions[i];
          cout << i + 1 << ". " << currentAnimal->getSpecies() << ":" << endl;
          cout << "- Happiness Threshold - " << currentAnimal->getFunThreshold()
               << endl;
          cout << "- Happiness Decrement Time (min/1%) - "
               << currentAnimal->getFunDecayTime() << endl;
          cout << "- Satiation Threshold - "
               << currentAnimal->getFoodThreshold() << endl;
          cout << "- Satiation Decrement Time (min/1%) - "
               << currentAnimal->getFoodDecayTime() << endl
               << endl;
        }
      }
      // Input verification.
      while (takingInAnimalChoice) {
        cout << "Choice (number): ";
        cin >> choice;

        if (choice >= 0 && choice <= NUM_ANIMAL_OPTIONS)
          takingInAnimalChoice = false;
        else
          cout << choice << " is not an option! Try Again." << endl << endl;
      }
    } while (takingInAnimalChoice);

    // If 0, quit without adding a pet.
    if (choice == 0) {
      cin.ignore();
    } else {
      // Re-index choice (starts visual list at index 1).
      choice -= 1;

      cout << petOptions[choice]->getSpecies()
           << " chosen! Please enter what you'd like to name it: ";
      string petName;
      cin >> petName;
      cin.ignore();

      if (dynamic_cast<Carnivore*>(petOptions[choice]) != nullptr) {
        pets[currentPets] =
            new Carnivore(petName, petOptions[choice]->getSpecies(), 0, 80,
                          petOptions[choice]->getFunThreshold(),
                          petOptions[choice]->getFunDecayTime(), 80,
                          petOptions[choice]->getFoodThreshold(),
                          petOptions[choice]->getFoodDecayTime(),
                          petOptions[choice]->getDiet());
      } else if (dynamic_cast<Herbivore*>(petOptions[choice]) != nullptr) {
        pets[currentPets] =
            new Herbivore(petName, petOptions[choice]->getSpecies(), 0, 80,
                          petOptions[choice]->getFunThreshold(),
                          petOptions[choice]->getFunDecayTime(), 80,
                          petOptions[choice]->getFoodThreshold(),
                          petOptions[choice]->getFoodDecayTime(),
                          petOptions[choice]->getDiet());
      } else if (dynamic_cast<Omnivore*>(petOptions[choice]) != nullptr) {
        pets[currentPets] =
            new Omnivore(petName, petOptions[choice]->getSpecies(), 0, 80,
                         petOptions[choice]->getFunThreshold(),
                         petOptions[choice]->getFunDecayTime(), 80,
                         petOptions[choice]->getFoodThreshold(),
                         petOptions[choice]->getFoodDecayTime(),
                         petOptions[choice]->getDiet());
      }

      // Notify user that pet was successfully added.
      cout << "Added " << pets[currentPets]->getSpecies() << " "
           << pets[currentPets]->getName() << "!" << endl
           << endl;
      currentPets++;
    }
  }
}

// @brief Removes a pet from the dynamic array.
// @param pets Dynamic array of Animal objects.
void removePet(Animal* pets[]) {
  if (currentPets <= 0)
    cout << "You have no pets! Please add a pet first." << endl << endl;
  else {
    currentPets--;
    pets[currentPets]->setName("null");
  }
  // TODO - Implement removal choice, like in addPet().
}

// @brief Prints the dynamic array.
// @param pets Dynamic array of Animal objects.
void viewPets(Animal* pets[]) {
  if (currentPets <= 0)
    cout << "You have no pets!" << endl << endl;
  else {
    cout << "You have the following pets:" << endl;
    for (int i = 0; i < currentPets; i++)
      cout << pets[i]->getSpecies() << " - " << pets[i]->getName() << endl;
    // Uncomment once ready to implement a Happiness and Hunger bar:
    // cout << pets[i].getAnimalName() << " - " << pets[i].getName() << "
    // Hunger: " << hungerBar << " Happiness: " << happinessBar << endl;
    cout << endl;
  }
}

// @brief Prints inventory, then attempts to feed a chosen pet.
// @param pets Dynamic array of Animal objects.
// @param inventory Array of food amounts.
void feedPets(Animal* pets[], int inventory[]) {
  if (currentPets <= 0)
    cout << "You have no pets to feed!" << endl << endl;
  else {

    // Check if inventory is empty.
    if (inventory[0] <= 0 && inventory[1] <= 0 && inventory[2] <= 0) {
      cout << "You have no food to feed your pets!" << endl << endl;
      return;
    }
    
    // Ask which pet to feed
    cout << "Which pet would you like to feed?" << endl;
    for (int i = 0; i < currentPets; i++)
      cout << i + 1 << ". " << pets[i]->getSpecies() << " - " << pets[i]->getName() << endl;
    cout << "Choice (number): ";
    int choice;
    cin >> choice;
    cin.ignore();
    choice -= 1;  // Re-index choice (starts visual list at index 1).

    // Check if choice is valid.
    if (choice < 0 || choice >= currentPets) {
      cout << "Invalid choice!" << endl;
      return;
    }

    // TODO: implement check that proper food type is available.
    // ----------------------------
    // TEMPORARY CODE
    
    // Print inventory.
    cout << "What would you like to feed " <<  pets[choice]->getName() << "?" << endl;
    cout << "1. Meat: " << inventory[0] << endl;
    cout << "2. Veggies: " << inventory[1] << endl;
    cout << "3. Other: " << inventory[2] << endl;
    // take in food choice
    int foodChoice;
    cout << "Choice (number): ";
    cin >> foodChoice;
    cin.ignore();
    // check if food choice is valid
    if (foodChoice < 1 || foodChoice > 3) {
      cout << "Invalid choice!" << endl;
      return;
    }
    // call d
    // decrement inventory of that food type
    inventory[foodChoice - 1]--;
    // display new inventory of that food type
    cout << "You have " << inventory[foodChoice - 1] << " of that food type left." << endl;

    // END TEMPORARY CODE
    // ----------------------------

    // Call appropriate feed member function (feed function does the checking)
    pets[choice]->feed();

    
    // TODO - Feed member functions should subtract correct food type.
    // TODO - Loop until a sentinel value is entered (0?).

    // TODO - Omnivores can eat meat AND veggies? Remove 'other' food type?

  }
}

// @brief Prints inventory, then attempts to feed a chosen pet.
// @param pets Dynamic array of Animal objects.
void playPets(Animal* pets[]) {
  if (currentPets <= 0)
    cout << "You have no pets to play with!" << endl << endl;
  else {
    // TODO - This is temporary code.
    for (int i = 0; i < 10; i++) {
      cout << "Yippee! ";
    }
    cout << endl << endl;
  }
}

// @brief Deallocates the dynamic arrays and quits the program.
// @param pets Dynamic array of Animal objects.
// @param petOptions Dynamic array of Animal object options.
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
  Animal** petOptions = readAnimalOptions();

  // Fills inventory from dataFile
  int inventory[3];
  updateData(inventory);

  // TODO - Give the game a name?
  cout << "Welcome to the pet simulator game!" << endl << endl;

  // TODO - Move actionMenu code to main? Make this the primary game loop?
  actionMenu(pets, petOptions, inventory);

  return 0;
}