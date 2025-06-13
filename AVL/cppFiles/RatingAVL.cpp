// RatingAVL.cpp
#include "RatingAVL.h"

RatingAVL::RatingAVL() : root(nullptr) {}

RatingAVL::~RatingAVL() {
    destroy(root);
}

int RatingAVL::height(RatingAVL::AVLNode* t) const {
    return t == nullptr ? -1 : t->height;
}

int RatingAVL::max(int a, int b) const {
    return (a > b) ? a : b;
}

void RatingAVL::rotateWithLeftChild(RatingAVL::AVLNode*& k2) {
    AVLNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

void RatingAVL::rotateWithRightChild(RatingAVL::AVLNode*& k1) {
    AVLNode* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    k1 = k2;
}

void RatingAVL::doubleWithLeftChild(RatingAVL::AVLNode*& k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void RatingAVL::doubleWithRightChild(RatingAVL::AVLNode*& k1) {
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

void RatingAVL::balance(RatingAVL::AVLNode*& t) {
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

void RatingAVL::insert(RatingAVL::AVLNode*& node, RatingNode* data) {
    if (node == nullptr)
        node = new AVLNode(data, nullptr, nullptr);
    else if (data->date < node->data->date)
        insert(node->left, data);
    else if (data->date > node->data->date)
        insert(node->right, data);

    balance(node);
}

void RatingAVL::destroy(RatingAVL::AVLNode* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

double RatingAVL::getCuisineRatingForMonth(const RatingAVL::AVLNode* node, const std::string& month, int restaurantId, const std::string& cuisine) const {
    while (node != nullptr) {
        if (month < node->data->date) {
            node = node->left;
        } else if (month > node->data->date) {
            node = node->right;
        } else {
            auto it = node->data->restaurantData.find(restaurantId);
            if (it != node->data->restaurantData.end()) {
                auto cuisineIt = it->second.find(cuisine);
                if (cuisineIt != it->second.end()) {
                    return cuisineIt->second;
                }
            }
            return 0.0; // No match
        }
    }
    return 0.0; // No match
}

void RatingAVL::displayCuisineRatingForMonth(const RatingAVL::AVLNode* node, int restaurantId, const std::string& month, const std::string& cuisine) const {
    double cuisineRating = getCuisineRatingForMonth(node, month, restaurantId, cuisine);
    std::cout << "Rating for Restaurant " << restaurantId << " in " << month << " for Cuisine " << cuisine << ": " << cuisineRating << std::endl;
}

void RatingAVL::insert(RatingNode* data) {
    insert(root, data);
}

void RatingAVL::displayCuisineRatingForMonth(int restaurantId, const std::string& month, const std::string& cuisine) const {
    displayCuisineRatingForMonth(root, restaurantId, month, cuisine);
}

void RatingAVL::readFromFile(const std::string& filePath) {
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
        std::istringstream iss(line);
        std::string date, id, algerianRating, syrianRating, indianRating, chineseRating, europeanRating;

        if (!(iss >> date >> id >> algerianRating >> syrianRating >> indianRating >> chineseRating >> europeanRating)) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }

        int restaurantId = std::stoi(id);
        double algerian = std::stod(algerianRating);
        double syrian = std::stod(syrianRating);
        double indian = std::stod(indianRating);
        double chinese = std::stod(chineseRating);
        double european = std::stod(europeanRating);

        RatingNode* ratingNode = new RatingNode(date);
        ratingNode->restaurantData[restaurantId]["Algerian"] = algerian;
        ratingNode->restaurantData[restaurantId]["Syrian"] = syrian;
        ratingNode->restaurantData[restaurantId]["Indian"] = indian;
        ratingNode->restaurantData[restaurantId]["Chinese"] = chinese;
        ratingNode->restaurantData[restaurantId]["European"] = european;

        insert(ratingNode);
    }

    file.close();
}
