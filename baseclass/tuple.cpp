/* tuple.cpp - implementation for tuple.h header
 * Quang Tran - 9/4/2019
 * */

#include "headers/tuple.hpp"
#include "math.h"

//default constructor
Tuple::Tuple() {
    x = 0;
    y = 0;
    z = 0;
    w = 0;
}


//basic constructor
Tuple::Tuple(double x_, double y_, double z_, double w_) {
    x = x_;
    y = y_;
    z = z_;
    w = w_;
}

//point
Tuple Tuple::Point(double x_, double y_, double z_) {
    return Tuple(x_, y_, z_, 1.0);
}

//vector
Tuple Tuple::Vector(double x_, double y_, double z_) {
    return Tuple(x_, y_, z_, 0.0);
}

//getter functions
double Tuple::getx() const{
    return x;
}
double Tuple::gety() const{
    return y;
}
double Tuple::getz() const{
    return z;
}
double Tuple::getw() const{
    return w;
}

//isPoint check
bool Tuple::isPoint() {
    if (w == 0.0) return false;
    else return true;
}

//isVector check
bool Tuple::isVector() {
    if (w == 1.0) return false;
    else return true;
}

//operator == overloading
bool Tuple::operator==(const Tuple &a) const{
    if ((abs(x - a.x) <= EPSILON) &&
        (abs(y - a.y) <= EPSILON) &&
        (abs(z - a.z) <= EPSILON) &&
        (abs(w - a.w) <= EPSILON)) {
        return true;
    }
    else return false;
}

//operator + overloading
Tuple Tuple::operator+(const Tuple &a) const{
    Tuple out(x + a.x, y + a.y, z + a.z, w + a.w);
    return out;
}

//operator - overloading
Tuple Tuple::operator-(const Tuple &a) const{
    Tuple out(x - a.x, y - a.y, z - a.z, w - a.w);
    return out;
}

//operator negate overloading
Tuple Tuple::operator-() const{
    Tuple out(-x, -y, -z, -w);
    return out;
}

//operator assignment overloading
Tuple& Tuple::operator=(const Tuple &a) {
    //cheking for self-assignment
    if (this == &a) {
        return *this;
    }

    this -> x = a.x;
    this -> y = a.y;
    this -> z = a.z;
    this -> w = a.w;
    return *this;
}

//operator * overload
Tuple Tuple::operator*(const double &scalar) const{
    Tuple out(x * scalar,
              y * scalar,
              z * scalar,
              w * scalar);
    return out;
}

//operator / overload
Tuple Tuple::operator/(const double &scalar) const{
    Tuple out = *this * (1 / scalar);
    return out;
}

//other functions: calculations
//finds magnitude of vector
double Tuple::magnitude() const{
    double out = sqrt(x*x + y*y + z*z);
    return out;
}

//normalize a vector (magn = 1)
Tuple Tuple::normalize() const{
    double mag = this -> magnitude();
    return Tuple(x / mag, y / mag, z / mag, 0.0);
}
