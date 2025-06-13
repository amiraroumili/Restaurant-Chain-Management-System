#ifndef COSTCLASS_H
#define COSTCLASS_H

#include <string>

class Cost {
private:
    std::string date;
    double total;
    double publicitySpending;

public:
    // Constructor
    Cost(const std::string& date, double total, double publicitySpending)
        : date(date), total(total), publicitySpending(publicitySpending) {}

    // Getters
    const std::string& getDate() const;
    double getTotal() const;
    double getPublicitySpending() const;

    // Setters
    void setDate(const std::string& newDate);
    void setTotal(double newTotal);
    void setPublicitySpending(double newPublicitySpending);

    friend void addCostToFile();
};

#endif // COSTCLASS_H
