#include <iostream>
#include "lib.h"

Math::Vector2D::Vector2D()
{
	x = 0;
	y = 0;
}

Math::Vector2D::Vector2D(double x)
{       
        this->x = x;
        y = x;
}

Math::Vector2D::Vector2D(double x, double y)
{
        this->x = x;
        this->y = y;
}

Math::Vector2D::~Vector2D()
{
        std::cout << "Vector2D class is deleted\n";
}

void Math::Vector2D::set_x(double _x)
{
	x = _x;
}

void Math::Vector2D::set_y(double _y)
{
        y = _y;
}

double Math::Vector2D::get_x()
{
        return x;
}

double Math::Vector2D::get_y()
{
        return y;
}

double Math::Vector2D::sum(double _x, double _y)
{
	return (_x + _y);
}

Math::Vector2D* Math::Vector2D::sum(Vector2D *A, Vector2D *B)
{
	return new Vector2D((A->get_x() + B->get_x()), (A->get_y() + B->get_y()));
}

Math::Vector2D Math::Vector2D::times(double A)
{
	return *(new Vector2D(x * A, y * A));
}

double Math::Vector2D::times(Vector2D *B)
{
	return(x * B->get_x() + y * B->get_y());
}

Math::Vector2D Math::Vector2D::operator *(double N)
{
	return *(new Math::Vector2D(x * N, y * N));
}

double Math::Vector2D::operator *(Math::Vector2D V)
{
	return (x * V.get_x() + y * V.get_y());
}

Math::Vector2D Math::Vector2D::operator -(Math::Vector2D V)
{
        return *(new Math::Vector2D(x - V.get_x(), y - V.get_y()));
}

Math::Vector2D Math::Vector2D::operator +(Math::Vector2D V)
{
        return *(new Math::Vector2D(x + V.get_x(), y + V.get_y()));
}

