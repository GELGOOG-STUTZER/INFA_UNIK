#include<iostream>

class Complex
{
	double x, y; //(private) (public) - инкапсуляция переменных
	public:
	Complex(double _x, double _y);
	~Complex();
	void set_x(double _x);
	void set_y(double _y);
	double get_x();
	double get_y();
	Complex* plus(Complex *A);
	Complex* minus(Complex *A);
	double scal_mul(Complex *A);
	Complex* sopr();
	double abs();
	Complex* mul_num(double A);
};

Complex::Complex(double _x, double _y)
{
	x = 0;
	y = 0;
}

Complex::~Complex()
{
	std::cout << "Complex class is deleted\n";
}

void Complex::set_x(double _x)
{
	x = _x;
}

void Complex::set_y(double _y)
{
	y = _y;
}

double Complex::get_x()
{
	return x;
}

double Complex::get_y()
{
	return y;
}

Complex* Complex::plus(Complex *A)
{
	return new Complex(x+A->get_x(), y+A->get_y());
}

Complex* Complex::minus(Complex *A)
{
	return new Complex(x-A->get_x(), y-A->get_y());
}

double Complex::scal_mul(Complex *A)
{
	return x * A->get_x() + y * A->get_y();
}

Complex* Complex::sopr()
{
	return new Complex(x, -y);
}

double Complex::abs()
{
	return x * x + y * y;
}

Complex* Complex::mul_num(double A)
{
        return new Complex(A*x, A*y);
}

//метод - функция, выполняемая над объектом данного класса

int main() 
{
	Complex *a = new Complex(0, 0);
	//printf("%f", a.x);
	//a.x = 1;
	//a.y = 2;
	a->set_x(4);
	a->set_y(8);
	Complex *b = new Complex(0, 0);
	b->set_x(-4);
	b->set_y(9);

	Complex *c = a->plus(b);

	std::cout << a->get_x() << " " << a->get_y() << "\n";
	delete a;
}
