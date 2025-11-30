#include "CsvDataSource.h"
#include "Employee.h"          // FULL Employee definition
#include "HourlyEmployee.h"    // Needed for dynamic_cast + getters
#include "SalariedEmployee.h"  // Needed for dynamic_cast + getters
#include <iostream>

CsvDataSource::CsvDataSource(const string& empFile) : employeeFile(empFile) {}

vector<Employee*> CsvDataSource::loadEmployees() {
    vector<Employee*> employees;
    ifstream file(employeeFile);
    
    if (!file.is_open()) {
        cout << "No file found, starting fresh\n";
        return employees;
    }

    string line;
    // Skip header line
    getline(file, line);

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string idStr, name, position, department, type, pay1Str, pay2Str;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, position, ',');
        getline(ss, department, ',');
        getline(ss, type, ',');
        getline(ss, pay1Str, ',');
        getline(ss, pay2Str, ',');

        try {
            int id = stoi(idStr);
            double pay1 = stod(pay1Str);
            double pay2 = pay2Str.empty() ? 0.0 : stod(pay2Str);

            Employee* emp = EmployeeFactory::createEmployee(type, id, name, position, department, pay1, pay2);
            if (emp != nullptr) {
                employees.push_back(emp);
            }
        } catch (...) {
            // skip bad line
        }
    }

    file.close();
    cout << "Loaded " << employees.size() << " employees\n";
    return employees;
}

bool CsvDataSource::saveEmployees(const vector<Employee*>& employees) {
    ofstream file(employeeFile);
    
    if (!file.is_open()) {
        cout << "Can't write to file\n";
        return false;
    }

    // Write header
    file << "EmployeeID,Name,Position,Department,Type,PrimaryPay,SecondaryPay\n";

    // Write employee data
    for (const Employee* emp : employees) {
        file << emp->getEmployeeId() << ","
             << emp->getName() << ","
             << emp->getPosition() << ","
             << emp->getDepartment() << ","
             << emp->getEmployeeType() << ",";

        // Write type-specific pay data
        if (emp->getEmployeeType() == "Hourly") {
            const HourlyEmployee* hourly = dynamic_cast<const HourlyEmployee*>(emp);
            file << hourly->getHourlyRate() << ","
                 << hourly->getHoursWorked();
        } else if (emp->getEmployeeType() == "Salaried") {
            const SalariedEmployee* salaried = dynamic_cast<const SalariedEmployee*>(emp);
            file << salaried->getAnnualSalary() << ","
                 << salaried->getBonus();
        }

        file << "\n";
    }

    file.close();
    cout << "Saved " << employees.size() << " employees\n";
    return true;
}
