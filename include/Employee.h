#pragma once
#include <string>
#include <iostream>
using namespace std;

class Employee {
protected:
    int employeeId;
    string name;
    string position;
    string department;

public:
    Employee(int id, const string& name, const string& position, const string& department);
    
    virtual void displayInfo() const = 0;
    virtual double calculatePay() const = 0;
    virtual string getEmployeeType() const = 0;
    virtual ~Employee();

    // Getters
    int getEmployeeId() const;
    string getName() const;
    string getPosition() const;
    string getDepartment() const;

    // Setters
    void setName(const string& newName);
    void setPosition(const string& newPosition);
    void setDepartment(const string& newDepartment);

    // Equality operator - compares by employee ID
    virtual bool operator==(const Employee& other) const;

    // Stream insertion operator
    friend ostream& operator<<(ostream& os, const Employee& emp);
};