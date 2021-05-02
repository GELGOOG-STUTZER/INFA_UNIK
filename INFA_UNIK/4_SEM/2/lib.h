namespace Math {
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
}
