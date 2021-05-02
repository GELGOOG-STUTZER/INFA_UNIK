#include <iostream>
#include "lib.h"

Vector2D::Vector2D()
{
	x = 0;
	y = 0;
}

Vector2D::Vector2D(double x)
{       
        this->x = x;
        y = x;
}

Vector2D::Vector2D(double x, double y)
{
        this->x = x;
        this->y = y;
}

Vector2D::~Vector2D()
{
//        std::cout << "Vector2D class is deleted\n";
}

void Vector2D::set_x(double _x)
{
	x = _x;
}

void Vector2D::set_y(double _y)
{
        y = _y;
}

double Vector2D::get_x()
{
        return x;
}

double Vector2D::get_y()
{
        return y;
}

double abs_num(double N)
{
    if (N >= 0)
        {
            return N;
        }
    else return -N;
}

Vector2D operator +(Vector2D &A, Vector2D &B)
{
	return *(new Vector2D(A.x + B.x, A.y + B.y));
}

Vector2D operator +(Vector2D &A)
{
    return *(new Vector2D(abs(A.x), abs(A.y)));
}

Vector2D operator -(Vector2D &A, Vector2D &B)
{
    return *(new Vector2D(A.x - B.x, A.y - B.y));
}

Vector2D operator -(Vector2D &A)
{
    return *(new Vector2D(-abs(A.x), -abs(A.y)));
}

Vector2D operator *(double N, Vector2D &A)
{
    return *(new Vector2D(A.x * N, A.y * N));
}

Vector2D operator *(Vector2D &A, double N)
{
    return *(new Vector2D(A.x * N, A.y * N));
}

double operator * (Vector2D &A, Vector2D &B)
{
    return (A.x * B.x + A.y * B.y);
}

Vector2D& operator ++(Vector2D &A, int i)
{
    A.x++;
    A.y++;
    return A;
}

Vector2D& operator ++(Vector2D &A)
{
    ++A.x;
    ++A.y;
    return A;
}

Vector2D& operator --(Vector2D &A, int i)
{
    A.x--;
    A.y--;
    return A;
}

Vector2D& operator --(Vector2D &A)
{
    --A.x;
    --A.y;
    return A;
}

Vector2D& operator +=(Vector2D &A, Vector2D &B)
{
    A.x = A.x + B.x;
    A.y = A.y + B.y;
    return A;
}

Vector2D& operator -=(Vector2D &A, Vector2D &B)
{
    A.x = A.x - B.x;
    A.y = A.y - B.y;
    return A;
}

Vector2D& operator *=(Vector2D &A, double &B)
{
    A.x = A.x * B;
    A.y = A.y * B;
    return A;
}

bool operator ==(Vector2D &A, Vector2D &B)
{
    if(A.x == B.x && A.y == B.y) {
        return 1;
    }
    else return 0;
}

bool operator !=(Vector2D &A, Vector2D &B)
{
    if(A.x != B.x && A.y != B.y) {
        return 1;
    }
    else return 0;
}

bool operator >(Vector2D &A, Vector2D &B)
{
    if(A.x > B.x && A.y > B.y) {
        return 1;
    }
    else return 0;
}

bool operator <(Vector2D &A, Vector2D &B)
{
    if(A.x < B.x && A.y < B.y) {
        return 1;
    }
    else return 0;
}

bool operator <=(Vector2D &A, Vector2D &B)
{
    if(A.x <= B.x && A.y <= B.y) {
        return 1;
    }
    else return 0;
}

bool operator >=(Vector2D &A, Vector2D &B)
{
    if(A.x >= B.x && A.y >= B.y) {
        return 1;
    }
    else return 0;
}

bool operator && (Vector2D &A, Vector2D &B)
{
    if(A.x && B.x && A.y && B.y) {
        return 1;
    }
    else return 0;
}

bool operator || (Vector2D &A, Vector2D &B)
{
    if(A.x || B.x && A.y || B.y) {
        return 1;
    }
    else return 0;
}

bool operator ! (Vector2D &A)
{
    if(!A.x && !A.y) {
        return 1;
    }
    else return 0;
}

Matrix22::Matrix22()
{
	x11 = 0;
	x12 = 0;
	x21 = 0;
	x22 = 0;
}

Matrix22::Matrix22(double x)
{       
        this->x11 = x;
        this->x12 = x;
        this->x21 = x;
        this->x22 = x;
}

Matrix22::Matrix22(double x11, double x12, double x21, double x22)
{
        this->x11 = x11;
        this->x12 = x12;
        this->x21 = x21;
        this->x22 = x22;
}

Matrix22::~Matrix22()
{
//        std::cout << "Matrix22 class is deleted\n";
}

Matrix22 operator +(Matrix22 &A, Matrix22 &B)
{
	return *(new Matrix22(A.x11 + B.x11, A.x12 + B.x12, A.x21 + B.x21, A.x22 + B.x22));
}

Matrix22 operator +(Matrix22 &A)
{
    return *(new Matrix22(abs(A.x11), abs(A.x12), abs(A.x21), abs(A.x22)));
}

Matrix22 operator -(Matrix22 &A, Matrix22 &B)
{
    return *(new Matrix22(A.x11 - B.x11, A.x12 - B.x12, A.x21 - B.x21, A.x22 - B.x22));
}

Matrix22 operator -(Matrix22 &A)
{
    return *(new Matrix22(-abs(A.x11), -abs(A.x12), -abs(A.x21), -abs(A.x22)));
}

Matrix22 operator *(double N, Matrix22 &A)
{
    return *(new Matrix22(A.x11 * N, A.x12 * N, A.x21 * N, A.x22 * N));
}

Matrix22 operator *(Matrix22 &A, double N)
{
    return *(new Matrix22(A.x11 * N, A.x12 * N, A.x21 * N, A.x22 * N));
}

Matrix22 operator * (Matrix22 &A, Matrix22 &B)
{
    return *(new Matrix22(A.x11 * B.x11 + A.x12 * B.x21, A.x11 * B.x12 + A.x12 * B.x22, A.x21 * B.x11 + A.x22 * B.x21, A.x21 * B.x12 + A.x22 * B.x22));
}

Matrix22& operator ++(Matrix22 &A, int i)
{
    A.x11++;
    A.x12++;
    A.x21++;
    A.x22++;
    return A;
}

Matrix22& operator ++(Matrix22 &A)
{
    ++A.x11;
    ++A.x12;
    ++A.x21;
    ++A.x22;
    return A;
}

Matrix22& operator --(Matrix22 &A, int i)
{
    A.x11--;
    A.x12--;
    A.x21--;
    A.x22--;
    return A;
}

Matrix22& operator --(Matrix22 &A)
{
    --A.x11;
    --A.x12;
    --A.x21;
    --A.x22;
    return A;
}

Matrix22& operator +=(Matrix22 &A, Matrix22 &B)
{
    A.x11 = A.x11 + B.x11;
    A.x12 = A.x12 + B.x12;
    A.x21 = A.x21 + B.x21;
    A.x22 = A.x22 + B.x22;
    return A;
}

Matrix22& operator -=(Matrix22 &A, Matrix22 &B)
{
    A.x11 = A.x11 - B.x11;
    A.x12 = A.x12 - B.x12;
    A.x21 = A.x21 - B.x21;
    A.x22 = A.x22 - B.x22;
    return A;
}

Matrix22& operator *=(Matrix22 &A, double &B)
{
    A.x11 = A.x11 * B;
    A.x12 = A.x12 * B;
    A.x21 = A.x21 * B;
    A.x22 = A.x22 * B;
    return A;
}

bool operator ==(Matrix22 &A, Matrix22 &B)
{
    if(A.x11 == B.x11 && A.x12 == B.x12 && A.x21 == B.x21 && A.x22 == B.x22) {
        return 1;
    }
    else return 0;
}

bool operator !=(Matrix22 &A, Matrix22 &B)
{
    if(A.x11 != B.x11 && A.x12 != B.x12 && A.x21 != B.x21 && A.x22 != B.x22) {
        return 1;
    }
    else return 0;
}

bool operator >(Matrix22 &A, Matrix22 &B)
{
    if(A.x11 > B.x11 && A.x12 > B.x12 && A.x21 > B.x21 && A.x22 > B.x22) {
        return 1;
    }
    else return 0;
}

bool operator <(Matrix22 &A, Matrix22 &B)
{
    if(A.x11 < B.x11 && A.x12 < B.x12 && A.x21 < B.x21 && A.x22 < B.x22) {
        return 1;
    }
    else return 0;
}

bool operator <=(Matrix22 &A, Matrix22 &B)
{
    if(A.x11 <= B.x11 && A.x12 <= B.x12 && A.x21 <= B.x21 && A.x22 <= B.x22) {
        return 1;
    }
    else return 0;
}

bool operator >=(Matrix22 &A, Matrix22 &B)
{
    if(A.x11 >= B.x11 && A.x12 >= B.x12 && A.x21 >= B.x21 && A.x22 >= B.x22) {
        return 1;
    }
    else return 0;
}

bool operator && (Matrix22 &A, Matrix22 &B)
{
    if(A.x11 && B.x11 && A.x12 && B.x12 && A.x21 && B.x21 && A.x22 && B.x22) {
        return 1;
    }
    else return 0;
}

bool operator || (Matrix22 &A, Matrix22 &B)
{
    if(A.x11 || B.x11 && A.x12 || B.x12 && A.x21 || B.x21 && A.x22 || B.x22) {
        return 1;
    }
    else return 0;
}

bool operator ! (Matrix22 &A)
{
    if(!A.x11 && !A.x12 && !A.x21 && !A.x22) {
        return 1;
    }
    else return 0;
}

