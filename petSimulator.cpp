#include <iostream>

using namespace std;

const int MAX_PET_AMOUNT = 10;

// 1. "Reading in and storing your data in a meaningful way": can store on a dynmaic array of animal structs
// - define animal struct
struct Animal {
    string name;
    int age;
    int hungerPercetage;
    int happinessPercetage;
    int happinessThresholdPercentage;
    int defaultHappinessDecrementTimeMinutes;
    int satiationThresholdPercentage;
    int defaultSatiationDecrementTimeMinutes;
};
// - iterating over lines selectionOptions.txt, store data in animal struct on the dynamic array 


// 2. "Providing some limited set of interactions for the user that utilizes the data": function to prompt user with action menu
// - function for prompting menu to user (starting with just add pet, remove pet, and will add more later on)
// - function to handle adding pet: taking in name for pet
// - function to handle removing pet


// 3. "Providing some basic output to the user in response to their interactions": displaying pets list after every addition/removal of a pet
// - function to display pet list
void displayPets();

int main() {

    // - define dynamic array of the animal struct to hold the data
    Animal* pets = new Animal[MAX_PET_AMOUNT];

    // Game loop

    return 0;
}