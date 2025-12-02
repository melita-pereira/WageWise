#include "EmployeeManager.h"
#include <iomanip>

// Initialize static member
EmployeeManager* EmployeeManager::instance = nullptr;

// Private constructor
EmployeeManager::EmployeeManager() : nextEmployeeId(1001) {}

// Get singleton instance
EmployeeManager* EmployeeManager::getInstance() {
    if (instance == nullptr) {
        instance = new EmployeeManager();
    }
    return instance;
}

// Destructor - clean up employees
EmployeeManager::~EmployeeManager() {
    for (Employee* emp : employees) {
        delete emp;
    }
    employees.clear();
}

// Add employee
void EmployeeManager::addEmployee(Employee* emp) {
    if (emp != nullptr) {
        employees.push_back(emp);
    }
}

// Get next available employee ID
int EmployeeManager::getNextEmployeeId() {
    return nextEmployeeId++;
}

// Find employee by ID
Employee* EmployeeManager::findEmployeeById(int id) {
    for (Employee* emp : employees) {
        if (emp->getEmployeeId() == id) {
            return emp;
        }
    }
    return nullptr;
}

// Display all employees
void EmployeeManager::displayAllEmployees() const {
    if (employees.empty()) {
        cout << "\nNo employees\n";
        return;
    }

    cout << "\n+==================================================================+\n";
    cout << "|  ID   | Name           | Position      | Dept      | Type   |  Pay |\n";
    cout << "+-------+----------------+--------------+----------+--------+------+\n";
    for (const Employee* emp : employees) {
        cout << "| " << left << setw(5) << emp->getEmployeeId() << " | "
             << left << setw(14) << emp->getName().substr(0,14) << " | "
             << left << setw(13) << emp->getPosition().substr(0,13) << " | "
             << left << setw(10) << emp->getDepartment().substr(0,10) << " | "
             << left << setw(7) << emp->getEmployeeType().substr(0,7) << " | "
             << right << setw(6) << emp->calculatePay() << " |\n";
    }
    cout << "+==================================================================+\n";
}

// Delete employee by ID
bool EmployeeManager::deleteEmployee(int id) {
    auto it = find_if(employees.begin(), employees.end(),
                     [id](Employee* emp) { return emp->getEmployeeId() == id; });
    
    if (it != employees.end()) {
        delete *it;
        employees.erase(it);
        return true;
    }
    return false;
}

// Get all employees
const vector<Employee*>& EmployeeManager::getAllEmployees() const {
    return employees;
}

// Get employee count
int EmployeeManager::getEmployeeCount() const {
    return employees.size();
}

// Clear all employees
void EmployeeManager::clearAllEmployees() {
    for (Employee* emp : employees) {
        delete emp;
    }
    employees.clear();
    nextEmployeeId = 1001;
}

// Load employees from data source
void EmployeeManager::loadEmployees(const vector<Employee*>& loadedEmployees) {
    for (Employee* emp : loadedEmployees) {
        employees.push_back(emp);
        if (emp->getEmployeeId() >= nextEmployeeId) {
            nextEmployeeId = emp->getEmployeeId() + 1;
        }
    }
}
