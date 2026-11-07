# Wildlife Sanctuary Manager 🐾

A C++ console application designed to manage animal records efficiently, featuring data tracking, automated species assignment, and aggregate statistical analysis.

## Features
* **Add Animals:** Record new animal entries with custom names, ages, and automated pseudo-random species assignment from a predefined wildlife list.
* **Display Database:** View a formatted, numbered list of all currently sheltered animals along with their attributes.
* **Remove Records:** Search for and safely remove animal profiles by name, utilizing dynamic array shifting to maintain sequential ordering.
* **Calculate Statistics:** Instantly compute and display the average age of all animals in the sanctuary using precise floating-point formatting.

## Technologies Used
* **Language:** C++
* **Standard Libraries:** `<iostream>`, `<string>`, `<cstdlib>`, `<ctime>`, `<iomanip>`

## How to Run
1. Clone the repository or download the source code file (`wildlifesanxt.cpp`).
2. Compile the program using a C++ compiler (such as `g++`):
   ```bash
   g++ -std=c++17 wildlifesanxt.cpp -o sanctuary
