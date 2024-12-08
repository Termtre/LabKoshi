#include "../include/numeric_methods.h"

std::vector<double> NumericMethods::Eler(Meshersky &eq, double t, double tau,
                                         const std::vector<double> &v,
                                         double (Meshersky::*f1)(double, double, double),
                                         double (Meshersky::*f2)(double, double, double))
{
    return std::vector<double>{v[0] + tau * (eq.*f1)(t, v[0], v[1]), v[1] + tau * (eq.*f2)(t, v[0], v[1])};
}

std::vector<double> NumericMethods::RKII(Meshersky& eq, double t, double tau,
                                         const std::vector<double>& v,
                                         double(Meshersky::*f1)(double, double, double),
                                         double(Meshersky::*f2)(double, double, double))
{
    double k11 = (eq.*f1)(t, v[0], v[1]);
    double k12 = (eq.*f2)(t, v[0], v[1]);
    double k21 = (eq.*f1)(t + tau, v[0] + tau * k11, v[1] + tau * k11);
    double k22 = (eq.*f2)(t + tau, v[0] + tau * k12, v[1] + tau * k12);

    return std::vector<double>{v[0] + tau / 2. * (k11 + k21), v[1] + tau / 2. * (k12 + k22)};
}
