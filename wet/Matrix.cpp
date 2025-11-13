//
// Created by User on 13/11/2025.
//

#include "Matrix.h"
#include <ostream>

Matrix::Matrix() : m_numOfRow(0), m_numOfCol(0), m_matrixData(nullptr){}

Matrix::Matrix(int n, int m) : m_numOfRow(n), m_numOfCol(m) {
    m_matrixData = new int[m_numOfRow * m_numOfCol];
    for(int i = 0; i < m_numOfRow * m_numOfCol; i++){
        m_matrixData[i] = 0;
    }
}

Matrix::Matrix(int n, int m, int value) : m_numOfRow(n), m_numOfCol(m) {
    m_matrixData = new int[m_numOfRow * m_numOfCol];
    for (int i = 0; i < m_numOfRow * m_numOfCol; i++) {
        m_matrixData[i] = value;
    }
}

Matrix::Matrix(const Matrix& other): m_numOfRow(other.m_numOfRow), m_numOfCol(other.m_numOfCol){
    m_matrixData = new int[m_numOfRow * m_numOfCol];
    for (int i = 0; i < m_numOfRow * m_numOfCol; i++) {
        m_matrixData[i] = other.m_matrixData[i];
    }
}

Matrix::~Matrix(){
    delete[] m_matrixData;
}

Matrix& Matrix::operator=(const int i){
    return *this;
}

Matrix& Matrix::operator=(const Matrix& other){
    return *this;
}

Matrix& Matrix::operator()(const int x, const int y) {
    return *this;
}

Matrix& Matrix::operator+(const Matrix& other) {
    return *this;
}

bool Matrix::operator==(const Matrix& other) {
    return false;
}

bool Matrix::operator==(const int i) {
    return false;
}

Matrix& Matrix::operator*(const Matrix& other) {
    return *this;
}

Matrix& Matrix::operator*(const int i) {
    return *this;
}

Matrix& Matrix::operator*=(const int i) {
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    return *this;
}

Matrix& Matrix::operator-(const Matrix& other) {
    return *this;
}

Matrix& Matrix::operator-() {
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Matrix& other){
    return out;
}


Matrix& Matrix::rotateClockwise() {
    return *this;
}

Matrix &Matrix::rotateCounterClockwise() {
    return *this;
}

Matrix &Matrix::transpose() {
    return *this;
}



//Matrix& Matrix::operator*(const int x, const Matrix m) {
//    return *this;
//}
//Matrix operator*(int scalar, const Matrix& matrix) {
//    return new Matrix();
//}

//Matrix::Matrix operator*(int scalar, const Matrix& other){
//    return new Matrix();
//}






