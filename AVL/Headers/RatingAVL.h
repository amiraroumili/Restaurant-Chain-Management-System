// RatingAVL.h
#ifndef RATINGAVL_H
#define RATINGAVL_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <exception>

class RatingNode {
public:
    std::string date;
    std::map<int, std::map<std::string, double>> restaurantData; // Map of restaurantId to cuisine ratings

    RatingNode(std::string d) : date(d) {}
};

class RatingAVL {
private:
    class AVLNode {
    public:
        RatingNode* data;
        AVLNode* left;
        AVLNode* right;
        int height;

        AVLNode(RatingNode* d, AVLNode* lt, AVLNode* rt, int h = 0) : data(d), left(lt), right(rt), height(h) {}
    };

    AVLNode* root;

    int height(AVLNode* t) const;
    int max(int a, int b) const;
    void rotateWithLeftChild(AVLNode*& k2);
    void rotateWithRightChild(AVLNode*& k1);
    void doubleWithLeftChild(AVLNode*& k3);
    void doubleWithRightChild(AVLNode*& k1);
    void balance(AVLNode*& t);
    void insert(AVLNode*& node, RatingNode* data);
    void destroy(AVLNode* node);
    double getCuisineRatingForMonth(const AVLNode* node, const std::string& month, int restaurantId, const std::string& cuisine) const;
    void displayCuisineRatingForMonth(const AVLNode* node, int restaurantId, const std::string& month, const std::string& cuisine) const;

public:
    RatingAVL();
    ~RatingAVL();
    void insert(RatingNode* data);
    void displayCuisineRatingForMonth(int restaurantId, const std::string& month, const std::string& cuisine) const;
    void readFromFile(const std::string& filePath);
};

#endif // RATINGAVL_H
