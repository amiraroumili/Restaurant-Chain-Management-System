#ifndef SALES_H
#define SALES_H

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <algorithm>
 #include <string>


using namespace std;


class Sales {
private:
    string date;
    double sales;

public:
    // Constructor
    Sales(const std::string& _date, double _sales)
        : date(_date),
          sales(_sales) {
        // Additional initialization if needed
    }

    Sales();
    // Destructor
    ~Sales() {
        // Cleanup code if needed
    }

    // Getters
    std::string getDate() const {
        return date;
    }

    double getSales() const {
        return sales;
    }

    // Setters
    void setDate(const std::string& _date) {
        date = _date;
    }

    void setSales(double _sales) {
        sales = _sales;
    }

  
     void addSalesDataToFile() ;
};

#endif
