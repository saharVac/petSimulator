#ifndef OMNIVORE_H
#define OMNIVORE_H

#include "Animal.h"
using namespace std;

class Omnivore : public Animal {
 public:
  // default constructor
  Omnivore();
  // parameterized constructor
  Omnivore(string, string, int, int, int, int, int, int, int, string);

  // Interaction functions
  void feed();
  void play();
};

#endif