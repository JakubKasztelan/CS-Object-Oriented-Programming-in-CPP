#ifndef POLY_H
#define POLY_H

#include <map>
#include <ostream>

class Poly {
public:
    std::map<int, double> coeffs;

    Poly(double constant = 0);

    double operator[](int power) const;
    double& operator[](int power);

    double operator()(double position) const;

    void cleanup();
};

Poly operator+(const Poly& p1, const Poly& p2);
Poly operator-(const Poly& p1, const Poly& p2);
Poly operator*(const Poly& p1, const Poly& p2);

std::ostream& operator<<(std::ostream& os, const Poly& p);

#endif //POLY_H
