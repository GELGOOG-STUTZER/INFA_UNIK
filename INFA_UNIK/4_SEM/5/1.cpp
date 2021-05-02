#include <iostream>
#include <math.h>
#include "lib.h"

int main()
{
    Drob a, b, c;
    double N = 3.5, M;
    int A;
    a = *(new Drob());
    b = *(new Drob(5, 3));
    c = *(new Drob(N));

    std::cout << "a "<< a.get_x() << " " << a.get_y() << "\n";
    std::cout << "b "<< b.get_x() << " " << b.get_y() << "\n";
    std::cout << "c "<< c.get_x() << " " << c.get_y() << "\n";
    
    M = c.get_double();
    std::cout << "c.get_double() "<< M << "\n";
    
    A = c.get_integer();
    std::cout << "c.get_double() "<< A << "\n";
    A = 7;
    a = A;
    std::cout << "a = (int)7 "<< a.get_x() << " " << a.get_y() << "\n";
    
    N = 4.5;
    a = N;
    std::cout << "a = (double)4.5 "<< a.get_x() << " " << a.get_y() << "\n";
    a = 4.5;
    b = 1.5;
    c = a + b;
    std::cout << c;
}

