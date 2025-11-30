#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee(int id, const string& name, const string& position, 
                               const string& department, double rate, double hours)
    : Employee(id, name, position, department), hourlyRate(rate), hoursWorked(hours) {}

void HourlyEmployee::displayInfo() const {
    cout << "\n--- Employee Info ---\n";
    cout << "ID: " << employeeId << "\n";
    cout << "Name: " << name << "\n";
    cout << "Position: " << position << "\n";
    cout << "Department: " << department << "\n";
    cout << "Type: Hourly\n";
    cout << "Rate: $" << hourlyRate << "/hr\n";
    cout << "Hours: " << hoursWorked << "\n";
    cout << "Pay: $" << calculatePay() << "\n";
}

double HourlyEmployee::calculatePay() const {
    double regularPay = 0.0;
    double overtimePay = 0.0;
    
    if (hoursWorked <= 40) {
        regularPay = hoursWorked * hourlyRate;
    } else {
        regularPay = 40 * hourlyRate;
        overtimePay = (hoursWorked - 40) * hourlyRate * 1.5; // 1.5x overtime
    }
    
    return regularPay + overtimePay;
}

string HourlyEmployee::getEmployeeType() const {
    return "Hourly";
}

// Getters
double HourlyEmployee::getHourlyRate() const { 
    return hourlyRate; 
}

double HourlyEmployee::getHoursWorked() const { 
    return hoursWorked; 
}

// Setters
void HourlyEmployee::setHourlyRate(double rate) { 
    hourlyRate = rate; 
}

void HourlyEmployee::setHoursWorked(double hours) { 
    hoursWorked = hours; 
}
