#ifndef MATRIXEXCEPTIONS_H
#define MATRIXEXCEPTIONS_H

#include <string>

class SizeException : public std::exception {
private:
    std::string msg;
public:
    explicit SizeException(const std::string& message);
    const char* what() const noexcept override;
};

class MatrixReadException : public std::exception {
private:
    std::string msg;
public:
    explicit MatrixReadException(const std::string& message);
    const char* what() const noexcept override;
};

class FileReadException : public std::exception {
private:
    std::string msg;
public:
    explicit FileReadException(const std::string& message);
    const char* what() const noexcept override;
};


#endif
