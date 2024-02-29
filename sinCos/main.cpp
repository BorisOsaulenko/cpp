#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <cmath>

namespace mp = boost::multiprecision;

mp::cpp_dec_float_50 calculateSin(const mp::cpp_dec_float_50& opposite, const mp::cpp_dec_float_50& hypotenuse) {
    return opposite / hypotenuse;
};

mp::cpp_dec_float_50 calculateCos(const mp::cpp_dec_float_50& adjacent, const mp::cpp_dec_float_50& hypotenuse) {
    return adjacent / hypotenuse;
};

mp::cpp_dec_float_50 calculateArcsin(const mp::cpp_dec_float_50& value) {
    return std::asin(static_cast<double>(value));
};

mp::cpp_dec_float_50 calculateArccos(const mp::cpp_dec_float_50& value) {
    return std::acos(static_cast<double>(value));
};

int main() {
    mp::cpp_dec_float_50 side1 = 3.0;
    mp::cpp_dec_float_50 side2 = 4.0;
    mp::cpp_dec_float_50 hypotenuse = 5.0;

    mp::cpp_dec_float_50 sin, cos;
    sin = calculateSin(side1, hypotenuse);
    cos = calculateCos(side2, hypotenuse);
    std::cout << "Sine: " << sin << std::endl;
    std::cout << "Cosine: " << cos << std::endl;

    mp::cpp_dec_float_50 angleSin = calculateArcsin(sin);
    std::cout << "The angle calculated from the sin is: " << angleSin << std::endl;

    mp::cpp_dec_float_50 angleCos = calculateArccos(cos);
    std::cout << "The angle calculated from the cos is: " << angleCos << std::endl;

    return 0;
}