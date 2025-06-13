#include "PlaceClass.h"

 // Constructors
        Place::Place() : District(""), City(""), Wilaya(""), Country("") {}

        Place::Place(const string& _district, const string& _city, const string& _wilaya, const string& _country)
            : District(_district), City(_city), Wilaya(_wilaya), Country(_country) {}

        // Destructor
        Place::~Place() {

        }

        // Getters
        string Place::getDistrict() const {
            return District;
        }

        string Place::getCity() const {
            return City;
        }

        string Place::getWilaya() const {
            return Wilaya;
        }

        string Place::getCountry() const {
            return Country;
        }

        // Setters
        void Place::setDistrict(const string& _district) {
            District = _district;
        }

        void Place::setCity(const string& _city) {
            City = _city;
        }

        void Place::setWilaya(const string& _wilaya) {
            Wilaya = _wilaya;
        }

        void Place::setCountry(const string& _country) {
            Country = _country;
        }

          // Stream insertion operator for Place class
     ostream& operator<<(ostream& os, const Place& place) {
        os << place.getCity() << " "
           << place.getWilaya() << " "
           << place.getCountry() << " "
           << place.getDistrict();
        return os;
    }

    // Stream extraction operator for Place class
     istream& operator>>(istream& is, Place& place) {
    is >> place.City >> place.Wilaya >> place.Country >> place.District;
    return is;
}
