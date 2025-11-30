@echo off
g++ -std=c++17 src/Employee.cpp src/HourlyEmployee.cpp src/SalariedEmployee.cpp src/EmployeeManager.cpp src/CsvDataSource.cpp src/PaymentSlip.cpp src/main.cpp -I src -o WageWise.exe
if %ERRORLEVEL% EQU 0 (
    echo Compiled successfully!
    WageWise.exe
) else (
    echo Compilation failed
)
