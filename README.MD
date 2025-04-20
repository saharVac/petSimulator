# Virtual Pet Simulator

A C++ based virtual pet simulator game where users can adopt, manage, and care for multiple pets simultaneously.

## Project Overview

This project is a console-based pet simulation game that allows users to interact with virtual pets, manage their needs, and track their well-being over time. The game implements dynamic memory management and object-oriented programming principles.

## Current Features

- [x] Dynamic array of Animal objects for pet management
- [x] File I/O for loading animal options from CSV/text files
- [x] Basic user interaction menu system
- [x] Add pets (with maximum limit of 10)
- [x] Remove pets from collection
- [x] View current pets
- [x] Proper encapsulation using class with private members
- [x] Getters and setters for necessary properties
- [x] Each pet tracks:
  - Name and animal type
  - Age
  - Happiness percentage with degradation over time
  - Satiation (hunger) percentage with degradation over time

## Recent Updates

- [x] Converted Animal struct to class with proper encapsulation
- [x] Implemented necessary getters and setters
- [x] Updated all functions to work with class methods
- [x] Properly initialized objects using constructor

## PLANNED FEATURES

### Core Gameplay
- [ ] Pet interaction menu for individual pets
- [ ] Feed pet functionality
- [ ] Play with pet functionality
- [ ] Pet aging system
- [ ] Happiness and satiation decay mechanics

### Pet Management
- [ ] Proper removal of specific pets by name/index
- [ ] Cancel option during pet selection
- [ ] Input validation for all user choices
- [ ] More detailed pet status display

### Saving and Loading
- [ ] Save current pets to file
- [ ] Load saved pets from file
- [ ] Auto-save feature

### Advanced Features
- [ ] Different pet behaviors based on animal type
- [ ] Random events (pet gets sick, finds toy, etc.)
- [ ] Pet evolution or aging stages
- [ ] Currency system for buying food/toys
- [ ] Time-based events (day/night cycle)

## Technical Improvements Needed

- [ ] Memory leak prevention for dynamic arrays
- [ ] Error handling improvements
- [ ] Implement proper exception handling
- [ ] Add unit tests for key functionality
- [ ] Consider using STL containers (vector) instead of raw arrays

## Known Issues
- [ ] Need to condense pet attribute assignment in addPet()
- [ ] Implement removal choice in removePet()
- [ ] Add cancel functionality during pet selection
- [ ] Improve input verification in do-while loop
- [ ] Give the game a proper name
