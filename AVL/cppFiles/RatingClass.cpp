#include "RatingClass.h"

// Constructor implementation
Rating::Rating(double rate, const std::string& date) : rate(rate), date(date) {}

// Getter for rate implementation
double Rating::getRate() const {
    return rate;
}

// Getter for date implementation
std::string Rating::getDate() const {
    return date;
}

// Setter for rate implementation
void Rating::setRate(double newRate) {
    rate = newRate;
}

// Setter for date implementation
void Rating::setDate(const std::string& newDate) {
    date = newDate;
}
