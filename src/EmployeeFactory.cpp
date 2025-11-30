#include "EmployeeFactory.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"

Employee* EmployeeFactory::createEmployee(EmployeeType type, int id, const std::string& name,
                                          const std::string& position, const std::string& department,
                                          double primaryPay, double secondaryPay) {
    switch (type) {
        case HOURLY:
            return new HourlyEmployee(id, name, position, department, primaryPay, secondaryPay);
        case SALARIED:
            return new SalariedEmployee(id, name, position, department, primaryPay, secondaryPay);
        default:
            return nullptr;
    }
}

Employee* EmployeeFactory::createEmployee(const std::string& typeStr, int id, const std::string& name,
                                          const std::string& position, const std::string& department,
                                          double primaryPay, double secondaryPay) {
    if (typeStr == "Hourly" || typeStr == "hourly" || typeStr == "H") {
        return createEmployee(HOURLY, id, name, position, department, primaryPay, secondaryPay);
    } else if (typeStr == "Salaried" || typeStr == "salaried" || typeStr == "S") {
        return createEmployee(SALARIED, id, name, position, department, primaryPay, secondaryPay);
    }
    return nullptr;
}
