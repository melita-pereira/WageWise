#include "Employee.h"

Employee::Employee(int id, const string& name, const string& position, const string& department)
    : employeeId(id), name(name), position(position), department(department) {}

Employee::~Employee() {}

// Getters
int Employee::getEmployeeId() const { 
    return employeeId; 
}

string Employee::getName() const { 
    return name; 
}

string Employee::getPosition() const { 
    return position; 
}

string Employee::getDepartment() const { 
    return department; 
}

// Setters
void Employee::setName(const string& newName) { 
    name = newName; 
}

void Employee::setPosition(const string& newPosition) { 
    position = newPosition; 
}

void Employee::setDepartment(const string& newDepartment) { 
    department = newDepartment; 
}

// Equality operator
bool Employee::operator==(const Employee& other) const {
    return employeeId == other.employeeId;
}

// Stream insertion operator
ostream& operator<<(ostream& os, const Employee& emp) {
    emp.displayInfo();
    return os;
}
