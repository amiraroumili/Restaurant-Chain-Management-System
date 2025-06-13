#ifndef RESTAURANT_AVL_H
#define RESTAURANT_AVL_H

#include "RestaurantClass.h"
#include <iostream>
#include <string>
#include <sstream>

class RestaurantAVL {
private:
    struct AVLNode {
        Restaurant element;
        AVLNode *left;
        AVLNode *right;
        int height;

        AVLNode(const Restaurant &theElement, AVLNode *lt, AVLNode *rt, int h = 0)
            : element(theElement), left(lt), right(rt), height(h) {}
    };

    AVLNode *root;

    int height(AVLNode *t) const;
    int max(int a, int b) const;
    void rotateWithLeftChild(AVLNode *&k2);
    void rotateWithRightChild(AVLNode *&k1);
    void doubleWithLeftChild(AVLNode *&k3);
    void doubleWithRightChild(AVLNode *&k1);
    void balance(AVLNode *&t);
    void insert(const Restaurant &restaurant, AVLNode *&t);
    bool contains(const Restaurant &restaurant, AVLNode *t) const;
    void makeEmpty(AVLNode *&t);
    void printTree(AVLNode *t, std::ostream &out) const;
    Restaurant *findRestaurantById(int id, AVLNode *t) const;

public:
    RestaurantAVL();
    ~RestaurantAVL();

    void insert(const Restaurant &restaurant);
    bool contains(const Restaurant &restaurant) const;
    void makeEmpty();
    void printTree(std::ostream &out) const;
    Restaurant *findRestaurantById(int id) const;
    void readFromFile(const std::string &filePath);
};

#endif // RESTAURANT_AVL_H
