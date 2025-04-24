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
  // TODO - Implement feeding logic for carnivores.
}
void Herbivore::play() {
  // TODO - Implement play logic for carnivores.
}