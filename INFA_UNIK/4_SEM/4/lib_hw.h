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
    friend double    abs_num     (double N);
    friend Vector2D  operator +  (Vector2D&, Vector2D&);
    friend Vector2D  operator +  (Vector2D&);
    friend Vector2D  operator -  (Vector2D&, Vector2D&);
    friend Vector2D  operator -  (Vector2D&);
    friend Vector2D  operator *  (double, Vector2D&);
    friend Vector2D  operator *  (Vector2D&, double);
    friend double    operator *  (Vector2D&, Vector2D&);
    friend Vector2D& operator ++ (Vector2D&, int);
    friend Vector2D& operator ++ (Vector2D&);
    friend Vector2D& operator -- (Vector2D&, int);
    friend Vector2D& operator -- (Vector2D&);
    friend Vector2D& operator += (Vector2D&, Vector2D&);
    friend Vector2D& operator -= (Vector2D&, Vector2D&);
    friend Vector2D& operator *= (Vector2D&, double&);
    friend bool      operator == (Vector2D&, Vector2D&);
    friend bool      operator != (Vector2D&, Vector2D&);
    friend bool      operator >  (Vector2D&, Vector2D&);
    friend bool      operator <  (Vector2D&, Vector2D&);
    friend bool      operator <= (Vector2D&, Vector2D&);
    friend bool      operator >= (Vector2D&, Vector2D&);
    friend bool      operator && (Vector2D&, Vector2D&);
    friend bool      operator || (Vector2D&, Vector2D&);
    friend bool      operator !  (Vector2D&);
    
};

class Matrix22
{
    double x11, x12, x21, x22;
    public:
    Matrix22();
    Matrix22(double x);
    Matrix22(double x11, double x12, double x21, double x22);
    ~Matrix22();
    friend double    abs_num     (double N);
    friend Matrix22  operator +  (Matrix22&, Matrix22&);
    friend Matrix22  operator +  (Matrix22&);
    friend Matrix22  operator -  (Matrix22&, Matrix22&);
    friend Matrix22  operator -  (Matrix22&);
    friend Matrix22  operator *  (double, Matrix22&);
    friend Matrix22  operator *  (Matrix22&, double);
    friend Matrix22    operator *  (Matrix22&, Matrix22&);
    friend Matrix22& operator ++ (Matrix22&, int);
    friend Matrix22& operator ++ (Matrix22&);
    friend Matrix22& operator -- (Matrix22&, int);
    friend Matrix22& operator -- (Matrix22&);
    friend Matrix22& operator += (Matrix22&, Matrix22&);
    friend Matrix22& operator -= (Matrix22&, Matrix22&);
    friend Matrix22& operator *= (Matrix22&, double&);
    friend bool      operator == (Matrix22&, Matrix22&);
    friend bool      operator != (Matrix22&, Matrix22&);
    friend bool      operator >  (Matrix22&, Matrix22&);
    friend bool      operator <  (Matrix22&, Matrix22&);
    friend bool      operator <= (Matrix22&, Matrix22&);
    friend bool      operator >= (Matrix22&, Matrix22&);
    friend bool      operator && (Matrix22&, Matrix22&);
    friend bool      operator || (Matrix22&, Matrix22&);
    friend bool      operator !  (Matrix22&);
    
};
