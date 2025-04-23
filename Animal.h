#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal {
    private:
      string name;
      string animalName;
      int age;
      int happinessPercentage;
      int happinessThresholdPercentage;
      int happinessDecrementTimeMinutes;
      int satiationPercentage;
      int satiationThresholdPercentage;
      int satiationDecrementTimeMinutes;
      string animalCategory; // carnivore, herbivore, omnivore
    protected:
      // void renderPercentageBar(int percentage, int threshold)
    public:
      // default constructor
      Animal() {
        // TODO: rethink initial values.
        name = "null";
        animalName = "";
        age = 0;
        happinessPercentage = 0;
        happinessThresholdPercentage = 0;
        happinessDecrementTimeMinutes = 0;
        satiationPercentage = 0;
        satiationThresholdPercentage = 0;
        satiationDecrementTimeMinutes = 0;
      }
  
      // parameterized constructor
      Animal(string name, string animalName, int age,int happinessPercentage, int happinessThresholdPercentage, int happinessDecrementTimeMinutes, int satiationPercentage, int satiationThresholdPercentage, int satiationDecrementTimeMinutes) {
        this->name = name;
        this->animalName = animalName;
        this->age = age;
        this->happinessPercentage = happinessPercentage;
        this->happinessThresholdPercentage = happinessThresholdPercentage;
        this->happinessDecrementTimeMinutes = happinessDecrementTimeMinutes;
        this->satiationPercentage = satiationPercentage;
        this->satiationThresholdPercentage = satiationThresholdPercentage;
        this->satiationDecrementTimeMinutes = satiationDecrementTimeMinutes;
      }
  
      // setters and getters - adding as needed
  
      void setName(string name) { this->name = name; }
      void setAnimalName(string animalName) { this->animalName = animalName; }
      void setAge(int age) { this->age = age; }
      void setHappinessPercentage(int happinessPercentage) {
        this->happinessPercentage = happinessPercentage;
      }
      void setSatiationPercentage(int satiationPercentage) {
        this->satiationPercentage = satiationPercentage;
      }
      void setHappinessThresholdPercentage(int happinessThresholdPercentage) {
        this->happinessThresholdPercentage = happinessThresholdPercentage;
      }
      void setHappinessDecrementTimeMinutes(int happinessDecrementTimeMinutes) {
        this->happinessDecrementTimeMinutes = happinessDecrementTimeMinutes;
      }
      void setSatiationThresholdPercentage(int satiationThresholdPercentage) {
        this->satiationThresholdPercentage = satiationThresholdPercentage;
      }
      void setSatiationDecrementTimeMinutes(int satiationDecrementTimeMinutes) {
        this->satiationDecrementTimeMinutes = satiationDecrementTimeMinutes;
      }
      void setAnimalCategory(string animalCategory) {
        this->animalCategory = animalCategory;
      }
  
      string getName() { return name; }
      string getAnimalName() { return animalName; }
      int getHappinessThresholdPercentage() {
        return happinessThresholdPercentage;
      }
      int getHappinessDecrementTimeMinutes() {
        return happinessDecrementTimeMinutes;
      }
      int getSatiationThresholdPercentage() {
        return satiationThresholdPercentage;
      }
      int getSatiationDecrementTimeMinutes() {
        return satiationDecrementTimeMinutes;
      }
      string getAnimalCategory() {
        return animalCategory;
      }

      // Interaction functions
      virtual void feed() = 0;
      virtual void play() = 0;
  
  
  };

#endif