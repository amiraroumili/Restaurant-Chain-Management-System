#include <iostream>
#include <map>
#include <vector>
#include <string>

// Node representing a city in a Wilaya
struct CityNode {
    std::string cityName;
    std::map<std::string, std::pair<int, std::string>> districts; // district name -> <restaurant ID, district name>

    CityNode(const std::string& name) : cityName(name) {}
};

// Node representing a Wilaya in the binary search tree
struct WilayaNode {
    std::string wilayaName;
    std::map<std::string, CityNode> cities;

    WilayaNode(const std::string& name) : wilayaName(name) {}
};

// Binary Search Tree for Wilayas
class BST_Wilaya {
private:
    struct Node {
        WilayaNode data;
        Node* left;
        Node* right;

        Node(const std::string& name) : data(name), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    BST_Wilaya() : root(nullptr) {}

    // Function to insert a Wilaya into the BST
    void insert(const std::string& wilayaName) {
        root = insertRecursive(root, wilayaName);
    }

    // Recursive function to insert a Wilaya
    Node* insertRecursive(Node* node, const std::string& wilayaName) {
        if (node == nullptr) {
            return new Node(wilayaName);
        }

        if (wilayaName < node->data.wilayaName) {
            node->left = insertRecursive(node->left, wilayaName);
        } else if (wilayaName > node->data.wilayaName) {
            node->right = insertRecursive(node->right, wilayaName);
        }

        return node;
    }
};

// Country class containing a binary search tree of Wilayas
class Country {
private:
    std::string countryName;
    BST_Wilaya bstWilaya;

public:
    Country(const std::string& name) : countryName(name) {}

    // Function to insert a Wilaya into the BST
    void insertWilaya(const std::string& wilayaName) {
        bstWilaya.insert(wilayaName);
    }
};

int main() {
    // Example usage
    Country myCountry("MyCountry");
    myCountry.insertWilaya("Wilaya1");
    myCountry.insertWilaya("Wilaya2");

    return 0;
}