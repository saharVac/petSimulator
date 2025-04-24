#ifndef ANIMAL_H
#define ANIMAL_H

#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Animal {
 private:
  string name;
  string species;
  int age;
  int funValue;
  int funThreshold;
  int funDecayTime;  // minutes
  int foodValue;
  int foodThreshold;
  int foodDecayTime;
  string diet;  // Carnivore, Herbivore, Omnivore
 protected:
  // void renderPercentageBar(int percentage, int threshold)
 public:
  // default constructor
  Animal();
  // parameterized constructor
  Animal(string, string, int, int, int, int, int, int, int, string);

  // setters and getters
  void setName(string);
  void setAge(int);
  void setFunValue(int);
  void setFoodValue(int);
  void setDiet(string);

  string getName();
  string getSpecies();
  int getFunValue();
  int getFunThreshold();
  int getFunDecayTime();
  int getFoodValue();
  int getFoodThreshold();
  int getFoodDecayTime();
  string getDiet();

  // Interaction functions
  virtual void feed() = 0;
  virtual void play() = 0;
};

#endif