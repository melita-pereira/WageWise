#pragma once
#include <string>

class Employee; // Forward declaration

class EmployeeFactory {
public:
    enum EmployeeType {
        HOURLY,
        SALARIED
    };

    static Employee* createEmployee(EmployeeType type, int id, const std::string& name,
                                    const std::string& position, const std::string& department,
                                    double primaryPay, double secondaryPay = 0.0);

    static Employee* createEmployee(const std::string& typeStr, int id, const std::string& name,
                                    const std::string& position, const std::string& department,
                                    double primaryPay, double secondaryPay = 0.0);
};