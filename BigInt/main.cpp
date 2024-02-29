#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;

using namespace std;

class BigNumber {
private:
    mp::cpp_int value;

public:
    // Constructors
    BigNumber() : value(0) {}
    BigNumber(const std::string& str) : value(str) {}
    BigNumber(const long long& num) : value(num) {}
    BigNumber(const mp::cpp_int& num) : value(num) {}

    // Copy constructor
    BigNumber(const BigNumber& other) : value(other.value) {}

    std::string getValue() const {
        return value.str();
    }

    // Arithmetic operations
    BigNumber operator+(const BigNumber& other) const {
        BigNumber result;
        result.value = this->value + other.value;
        return result;
    }

    BigNumber operator*(const BigNumber& other) const {
        BigNumber result;
        result.value = this->value * other.value;
        return result;
    }

    BigNumber operator-(const BigNumber& other) const {
        BigNumber result;
        result.value = this->value - other.value;
        return result;
    }

    BigNumber operator/(const BigNumber& other) const {
        BigNumber result;
        result.value = this->value / other.value;
        return result;
    }

    BigNumber operator%(const BigNumber& other) const {
        BigNumber result;
        result.value = this->value % other.value;
        return result;
    }

    BigNumber toPower(const BigNumber& other) const {
        BigNumber result;
        result.value = 1;
        for (int i = 0; i < other.value; i++) {
            result.value *= this->value;
        }
        return result;
    }

    BigNumber takeSqrt() const {
        BigNumber result, left = 0, right = this->value;

        while (left <= right) {
            BigNumber mid = (left + right) / 2;
            if (mid * mid == this->value) {
                result = mid;
                break;
            } else if (mid * mid < *new BigNumber(this->value)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    // Comparison operators
    bool operator==(const BigNumber& other) const {
        return this->value == other.value;
    }

    BigNumber operator=(const BigNumber& other) {
        this->value = other.value;
        return *this;
    }

    BigNumber operator=(const std::string& str) {
        return *new BigNumber(str);
    }

    void operator=(const long long& num) {
        this->value = num;
    }

    bool operator<(const BigNumber& other) const {
        return this->value < other.value;
    }

    bool operator<=(const BigNumber& other) const {
        return this->value <= other.value;
    }

    bool operator>(const BigNumber& other) const {
        return this->value > other.value;
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const BigNumber& num) {
        os << num.value;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, BigNumber& num) {
        string str;
        is >> str;
        num = *new BigNumber(str);

        return is;
    }
};

int main() {
    BigNumber num1("123456789012345678901234567890"); // too big to be a number
    BigNumber num2(10000000000); // 10^10

    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;

    BigNumber sum = num1 + num2;
    std::cout << "Sum: " << sum << std::endl;

    BigNumber product = num1 * num2;
    std::cout << "Product: " << product << std::endl;

    BigNumber difference = num1 - num2;
    std::cout << "Difference: " << difference << std::endl;

    BigNumber quotient = num1 / num2;
    std::cout << "Quotient: " << quotient << std::endl;

    BigNumber remainder = num1 % num2;
    std::cout << "Remainder: " << remainder << std::endl;

    BigNumber power = num1.toPower(3); // too big if toPower(num2)
    std::cout << "Power: " << power << std::endl;

    BigNumber sqrt1 = num1.takeSqrt();
    std::cout << "Square root num1: " << sqrt1 << std::endl;

    BigNumber sqrt2 = num2.takeSqrt();
    std::cout << "Square root num2: " << sqrt2 << std::endl;

    if (num1 == num2) {
        std::cout << "num1 is equal to num2" << std::endl;
    } else if (num1 < num2) {
        std::cout << "num1 is less than num2" << std::endl;
    } else {
        std::cout << "num1 is greater than num2" << std::endl;
    }

    return 0;
}