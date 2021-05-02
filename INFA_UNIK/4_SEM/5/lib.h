class Drob
{
    int x, y;
    public:
    Drob ();
    Drob (int x, int y);
    Drob (double x);
    ~Drob();
    void     set_x(int _x);
    void     set_y(int _y);
    int      get_x();
    int      get_y();
    void     ration();
    double   get_double();
    int      get_integer();
           Drob& operator =  (int);
           Drob& operator =  (double);
   friend std::ostream& operator << (std::ostream&, Drob&);
   friend std::istream& operator >> (std::istream&, Drob&);
    friend Drob  operator +  (Drob&, Drob&);
    friend Drob  operator -  (Drob&, Drob&);
    friend Drob  operator *  (Drob&, Drob&);
    friend Drob  operator /  (Drob&, Drob&);
    friend Drob& operator ++ (Drob&, int);
    friend Drob& operator ++ (Drob&);
    friend Drob& operator -- (Drob&, int);
    friend Drob& operator -- (Drob&);
    friend Drob& operator += (Drob&, Drob&);
    friend Drob& operator -= (Drob&, Drob&);
    friend Drob& operator *= (Drob&, Drob&);
    friend Drob& operator /= (Drob&, Drob&);
    friend bool  operator == (Drob&, Drob&);
    friend bool  operator != (Drob&, Drob&);
    friend bool  operator >  (Drob&, Drob&);
    friend bool  operator <  (Drob&, Drob&);
    friend bool  operator <= (Drob&, Drob&);
    friend bool  operator >= (Drob&, Drob&);
    
};
