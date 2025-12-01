#include "PolygonExceptions.h"

IndexOutOfBoundsException::IndexOutOfBoundsException(const std::string& message)
    : msg(message)
{}

const char* IndexOutOfBoundsException::what() const noexcept {
    return msg.c_str();
}
