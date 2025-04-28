#include "Carnivore.h"

const int FOODPOWER = 15;
const int FUNPOWER = 15;

// default constructor
Carnivore::Carnivore() : Animal() { this->setDiet("Carnivore"); }
// parameterized constructor
Carnivore::Carnivore(string name, string species, int age, int funValue,
                     int funThreshold, int funDecayTime, int foodValue,
                     int foodThreshold, int foodDecayTime, string diet)
    : Animal(name, species, age, funValue, funThreshold, funDecayTime,
             foodValue, foodThreshold, foodDecayTime, diet) {}

// Interaction functions
void Carnivore::feed() {
  // Otherwise, increase food value by FOODPOWER.
  this->setFoodValue(this->getFoodValue() + FOODPOWER);
  if (this->getFoodValue() > 100) this->setFoodValue(100);
  // displau new food value: petName + foodValue
  cout << this->getName() << " is now at " << this->getFoodValue() << "\% food!"
       << endl;
}

void Carnivore::play() {
  // If fun value already at max of value of 100, do nothing.
  if (this->getFunValue() >= 100) {
    cout << "Your pet is already at max fun!" << endl;
    return;
  }
  // Otherwise, increase fun value by FUNPOWER.
  this->setFunValue(this->getFunValue() + FUNPOWER);
  if (this->getFunValue() > 100) this->setFunValue(100);
  // display new fun value: petName + funValue
  cout << this->getName() << " is now at " << this->getFunValue() << "\% fun!"
       << endl;
}