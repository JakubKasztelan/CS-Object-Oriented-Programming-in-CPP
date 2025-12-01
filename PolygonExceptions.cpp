#include "PolygonExceptions.h"

PolygonEmptyException::PolygonEmptyException(const std::string &msg) {
    this->msg = msg;
}

const char* PolygonEmptyException::what() const noexcept {
    return msg.c_str();
}
