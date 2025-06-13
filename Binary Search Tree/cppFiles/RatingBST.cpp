// RatingBST.cpp
#include "RatingBST.h"

RatingBST::RatingBST() : root(nullptr) {}

RatingBST::~RatingBST() {
    destroy(root);
}

void RatingBST::insert(RatingNode* data) {
    insert(root, data);
}

void RatingBST::insert(RatingBST::Node*& node, RatingNode* data) {
    if (node == nullptr) {
        node = new Node(data);
    } else if (data->date < node->data->date) {
        insert(node->left, data);
    } else if (data->date > node->data->date) {
        insert(node->right, data);
    }
}

void RatingBST::destroy(RatingBST::Node* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

double RatingBST::getCuisineRatingForMonth(const RatingBST::Node* node, const std::string& month, int restaurantId, const std::string& cuisine) const {
    if (node == nullptr) {
        return 0.0;
    }

    if (node->data->date.substr(0, 7) == month) {
        auto it = node->data->restaurantData.find(restaurantId);
        if (it != node->data->restaurantData.end()) {
            auto cuisineIt = it->second.find(cuisine);
            return (cuisineIt != it->second.end()) ? cuisineIt->second : 0.0;
        }
    }

    return getCuisineRatingForMonth(node->left, month, restaurantId, cuisine) +
           getCuisineRatingForMonth(node->right, month, restaurantId, cuisine);
}

void RatingBST::displayCuisineRatingForMonth(const RatingBST::Node* node, int restaurantId, const std::string& month, const std::string& cuisine) const {
    double cuisineRating = getCuisineRatingForMonth(node, month, restaurantId, cuisine);
    std::cout << "Cuisine Rating for Restaurant " << restaurantId << " in " << month << ":\n"
              << "- " << cuisine << ": " << cuisineRating << std::endl;
}

std::vector<RatingNode> readRatingsFromFile(const std::string& filePath) {
    std::vector<RatingNode> ratingNodes;

    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return ratingNodes;
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

        try {
            int restaurantId = std::stoi(id);
            double algerian = std::stod(algerianRating);
            double syrian = std::stod(syrianRating);
            double indian = std::stod(indianRating);
            double chinese = std::stod(chineseRating);
            double european = std::stod(europeanRating);

            RatingNode ratingNode(date);
            ratingNode.restaurantData[restaurantId]["Algerian"] = algerian;
            ratingNode.restaurantData[restaurantId]["Syrian"] = syrian;
            ratingNode.restaurantData[restaurantId]["Indian"] = indian;
            ratingNode.restaurantData[restaurantId]["Chinese"] = chinese;
            ratingNode.restaurantData[restaurantId]["European"] = european;

            ratingNodes.push_back(ratingNode);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error converting string to number (invalid argument): " << e.what() << std::endl;
            // Handle the error (e.g., skip the line)
        } catch (const std::out_of_range& e) {
            std::cerr << "Error converting string to number (out of range): " << e.what() << std::endl;
            // Handle the error (e.g., skip the line)
        }
    }

    file.close();

    return ratingNodes;
}