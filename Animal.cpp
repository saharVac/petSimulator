#include "Animal.h"

Animal::Animal() {
  this->name = "null";
  this->species = "null";
  this->age = 0;
  this->funValue = 0;
  this->funThreshold = 0;
  this->funDecayTime = 0;
  this->foodValue = 0;
  this->foodThreshold = 0;
  this->foodDecayTime = 0;
}

Animal::Animal(string name, string species, int age, int funValue,
               int funThreshold, int funDecayTime, int foodValue,
               int foodThreshold, int foodDecayTime, string diet) {
  this->name = name;
  this->species = species;
  this->age = age;
  this->funValue = funValue;
  this->funThreshold = funThreshold;
  this->funDecayTime = funDecayTime;
  this->foodValue = foodValue;
  this->foodThreshold = foodThreshold;
  this->foodDecayTime = foodDecayTime;
  this->diet = diet;
}

// Setters (added as needed)

void Animal::setName(string name) { this->name = name; }
void Animal::setAge(int age) { this->age = age; }
void Animal::setFunValue(int funValue) { this->funValue = funValue; }
void Animal::setFoodValue(int foodValue) { this->foodValue = foodValue; }
void Animal::setDiet(string diet) { this->diet = diet; }

// Getters

string Animal::getName() { return name; }
string Animal::getSpecies() { return species; }
int Animal::getAge() { return age; }
int Animal::getFunValue() { return funValue; }
int Animal::getFunThreshold() { return funThreshold; }
int Animal::getFunDecayTime() { return funDecayTime; }
int Animal::getFoodValue() { return foodValue; }
int Animal::getFoodThreshold() { return foodThreshold; }
int Animal::getFoodDecayTime() { return foodDecayTime; }
string Animal::getDiet() { return diet; }

// Interaction functions not included (purely virtual)
