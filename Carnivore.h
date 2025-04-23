#ifndef CARNIVORE_H
#define CARNIVORE_H

#include <string>

#include "Animal.h"

using namespace std;

class Carnivore : public Animal {
    public:
        // Constructor
        Carnivore(string name, string animalName, int age, int happinessPercentage, int happinessThresholdPercentage, int happinessDecrementTimeMinutes, int satiationPercentage, int satiationThresholdPercentage, int satiationDecrementTimeMinutes) : Animal(name, animalName, age, happinessPercentage, happinessThresholdPercentage, happinessDecrementTimeMinutes, satiationPercentage, satiationThresholdPercentage, satiationDecrementTimeMinutes) {}
        
        void feed() {
            // TODO - Implement feeding logic for carnivores.
        }
        void play() {
            // TODO - Implement play logic for carnivores.
        }
};


#endif