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

// Other member functions 


//---------------------------------------------------------------Sales-----------------------------------------------------------------------------

// Function to calculate the total monthly sales of Algerian cuisine for a specified restaurant
    double Restaurant::calculateMonthlyAlgerianSalesFromFile( int restaurantId, const string& month) {
    double totalMonthlyAlgerianSales = 0.0;
    ifstream file("../File_csv/Sales.csv");

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << "../File_csv/Sales.csv"<< endl;
        return totalMonthlyAlgerianSales;
    }

    string line;
    std::getline(file, line); // Read and discard the header line

    while (std::getline(file, line)) {
        istringstream ss(line);
        string token;
        std::getline(ss, token, ','); // Read Date
        string currentDate = token.substr(0, 7); // Extract the year-month part

        std::getline(ss, token, ','); // Read Id

        // Use a try-catch block to handle potential stoi exception
        try {
            int currentRestaurantId = stoi(token);

            if (currentRestaurantId == restaurantId && currentDate == month) {
                std::getline(ss, token, ','); // Read Algerian Sales
                totalMonthlyAlgerianSales += stod(token);
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Error converting Id to integer: " << e.what() << endl;
            // Handle the error (e.g., skip the line)
        }
    }

    file.close();
    return totalMonthlyAlgerianSales;
}



    // Function to calculate the total monthly sales of Syrian cuisine for a specified restaurant
    double Restaurant::calculateMonthlySyrianSalesFromFile( int restaurantId, const string& month) {
    double totalMonthlySyrianSales = 0.0;
    ifstream file("../File_csv/Sales.csv");

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << "../File_csv/Sales.csv"<< endl;
        return totalMonthlySyrianSales;
    }

    string line;
    std::getline(file, line); // Read and discard the header line

    while (std::getline(file, line)) {
        istringstream ss(line);
        string token;
        std::getline(ss, token, ','); // Read Date
        string currentDate = token.substr(0, 7); // Extract the year-month part

        std::getline(ss, token, ','); // Read Id

        // Use a try-catch block to handle potential stoi exception
        try {
            int currentRestaurantId = stoi(token);

            if (currentRestaurantId == restaurantId && currentDate == month) {
                // Skip to Syrian Sales column
                for (int i = 0; i < 2; ++i) {
                    std::getline(ss, token, ',');
                }

                // Read Syrian Sales
                totalMonthlySyrianSales += stod(token);
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Error converting Id to integer: " << e.what() << endl;
            // Handle the error (e.g., skip the line)
        }
    }

    file.close();
    return totalMonthlySyrianSales;
}

    // Function to calculate the total monthly sales of Indian cuisine for a specified restaurant
   double Restaurant::calculateMonthlyIndianSalesFromFile( int restaurantId, const string& month) {
    double totalMonthlyIndianSales = 0.0;
    ifstream file("../File_csv/Sales.csv");

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << "../File_csv/Sales.csv" << endl;
        return totalMonthlyIndianSales;
    }

    string line;
    std::getline(file, line); // Read and discard the header line

    while (std::getline(file, line)) {
        istringstream ss(line);
        string token;
        std::getline(ss, token, ','); // Read Date
        string currentDate = token.substr(0, 7); // Extract the year-month part

        std::getline(ss, token, ','); // Read Id

        // Use a try-catch block to handle potential stoi exception
        try {
            int currentRestaurantId = stoi(token);

            if (currentRestaurantId == restaurantId && currentDate == month) {
                // Skip to Indian Sales column
                for (int i = 0; i < 3; ++i) {
                    std::getline(ss, token, ',');
                }
                // Read Indian Sales
                totalMonthlyIndianSales += stod(token);
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Error converting Id to integer: " << e.what() << endl;
            // Handle the error (e.g., skip the line)
        }
    }

    file.close();
    return totalMonthlyIndianSales;
}

    // Function to calculate the total monthly sales of Chinese cuisine for a specified restaurant
   double Restaurant::calculateMonthlyChineseSalesFromFile( int restaurantId, const string& month) {
    double totalMonthlyChineseSales = 0.0;
    ifstream file("../File_csv/Sales.csv");

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << "../File_csv/Sales.csv"<< endl;
        return totalMonthlyChineseSales;
    }

    string line;
    std::getline(file, line); // Read and discard the header line

    while (std::getline(file, line)) {
        istringstream ss(line);
        string token;

        std::getline(ss, token, ','); // Read Date
        string currentDate = token.substr(0, 7); // Extract the year-month part

        std::getline(ss, token, ','); // Read Id

        // Use a try-catch block to handle potential stoi exception
        try {
            int currentRestaurantId = stoi(token);

            if (currentRestaurantId == restaurantId && currentDate == month) {
                // Skip to Chinese Sales column
                for (int i = 0; i < 4; ++i) {
                    std::getline(ss, token, ',');
                }

                // Read Chinese Sales
                totalMonthlyChineseSales += stod(token);
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Error converting Id to integer: " << e.what() << endl;
            // Handle the error (e.g., skip the line)
        }
    }
    file.close();
    return totalMonthlyChineseSales;
}

    // Function to calculate the total monthly sales of European cuisine for a specified restaurant
   double Restaurant::calculateMonthlyEuropeanSalesFromFile( int restaurantId, const string& month) {
    double totalMonthlyEuropeanSales = 0.0;
    ifstream file("../File_csv/Sales.csv");

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << "../File_csv/Sales.csv" << endl;
        return totalMonthlyEuropeanSales;
    }

    string line;
    std::getline(file, line); // Read and discard the header line

    while (std::getline(file, line)) {
        istringstream ss(line);
        string token;
        std::getline(ss, token, ','); // Read Date
        string currentDate = token.substr(0, 7); // Extract the year-month part

        std::getline(ss, token, ','); // Read Id

        // Use a try-catch block to handle potential stoi exception
        try {
            int currentRestaurantId = stoi(token);

            if (currentRestaurantId == restaurantId && currentDate == month) {
                // Skip to European Sales column
                for (int i = 0; i < 5; ++i) {
                    std::getline(ss, token, ',');
                }

                // Read European Sales
                totalMonthlyEuropeanSales += stod(token);
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Error converting Id to integer: " << e.what() << endl;
            // Handle the error (e.g., skip the line)
        }
    }
    file.close();
    return totalMonthlyEuropeanSales;
}
    // Function to calculate the monthly sales of a restaurant

 double Restaurant::RestaurantMonthlySales (int restaurantId, const string& month) {
    return calculateMonthlyAlgerianSalesFromFile( restaurantId,month)
    + calculateMonthlySyrianSalesFromFile(restaurantId, month)
    + calculateMonthlyIndianSalesFromFile(restaurantId,month) 
    + calculateMonthlyChineseSalesFromFile(restaurantId,month)
    + calculateMonthlyEuropeanSalesFromFile(restaurantId,month);  }

 void Restaurant::generateMonthlySalesReport(int restaurantId, const string &month)
 {
    // Calculate monthly sales for each cuisine
    double monthlyAlgerianSales = calculateMonthlyAlgerianSalesFromFile( restaurantId, month);
    double monthlySyrianSales = calculateMonthlySyrianSalesFromFile( restaurantId, month);
    double monthlyIndianSales = calculateMonthlyIndianSalesFromFile( restaurantId, month);
    double monthlyChineseSales = calculateMonthlyChineseSalesFromFile( restaurantId, month);
    double monthlyEuropeanSales = calculateMonthlyEuropeanSalesFromFile( restaurantId, month);

  
 }

//---------------------------------------------------------------Publicity Spending-----------------------------------------------------------------------------


    // Function to calculate the Average Publicity Spending on a given month

void Restaurant::calculateAverageSpending(  int restaurantId, const std::string& month) {
    std::ifstream fileIn("../File_csv/Cost.csv");

    if (!fileIn.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::ofstream fileOut("../File_csv/temp.csv");

    if (!fileOut.is_open()) {
        std::cerr << "Error opening temporary file." << std::endl;
        fileIn.close();
        return;
    }

    std::string line;
    std::getline(fileIn, line); // Read the header line

    // Write the header to the output file
    fileOut << line << std::endl;

    double previousAverage = 0.0;
    int dayCount = 0;

    while (std::getline(fileIn, line)) {
        std::stringstream ss(line);
        std::string date, id_str, total_str, publicitySpending_str, avrgPS_str;

        std::getline(ss, date, ',');
        std::getline(ss, id_str, ',');
        std::getline(ss, total_str, ',');
        std::getline(ss, publicitySpending_str, ',');
        std::getline(ss, avrgPS_str, ',');

        try {
            int currentRestaurantId = std::stoi(id_str);

            // Check if the date contains the specified month and the restaurant ID matches
            if (currentRestaurantId == restaurantId && date.find(month) != std::string::npos) {
                // Calculate the average publicity spending
                double currentPS = std::stod(publicitySpending_str);
                double currentAverage;

                if (dayCount == 0) {
                    // For the first day, use the current day's publicity spending as the initial average
                    currentAverage = currentPS;
                } else {
                    // For subsequent days, calculate the average based on the previous average
                    currentAverage = (previousAverage + currentPS) / 2.0;
                }

                // Update the line with the new average
                ss.seekg(0); // Move back to the beginning of the string stream
                fileOut << date << "," << id_str << "," << total_str << ","
                         << publicitySpending_str << "," << std::fixed << std::setprecision(2) << currentAverage << std::endl;

                // Update the previous average for the next iteration
                previousAverage = currentAverage;

                dayCount++;
            }
        } catch (const std::invalid_argument& e) {
          std::cerr << "Error converting Id to integer: " << e.what() << " for string: " << id_str << endl;
           // Handle the error (e.g., skip the line)
}

    }
    
    fileIn.close();
    fileOut.close();

    // Rename the temporary file to the original filename
    if (rename("../File_csv/temp.csv", "../File_csv/Cost.csv") != 0) {
        std::cerr << "Error renaming file." << std::endl;
    }
}


    //   Function to calculate the total Publicity Spending on a given month


double Restaurant::calculateAdvSpending(int restaurantId,const string& month) {
    double publicityySpending = 0.0;
    ifstream file("../File_csv/Cost.csv");
   

    if (!file.is_open()) {
        cerr << "Error opening file:" << "../File_csv/Cost.csv"<< endl;
        return 0.0;  // Return 0 if the file cannot be opened  
    }
    string line;
    std::getline(file, line);  // Read the header line

 // Iterate through each line of the file
    while (std::getline(file, line)) {
        stringstream ss(line);
        string date, id_str, total_str, publicitySpending_str, avrgPS_str;

 // Read the values from the CSV line
        std::getline(ss, date, ',');
        std::getline(ss, id_str, ',');
        std::getline(ss, total_str, ',');
        std::getline(ss, publicitySpending_str, ',');
        std::getline(ss, avrgPS_str, ',');

  // Convert string to int and double
        try {
            int id = stoi(id_str);
            double publicitySpending = stod(publicitySpending_str);

            // Check if the restaurant ID and month match
            if (id == restaurantId && date.find(month) != string::npos) {
                publicityySpending += publicitySpending;
            }
        } catch (const std::invalid_argument& e) {
            cerr << "Error converting string to number: " << e.what() << endl;
        }
    }

  // Close the file
  file.close();

    return publicityySpending;
    }


    //   Function to calculate Ratio on a given month

    double Restaurant::calculateRatio(int restaurantId, const string& month ) {
    double monthlySales = this->RestaurantMonthlySales (restaurantId, month);
    double advSpending = this->calculateAdvSpending(restaurantId , month);
     std::cout << "The Restaurant " << getRestaurantName() << "'s ROI: "
              << std::fixed << std::setprecision(2) << (monthlySales / advSpending) << std::endl;
}



//---------------------------------------------------------------Files Handling and Other-----------------------------------------------------------------------------


// Find and return a specific Cuisine by name
   const Cuisine* Restaurant::findCuisineByName(const std::string& cuisineName) const{
        for (const Cuisine& cuisine : Cuisines) {
            if (cuisine.getName() == cuisineName) {
                return &cuisine;
            }
        }
        return nullptr; // Cuisine not found
    }

// operators 

std::ostream& operator<<(ostream& os, const Restaurant& restaurant) {
    os << "ID: " << restaurant.getId() << ", Name: " << restaurant.getRestaurantName() << ", Employees Number: " << restaurant.getEmployeeNumber()
       << ", Type: " << restaurant.getType() << ", Location: " << restaurant.getType();
    return os;
}

std::istream& operator>>(istream& is, Restaurant& restaurant) {
    is >> restaurant.getId() >> restaurant.getRestaurantName() >> restaurant.getEmployeeNumber()>> restaurant.getType() >> restaurant.getPlace();
    return is;
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
     

 

