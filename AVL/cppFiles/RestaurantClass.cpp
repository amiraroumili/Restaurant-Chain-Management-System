#include "RestaurantClass.h"
#include "CuisineClass.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

// Constructors
Restaurant::Restaurant(int id, const std::string& restaurantName, const std::string& type, int employeeNumber, const Place& place)
    : id(id), restaurantName(restaurantName), type(type), employeeNumber(employeeNumber), place(place) {
    Cuisines = {
        Cuisine("Algerian"),
        Cuisine("Syrian"),
        Cuisine("European"),
        Cuisine("Indian"),
        Cuisine("Chinese")
    };
}

// Getters
int Restaurant::getId() const {
    return id;
}

std::string Restaurant::getRestaurantName() const {
    return restaurantName;
}

std::string Restaurant::getType() const {
    return type;
}

int Restaurant::getEmployeeNumber() const {
    return employeeNumber;
}

Place Restaurant::getPlace() const {
    return place;
}

std::vector<Cuisine> Restaurant::getCuisines() const {
    return Cuisines;
}

// Setters
void Restaurant::setId(int id) {
    this->id = id;
}

void Restaurant::setRestaurantName(const std::string& restaurantName) {
    this->restaurantName = restaurantName;
}

void Restaurant::setType(const std::string& type) {
    this->type = type;
}

void Restaurant::setEmployeeNumber(int employeeNumber) {
    this->employeeNumber = employeeNumber;
}

void Restaurant::setPlace(const Place& place) {
    this->place = place;
}

void Restaurant::setCuisines(const std::vector<Cuisine>& cuisines) {
    this->Cuisines = cuisines;
}

//---------------------------------------------------------------Files Handling and Other-----------------------------------------------------------------------------


// Find and return a specific Cuisine by name
    Cuisine* Restaurant::findCuisineByName(const std::string& cuisineName)  {
    for (const Cuisine& cuisine : Cuisines) {
        if (cuisine.getName() == cuisineName) {
            return const_cast<Cuisine*>(&cuisine);
        }
    }
    return nullptr; // Cuisine not found.
}





// Function to add restaurant to a csv file 'restaurants.csv'

void Restaurant::writeToCSVFile(const string& filename) const {
        ofstream file("../File_csv/restaurants.csv", ios::app);  // Open the file in append mode
    int newId ; 
    string newName, newType, newCountry, newWilaya, newCity, newDistrict;
    int newEmployeeNumber;

     cout << "Enter new restaurant ID: ";
     cin >> newId;

     cout << "Enter new restaurant name: ";
     cin.ignore(); // Ignore the newline character left in the buffer
     getline( cin, newName);

     cout << "Enter new restaurant type (Owned/Franchised): ";
     cin >> newType;

     cout << "Enter new employee number: ";
     cin >> newEmployeeNumber;

     cout << "Enter new country: ";
     cin >> newCountry;

     cout << "Enter new wilaya: ";
     cin >> newWilaya;

     cout << "Enter new city: ";
     cin >> newCity;

     cout << "Enter new district: ";
     cin >> newDistrict;


        if (!file.is_open()) {
            cerr << "Error: Unable to open file " << filename << endl;
            return;
        }
    file<< newId << "," << newName << "," << newEmployeeNumber << "," << newType << "," << newCountry << "," << newWilaya << "," << newCity << "," << newDistrict << "\n";
    file.close();
       }
     

