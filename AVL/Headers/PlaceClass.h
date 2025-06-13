#ifndef PLACECLASS_H
#define PLACECLASS_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Place {
    private :
         string District;
         string City;
         string Wilaya;
         string Country;
        
    public:
         // Constructors
        Place() : District(""), City(""), Wilaya(""), Country("") {}

        Place(const string& _district, const string& _city, const string& _wilaya, const string& _country)
            : District(_district), City(_city), Wilaya(_wilaya), Country(_country) {}

        // Destructor
        ~Place() {

        }

        // Getters
        string getDistrict() const {
            return District;
        }

        string getCity() const {
            return City;
        }

        string getWilaya() const {
            return Wilaya;
        }

        string getCountry() const {
            return Country;
        }

        // Setters
        void setDistrict(const string& _district) {
            District = _district;
        }

        void setCity(const string& _city) {
            City = _city;
        }

        void setWilaya(const string& _wilaya) {
            Wilaya = _wilaya;
        }

        void setCountry(const string& _country) {
            Country = _country;
        }

         // Stream insertion operator for Place class
    friend ostream& operator<<(ostream& os, const Place& place);

    // Stream extraction operator for Place class
    friend istream& operator>>(istream& is, Place& place);
   
};

#endif