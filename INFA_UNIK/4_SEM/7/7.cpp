#include <iostream>
#include "7.h"
#include <vector>
#include <string>

void Drob::ration()
{
    while(this->y >= 60) {
	    this->y = y - 60;
	    this->x = x + 1;
    }
    while(this->y < 0) {
            this->y = y + 60;
            this->x = x - 1;
    }
}

Drob::Drob()
{
        x = 0;
        y = 0;
}

Drob::Drob(int _x, int _y)
{
        this->x = _x;
	this->y = _y;
        Drob::ration();
}

Drob::~Drob()
{
//        std::cout << "Drob class is deleted\n";
}

void Drob::set_x(int _x)
{
        x = _x;
        Drob::ration();
}

void Drob::set_y(int _y)
{
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

Drob operator + (Drob &A, Drob &B)
{
        return *(new Drob(A.x + B.x, A.y + B.y));
}

Drob operator - (Drob &A, Drob &B)
{
        return *(new Drob(A.x - B.x, A.y - B.y));
}

void Accountant::ration()
{
    while(this->z >= 60) {
            this->z = z - 60;
            this->y = y + 1;
    }
    while(this->z < 0) {
            this->z = z + 60;
            this->y = y - 1;
    }
    while(this->y >= 60) {
            this->y = y - 60;
            this->x = x + 1;
    }
    while(this->y < 0) {
            this->z = z + 60;
            this->x = x - 1;
    }
}

Accountant::Accountant():Drob() 
{
        z = 0;
}

Accountant::Accountant(int _x, int _y, int _z):Drob(_x, _y)
{
        this->z = _z;
	Accountant::ration();
}

Accountant::~Accountant()
{
//        std::cout << "Accountant class is deleted\n";
}

void Accountant::set_x(int _x)
{
        x = _x;
        Accountant::ration();
}

void Accountant::set_y(int _y)
{
        y = _y;
        Accountant::ration();
}

void Accountant::set_z(int _z)
{
        z = _z;
        Accountant::ration();
}

int Accountant::get_x()
{
        return x;
}

int Accountant::get_y()
{
        return y;
}

Accountant operator + (Accountant &A, Accountant &B)
{
        return *(new Accountant(A.x + B.x, A.y + B.y, A.z + B.z));
}

Accountant operator - (Accountant &A, Accountant &B)
{
        return *(new Accountant(A.x - B.x, A.y - B.y, A.z - B.z));
}

template<typename A>
Negotiation<A>::Negotiation()
{
	time = new A();
}

template<typename A>
Negotiation<A>::Negotiation(A _time)
{
        time = _time;
}

template<typename A>
Negotiation<A>::Negotiation(A _time, std::vector<std::string> students)
{
        time = _time;
	att_students = students;
}


template<typename A>
Negotiation<A>::~Negotiation()
{
//        std::cout << "Negotiation class is deleted\n";
}

template<typename A>
void Negotiation<A>::set_time(A _time)
{
	this->time = _time;
}

template<typename A>
void Negotiation<A>::set_students(std::vector<std::string> _students)
{
        this->att_students = _students;
}

template<typename A>
void Negotiation<A>::add_student(std::string student)
{
	try {
		if(student.length() > 20) {
			throw 228;
		}
	}
	catch(int i) {
		std::cout << "Ошибка №" << i << " - string is too long!!!!" << '\n';
		student.erase(19);
	}
        att_students.push_back(student);
}


template<typename A>
A Negotiation<A>::get_time()
{
        return time;
}

template<typename A>
std::vector<std::string> Negotiation<A>::get_students()
{
        return att_students;
}

template<typename B>
Negotiation<B> operator + (Negotiation<B> &neg, B &_time)
{
	return Negotiation<B>(neg.time + _time, neg.att_students);
}

template<typename B>
Negotiation<B> operator - (Negotiation<B> &neg, B &_time)
{
        return Negotiation<B>(neg.time - _time, neg.att_students);
}
