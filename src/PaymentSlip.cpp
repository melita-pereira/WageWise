
#include "PaymentSlip.h"
#include <chrono>
#include <sstream>

PaymentSlip::PaymentSlip(Employee* emp) 
    : employee(emp), taxDeduction(0), insuranceDeduction(0), otherDeductions(0) {
    grossPay = emp->calculatePay();
    calculateDeductions();
    netPay = grossPay - (taxDeduction + insuranceDeduction + otherDeductions);
    
    // Set paymentDate to current system date
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm;
#ifdef _WIN32
    localtime_s(&tm, &t);
#else
    tm = *std::localtime(&t);
#endif
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    paymentDate = oss.str();
}

// Calculate deductions based on gross pay
void PaymentSlip::calculateDeductions() {
    taxDeduction = grossPay * 0.15;           // 15% tax
    insuranceDeduction = grossPay * 0.05;     // 5% insurance
    otherDeductions = grossPay * 0.02;        // 2% other
}

// Operator overloading: Add bonus to payment
PaymentSlip& PaymentSlip::operator+=(double bonus) {
    grossPay += bonus;
    calculateDeductions();
    netPay = grossPay - (taxDeduction + insuranceDeduction + otherDeductions);
    return *this;
}

// Operator overloading: Subtract penalty from payment
PaymentSlip& PaymentSlip::operator-=(double penalty) {
    otherDeductions += penalty;
    netPay = grossPay - (taxDeduction + insuranceDeduction + otherDeductions);
    return *this;
}

// Operator overloading: Compare payment slips by net pay
bool PaymentSlip::operator>(const PaymentSlip& other) const {
    return netPay > other.netPay;
}

bool PaymentSlip::operator<(const PaymentSlip& other) const {
    return netPay < other.netPay;
}

// Display payment slip
void PaymentSlip::displayPaymentSlip() const {
    cout << "\n--- Payment Slip ---\n";
    cout << "Date: " << paymentDate << "\n\n";
    
    cout << "ID: " << employee->getEmployeeId() << "\n";
    cout << "Name: " << employee->getName() << "\n";
    cout << "Position: " << employee->getPosition() << "\n";
    cout << "Dept: " << employee->getDepartment() << "\n\n";
    
    cout << fixed << setprecision(2);
    cout << "Gross: $" << grossPay << "\n";
    cout << "Tax (15%): -$" << taxDeduction << "\n";
    cout << "Insurance (5%): -$" << insuranceDeduction << "\n";
    cout << "Other: -$" << otherDeductions << "\n";
    cout << "---\n";
    cout << "NET PAY: $" << netPay << "\n\n";
}

// Stream insertion operator
ostream& operator<<(ostream& os, const PaymentSlip& slip) {
    slip.displayPaymentSlip();
    return os;
}

// Getters
double PaymentSlip::getGrossPay() const { 
    return grossPay; 
}

double PaymentSlip::getNetPay() const { 
    return netPay; 
}

double PaymentSlip::getTotalDeductions() const { 
    return taxDeduction + insuranceDeduction + otherDeductions; 
}

string PaymentSlip::getPaymentDate() const { 
    return paymentDate; 
}
