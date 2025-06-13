#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>

class AvrgPublicityBST {
private:
    class Node {
    public:
        std::string date;
        std::map<int, double> restaurantData; // Map from restaurantId to average publicity spending
        Node* left;
        Node* right;
        Node(const std::string& d) : date(d), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, int restaurantId, double avgPublicity) ;

    void destroy(Node* node) ;

    double getAveragePublicityForMonth(const Node* node, const std::string& month, int restaurantId) const ;

    void calculateAveragePublicity(Node*& node, int restaurantId, const std::string& month) ;

public:

    AvrgPublicityBST() : root(nullptr) {}

    ~AvrgPublicityBST() ;

    void insert(int restaurantId, double avgPublicity) ;

    double getAveragePublicityForMonth(const std::string& month, int restaurantId) const ;

    void calculateAveragePublicity(int restaurantId, const std::string& month) ;

    void readFromFile(const std::string& filePath) ;
};


