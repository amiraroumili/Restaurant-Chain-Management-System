#include "SalesAVL.h"

// SalesNode implementation
SalesNode::SalesNode(std::string d) : date(d) {}

// SalesAVL::AVLNode implementation
SalesAVL::AVLNode::AVLNode(SalesNode* d, AVLNode* lt, AVLNode* rt, int h) : data(d), left(lt), right(rt), height(h) {}

// SalesAVL implementation
SalesAVL::SalesAVL() : root(nullptr) {}

SalesAVL::~SalesAVL() {
    destroy(root);
}

int SalesAVL::height(SalesAVL::AVLNode* t) const {
    return t == nullptr ? -1 : t->height;
}

int SalesAVL::max(int a, int b) const {
    return (a > b) ? a : b;
}

void SalesAVL::rotateWithLeftChild(SalesAVL::AVLNode*& k2) {
    AVLNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

void SalesAVL::rotateWithRightChild(SalesAVL::AVLNode*& k1) {
    AVLNode* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    k1 = k2;
}

void SalesAVL::doubleWithLeftChild(SalesAVL::AVLNode*& k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void SalesAVL::doubleWithRightChild(SalesAVL::AVLNode*& k1) {
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

void SalesAVL::balance(SalesAVL::AVLNode*& t) {
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

void SalesAVL::insert(SalesAVL::AVLNode*& node, SalesNode* data) {
    if (node == nullptr)
        node = new AVLNode(data, nullptr, nullptr);
    else if (data->date < node->data->date)
        insert(node->left, data);
    else if (data->date > node->data->date)
        insert(node->right, data);

    balance(node);
}

void SalesAVL::destroy(SalesAVL::AVLNode* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

double SalesAVL::getTotalSalesForMonth(const SalesAVL::AVLNode* node, const std::string& month, int restaurantId) const {
    while (node != nullptr) {
        if (month < node->data->date) {
            node = node->left;
        } else if (month > node->data->date) {
            node = node->right;
        } else {
            auto it = node->data->restaurantData.find(restaurantId);
            if (it != node->data->restaurantData.end()) {
                double totalSales = 0.0;
                for (const auto& entry : it->second) {
                    totalSales += entry.second;
                }
                return totalSales;
            }
            return 0.0; // No match
        }
    }
    return 0.0; // No match
}

double SalesAVL::getCuisineTotalSalesForMonth(const SalesAVL::AVLNode* node, const std::string& month, int restaurantId, const std::string& cuisine) const {
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

void SalesAVL::displayTotalSales(const SalesAVL::AVLNode* node, int restaurantId, const std::string& month) const {
    double totalSales = getTotalSalesForMonth(node, month, restaurantId);
    std::cout << "Total Sales for Restaurant " << restaurantId << " in " << month << ": " << totalSales << std::endl;
}

void SalesAVL::displayCuisineTotalSales(const SalesAVL::AVLNode* node, int restaurantId, const std::string& month, const std::string& cuisine) const {
    double cuisineTotalSales = getCuisineTotalSalesForMonth(node, month, restaurantId, cuisine);
    std::cout << "Total Sales for Restaurant " << restaurantId << " in " << month << " for Cuisine " << cuisine << ": " << cuisineTotalSales << std::endl;
}

void SalesAVL::insert(SalesNode* data) {
    insert(root, data);
}

void SalesAVL::displayTotalSales(int restaurantId, const std::string& month) const {
    displayTotalSales(root, restaurantId, month);
}

void SalesAVL::displayCuisineTotalSales(int restaurantId, const std::string& month, const std::string& cuisine) const {
    displayCuisineTotalSales(root, restaurantId, month, cuisine);
}

void SalesAVL::generateMonthlySalesReport(int restaurantId, const std::string& month, const std::string& cuisine) const {
    std::cout << "Monthly Sales Report for Restaurant " << restaurantId << " in " << month << " for Cuisine " << cuisine << ":" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    displayTotalSales(restaurantId, month);
    displayCuisineTotalSales(restaurantId, month, cuisine);
    std::cout << "---------------------------------------------" << std::endl;
}

void SalesAVL::readFromFile(const std::string& filePath) {
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
        std::string date, id, algerianSales, syrianSales, indianSales, chineseSales, europeanSales;

        if (!(iss >> date >> id >> algerianSales >> syrianSales >> indianSales >> chineseSales >> europeanSales)) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }

        int restaurantId = std::stoi(id);
        double algerian = std::stod(algerianSales);
        double syrian = std::stod(syrianSales);
        double indian = std::stod(indianSales);
        double chinese = std::stod(chineseSales);
        double european = std::stod(europeanSales);

        SalesNode* salesNode = new SalesNode(date);
        salesNode->restaurantData[restaurantId]["Algerian"] = algerian;
        salesNode->restaurantData[restaurantId]["Syrian"] = syrian;
        salesNode->restaurantData[restaurantId]["Indian"] = indian;
        salesNode->restaurantData[restaurantId]["Chinese"] = chinese;
        salesNode->restaurantData[restaurantId]["European"] = european;

        insert(salesNode);
    }

    file.close();
}
