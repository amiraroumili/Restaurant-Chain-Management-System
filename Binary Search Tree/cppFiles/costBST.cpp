#include "costBST.h"

void CostBST::insert(Node *&node, CostNode *data)
{
    if (node == nullptr) {
            node = new Node(data);
        }
        else if (data->date < node->data->date) {
            insert(node->left, data);
        }
        else if (data->date > node->data->date) {
            insert(node->right, data);
        }
}

void CostBST::destroy(Node *node)
{
     if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
}

double CostBST::getTotalPublicitySpendingForMonth(const Node *node, const std::string &month, int restaurantId) const
{
     if (node == nullptr) {
            return 0.0;
        }

        if (node->data->date.substr(0, 7) == month) {
            auto it = node->data->restaurantData.find(restaurantId);
            return (it != node->data->restaurantData.end()) ? it->second.second : 0.0; // Assuming the second value in the pair is publicity spending
        }

        return getTotalPublicitySpendingForMonth(node->left, month, restaurantId) +
               getTotalPublicitySpendingForMonth(node->right, month, restaurantId);
}

CostBST::~CostBST()
{
}

void CostBST::insert(CostNode *data)
{
    insert(root, data);
}

double CostBST::getTotalPublicitySpendingForMonth(const std::string &month, int restaurantId) const
{
    return getTotalPublicitySpendingForMonth(root, month, restaurantId);
}

std::vector<CostNode> CostBST::readFromFile(const std::string &filePath)
{
    std::vector<CostNode> costNodes;

    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return costNodes;
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

            CostNode costNode(date);
            costNode.restaurantData[restaurantId] = std::make_pair(cost, publicity);

            costNodes.push_back(costNode);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error converting string to number: " << e.what() << std::endl;
            // Handle the error (e.g., skip the line)
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Value out of range for conversion to integer." << std::endl;
            // Handle the error (e.g., skip the line)
        }
    }

    file.close();

    return costNodes;
}
