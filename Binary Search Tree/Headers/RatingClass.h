#ifndef RATING_H
#define RATING_H

#include <string>

class Rating {
public:
    // Constructor
    Rating(double rate, const std::string& date);

    // Getter for rate
    double getRate() const;

    // Getter for date
    std::string getDate( ) const ;

    // Setter for rate
    void setRate(double newRate);

    // Setter for date
    void setDate(const std::string& newDate);
    friend void addRatingtoFile ()  ; 

private:
    double rate;
    std::string date;  // format YYYY-MM-DD
};

#endif // RATING_H

