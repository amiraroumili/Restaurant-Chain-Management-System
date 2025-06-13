#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <exception>
class CostNode {
public:
    std::string date;
    std::map<int, std::pair<double, double>> restaurantData; // Pair of totalCost and publicity spending

    CostNode(std::string d) : date(d) {}
};

class CostBST {
private:
    class Node {
    public:
        CostNode* data;
        Node* left;
        Node* right;

        Node(CostNode* d) : data(d), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, CostNode* data);

    void destroy(Node* node) ;

    double getTotalPublicitySpendingForMonth(const Node* node, const std::string& month, int restaurantId) const ;

public:
    CostBST() : root(nullptr) {}

    ~CostBST();

    void insert(CostNode* data);
    double getTotalPublicitySpendingForMonth(const std::string& month, int restaurantId) const ;

std::vector<CostNode> readFromFile(const std::string& filePath) ;

};