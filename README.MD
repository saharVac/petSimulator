# Virtual Pet Simulator

A C++ based virtual pet simulator game where users can adopt, manage, and care for multiple pets simultaneously.

To compile, make sure needed txt files are sitting at the same directory as project files, and use
```g++ petSimulator.cpp Animal.cpp Carnivore.cpp Herbivore.cpp Omnivore.cpp```

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

## Requirements / Rubric

- [x] Classes, inheritance, files:
  - [x] The program contains at least two meaningful inheritance relationships between classes that are
  used during program execution
  - [x] The program contains at least four meaningful classes that are used during program execution
  - [x] The program is divided into multiple .cpp and .h files, with each class having separate declarations
  and definitions, each stored in appropriate files for correct #include usage
- [x] The program contains a text user interface (TUI) that is the main strategy for the user to see and interact with the program
- [x] The program uses pointers and dynamic memory to store class objects rather than static allocation
- [x] Each group member made at least five substantial commits to GitHub (5 points, individually)
- [x] A milestone submission displaying basic functionality of your program
- [x] The program contains at least five operations that the user can select to repeatedly interact with the
program in a meaningful way
  - [x] Adopt
  - [x] Remove
  - [x] View Pets
  - [x] View Inventory
  - [x] Feed
  - [x] Play
  - [ ] Resupply Food
  - [ ] Save (pet array)
- [x] The program fulfills the requirements as set forth in the project proposal
- [x] Program contains sufficient comments
- [x] Program Executes Successfully
- [ ] A group video presentation of your project and program
- [x] Get initial (rough) submission before further enhancements

### Bonus Points

- [ ] Project is particularly creative, complex, or goes well above and beyond the originally proposed project.
- [ ] Highly effective and informative poster that can explain the project in such a way that non-experts can understand
      the problem the project is solving and how it solves the problem.

### Final Checks

- [ ] Final comments, function docs, etc.
- [ ] Makes sure the program executes successfully

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
  - [ ] Food & Happiness "bars"
  - [ ] ASCII Pet Images

### Saving and Loading

- [ ] Time-based update system
  - Utilize \<ctime> for local time
  - Potential exceptions if delta time is negative (I.e. Computer time moved backwards)
- [ ] Save current pets to file
- [ ] Load saved pets from file
- [ ] Auto-save feature

### Advanced Features

- [ ] Different pet behaviors based on animal type
- [ ] Random events (pet gets sick, finds toy, etc.)
- [ ] Pet evolution or aging stages
  - [ ] Later-game / more expensive are pets harder to care for
- [ ] Currency system for buying food/toys
- [ ] Time-based events or details (day/night cycle)

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

## Individual To-Dos

### Chris

- [x] Finalize README (add, revise, etc.)
- [x] Inheritance
- [X] Subclass Feed Functions
  - [x] Separate Foods (stored in .txt file)
- [x] Define View Inventory (and more?)

### Sahar

- [x] Classes, Separate Files
  - [x] Ensure abstract base superclass (purely virtual Feed function)
- [x] Declare Feed, Play: next up - (declared as purely virtual funcs in Animal superclass)
- [X] Functions for Viewing Inventory and Resupply actions defined on main CPP file: next up
