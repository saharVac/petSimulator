#ifndef CARNIVORE_H
#define CARNIVORE_H

#include "Animal.h"
using namespace std;

class Carnivore : public Animal {
 public:
  // default constructor
  Carnivore();
  // parameterized constructor
  Carnivore(string, string, int, int, int, int, int, int, int, string);

  // Interaction functions
  void feed();
  void play();
};

#endif