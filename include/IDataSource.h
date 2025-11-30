#pragma once
#include <vector>
#include <string>

// Forward declaration ONLY — prevents redefinition issues
class Employee;

class IDataSource {
public:
    virtual ~IDataSource() {}
    virtual std::vector<Employee*> loadEmployees() = 0;
    virtual bool saveEmployees(const std::vector<Employee*>& employees) = 0;
};