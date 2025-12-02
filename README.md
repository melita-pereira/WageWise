#WageWise - Employee Payment Management System

WageWise is a console-based/command-line interface Employee Payment Management System built in C++ for COMP3773 (Advanced Object-Oriented Programming).

This project demonstrates clean OOP design, file handling, operator overloading, and relevant software design patterns.

This system enables company payroll administrators to manage employee records, update salary information, and generate payment slips, while maintaining persistent storage through external files.

---

##Features
* Employee Management
1. Add new employee records
1. Display existing employee details
1. Modify employee information
1. Delete employee records

* Payment Management
1. Enter or update salary details
1. Generate payment slips (gross, deductions, net pay)
1. Maintain a history of payment records

* Data Handling
1. Persistent storage via external files
1. Load and update records from files

* OOP Requirements
1. Encapsulation
1. Inheritance (Hourly vs Salaried Employees)
1. Polymorphism (pay calculation + display behavior)
1. Operator overloading (stream insertion, comparisons)

* Design Patters
1. Factory Method/Abstract Factory for employee creation
1. Adapter - File format handling (CSV<->internal object model)
1. Singleton for centralized employee management and file I/O

##Technologies
* C++ 17
* Standard Template Library
* File I/O (CSV/text-based storage)
* OOP & design patterns

##How to Compile & Run

### Requirements

You need to have [g++](https://www.mingw-w64.org/) (MinGW for Windows) installed to build and run this project.

Inside the project root:

### Compile & Run (Windows/MinGW)

Open a terminal in the project root and run:

```powershell
g++ -std=c++17 -Iinclude -o WageWise.exe src/*.cpp
.\WageWise.exe
```

This will build and run the program. No batch files are required.

If you want to build object files individually (advanced):

```powershell
g++ -std=c++17 -Iinclude -c src/Employee.cpp -o Employee.o
g++ -std=c++17 -Iinclude -c src/HourlyEmployee.cpp -o HourlyEmployee.o
g++ -std=c++17 -Iinclude -c src/SalariedEmployee.cpp -o SalariedEmployee.o
g++ -std=c++17 -Iinclude -c src/EmployeeManager.cpp -o EmployeeManager.o
g++ -std=c++17 -Iinclude -c src/CsvDataSource.cpp -o CsvDataSource.o
g++ -std=c++17 -Iinclude -c src/PaymentSlip.cpp -o PaymentSlip.o
g++ -std=c++17 -Iinclude -c src/main.cpp -o main.o
g++ *.o -o WageWise.exe
```

##Documentation
All relevant documents are in include/data/docs