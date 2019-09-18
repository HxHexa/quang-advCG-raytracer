/* material.cpp - Implementation of funcs in material.hpp
 * Quang Tran - 9/15/19
 * */

#include "headers/material.hpp"

Material::Material() {
    Color color_(1, 1, 1);
    color = color_;
    diffuse = 1;
}

Color Material::getColor() const {
    return color;
}

//getter
int Material::getDiffuse() const {
    return diffuse;
}

//setter
void Material::setColor(Color c) {
    color = c;
}

//operator overloading
bool Material::operator== (const Material &m) const {
    return((diffuse == m.getDiffuse()) && (color == m.getColor()));
}