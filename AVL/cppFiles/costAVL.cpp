#include "CostAVL.h"

CostAVL::~CostAVL() {
    destroy(root);
}

int CostAVL::height(CostAVL::AVLNode* t) const {
    return t == nullptr ? -1 : t->height;
}

int CostAVL::max(int a, int b) const {
    return (a > b) ? a : b;
}

void CostAVL::rotateWithLeftChild(CostAVL::AVLNode*& k2) {
    AVLNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

void CostAVL::rotateWithRightChild(CostAVL::AVLNode*& k1) {
    AVLNode* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    k1 = k2;
}

void CostAVL::doubleWithLeftChild(CostAVL::AVLNode*& k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void CostAVL::doubleWithRightChild(CostAVL::AVLNode*& k1) {
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

void CostAVL::balance(CostAVL::AVLNode*& t) {
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

void CostAVL::insert(CostAVL::AVLNode*& node, CostNode* data) {
    if (node == nullptr)
        node = new AVLNode(data, nullptr, nullptr);
    else if (data->date < node->data->date) {
        insert(node->left, data);
    } else if (data->date > node->data->date) {
        insert(node->right, data);
    }

    balance(node);
}

void CostAVL::insert(CostNode* data) {
    insert(root, data);
}

double CostAVL::getTotalPublicitySpendingForMonth(const CostAVL::AVLNode* node, const std::string& month, int restaurantId) const {
    if (node == nullptr)
        return 0.0;

    if (month < node->data->date) {
        return getTotalPublicitySpendingForMonth(node->left, month, restaurantId);
    } else if (month > node->data->date) {
        return getTotalPublicitySpendingForMonth(node->right, month, restaurantId);
    } else {
        auto it = node->data->restaurantData.find(restaurantId);
        if (it != node->data->restaurantData.end()) {
            return it->second.second; // Return publicity spending for the given restaurant and month
        } else {
            return 0.0; // Restaurant not found for the given month
        }
    }
}

double CostAVL::getTotalPublicitySpendingForMonth(const std::string& month, int restaurantId) const {
    return getTotalPublicitySpendingForMonth(root, month, restaurantId);
}

void CostAVL::destroy(CostAVL::AVLNode* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node->data;
        delete node;
    }
}

void CostAVL::readFromFile(const std::string& filePath) {
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
        std::string date, id, totalCost, publicitySpending;

        if (!(iss >> date >> id >> totalCost >> publicitySpending)) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }

        try {
            int restaurantId = std::stoi(id);
            double cost = std::stod(totalCost);
            double publicity = std::stod(publicitySpending);

            // Create CostNode object
            CostNode* costNode = new CostNode(date);
            costNode->restaurantData[restaurantId] = std::make_pair(cost, publicity);

            // Insert into AVL tree
            insert(costNode);

        } catch (const std::invalid_argument& e) {
            std::cerr << "Error converting string to number: " << e.what() << std::endl;
            // Handle the error (e.g., skip the line)
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Value out of range for conversion to integer." << std::endl;
            // Handle the error (e.g., skip the line)
        }
    }

    file.close();
}
