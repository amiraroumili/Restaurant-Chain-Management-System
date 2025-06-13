#include <iostream>
#include <fstream>
#include <string>
#include "PlaceClass.h"
#include "RestaurantClass.h"
#include "CuisineClass.h"
#include "SalesClass.h"
#include "CostClass.h"


using namespace std;

// Function to display the main menu
void displayMainMenu() {
    cout << "Menu:\n";
    cout << "1. Display Sales Report of One Restaurant\n";
    cout << "2. Display Sales of All Restaurants in a Specific Place\n";
    cout << "3. Display Prize Winners for the 5 Cuisines\n";
    cout << "4. Display the Ratio of Monthly Sales to the Money Spent on Publicity\n";
    cout << "5. Add Restaurant to the Company\n";
    cout << "6. Update Restaurant's Information (Sales, Costs, Rating)\n";
    cout << "7. Remove a Restaurant\n";
    cout << "8. Exit\n";
}

