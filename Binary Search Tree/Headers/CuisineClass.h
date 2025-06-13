#ifndef CUISINE_H
#define CUISINE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <cctype>
#include <string>
#include "RatingClass.h"  // Include the header for the Rating class
#include "SalesClass.h"   // Include the header for the Sales class
#include "RestaurantClass.h"  // Include the header for the Restaurant class

class Cuisine {
public:
    // Constructors
    Cuisine(const std::string& name);
    Cuisine(const std::string& name, const Rating& rating, const Sales& sales);

    // Getters
    std::string getName() const;
    Rating getRating() const;
    Sales getSales() const;

    // Setters
    void setName(const std::string& name);
    void setRating(const Rating& rating);
    void setSales(const Sales& sales);

    // Rating
    double getAlgerianRating(int restaurantId, const std::string& month);
    double getSyrianRating(int restaurantId, const std::string& month);
    double getChineseRating(int restaurantId, const std::string& month);
    double getEuropeanRating(int restaurantId, const std::string& month);
    double getIndianRating(int restaurantId, const std::string& month);

    // Score
    void calculateAndPopulateHeap(const std::vector<Restaurant>& restaurants, std::priority_queue<std::pair<int, double>>& cuisineHeap, const std::string& cuisineName, const std::string& month);    double calculateScore(const std::string& month, Restaurant resto, const std::string& cuisineName);
    int  getHighestScoreRestaurantIDFromHeap(std::priority_queue<std::pair<int, double>>& cuisineHeap);
    void displayWinners(std::string month);

private:
    std::string name;
    Rating rating;
    Sales sales;
};

#endif // CUISINE_H