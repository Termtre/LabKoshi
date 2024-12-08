#include "../include/equation_meshersky.h"
#include <cmath>

Meshersky::Meshersky(double _V0, double _Mempty, double _M0, double _DM, double _tmax, double _cV, double _alpha) :
    V0(_V0), Mempty(_Mempty), M0(_M0), DM(_DM), tmax(_tmax), cV(_cV), alpha(_alpha)
{
    a = 1. - Mempty / M0;
}

void Meshersky::setNewParam(double _V0, double _Mempty, double _M0, double _DM, double _tmax, double _cV, double _alpha)
{
    V0 = _V0;
    M0 = _M0;
    DM = _DM;
    tmax = _tmax;
    cV = _cV;
    alpha = _alpha;
    Mempty = _Mempty;
}

double Meshersky::equation11(double t, double x1, double y1)
{
    double V2 = (x1 * x1 + y1 * y1);
    return -(cV * V2 + M(M0, a) * V0) * x1 / M(M0, a, t) / sqrt(V2);
}

double Meshersky::equation12(double t, double x1, double y1)
{
    double V2 = (x1 * x1 + y1 * y1);
    return -g -(cV * V2 + M(M0, a) * V0) * y1 / M(M0, a, t) / sqrt(V2);
}

double Meshersky::equation21(double t, double x1, double y1)
{
    double V2 = (x1 * x1 + y1 * y1);
    return -cV * V2 * x1 / Mempty / sqrt(V2);
}

double Meshersky::equation22(double t, double x1, double y1)
{
    double V2 = (x1 * x1 + y1 * y1);
    return -g -cV * V2 * y1 / Mempty / sqrt(V2);
}

double Meshersky::x(double t, double x1, double x2)
{
    return x0 + x1 * t + x2 * t * t / 2.;
}

double Meshersky::y(double t, double y1, double y2)
{
    return y0 + y1 * t + y2 * t * t / 2.;
}
