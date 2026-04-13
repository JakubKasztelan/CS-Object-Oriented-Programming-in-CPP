#include "MatrixExceptions.h"

SizeException::SizeException(const std::string &message) {
    msg = message;
};

const char *SizeException::what() const noexcept {
    return msg.c_str();
}

MatrixReadException::MatrixReadException(const std::string &message) {
    msg = message;
};

const char *MatrixReadException::what() const noexcept {
    return msg.c_str();
}

FileReadException::FileReadException(const std::string &message) {
    msg = message;
};

const char *FileReadException::what() const noexcept {
    return msg.c_str();
}
