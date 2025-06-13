#include "SalesBST.h"

// SalesNode Definitions
SalesNode::SalesNode(std::string d) : date(d) {}

// SalesBST Definitions
SalesBST::SalesBST() : root(nullptr) {}

SalesBST::~SalesBST() {
    destroy(root);
}

void SalesBST::insert(SalesNode* data) {
    insert(root, data);
}

void SalesBST::displayTotalSales(int restaurantId, const std::string& month) const {
    displayTotalSales(root, restaurantId, month);
}

void SalesBST::displayCuisineTotalSales(int restaurantId, const std::string& month, const std::string& cuisine) const {
    displayCuisineTotalSales(root, restaurantId, month, cuisine);
}

SalesBST::Node::Node(SalesNode* d) : data(d), left(nullptr), right(nullptr) {}

void SalesBST::insert(Node*& node, SalesNode* data) {
    if (node == nullptr) {
        node = new Node(data);
    } else if (data->date < node->data->date) {
        insert(node->left, data);
    } else if (data->date > node->data->date) {
        insert(node->right, data);
    }
}

void SalesBST::destroy(Node* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

double SalesBST::getTotalSalesForMonth(const Node* node, const std::string& month, int restaurantId) const {
    if (node == nullptr) {
        return 0.0;
    }

    if (node->data->date.substr(0, 7) == month) {
        auto it = node->data->restaurantData.find(restaurantId);
        if (it != node->data->restaurantData.end()) {
            double totalSales = 0.0;
            for (const auto& entry : it->second) {
                totalSales += entry.second; // Summing up sales for all cuisines
            }
            return totalSales;
        }
    }

    return getTotalSalesForMonth(node->left, month, restaurantId) +
           getTotalSalesForMonth(node->right, month, restaurantId);
}

double SalesBST::getCuisineTotalSalesForMonth(const Node* node, const std::string& month, int restaurantId, const std::string& cuisine) const {
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

    return getCuisineTotalSalesForMonth(node->left, month, restaurantId, cuisine) +
           getCuisineTotalSalesForMonth(node->right, month, restaurantId, cuisine);
}
// hadi
void SalesBST::displayTotalSales(const Node* node, int restaurantId, const std::string& month) const {
    double totalSales = getTotalSalesForMonth(node, month, restaurantId);
    std::cout << "Total Sales for Restaurant " << restaurantId << " in " << month << ": " << totalSales << std::endl;
}
// hadi
void SalesBST::displayCuisineTotalSales(const Node* node, int restaurantId, const std::string& month, const std::string& cuisine) const {
    double cuisineTotalSales = getCuisineTotalSalesForMonth(node, month, restaurantId, cuisine);
    std::cout << "Total " << cuisine << " Sales for Restaurant " << restaurantId << " in " << month << ": " << cuisineTotalSales << std::endl;
}

std::vector<SalesNode> readSalesFromFile(const std::string& filePath) {
    std::vector<SalesNode> salesNodes;

    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return salesNodes;
    }

    // Skip the header line
    std::string header;
    std::getline(file, header);

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, id, algerianSales, syrianSales, indianSales, chineseSales, europeanSales, totalSales;

        if (!(iss >> date >> id >> algerianSales >> syrianSales >> indianSales >> chineseSales >> europeanSales >> totalSales)) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }

        try {
            int restaurantId = std::stoi(id);
            double algerian = std::stod(algerianSales);
            double syrian = std::stod(syrianSales);
            double indian = std::stod(indianSales);
            double chinese = std::stod(chineseSales);
            double european = std::stod(europeanSales);
            double total = std::stod(totalSales);

            SalesNode salesNode(date);
            salesNode.restaurantData[restaurantId]["Algerian"] = algerian;
            salesNode.restaurantData[restaurantId]["Syrian"] = syrian;
            salesNode.restaurantData[restaurantId]["Indian"] = indian;
            salesNode.restaurantData[restaurantId]["Chinese"] = chinese;
            salesNode.restaurantData[restaurantId]["European"] = european;
            salesNode.restaurantData[restaurantId]["Total"] = total;

            salesNodes.push_back(salesNode);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error converting string to number: " << e.what() << std::endl;
            // Handle the error (e.g., skip the line)
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Value out of range for conversion to integer." << std::endl;
            // Handle the error (e.g., skip the line)
        }
    }

    file.close();

    return salesNodes;
}


// Function to generate a report on the sales of a restaurant for a specific month
void SalesBST::generateMonthlySalesReport(const Node* node, int restaurantId, const std::string& month, const std::string& cuisine) const {
    displayCuisineTotalSales(node, restaurantId, month, cuisine);
    displayTotalSales( node,  restaurantId, month);
   
}


