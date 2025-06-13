#include "RestaurantAVL.h"

RestaurantAVL::RestaurantAVL() : root(nullptr) {}

RestaurantAVL::~RestaurantAVL() {
    makeEmpty();
}

int RestaurantAVL::height(AVLNode *t) const {
    return t == nullptr ? -1 : t->height;
}

int RestaurantAVL::max(int a, int b) const {
    return (a > b) ? a : b;
}

void RestaurantAVL::rotateWithLeftChild(AVLNode *&k2) {
    AVLNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

void RestaurantAVL::rotateWithRightChild(AVLNode *&k1) {
    AVLNode *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    k1 = k2;
}

void RestaurantAVL::doubleWithLeftChild(AVLNode *&k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void RestaurantAVL::doubleWithRightChild(AVLNode *&k1) {
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

void RestaurantAVL::balance(AVLNode *&t) {
    if (t == nullptr)
        return;

    if (height(t->left) - height(t->right) > 1) {
        if (height(t->left->left) >= height(t->left->right))
            rotateWithLeftChild(t);
        else
            doubleWithLeftChild(t);
    } else if (height(t->right) - height(t->left) > 1) {
        if (height(t->right->right) >= height(t->right->left))
            rotateWithRightChild(t);
        else
            doubleWithRightChild(t);
    }

    t->height = max(height(t->left), height(t->right)) + 1;
}

void RestaurantAVL::insert(const Restaurant &restaurant, AVLNode *&t) {
    if (t == nullptr)
        t = new AVLNode(restaurant, nullptr, nullptr);
    else if (restaurant.getId() < t->element.getId()) {
        insert(restaurant, t->left);
    } else if (restaurant.getId() > t->element.getId()) {
        insert(restaurant, t->right);
    }

    balance(t);
}

void RestaurantAVL::insert(const Restaurant &restaurant) {
    insert(restaurant, root);
}

bool RestaurantAVL::contains(const Restaurant &restaurant, AVLNode *t) const {
    while (t != nullptr) {
        if (restaurant.getId() < t->element.getId()) {
            t = t->left;
        } else if (restaurant.getId() > t->element.getId()) {
            t = t->right;
        } else {
            return true; // Match
        }
    }
    return false; // No match
}

bool RestaurantAVL::contains(const Restaurant &restaurant) const {
    return contains(restaurant, root);
}

void RestaurantAVL::makeEmpty(AVLNode *&t) {
    if (t != nullptr) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

void RestaurantAVL::makeEmpty() {
    makeEmpty(root);
}

void RestaurantAVL::printTree(AVLNode *t, std::ostream &out) const {
    if (t != nullptr) {
        printTree(t->left, out);
        out << t->element.getId() << " ";
        printTree(t->right, out);
    }
}

void RestaurantAVL::printTree(std::ostream &out) const {
    printTree(root, out);
}

Restaurant *RestaurantAVL::findRestaurantById(int id, AVLNode *t) const {
    while (t != nullptr) {
        if (id < t->element.getId()) {
            t = t->left;
        } else if (id > t->element.getId()) {
            t = t->right;
        } else {
            return &(t->element); // Match
        }
    }
    return nullptr; // No match
}

Restaurant *RestaurantAVL::findRestaurantById(int id) const {
    return findRestaurantById(id, root);
}

void RestaurantAVL::readFromFile(const std::string &filePath) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }

    // Skip the header line
    std::string header;
    std::getline(file, header);

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss (line);
        std::string id_str, name, employeeNumber_str, type, country, wilaya, city, district;

        if (!(iss >> id_str >> name >> employeeNumber_str >> type >> country >> wilaya >> city >> district)) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }

        try {
            int id = std::stoi(id_str);
            int employeeNumber = std::stoi(employeeNumber_str);

            // Create Place object
            Place place(wilaya, city, district, country);

            // Create Restaurant object
            Restaurant restaurant(id, name, type, employeeNumber, place);

            // Insert into AVL tree
            insert(restaurant);

        } catch (const std::invalid_argument &e) {
            std::cerr << "Error converting string to number: " << e.what() << std::endl;
            // Handle the error (e.g., skip the line)
        } catch (const std::out_of_range &e) {
            std::cerr << "Error: Value out of range for conversion to integer." << std::endl;
            // Handle the error (e.g., skip the line)
        }
    }

    file.close();
}