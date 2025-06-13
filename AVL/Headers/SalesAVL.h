#ifndef SALESAVL_H
#define SALESAVL_H

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

class SalesAVL {
private:
    class AVLNode {
    public:
        SalesNode* data;
        AVLNode* left;
        AVLNode* right;
        int height;

        AVLNode(SalesNode* d, AVLNode* lt, AVLNode* rt, int h = 0);
    };

    AVLNode* root;

    int height(AVLNode* t) const;
    int max(int a, int b) const;
    void rotateWithLeftChild(AVLNode*& k2);
    void rotateWithRightChild(AVLNode*& k1);
    void doubleWithLeftChild(AVLNode*& k3);
    void doubleWithRightChild(AVLNode*& k1);
    void balance(AVLNode*& t);
    void insert(AVLNode*& node, SalesNode* data);
    double getTotalSalesForMonth(const AVLNode* node, const std::string& month, int restaurantId) const;
    double getCuisineTotalSalesForMonth(const AVLNode* node, const std::string& month, int restaurantId, const std::string& cuisine) const;
    void displayTotalSales(const AVLNode* node, int restaurantId, const std::string& month) const;
    void displayCuisineTotalSales(const AVLNode* node, int restaurantId, const std::string& month, const std::string& cuisine) const;
    void destroy(AVLNode* node);
    void readFromFile(const std::string& filePath);

public:
    SalesAVL();
    ~SalesAVL();
    void insert(SalesNode* data);
    void displayTotalSales(int restaurantId, const std::string& month) const;
    void displayCuisineTotalSales(int restaurantId, const std::string& month, const std::string& cuisine) const;
    void generateMonthlySalesReport(int restaurantId, const std::string& month, const std::string& cuisine) const;
};

#endif // SALESAVL_H
