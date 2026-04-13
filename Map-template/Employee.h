#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <ostream>

class Employee {
public:
    std::string name;
    std::string position;
    size_t age;

    Employee() = default;
    Employee(std::string name, std::string position, size_t age);
    friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
};


#endif
