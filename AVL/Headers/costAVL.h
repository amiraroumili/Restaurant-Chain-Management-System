#ifndef COST_AVL_H
#define COST_AVL_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <stdexcept>

class CostNode {
public:
    std::string date;
    std::map<int, std::pair<double, double>> restaurantData; // Pair of totalCost and publicity spending

    CostNode(std::string d) : date(d) {}
};

class CostAVL {
private:
    class AVLNode {
    public:
        CostNode* data;
        AVLNode* left;
        AVLNode* right;
        int height;

        AVLNode(CostNode* d, AVLNode* lt, AVLNode* rt, int h = 0)
            : data(d), left(lt), right(rt), height(h) {}
    };

    AVLNode* root;

    int height(AVLNode* t) const;
    int max(int a, int b) const;
    void rotateWithLeftChild(AVLNode*& k2);
    void rotateWithRightChild(AVLNode*& k1);
    void doubleWithLeftChild(AVLNode*& k3);
    void doubleWithRightChild(AVLNode*& k1);
    void balance(AVLNode*& t);
    void insert(AVLNode*& node, CostNode* data);
    void destroy(AVLNode* node);
    double getTotalPublicitySpendingForMonth(const AVLNode* node, const std::string& month, int restaurantId) const;
    void readFromFile(const std::string& filePath);

public:
    CostAVL() : root(nullptr) {}

    ~CostAVL();

    void insert(CostNode* data);
    double getTotalPublicitySpendingForMonth(const std::string& month, int restaurantId) const;
    void readFromFile(const std::string& filePath);
};

#endif // COST_AVL_H
