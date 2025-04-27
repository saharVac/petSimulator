#include "Herbivore.h"

// default constructor
Herbivore::Herbivore() : Animal() { this->setDiet("Herbivore"); }
// parameterized constructor
Herbivore::Herbivore(string name, string species, int age, int funValue,
                     int funThreshold, int funDecayTime, int foodValue,
                     int foodThreshold, int foodDecayTime, string diet)
    : Animal(name, species, age, funValue, funThreshold, funDecayTime,
             foodValue, foodThreshold, foodDecayTime, diet) {}

// Interaction functions
void Herbivore::feed() {
  // Otherwise, increase food value by 5.
  this->setFoodValue(this->getFoodValue() + 10);
  // display new food value: petName + foodValue
  cout << this->getName() << " is now at " << this->getFoodValue() << "\% food!"
       << endl;
}

void Herbivore::play() {
  // If fun value already at max of value of 100, do nothing.
  if (this->getFunValue() >= 100) {
    cout << "Your pet is already at max fun!" << endl;
    return;
  }
  // Otherwise, increase fun value by 5.
  this->setFunValue(this->getFunValue() + 10);
  // display new fun value: petName + funValue
  cout << this->getName() << " is now at " << this->getFunValue() << "\% fun!"
       << endl;
}