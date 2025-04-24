#include "Carnivore.h"

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
  // TODO - Implement feeding logic for carnivores.
}
void Carnivore::play() {
  // TODO - Implement play logic for carnivores.
}