#include "RestaurantBST.h"

void RestaurantBST::insert(const Restaurant &restaurant, BinaryNode *&t) {
    if (t == nullptr) {
        t = new BinaryNode(restaurant, nullptr, nullptr);
    } else if (restaurant.getId() < t->element.getId()) {
        insert(restaurant, t->left);
    } else if (restaurant.getId() > t->element.getId()) {
        insert(restaurant, t->right);
    }
    // Ignore duplicate IDs (you may adjust this logic based on your requirements)
}

void RestaurantBST::insert(const Restaurant &restaurant) {
    insert(restaurant, root);
}

bool RestaurantBST::contains(const Restaurant &restaurant, BinaryNode *t) const {
    if (t == nullptr) {
        return false;
    } else if (restaurant.getId() < t->element.getId()) {
        return contains(restaurant, t->left);
    } else if (restaurant.getId() > t->element.getId()) {
        return contains(restaurant, t->right);
    } else {
        return true; // Found the restaurant with the same ID
    }
}

bool RestaurantBST::contains(const Restaurant &restaurant) const {
    return contains(restaurant, root);
}

void RestaurantBST::makeEmpty(BinaryNode *&t) {
    if (t != nullptr) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

void RestaurantBST::makeEmpty() {
    makeEmpty(root);
}

void RestaurantBST::printTree(BinaryNode *t, std::ostream &out) const {
    if (t != nullptr) {
        printTree(t->left, out);
        out << t->element.getId() << ": " << t->element.getRestaurantName() << std::endl;
        printTree(t->right, out);
    }
}

void RestaurantBST::printTree(std::ostream &out) const {
    printTree(root, out);
}

Restaurant *RestaurantBST::findRestaurantById(int id, BinaryNode *t) const {
    if (t == nullptr) {
        return nullptr; // Restaurant with the given ID not found
    } else if (id < t->element.getId()) {
        return findRestaurantById(id, t->left);
    } else if (id > t->element.getId()) {
        return findRestaurantById(id, t->right);
    } else {
        return &t->element; // Found the restaurant with the specified ID
    }
}

Restaurant *RestaurantBST::findRestaurantById(int id) const {
    return findRestaurantById(id, root);
}

RestaurantBST::RestaurantBST()
{
}

RestaurantBST::~RestaurantBST()
{
    makeEmpty();
}

void RestaurantBST::readFromFile(const std::string &filePath) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }

    std::string header;
    std::getline(file, header);

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string id_str, name, type, employeeNumber_str, country, wilaya, city, district;

        std::getline(ss, id_str, ',');
        std::getline(ss, name, ',');
        std::getline(ss, type, ',');
        std::getline(ss, employeeNumber_str, ',');
        std::getline(ss, country, ',');
        std::getline(ss, wilaya, ',');
        std::getline(ss, city, ',');
        std::getline(ss, district, ',');

        try {
            int id = std::stoi(id_str);
            int employeeNumber = std::stoi(employeeNumber_str);

            // Create Place object
            Place place(wilaya, city, district, country);

            // Create Restaurant object
            Restaurant restaurant(id, name, type, employeeNumber, place);

            // Insert into BST
            insert(restaurant); // Assuming insert is a member function of your BST class

        } catch (const std::invalid_argument &e) {
            std::cerr << "Error converting string to number: " << e.what() << std::endl;
            // Handle the error (e.g., skip the line)
        }
    }

    file.close();
}

void RestaurantBST::deleteRestaurantById(int idToDelete) {
    ifstream inFile("../File_csv/restaurants.csv");
    if (!inFile) {
        cerr << "Error opening file: " << "../File_csv/restaurants.csv" << endl;
        return;
    }

    vector<string> lines;
    string line;

    // Read the first line and store it separately
    getline(inFile, line);
    lines.push_back(line);

    // Read the rest of the lines from the file
    while (getline(inFile, line)) {
        lines.push_back(line);
    }

    // Find the line with the specified ID and remove it
    vector<string> newLines;
    for (size_t i = 0; i < lines.size(); ++i) {
        if (i == 0) {
            // Keep the first line
            newLines.push_back(lines[i]);
        } else {
            stringstream ss(lines[i]);
            string idStr;
            if (getline(ss, idStr, ',')) {
                try {
                    int currentId = stoi(idStr);
                    if (currentId != idToDelete) {
                        newLines.push_back(lines[i]);
                    }
                } catch (const invalid_argument& e) {
                    cerr << "Invalid ID found in the file: " << idStr << endl;
                }
            }
        }
    }

    inFile.close();

    // Write the updated lines back to the file
    ofstream outFile("../File_csv/restaurants.csv");
    if (!outFile) {
        cerr << "Error opening file for writing: " << "../File_csv/restaurants.csv"<< endl;
        return;
    }

    for (const auto& updatedLine : newLines) {
        outFile << updatedLine << endl;
    }

    cout << "Restaurant with ID " << idToDelete << " deleted successfully." << endl;
}