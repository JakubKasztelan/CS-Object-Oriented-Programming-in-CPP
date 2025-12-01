#pragma once
#include <string>

class PolygonEmptyException : public std::exception {
private:
    std::string msg;
public:
    explicit PolygonEmptyException(const std::string& msg);
    const char* what() const noexcept override;
};