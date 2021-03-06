/* matrix.hpp - Header file for matrix class
 * Quang Tran - 9/24/2019
 * */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <math.h>
#include <memory>
#include "tuple.hpp"

class Matrix {
    private:
        int size;
        int detCalc;
        double det;
        std::shared_ptr<Matrix> inversion;
        std::vector<std::vector<double>> matrix_grid;
    public:
        //constructors
        Matrix();
        Matrix(int size_);

        //special named constructors
        static Matrix Identity();
        static Matrix Translation(double x, double y, double z);
        static Matrix Scaling(double x, double y, double z);
        static Matrix Rotation(char axis, double angleDeg);

        //filler
        void fillMatrix(double* valArray);

        //accesser
        double accessMatrix(int row, int col) const;
        int getSize() const;

        //operator == overload
        bool operator== (const Matrix &m) const;
        bool operator!= (const Matrix &m) const;

        //operator * overload
        Matrix operator* (const Matrix &m) const;
        Tuple operator* (const Tuple &t) const;
        Matrix operator* (const double &d) const;

        //calculation function
        double determinant();
        Matrix submatrix(int row, int col) const;
        double cofactor(int row, int col) const;

        //inverse
        Matrix inverse();

        //helper function
        double multMatRowTuple(const std::vector<double> matRow, const Tuple &t) const;
        Matrix transpose() const;
};

inline Matrix Matrix::Translation(double x, double y, double z) {
    Matrix out(4);
    double valArray[16] = {1, 0, 0, x,
                           0, 1, 0, y,
                           0, 0, 1, z,
                           0, 0, 0, 1};
    out.fillMatrix(valArray);
    return out;
}

inline Matrix Matrix::Scaling(double x, double y, double z) {
    Matrix out(4);
    double valArray[16] = {x, 0, 0, 0,
                           0, y, 0, 0,
                           0, 0, z, 0,
                           0, 0, 0, 1};
    out.fillMatrix(valArray);
    return out;
}

inline Matrix Matrix::Identity() {
    Matrix identity(4);
    double valArray[16] = {1, 0, 0, 0,
                           0, 1, 0, 0,
                           0, 0, 1, 0,
                           0, 0, 0, 1};
    identity.fillMatrix(valArray);
    return identity;
}

inline Matrix Matrix::Rotation(char axis, double angleDeg) {
    Matrix rotation(4);
    double a = angleDeg * M_PI / 180.0; //angleRad
    if (axis == 'x') {
        double valArray[16] = {1, 0, 0, 0,
                               0, cos(a), -sin(a), 0,
                               0, sin(a), cos(a), 0,
                               0, 0, 0, 1};
        rotation.fillMatrix(valArray);
    }
    else if (axis == 'y') {
        double valArray[16] = {cos(a), 0, sin(a), 0,
                               0, 1, 0, 0,
                               -sin(a), 0, cos(a), 0,
                               0, 0, 0, 1};
        rotation.fillMatrix(valArray);
    }
    else if (axis == 'z') {
        double valArray[16] = {cos(a), -sin(a), 0, 0,
                               sin(a), cos(a), 0, 0,
                               0, 0, 1, 0,
                               0, 0, 0, 1};
        rotation.fillMatrix(valArray);
    }
    return rotation;
}

#endif
