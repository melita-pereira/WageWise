#pragma once
#include "Employee.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class PaymentSlip {
private:
    Employee* employee;
    double grossPay;
    double taxDeduction;
    double insuranceDeduction;
    double otherDeductions;
    double netPay;
    string paymentDate;

    void calculateDeductions();

public:
    PaymentSlip(Employee* emp);

    // Operator overloading: Add bonus to payment
    PaymentSlip& operator+=(double bonus);

    // Operator overloading: Subtract penalty from payment
    PaymentSlip& operator-=(double penalty);

    // Operator overloading: Compare payment slips by net pay
    bool operator>(const PaymentSlip& other) const;
    bool operator<(const PaymentSlip& other) const;

    // Display payment slip
    void displayPaymentSlip() const;

    // Stream insertion operator
    friend ostream& operator<<(ostream& os, const PaymentSlip& slip);

    // Getters
    double getGrossPay() const;
    double getNetPay() const;
    double getTotalDeductions() const;
    string getPaymentDate() const;
};