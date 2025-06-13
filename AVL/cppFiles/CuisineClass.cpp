#include "CuisineClass.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <cctype>
#include <string>


// Constructors
Cuisine::Cuisine(const std::string& name) : name(name) {}

Cuisine::Cuisine(const std::string& name, const Rating& rating, const Sales& sales) : name(name), rating(rating), sales(sales) {}

// Getters
std::string Cuisine::getName() const {
    return name;
}

Rating Cuisine::getRating() const {
    return rating;
}

Sales Cuisine::getSales() const {
    return sales;
}

// Setters
void Cuisine::setName(const std::string& name) {
    this->name = name;
}

void Cuisine::setRating(const Rating& rating) {
    this->rating = rating;
}

void Cuisine::setSales(const Sales& sales) {
    this->sales = sales;
}


//Other member Functions

//--------------------------------------------------------------------Rating-----------------------------------------------------------------------

// Function to get average Algerian rating for a specific month
  double Cuisine::getAlgerianRating(int restaurantId, const string& month, const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return -1.0;  // Return -1 if the file cannot be opened
    }

    string line;
    getline(file, line); // Read and discard the header line

    while (getline(file, line)) {
        istringstream ss(line);
        string token;

        getline(ss, token, ','); // Read Date
        string currentDate = token.substr(0, 7); // Extract the year-month part

        getline(ss, token, ','); // Read Id

        // Use a try-catch block to handle potential stoi exception
        try {
            int currentRestaurantId = stoi(token);

            if (currentRestaurantId == restaurantId && currentDate == month) {
                // Skip to AlgerianRating column
                for (int i = 0; i < 2; ++i) {
                    getline(ss, token, ',');
                }

                // Read AlgerianRating and close the file
                double algerianRating = stod(token);
                file.close();
                return algerianRating;
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Error converting Id to integer: " << e.what() << endl;
            // Handle the error (e.g., skip the line)
        }
    }

    file.close();
    return -1.0;  // Return -1 if the data is not found
}

// Function to calculate average Syrian rating for a specific month
double getSyrianRating(int restaurantId, const string& month, const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return -1.0;  // Return -1 if the file cannot be opened
    }

    string line;
    getline(file, line); // Read and discard the header line

    while (getline(file, line)) {
        istringstream ss(line);
        string token;

        getline(ss, token, ','); // Read Date
        string currentDate = token.substr(0, 7); // Extract the year-month part

        getline(ss, token, ','); // Read Id

        // Use a try-catch block to handle potential stoi exception
        try {
            int currentRestaurantId = stoi(token);

            if (currentRestaurantId == restaurantId && currentDate == month) {
                // Skip to SyrianRating column
                for (int i = 0; i < 3; ++i) {
                    getline(ss, token, ',');
                }

                // Read SyrianRating and close the file
                double syrianRating = stod(token);
                file.close();
                return syrianRating;
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Error converting Id to integer: " << e.what() << endl;
            // Handle the error (e.g., skip the line)
        }
    }

    file.close();
    return -1.0;  // Return -1 if the data is not found
}
// Function to calculate average Indian rating for a specific month
double getIndianRating(int restaurantId, const string& month, const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return -1.0;  // Return -1 if the file cannot be opened
    }

    string line;
    getline(file, line); // Read and discard the header line

    while (getline(file, line)) {
        istringstream ss(line);
        string token;

        getline(ss, token, ','); // Read Date
        string currentDate = token.substr(0, 7); // Extract the year-month part

        getline(ss, token, ','); // Read Id

        // Use a try-catch block to handle potential stoi exception
        try {
            int currentRestaurantId = stoi(token);

            if (currentRestaurantId == restaurantId && currentDate == month) {
                // Skip to IndianRating column
                for (int i = 0; i < 4; ++i) {
                    getline(ss, token, ',');
                }
        // Read Rating and close the file
                double IndianRating = stod(token);
                file.close();
                return IndianRating;
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Error converting Id to integer: " << e.what() << endl;
            // Handle the error (e.g., skip the line)
        }
    }

    file.close();
    return -1.0;  // Return -1 if the data is not found
}


// Function to calculate average Chinese rating for a specific month
double getChineseRating(int restaurantId, const string& month, const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return -1.0;  // Return -1 if the file cannot be opened
    }

    string line;
    getline(file, line); // Read and discard the header line

    while (getline(file, line)) {
        istringstream ss(line);
        string token;

        getline(ss, token, ','); // Read Date
        string currentDate = token.substr(0, 7); // Extract the year-month part

        getline(ss, token, ','); // Read Id

        // Use a try-catch block to handle potential stoi exception
        try {
            int currentRestaurantId = stoi(token);

            if (currentRestaurantId == restaurantId && currentDate == month) {
                // Skip to IndianRating column
                for (int i = 0; i < 5; ++i) {
                    getline(ss, token, ',');
                }

                // Read Rating and close the file
                double ChineseRating = stod(token);
                file.close();
                return ChineseRating;
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Error converting Id to integer: " << e.what() << endl;
            // Handle the error (e.g., skip the line)
        }
    }

    file.close();
    return -1.0;  // Return -1 if the data is not found
}




// Function to calculate average European rating for a specific month
double getEuropeanRating(int restaurantId, const string& month, const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return -1.0;  // Return -1 if the file cannot be opened
    }

    string line;
    getline(file, line); // Read and discard the header line

    while (getline(file, line)) {
        istringstream ss(line);
        string token;

        getline(ss, token, ','); // Read Date
        string currentDate = token.substr(0, 7); // Extract the year-month part

        getline(ss, token, ','); // Read Id

        // Use a try-catch block to handle potential stoi exception
        try {
            int currentRestaurantId = stoi(token);
            if (currentRestaurantId == restaurantId && currentDate == month) {
                // Skip to IndianRating column
                for (int i = 0; i < 6; ++i) {
                    getline(ss, token, ',');
                }

                // Read Rating and close the file
                double EuropeanRating = stod(token);
                file.close();
                return ChineseRating;
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Error converting Id to integer: " << e.what() << endl;
            // Handle the error (e.g., skip the line)
        }
    }

    file.close();
    return -1.0;  // Return -1 if the data is not found
}

//--------------------------------------------------------------------Score-----------------------------------------------------------------------


// Function to calculate and populate max-heap for a specific cuisine
void Cuisine::calculateAndPopulateHeap(const std::vector<Restaurant>& restaurants, std::priority_queue<std::pair<int, double>>& cuisineHeap, const std::string& cuisineName, const std::string& month) {
    cuisineHeap = std::priority_queue<std::pair<int, double>>(); // Clear the heap before populating

    for (const auto& restaurant : restaurants) {
        Cuisine* cuisine = restaurant.findCuisineByName(cuisineName);
        if (cuisine != nullptr) {
            double cuisineScore = cuisine->calculateScore(month, restaurant, cuisineName);
            cuisineHeap.push(std::make_pair(restaurant.getId(), cuisineScore));
        }
    }
}


double Cuisine::calculateScore(const string& month, Restaurant resto, const string& cuisineNamee) {
    double monthlySales = resto.RestaurantMonthlySales(resto.getId(), month);
    double avrRating = 0.0;

    // Convert cuisineNamee to lowercase
    string cuisineNameLower = cuisineNamee;
    std::transform(cuisineNameLower.begin(), cuisineNameLower.end(), cuisineNameLower.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    if (cuisineNameLower == "algerian") {
        avrRating = getAlgerianRating(resto.getId(), month);
    } else if (cuisineNameLower == "chinese") {
        avrRating = getChineseRating(resto.getId(), month);
    } else if (cuisineNameLower == "indian") {
        avrRating = getIndianRating(resto.getId(), month);
    } else if (cuisineNameLower == "syrian") {
        avrRating = getSyrianRating(resto.getId(), month);
    } else if (cuisineNameLower == "european") {
        avrRating = getEuropeanRating(resto.getId(), month);
    } else {
        std::cerr << "Error: Invalid cuisine name" << std::endl;
        return -1;
    }

    // Return the calculated score
    return (monthlySales + (avrRating / 100));
}


// Function to get the highest score restaurant ID from a max-heap
int Cuisine::getHighestScoreRestaurantIDFromHeap(std::priority_queue<std::pair<int, double>>& cuisineHeap) {
    if (cuisineHeap.empty()) {
        std::cerr << "Cuisine heap is empty." << std::endl;
        return -1;  //error
    }

    // Get the ID of the restaurant with the highest score
    return cuisineHeap.top().first;
}

// Function to display winners on a given month
void Cuisine::displayWinners(std::string month) {
  // Create max-heaps for Chinese, Algerian, Syrian, European, and Indian cuisines
    std::priority_queue<std::pair<int, double>> Chinese, Algerian, Syrian, European, Indian;

    // Calculate and populate vectors for each cuisine
    calculateAndPopulateHeap(restaurants, Chinese, "chinese", month);
    calculateAndPopulateHeap(restaurants, Algerian, "algerian", month);
    calculateAndPopulateHeap(restaurants, Syrian, "syrian", month);
    calculateAndPopulateHeap(restaurants, European, "european", month);
    calculateAndPopulateHeap(restaurants, Indian, "indian", month);
    // Get the ID of the restaurant with the highest score for each cuisine
    int highestScoreChineseID = getHighestScoreRestaurantID(Chinese);
    int highestScoreAlgerianID = getHighestScoreRestaurantID(Algerian);
    int highestScoreSyrianID = getHighestScoreRestaurantID(Syrian);
    int highestScoreEuropeanID = getHighestScoreRestaurantID(European);
    int highestScoreIndianID = getHighestScoreRestaurantID(Indian);

    // Print the results
    std::cout << "Winners of the month "<< month <<" are :" <<endl ;
    std::cout << "Restaurant ID with the highest score for Chinese cuisine: " << highestScoreChineseID << std::endl;
    std::cout << "Restaurant ID with the highest score for Algerian cuisine: " << highestScoreAlgerianID << std::endl;
    std::cout << "Restaurant ID with the highest score for Syrian cuisine: " << highestScoreSyrianID << std::endl;
    std::cout << "Restaurant ID with the highest score for European cuisine: " << highestScoreEuropeanID << std::endl;
    std::cout << "Restaurant ID with the highest score for Indian cuisine: " << highestScoreIndianID << std::endl;

}

