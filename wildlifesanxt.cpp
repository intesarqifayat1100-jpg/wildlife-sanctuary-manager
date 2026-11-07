/****************This is the line of 80 characters in length*******************
// Author: Intesar Qifayat
// Date: 11/20/25
// CS1428 Lab
// Lab 11 - Wildlife Sanctuary Manager
// Description: You manage a wildlife sanctuary's animal database, allowing
// adding, removing, and displaying animal records.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

struct Animal {
    string name;
    int age;
    string species;
};

void displayAnimals(Animal animals[], int count);
void addAnimal(Animal animals[], int &count, int maxCapacity);
void removeAnimal(Animal animals[], int &count);
void displayAverageAge(Animal animals[], int count);

int main()
{
    srand(time(0));

    const int MAX_ANIMALS = 10;
    int animalCount = 0;
    char choice;
    char continueChoice;

    Animal animals[MAX_ANIMALS];

    cout << "=== WILDLIFE SANCTUARY MANAGER ===" << endl;
    cout << "Manage rescued animal records efficiently." << endl;

    do
    {
        cout << "\nChoose an action:" << endl;
        cout << "1. Display animals" << endl;
        cout << "2. Add animal" << endl;
        cout << "3. Remove animal" << endl;
        cout << "4. Display average animal age" << endl;
        cout << "Enter choice (1-4): ";
        cin >> choice;

        while (choice < '1' || choice > '4')
        {
            cout << "Invalid choice. Enter choice (1-4): ";
            cin >> choice;
        }

        switch (choice)
        {
            case '1':
                displayAnimals(animals, animalCount);
                break;
            case '2':
                addAnimal(animals, animalCount, MAX_ANIMALS);
                break;
            case '3':
                removeAnimal(animals, animalCount);
                break;
            case '4':
                displayAverageAge(animals, animalCount);
                break;
        }

        cout << "\nContinue? (y/n): ";
        cin >> continueChoice;

    } while (continueChoice == 'y' || continueChoice == 'Y');

    cout << "\nFinal Animals:" << endl;
    displayAnimals(animals, animalCount);

    return 0;
}

void displayAnimals(Animal animals[], int count) {
    if (count == 0) {
        cout << "No animals in sanctuary." << endl;
    } else {
        for (int i = 0; i < count; i++) {
            cout << (i + 1) << ". " << animals[i].name
                 << " | Age: " << animals[i].age
                 << " | Species: " << animals[i].species << endl;
        }
    }
}

void addAnimal(Animal animals[], int &count, int maxCapacity) {
    if (count >= maxCapacity) {
        cout << "Sanctuary is full. Cannot add new animal." << endl;
        return;
    }

    string speciesList[5] = {"Gray Wolf", "Red Fox", "Bald Eagle", "Black Bear", "River Otter"};

    cin.ignore();

    cout << "Enter animal name: ";
    getline(cin, animals[count].name);

    cout << "Enter animal age: ";
    cin >> animals[count].age;

    int randomSpeciesIndex = rand() % 5;
    animals[count].species = speciesList[randomSpeciesIndex];

    cout << "Added animal " << animals[count].name
         << ", Age: " << animals[count].age
         << ", Species: " << animals[count].species << endl;

    count++;
}

void removeAnimal(Animal animals[], int &count) {
    if (count == 0) {
        cout << "No animals to remove." << endl;
        return;
    }

    string nameToRemove;
    bool found = false;

    cin.ignore();
    cout << "Enter name of animal to remove: ";
    getline(cin, nameToRemove);

    for (int i = 0; i < count; i++) {
        if (animals[i].name == nameToRemove) {
            found = true;

            for (int j = i; j < count - 1; j++) {
                animals[j] = animals[j + 1];
            }

            count--;
            cout << "Animal " << nameToRemove << " removed from sanctuary." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Animal not found." << endl;
    }
}

void displayAverageAge(Animal animals[], int count) {
    if (count == 0) {
        cout << "No animals in sanctuary." << endl;
        return;
    }

    double totalAge = 0;
    for (int i = 0; i < count; i++) {
        totalAge += animals[i].age;
    }

    double average = totalAge / count;

    cout << fixed << setprecision(1);
    cout << "Average Animal Age: " << average << endl;
}
