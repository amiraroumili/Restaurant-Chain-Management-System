// RatingBST.h
#ifndef RATINGBST_H
#define RATINGBST_H

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

class RatingBST {
private:
    class Node {
    public:
        RatingNode* data;
        Node* left;
        Node* right;

        Node(RatingNode* d) : data(d), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, RatingNode* data);

    void destroy(Node* node);

    double getCuisineRatingForMonth(const Node* node, const std::string& month, int restaurantId, const std::string& cuisine) const;

    void displayCuisineRatingForMonth(const Node* node, int restaurantId, const std::string& month, const std::string& cuisine) const;

public:
    RatingBST();

    ~RatingBST();

    void insert(RatingNode* data);

    void displayCuisineRatingForMonth(int restaurantId, const std::string& month, const std::string& cuisine) const;
};

std::vector<RatingNode> readRatingsFromFile(const std::string& filePath);

#endif // RATINGBST_H