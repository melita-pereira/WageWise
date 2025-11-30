#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "EmployeeFactory.h"
#include "EmployeeManager.h"
#include "CsvDataSource.h"
#include "PaymentSlip.h"
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

void displayMainMenu() {
    cout << "\n=== WageWise Payroll ===\n";
    cout << "1. Add Employee\n";
    cout << "2. View All\n";
    cout << "3. Search\n";
    cout << "4. Update\n";
    cout << "5. Delete\n";
    cout << "6. Generate Payslip\n";
    cout << "7. Save\n";
    cout << "8. Exit\n";
    cout << "\nChoice: ";
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void addNewEmployee(EmployeeManager* manager) {
    cout << "\n--- Add Employee ---\n";
    
    string name, position, department, typeStr;
    int type;
    double primaryPay, secondaryPay = 0.0;

    cout << "Name: ";
    clearInputBuffer();
    getline(cin, name);

    cout << "Position: ";
    getline(cin, position);

    cout << "Department: ";
    getline(cin, department);

    cout << "\nType (1=Hourly, 2=Salaried): ";
    cin >> type;

    int empId = manager->getNextEmployeeId();
    Employee* newEmployee = nullptr;

    if (type == 1) {
        cout << "Hourly Rate: $";
        cin >> primaryPay;
        cout << "Hours Worked: ";
        cin >> secondaryPay;
        
        newEmployee = EmployeeFactory::createEmployee(
            EmployeeFactory::HOURLY, empId, name, position, department, 
            primaryPay, secondaryPay);
    } 
    else if (type == 2) {
        cout << "Annual Salary: $";
        cin >> primaryPay;
        cout << "Bonus: $";
        cin >> secondaryPay;
        
        newEmployee = EmployeeFactory::createEmployee(
            EmployeeFactory::SALARIED, empId, name, position, department, 
            primaryPay, secondaryPay);
    }
    else {
        cout << "Invalid type\n";
        return;
    }

    if (newEmployee != nullptr) {
        manager->addEmployee(newEmployee);
        cout << "\nAdded! ID: " << empId << "\n";
    } else {
        cout << "\nFailed to add employee\n";
    }
}

void searchEmployee(EmployeeManager* manager) {
    cout << "\n--- Search ---\n";
    int id;
    cout << "Employee ID: ";
    cin >> id;

    Employee* emp = manager->findEmployeeById(id);
    if (emp != nullptr) {
        cout << *emp;
    } else {
        cout << "\nNot found\n";
    }
}

void updateEmployee(EmployeeManager* manager) {
    cout << "\n--- Update ---\n";
    int id;
    cout << "Employee ID: ";
    cin >> id;

    Employee* emp = manager->findEmployeeById(id);
    if (emp == nullptr) {
        cout << "\nNot found\n";
        return;
    }

    cout << *emp;

    cout << "\nUpdate: 1)Name 2)Position 3)Dept 4)Pay\n";
    cout << "Choice: ";
    
    int choice;
    cin >> choice;
    clearInputBuffer();

    string newValue;
    switch (choice) {
        case 1:
            cout << "New name: ";
            getline(cin, newValue);
            emp->setName(newValue);
            cout << "Updated\n";
            break;
        case 2:
            cout << "New position: ";
            getline(cin, newValue);
            emp->setPosition(newValue);
            cout << "Updated\n";
            break;
        case 3:
            cout << "New department: ";
            getline(cin, newValue);
            emp->setDepartment(newValue);
            cout << "Updated\n";
            break;
        case 4:
            if (emp->getEmployeeType() == "Hourly") {
                HourlyEmployee* hourly = dynamic_cast<HourlyEmployee*>(emp);
                double rate, hours;
                cout << "Rate: $";
                cin >> rate;
                cout << "Hours: ";
                cin >> hours;
                hourly->setHourlyRate(rate);
                hourly->setHoursWorked(hours);
                cout << "Updated\n";
            } else if (emp->getEmployeeType() == "Salaried") {
                SalariedEmployee* salaried = dynamic_cast<SalariedEmployee*>(emp);
                double salary, bonus;
                cout << "Salary: $";
                cin >> salary;
                cout << "Bonus: $";
                cin >> bonus;
                salaried->setAnnualSalary(salary);
                salaried->setBonus(bonus);
                cout << "Updated\n";
            }
            break;
        default:
            cout << "Invalid\n";
    }
}

void deleteEmployee(EmployeeManager* manager) {
    cout << "\n--- Delete ---\n";
    int id;
    cout << "Employee ID: ";
    cin >> id;

    Employee* emp = manager->findEmployeeById(id);
    if (emp != nullptr) {
        cout << *emp;
        
        char confirm;
        cout << "\nDelete? (y/n): ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            if (manager->deleteEmployee(id)) {
                cout << "Deleted\n";
            } else {
                cout << "Failed\n";
            }
        } else {
            cout << "Cancelled\n";
        }
    } else {
        cout << "\nNot found\n";
    }
}

void generatePaymentSlip(EmployeeManager* manager) {
    cout << "\n--- Payslip ---\n";
    int id;
    cout << "Employee ID: ";
    cin >> id;

    Employee* emp = manager->findEmployeeById(id);
    if (emp == nullptr) {
        cout << "\nNot found\n";
        return;
    }

    PaymentSlip slip(emp);
    
    cout << "\nAdjustment? 1)Bonus 2)Penalty 3)None: ";
    
    int choice;
    cin >> choice;

    if (choice == 1) {
        double bonus;
        cout << "Amount: $";
        cin >> bonus;
        slip += bonus;
    } else if (choice == 2) {
        double penalty;
        cout << "Amount: $";
        cin >> penalty;
        slip -= penalty;
    }

    cout << slip;
}

void saveData(EmployeeManager* manager, CsvDataSource* dataSource) {
    if (dataSource->saveEmployees(manager->getAllEmployees())) {
        cout << "Saved\n";
    } else {
        cout << "Save failed\n";
    }
}

int main() {
    cout << fixed << setprecision(2);
    
    EmployeeManager* manager = EmployeeManager::getInstance();
    CsvDataSource dataSource("employees.csv");
    
    cout << "Loading...\n";
    vector<Employee*> loadedEmployees = dataSource.loadEmployees();
    manager->loadEmployees(loadedEmployees);

    int choice;
    bool running = true;

    while (running) {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addNewEmployee(manager);
                break;
            case 2:
                manager->displayAllEmployees();
                break;
            case 3:
                searchEmployee(manager);
                break;
            case 4:
                updateEmployee(manager);
                break;
            case 5:
                deleteEmployee(manager);
                break;
            case 6:
                generatePaymentSlip(manager);
                break;
            case 7:
                saveData(manager, &dataSource);
                break;
            case 8:
                cout << "\nSave? (y/n): ";
                char save;
                cin >> save;
                if (save == 'y' || save == 'Y') {
                    saveData(manager, &dataSource);
                }
                cout << "Bye\n";
                running = false;
                break;
            default:
                cout << "Invalid\n";
        }
    }

    return 0;
}
