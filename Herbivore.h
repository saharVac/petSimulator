#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "Animal.h"
using namespace std;

class Herbivore : public Animal {
 public:
  // default constructor
  Herbivore();
  // parameterized constructor
  Herbivore(string, string, int, int, int, int, int, int, int, string);

  // Interaction functions
  void feed();
  void play();
};

#endif