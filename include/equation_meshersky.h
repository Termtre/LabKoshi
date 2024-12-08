#ifndef EQUATION_MESHERSKY_H
#define EQUATION_MESHERSKY_H

struct changeMass
{
    double operator()(double M0, double a, double t)
    {
        return M0 * (1. - a * t);
    }

    double operator()(double M0, double a)
    {
        return -M0 * a;
    }
};

struct Meshersky
{
    double V0;//начальная скорость
    double Mempty;// масса ракеты без топлива
    double M0;//начальная масса
    double DM;//сила тяги
    double tmax;//максимальное время работы двигателя
    double cV;//коэффициент сопротивления
    double alpha;// угол пуска
    double a;// скорость расхода топлива
    double x0 = 0., y0 = 0.;
    double g = 9.81;
    changeMass M;

    Meshersky() = default;
    ~Meshersky() = default;

    Meshersky(double _V0, double _Mempty, double _M0, double _DM, double _tmax, double _cV, double _alpha);

    void setNewParam(double _V0, double _Mempty, double _M0, double _DM, double _tmax, double _cV, double _alpha);

    double equation11(double t, double x1, double y1);
    double equation12(double t, double x1, double y1);

    double equation21(double t, double x1, double y1);
    double equation22(double t, double x1, double y1);

    double x(double t, double x1, double x2);
    double y(double t, double y1, double y2);
};

#endif // EQUATION_MESHERSKY_H
