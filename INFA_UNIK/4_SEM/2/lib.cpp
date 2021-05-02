#include<iostream>
#include "lib.h"

Math::Complex::Complex(double _x, double _y)
{
        x = 0;
        y = 0;
}

Math::Complex::~Complex()
{
        std::cout << "Complex class is deleted\n";
}

void Math::Complex::set_x(double _x)
{
        x = _x;
}

void Math::Complex::set_y(double _y)
{
        y = _y;
}

double Math::Complex::get_x()
{
        return x;
}

double Math::Complex::get_y()
{
        return y;
}

Math::Complex* Math::Complex::plus(Complex *A)
{
        return new Complex(x+A->get_x(), y+A->get_y());
}

Math::Complex* Math::Complex::minus(Complex *A)
{
        return new Complex(x-A->get_x(), y-A->get_y());
}

double Math::Complex::scal_mul(Complex *A)
{
        return x * A->get_x() + y * A->get_y();
}

Math::Complex* Math::Complex::sopr()
{
        return new Complex(x, -y);
}

double Math::Complex::abs()
{
        return x * x + y * y;
}

Math::Complex* Math::Complex::mul_num(double A)
{
        return new Complex(A*x, A*y);
}
