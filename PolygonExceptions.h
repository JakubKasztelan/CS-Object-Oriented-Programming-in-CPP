#include <exception>
#include <string>

class IndexOutOfBoundsException : std::exception {
private:
    std::string msg;
public:
    explicit IndexOutOfBoundsException(const std::string& message);
    const char* what() const noexcept override;
};
