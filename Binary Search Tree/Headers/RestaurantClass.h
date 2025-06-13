#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <vector>
#include "CuisineClass.h" // Include the header for the Cuisine class
#include "PlaceClass.h"   // Include the header for the Place class

class Cuisine;
class Restaurant {
public:

    // Constructors
    Restaurant(int id, const std::string& restaurantName, const std::string& type, int employeeNumber, const Place& place);


    // Getters
    int getId() const;
    std::string getRestaurantName() const;
    std::string getType() const;
    int getEmployeeNumber() const;
    Place getPlace() const;
    std::vector<Cuisine> getCuisines() const;


    // Setters
    void setId(int id);
    void setRestaurantName(const std::string& restaurantName);
    void setType(const std::string& type);
    void setEmployeeNumber(int employeeNumber);
    void setPlace(const Place& place);
    void setCuisines(const std::vector<Cuisine>& cuisines);


    // Other member functions
      //Sales
    double calculateMonthlyAlgerianSalesFromFile( int restaurantId , const std::string& month );
    double calculateMonthlySyrianSalesFromFile(  int restaurantId  , const std::string& month ) ;
    double calculateMonthlyIndianSalesFromFile( int restaurantId, const std::string& month);
    double calculateMonthlyChineseSalesFromFile( int restaurantId, const std::string& month);
    double calculateMonthlyEuropeanSalesFromFile( int restaurantId, const std::string& month);
    double RestaurantMonthlySales (int restaurantId, const std::string& month);
    
      //Publicity Spending
    double calculateAdvSpending(  int restaurantId,const string& month);
    double calculateRatio(int restaurantId, const string& month );
    void calculateAverageSpending( int restaurantId, const string& month);
      //Files handling and other functions 
    void writeToCSVFile(const string& filename) const;
    
    Cuisine* findCuisineByName(const std::string& cuisineName);
      
private:
    int id;
    std::string restaurantName;
    std::string type;
    int employeeNumber;
    Place place;
    std::vector<Cuisine> Cuisines;
};

#endif // RESTAURANT_H

