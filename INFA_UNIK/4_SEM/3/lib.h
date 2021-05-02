namespace Math {

	class Vector2D
	{
		double x, y;
		public:
		Vector2D();
		Vector2D(double x);
		Vector2D(double x, double y);
		~Vector2D();
		void set_x(double _x);
		void set_y(double _y);
		double get_x();
		double get_y();
		double sum(double _x, double _y);
		Vector2D* sum(Vector2D *A, Vector2D *B);
		Vector2D times(double A);
		double times(Vector2D *B);
		Vector2D operator *(double N);
		double operator *(Vector2D V);
		Vector2D operator -(Vector2D V);
		Vector2D operator +(Vector2D V);
	};
}
