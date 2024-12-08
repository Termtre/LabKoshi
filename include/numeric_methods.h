#ifndef NUMERIC_METHODS_H
#define NUMERIC_METHODS_H

#include <vector>
#include <functional>
#include "../include/equation_meshersky.h"

class NumericMethods
{
private:

public:
    NumericMethods() = default;
    std::vector<double> Eler(Meshersky& eq, double t, double tau,
                             const std::vector<double>& v,
                             double(Meshersky::*f1)(double, double, double),
                             double(Meshersky::*f2)(double, double, double));

    std::vector<double> RKII(Meshersky& eq, double t, double tau,
                             const std::vector<double>& v,
                             double(Meshersky::*f1)(double, double, double),
                             double(Meshersky::*f2)(double, double, double));

    double AdamsII(double t, double v1, double v2, double tau, double(*f)(double t, double x1, double x2));
    double implicitAdamsII(double t, double v1, double v2, double tau, double(*f)(double t, double x1, double x2));
};

#endif // NUMERIC_METHODS_H
