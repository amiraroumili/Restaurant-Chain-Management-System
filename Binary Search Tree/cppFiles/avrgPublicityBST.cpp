#include "AvrgPublicityBST.h"

void AvrgPublicityBST::insert(Node*& node, int restaurantId, double avgPublicity) {
    if (node == nullptr) {
        node = new Node("");
    }
    node->restaurantData[restaurantId] = avgPublicity;
}

void AvrgPublicityBST::destroy(Node* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

double AvrgPublicityBST::getAveragePublicityForMonth(const Node* node, const std::string& month, int restaurantId) const {
    if (node == nullptr) {
        return 0.0;
    }

    if (node->date.substr(0, 7) == month) {
        auto it = node->restaurantData.find(restaurantId);
        return (it != node->restaurantData.end()) ? it->second : 0.0;
    }

    return getAveragePublicityForMonth(node->left, month, restaurantId) +
           getAveragePublicityForMonth(node->right, month, restaurantId);
}

void AvrgPublicityBST::calculateAveragePublicity(Node*& node, int restaurantId, const std::string& month) {
    if (node == nullptr) {
        return;
    }

    calculateAveragePublicity(node->left, restaurantId, month);

    double previousAverage = 0.0;
    int dayCount = 0;

    if (node->date.substr(0, 7) == month) {
        auto it = node->restaurantData.find(restaurantId);
        if (it != node->restaurantData.end()) {
            double currentPS = it->second;
            double currentAverage;

            if (dayCount == 0) {
                currentAverage = currentPS;
            } else {
                currentAverage = (previousAverage + currentPS) / 2.0;
            }

            // Update the average in the node
            node->restaurantData[restaurantId] = currentAverage;

            previousAverage = currentAverage;
            dayCount++;
        }
    }

    calculateAveragePublicity(node->right, restaurantId, month);
}

AvrgPublicityBST::~AvrgPublicityBST() {
    destroy(root);
}

void AvrgPublicityBST::insert(int restaurantId, double avgPublicity) {
    insert(root, restaurantId, avgPublicity);
}

double AvrgPublicityBST::getAveragePublicityForMonth(const std::string& month, int restaurantId) const {
    return getAveragePublicityForMonth(root, month, restaurantId);
}

void AvrgPublicityBST::calculateAveragePublicity(int restaurantId, const std::string& month) {
    calculateAveragePublicity(root, restaurantId, month);
}

void AvrgPublicityBST::readFromFile(const std::string& filePath) {
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
        std::string date, id, totalCost, publicitySpending, avgPublicity;

        if (!(iss >> date >> id >> totalCost >> publicitySpending >> avgPublicity)) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }

        int restaurantId = std::stoi(id);
        double avg_Publicity = std::stod(avgPublicity);

        insert(restaurantId, avg_Publicity);
    }

    file.close();
}
