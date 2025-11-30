#pragma once
#include "Employee.h"

class SalariedEmployee : public Employee {
private:
    double annualSalary;
    double bonus;

public:
    SalariedEmployee(int id, const string& name, const string& position,
                     const string& department, double salary, double bonus = 0.0);

    void displayInfo() const override;
    double calculatePay() const override;
    string getEmployeeType() const override;

    // Getters
    double getAnnualSalary() const;
    double getBonus() const;

    // Setters
    void setAnnualSalary(double salary);
    void setBonus(double newBonus);
};
