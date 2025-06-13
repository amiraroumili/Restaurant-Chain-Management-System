#ifndef CUISINE_H
#define CUISINE_H

#include <string>
#include <vector>  // Include the necessary headers for types used in the class
#include <algorithm>
#include "RatingClass.h"  // Include the header for the Rating class
#include "SalesClass.h"   // Include the header for the Sales class
#include "RestaurantClass.h"  // Include the header for the Restaurant class

class Restaurant;
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
    double calculateAverageAlgerianRatingForMonth(int restaurantId, const std::string& month);
    double calculateAverageSyrianRatingForMonth(int restaurantId, const std::string& month);
    double calculateAverageChineseRatingForMonth(int restaurantId, const std::string& month);
    double calculateAverageEuropeanRatingForMonth(int restaurantId, const std::string& month);
    double calculateAverageIndianRatingForMonth(int restaurantId, const std::string& month);

    // Score
    void calculateAndPopulateVector(const std::vector<Restaurant>& restaurants, std::vector<std::pair<int, double>>& cuisineVector, const std::string& cuisineName, const std::string& month);
    double calculateScore(const std::string& month, Restaurant resto, const std::string& cuisineName);
    int getHighestScoreRestaurantID(const std::vector<std::pair<int, double>>& cuisineVector);

private:
    std::string name;
    Rating rating;
    Sales sales;
};

#endif // CUISINE_H
