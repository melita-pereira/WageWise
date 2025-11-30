#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee(int id, const string& name, const string& position,
                                   const string& department, double salary, double bonus)
    : Employee(id, name, position, department), annualSalary(salary), bonus(bonus) {}

void SalariedEmployee::displayInfo() const {
    cout << "\n--- Employee Info ---\n";
    cout << "ID: " << employeeId << "\n";
    cout << "Name: " << name << "\n";
    cout << "Position: " << position << "\n";
    cout << "Department: " << department << "\n";
    cout << "Type: Salaried\n";
    cout << "Salary: $" << annualSalary << "/year\n";
    cout << "Bonus: $" << bonus << "\n";
    cout << "Monthly: $" << calculatePay() << "\n";
}

double SalariedEmployee::calculatePay() const {
    // Monthly salary plus prorated bonus
    return (annualSalary / 12.0) + (bonus / 12.0);
}

string SalariedEmployee::getEmployeeType() const {
    return "Salaried";
}

// Getters
double SalariedEmployee::getAnnualSalary() const { 
    return annualSalary; 
}

double SalariedEmployee::getBonus() const { 
    return bonus; 
}

// Setters
void SalariedEmployee::setAnnualSalary(double salary) { 
    annualSalary = salary; 
}

void SalariedEmployee::setBonus(double newBonus) { 
    bonus = newBonus; 
}
