//
// Created by itamarq on 06/04/2022.
//

#ifndef EX3_A_MATRIX_HPP
#define EX3_A_MATRIX_HPP

#include <iostream>
#include <vector>

namespace zich {
    class Matrix {
    public:
        double **mat;
        size_t rows;
        size_t columns;
        //initialization
        Matrix(std::vector<double> values, int rows, int cols);

        ~Matrix();

        //void operators
        void operator+=(const Matrix &other);
        void operator-=(const Matrix &other);
        void operator*=(const double scalar);
        void operator*=(const Matrix other) ;

        //Matrix operators
        Matrix operator-();
        Matrix operator+();

        //Matrix& operators
        Matrix& operator++();
        Matrix& operator--();
        Matrix& operator=(const Matrix &other);

        //input output friend operators
        friend std::ostream& operator<< (std::ostream& output, const Matrix& matrix);
        friend std::istream& operator>> (std::istream& input, Matrix& matrix);

        //comparison friend operators
        friend bool operator<(const Matrix& matrixA, const Matrix& matrixB);
        friend bool operator==(const Matrix& matrixA, const Matrix& matrixB);
        friend bool operator!=(const Matrix& matrixA, const Matrix& matrixB);
        friend bool operator<=(const Matrix& matrixA, const Matrix& matrixB);
        friend bool operator>(const Matrix& matrixA, const Matrix& matrixB);
        friend bool operator>=(const Matrix& matrixA, const Matrix& matrixB);

        //math friend operators
        friend Matrix operator-(const Matrix& matrixA,const Matrix& matrixB);
        friend Matrix operator+(const Matrix& matrixA,const Matrix& matrixB);
        friend Matrix operator*(const double scalar,const Matrix& matrix);
        friend Matrix operator*(const Matrix& matrix,const double scalar);
        friend Matrix operator*(const Matrix& matrixA,const Matrix& matrixB);

    };
}


#endif //EX3_A_MATRIX_HPP
