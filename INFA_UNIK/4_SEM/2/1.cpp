#include <iostream>
#include "lib.h"


int main()
{
	Math::Complex *a = new Math::Complex(0, 0);
        //printf("%f", a.x);
        //a.x = 1;
        //a.y = 2;
        a->set_x(4);
        a->set_y(8);
	Math::Complex *b = new Math::Complex(0, 0);
        b->set_x(-4);
        b->set_y(9);

	Math::Complex *c = a->plus(b);

        std::cout << a->get_x() << " " << a->get_y() << "\n";
        delete a;
}
