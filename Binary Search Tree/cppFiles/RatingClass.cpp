#include "RatingClass.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std ; 

// Constructor implementation
Rating::Rating(double rate, const string& date) : rate(rate), date(date) {}

// Getter for rate implementation
double Rating::getRate() const {
    return rate;
}

// Getter for date implementation
string Rating::getDate() const {
    return date;
}

// Setter for rate implementation
void Rating::setRate(double newRate) {
    rate = newRate;
}

// Setter for date implementation
void Rating::setDate(const string& newDate) {
    date = newDate;
}

void addRatingtoFile() {
    ofstream file("../File_csv/Rating.csv", ios::app);  // Open the file in append mode

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << "../File_csv/Rating.csv" << endl;
        return;
    }

    string Date;
    int id;
    double AlgerianRating, SyrianRating, IndianRating, ChineseRating, EuropeanRating;

    cout << "Enter the date in the form yyyy/mm: ";
    cin >> Date;
    cout << "Enter the ID of the restaurant: ";
    cin >> id;
    cout << "Enter the Algerian rating: ";
    cin >> AlgerianRating;
    cout << "Enter the Syrian rating: ";
    cin >> SyrianRating;
    cout << "Enter the Indian rating: ";
    cin >> IndianRating;
    cout << "Enter the Chinese rating: ";
    cin >> ChineseRating;
    cout << "Enter the European rating: ";
    cin >> EuropeanRating;

    

    file << Date << ", " << id << ", " << AlgerianRating << ", " << SyrianRating << ", "
         << IndianRating << ", " << ChineseRating << ", " << EuropeanRating << endl;

    file.close();

    cout << "Rating added to file" << endl;
}

