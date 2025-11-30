#pragma once
#include "Employee.h"

class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    double hoursWorked;

public:
    HourlyEmployee(int id, const string& name, const string& position, 
                   const string& department, double rate, double hours = 0.0);

    void displayInfo() const override;
    double calculatePay() const override;
    string getEmployeeType() const override;

    // Getters
    double getHourlyRate() const;
    double getHoursWorked() const;

    // Setters
    void setHourlyRate(double rate);
    void setHoursWorked(double hours);
};