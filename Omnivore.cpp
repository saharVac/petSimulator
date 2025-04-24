#include "Omnivore.h"

// default constructor
Omnivore::Omnivore() : Animal() { this->setDiet("Omnivore"); }
// parameterized constructor
Omnivore::Omnivore(string name, string species, int age, int funValue,
                   int funThreshold, int funDecayTime, int foodValue,
                   int foodThreshold, int foodDecayTime, string diet)
    : Animal(name, species, age, funValue, funThreshold, funDecayTime,
             foodValue, foodThreshold, foodDecayTime, diet) {}

// Interaction functions
void Omnivore::feed() {
  // TODO - Implement feeding logic for carnivores.
}
void Omnivore::play() {
  // TODO - Implement play logic for carnivores.
}