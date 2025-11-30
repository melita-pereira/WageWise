#pragma once
#include "Employee.h"
#include "EmployeeFactory.h"
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

// Singleton Pattern for centralized employee management
class EmployeeManager {
private:
    static EmployeeManager* instance;
    vector<Employee*> employees;
    int nextEmployeeId;

    // Private constructor for singleton
    EmployeeManager();

    // Delete copy constructor and assignment operator
    EmployeeManager(const EmployeeManager&) = delete;
    EmployeeManager& operator=(const EmployeeManager&) = delete;

public:
    // Get singleton instance
    static EmployeeManager* getInstance();

    // Destructor - clean up employees
    ~EmployeeManager();

    // Add employee
    void addEmployee(Employee* emp);

    // Get next available employee ID
    int getNextEmployeeId();

    Employee* findEmployeeById(int id);

    // Display all employees
    void displayAllEmployees() const;

    // Delete employee by ID
    bool deleteEmployee(int id);

    // Get all employees
    const vector<Employee*>& getAllEmployees() const;

    // Get employee count
    int getEmployeeCount() const;

    // Clear all employees
    void clearAllEmployees();

    // Load employees from data source
    void loadEmployees(const vector<Employee*>& loadedEmployees);
};