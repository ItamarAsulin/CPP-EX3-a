//
// Created by itamarq on 06/04/2022.
//

#include "Matrix.hpp"
#include <iostream>
#include <vector>


    //initialization
    zich::Matrix::Matrix(std::vector<double> values, int rows, int cols){

    }

    zich::Matrix::~Matrix(){

    }

    //void operators
    void zich::Matrix::operator+=(const Matrix &other) const{

    }
    void zich::Matrix::operator-=(const Matrix &other) const{

    }
    void zich::Matrix::operator*=(const double scalar) const{

    }
    void zich::Matrix::operator*=(const Matrix other) const{

    }
    //Matrix operator

    zich::Matrix zich::Matrix::operator-() const{
        return *this;
    }
   zich:: Matrix zich::Matrix::operator+() const{
       return *this;
    }
    //Matrix& operator

    zich::Matrix& zich::Matrix::operator++(){
        return *this;
    }
    zich::Matrix& zich::Matrix::operator--(){
        return *this;
    }
    zich::Matrix& zich::Matrix::operator=(const Matrix &other){
        return *this;
    }

    //input output friend operators
    std::ostream& zich::operator<< (std::ostream& output, const zich::Matrix& matrix){
        return output;
}
    std::istream& zich::operator>> (std::istream& input, zich::Matrix& matrix){
        return input;
}

    //comparison friend operators
    bool zich::operator<(const zich::Matrix& matrixA, const zich::Matrix& matrixB){
        return false;
    }
    bool zich::operator==(const zich::Matrix& matrixA, const zich::Matrix& matrixB){
        return false;
    }
    bool zich::operator!=(const zich::Matrix& matrixA, const zich::Matrix& matrixB){
        return false;
    }
    bool zich::operator<=(const zich::Matrix& matrixA, const zich::Matrix& matrixB){
        return false;
    }
    bool zich::operator>(const zich::Matrix& matrixA, const zich::Matrix& matrixB){
        return false;
    }
    bool zich::operator>=(const zich::Matrix& matrixA, const zich::Matrix& matrixB){
        return false;
    }

    //math friend operators
    zich::Matrix zich::operator-(const zich::Matrix& matrixA,const zich::Matrix& matrixB){
        return matrixA;
}
    zich::Matrix zich::operator+(const zich::Matrix& matrixA,const zich::Matrix& matrixB){
        return matrixA;
}
    zich::Matrix zich::operator*(const zich::Matrix& matrixA,const zich::Matrix& matrixB){
        return matrixA;
}
    zich::Matrix zich::operator*(const double scalar,const zich::Matrix& matrix){
        return matrix;
}
    zich::Matrix zich::operator*(const zich::Matrix& matrix,const double scalar){
        return matrix;
}

