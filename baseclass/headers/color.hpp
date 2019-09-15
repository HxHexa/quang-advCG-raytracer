/* color.h - header file for color class, which is a child of tuple
 * RGB color, value from 0 to 1
 * Quang Tran - 9/6/2019
 * */

#ifndef COLOR_H
#define COLOR_H

#include "tuple.hpp"

class Color : public Tuple {
    public:
        Color();
        Color(double red_, double green_, double blue_);

        //getter function
        double getR() const;
        double getG() const;
        double getB() const;

        //special operator overloading for color
        Color operator*(const double &scalar);
        Color operator*(const Color &a);
};

#endif