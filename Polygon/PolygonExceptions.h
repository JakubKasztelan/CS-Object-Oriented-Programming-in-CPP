#include <exception>
#include <string>

class IndexOutOfBoundsException : public std::exception {
private:
    std::string msg;

public:
    explicit IndexOutOfBoundsException(const std::string& message);

    const char* what() const noexcept override;
};
