#pragma once
#include "IDataSource.h"
#include "EmployeeFactory.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Adapter Pattern: Adapts CSV file format to Employee objects
class CsvDataSource : public IDataSource {
private:
    string employeeFile;

public:
    CsvDataSource(const string& empFile);
    vector<Employee*> loadEmployees() override;
    bool saveEmployees(const vector<Employee*>& employees) override;
};

