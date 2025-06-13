#ifndef SALESBST_H
#define SALESBST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <exception>

class SalesNode {
public:
    std::string date;
    std::map<int, std::map<std::string, double>> restaurantData; // Map of restaurantId to cuisine sales

    SalesNode(std::string d);
};

class SalesBST {
private:
    class Node {
    public:
        SalesNode* data;
        Node* left;
        Node* right;

        Node(SalesNode* d);
    };

    Node* root;

    void insert(Node*& node, SalesNode* data);
    void destroy(Node* node);
    double getTotalSalesForMonth(const Node* node, const std::string& month, int restaurantId) const;
    double getCuisineTotalSalesForMonth(const Node* node, const std::string& month, int restaurantId, const std::string& cuisine) const;
    void displayTotalSales(const Node* node, int restaurantId, const std::string& month) const;
    void displayCuisineTotalSales(const Node* node, int restaurantId, const std::string& month, const std::string& cuisine) const;

public:
    SalesBST();
    ~SalesBST();
    void insert(SalesNode* data);
    void displayTotalSales(int restaurantId, const std::string& month) const;
    void displayCuisineTotalSales(int restaurantId, const std::string& month, const std::string& cuisine) const;
    void generateMonthlySalesReport(const Node* node, int restaurantId, const std::string& month, const std::string& cuisine) const;
    std::vector<SalesNode> readSalesFromFile(const std::string& filePath);
};



#endif // SALESBST_H