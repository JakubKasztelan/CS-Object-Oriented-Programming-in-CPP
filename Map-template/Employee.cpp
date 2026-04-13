#include "Employee.h"

Employee::Employee(std::string name, std::string position, size_t age)
    : name(name), position(position), age(age) {
}

std::ostream& operator<<(std::ostream& os, const Employee& e) {
    os << e.name << " (" << e.position << ", " << e.age << ")";
    return os;
}
