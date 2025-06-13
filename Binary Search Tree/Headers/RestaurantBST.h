#ifndef RESTAURANT_BST_H
#define RESTAURANT_BST_H

#include "RestaurantClass.h"
#include <iostream>
#include <string>
#include <sstream>

class RestaurantBST {
private:
    struct BinaryNode {
        Restaurant element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Restaurant &theElement, BinaryNode *lt, BinaryNode *rt)
            : element(theElement), left(lt), right(rt) {}
    };     

    BinaryNode *root;

    void insert(const Restaurant &restaurant, BinaryNode *&t);
    bool contains(const Restaurant &restaurant, BinaryNode *t) const;
    void makeEmpty(BinaryNode *&t);
    void printTree(BinaryNode *t, std::ostream &out) const;
    Restaurant *findRestaurantById(int id, BinaryNode *t) const;
    void readFromFile(const std::string &filePath);

public:
    RestaurantBST();
    ~RestaurantBST();

    void insert(const Restaurant &restaurant);
    bool contains(const Restaurant &restaurant) const;
    void makeEmpty();
    void printTree(std::ostream &out) const;
    Restaurant *findRestaurantById(int id) const;
    void deleteRestaurantById(int idToDelete) ;
};

#endif // RESTAURANT_BST_H
