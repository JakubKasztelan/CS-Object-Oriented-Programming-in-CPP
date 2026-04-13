#include "Poly.h"
#include <math.h>

Poly::Poly(double constant) {
    if (constant != 0) {
        coeffs[0] = constant;
    }
}


double Poly::operator[](int power) const {
    auto element = coeffs.find(power);
    if (element != coeffs.end()) {
        return element->second;
    }
    return 0.0;
}

double& Poly::operator[](int power) {
    return coeffs[power];
}


double Poly::operator()(double position) const {
    double result = 0;
    for (auto it = coeffs.begin(); it != coeffs.end(); it++) {
        result += it->second * pow(position, it->first);
    }
    return result;
}


void Poly::cleanup() {
    for (auto it = coeffs.begin(); it != coeffs.end();) {
        if (it->second == 0) {
            it = coeffs.erase(it);
        } else {
            it++;
        }
    }
}


Poly operator+(const Poly &p1, const Poly &p2) {
    Poly result;

    for (auto& [power, coeff] : p1.coeffs) {
        result.coeffs[power] += coeff;
    }

    for (auto& [power, coeff] : p2.coeffs) {
        result.coeffs[power] += coeff;
    }

    result.cleanup();
    return result;
}

Poly operator-(const Poly &p1, const Poly &p2) {
    Poly result;

    for (auto& [power, coeff] : p1.coeffs) {
        result.coeffs[power] += coeff;
    }

    for (auto& [power, coeff] : p2.coeffs) {
        result.coeffs[power] -= coeff;
    }

    result.cleanup();
    return result;
}

Poly operator*(const Poly &p1, const Poly &p2) {
    Poly result;

    for (auto& [power1, coeff1] : p1.coeffs) {
        for (auto& [power2, coeff2] : p2.coeffs) {
            int power = power1 + power2;
            double coeff = coeff1 * coeff2;
            result.coeffs[power] += coeff;
        }
    }

    result.cleanup();
    return result;
}

std::ostream &operator<<(std::ostream &os, const Poly &p) {
    if (p.coeffs.empty()) {
        return os;
    }

    bool first = true;
    for (auto it = p.coeffs.rbegin(); it != p.coeffs.rend(); ++it) {
        int pow = it->first;
        double coeff = it->second;

        if (first) {
            os << coeff;
        } else if (coeff >= 0) {
            os << " + " << coeff;
        } else {
            os << " - " << -coeff;
        }
        if (pow > 0) {
            os << "x";
        }
        if (pow > 1) {
            os << "^" << pow;
        }
        first = false;
    }

    return os;
}
