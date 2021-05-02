#include <iostream>
#include "lib_hw.h"

int main()
{
    Vector2D a, b;
    a = *(new Vector2D(4, 9));
    b = *(new Vector2D(5, 3));
    double N = 6;

    Vector2D c;
    c = a + b;
    std::cout << "c = a + b "<< c.get_x() << " " << c.get_y() << "\n";
    c++;
    std::cout << "c++  "<< c.get_x() << " " << c.get_y() << "\n";
    c += a;
    std::cout << "c += a  "<< c.get_x() << " " << c.get_y() << "\n";
    c *= N;
    std::cout << "c *= N  "<< c.get_x() << " " << c.get_y() << "\n";
}

