#include <iostream>
#include <math.h>
#include "lib.h"

void Drob::ration()
{
    int i = 1;
    while(i <= y) {
    	i++;
    	if(x % i == 0 && y % i == 0) {
    		this->x = x / i;
    		this->y = y / i;
    		i = 1;
    	}
    }
}

Drob::Drob()
{
	x = 1;
	y = 1;
}

Drob::Drob(double _x)
{       
	if(_x == 0) {
		_x = 1;
	}
        int i = 0;
        double arg;
        while(modf(_x, &arg) != 0) {
        	i++;
        	_x = _x * 10;
        }
        x = _x;
        y = 1;
        while(i != 0) {
        	y = y * 10;
        	i--;
        }
        Drob::ration();
}

Drob::Drob(int x, int y)
{
        this->x = x;
        if(y == 0) {
        	y = 1;
        }
        this->y = y;
        Drob::ration();
}

Drob::~Drob()
{
//        std::cout << "Vector2D class is deleted\n";
}

void Drob::set_x(int _x)
{	
	x = _x;
	Drob::ration();
}

void Drob::set_y(int _y)
{	
	if(_y == 0) {
		_y = 1;
	}
        y = _y;
        Drob::ration();
}

int Drob::get_x()
{
        return x;
}

int Drob::get_y()
{
        return y;
}

double Drob::get_double()
{
	double N = (double) x / y;
	return N;
}

int Drob::get_integer()
{
	int N = x / y;
	return N;
}

Drob operator + (Drob &A, Drob &B)
{
	return *(new Drob(A.x * B.y + B.x * A.y, A.y * B.y));
}

Drob operator - (Drob &A, Drob &B)
{
	return *(new Drob(A.x * B.y - B.x * A.y, A.y * B.y));
}

Drob operator * (Drob &A, Drob &B)
{
	return *(new Drob(A.x * B.x, A.y * B.y));
}

Drob operator / (Drob &A, Drob &B)
{
	return *(new Drob(A.x * B.y, A.y * B.x));
}

Drob& Drob::operator = (int A)
{
	this->x = A;
	this->y = 1;
	return *this;
}

Drob& Drob::operator = (double A)
{
	if(A == 0) {
		A = 1;
	}
        int i = 0;
        double arg;
        while(modf(A, &arg) != 0) {
        	i++;
        	A = A * 10;
        }
        x = A;
        y = 1;
        while(i != 0) {
        	y = y * 10;
        	i--;
        }
        Drob::ration();
	return *this;
}

Drob& operator ++(Drob &A, int i)
{
    A.x++;
    Drob::ration();
    return A;
}

Drob& operator ++(Drob &A)
{
    ++A.x;
    Drob::ration();
    return A;
}

Drob& operator --(Drob &A, int i)
{
    A.x--;
    Drob::ration();
    return A;
}

Drob& operator --(Drob &A)
{
    --A.x;
    Drob::ration();
    return A;
}

Drob& operator +=(Drob &A, Drob &B)
{
    A.x = A.x * B.y + B.x * A.y;
    A.y = A.y * B.y;
    A.ration();
    return A;
}

Drob& operator -=(Drob &A, Drob &B)
{
    A.x = A.x * B.y - B.x * A.y;
    A.y = A.y * B.y;
    A.ration();
    return A;
}

Drob& operator *=(Drob &A, Drob &B)
{
    A.x = A.x * B.x;
    A.y = A.y * B.y;
    A.ration();
    return A;
}

Drob& operator /=(Drob &A, Drob &B)
{
    A.x = A.x * B.y;
    A.y = A.y * B.x;
    A.ration();
    return A;
}

bool operator ==(Drob &A, Drob &B)
{
	if(A.x == B.x && A.y == B.y)
	{
		return 1;
	}
	else return 0;
}

bool operator !=(Drob &A, Drob &B)
{
	if(A.x != B.x && A.y != B.y)
	{
		return 1;
	}
	else return 0;
}

bool operator >(Drob &A, Drob &B)
{
	if(A.x > B.x && A.y > B.y)
	{
		return 1;
	}
	else return 0;
}

bool operator <(Drob &A, Drob &B)
{
	if(A.x < B.x && A.y < B.y)
	{
		return 1;
	}
	else return 0;
}

bool operator <=(Drob &A, Drob &B)
{
	if(A.x <= B.x && A.y <= B.y)
	{
		return 1;
	}
	else return 0;
}

bool operator >=(Drob &A, Drob &B)
{
	if(A.x >= B.x && A.y >= B.y)
	{
		return 1;
	}
	else return 0;
}

std::ostream& operator << (std::ostream& out, Drob &A)
{
	out << A.x << "/" << A.y << "\n";
	return out;
}

std::istream& operator >> (std::istream& in, Drob &A)
{
	in >> A.x;
	in >> A.y;
	return in;
}
