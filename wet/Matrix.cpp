//
// Created by User on 13/11/2025.
//

#include "Matrix.h"
#include <ostream>
#include "Utilities.h"

Matrix::Matrix() : m_numOfRow(0), m_numOfCol(0), m_matrixData(nullptr){}

Matrix::Matrix(int n, int m) : m_numOfRow(n), m_numOfCol(m) {
    m_matrixData = new double [m_numOfRow * m_numOfCol];
    for(int i = 0; i < m_numOfRow * m_numOfCol; i++){
        m_matrixData[i] = 0;
    }
}

Matrix::Matrix(int n, int m, int value) : m_numOfRow(n), m_numOfCol(m) {
    m_matrixData = new double[m_numOfRow * m_numOfCol];
    for (int i = 0; i < m_numOfRow * m_numOfCol; i++) {
        m_matrixData[i] = value;
    }
}

Matrix::Matrix(const Matrix& other): m_numOfRow(other.m_numOfRow), m_numOfCol(other.m_numOfCol){

    m_matrixData = new double[m_numOfRow * m_numOfCol];
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
    if (this == &other)
        return *this;

    delete[] m_matrixData;

    m_numOfCol = other.m_numOfCol;
    m_numOfRow = other.m_numOfRow;
    m_matrixData = new double[m_numOfRow * m_numOfCol];
    for (int i = 0; i < m_numOfRow * m_numOfCol; i++) {
        m_matrixData[i] = other.m_matrixData[i];
    }
    return  *this;
}

double& Matrix::operator()(const int x, const int y) const{
    return this->m_matrixData[m_numOfCol * x + y];
}

Matrix Matrix::operator+(const Matrix& other) const{
    if(m_numOfCol != other.m_numOfCol || m_numOfRow != other.m_numOfRow)
        exitWithError(MatamErrorType::UnmatchedSizes);
    Matrix newMatrix(m_numOfRow, m_numOfCol);
    for (int i = 0; i < other.m_numOfRow; ++i) {
        for (int j = 0; j < other.m_numOfCol; ++j) {
            newMatrix(i, j) = (*this)(i, j) + other(i, j);
        }
    }
    return newMatrix;
}

bool Matrix::operator==(const Matrix& other) {
    if(m_numOfCol != other.m_numOfCol || m_numOfRow != other.m_numOfRow)
        return false;
    for (int i = 0; i < other.m_numOfRow; ++i) {
        for (int j = 0; j < other.m_numOfCol; ++j) {
            if((*this)(i, j) != other(i, j))
                return false;
        }
    }    return true;
}

bool Matrix::operator!=(const Matrix& other){
    if(m_numOfCol != other.m_numOfCol || m_numOfRow != other.m_numOfRow)
        return true;
    for (int i = 0; i < other.m_numOfRow; ++i) {
        for (int j = 0; j < other.m_numOfCol; ++j) {
            if((*this)(i, j) != other(i, j))
                return true;
        }
    }    return false;
}

bool Matrix::operator==(const int i) {
    return false;
}

Matrix Matrix::operator*(const Matrix& other) const{
    if(this->m_numOfCol != other.m_numOfRow)
        exitWithError(MatamErrorType::UnmatchedSizes);
    Matrix newMatrix(this->m_numOfCol, other.m_numOfRow);
    for (int i = 0; i < m_numOfCol; ++i) {
        for (int j = 0; j < other.m_numOfRow; ++j) {
            double sum = 0;
            for (int k = 0; k < m_numOfCol; ++k) {
                sum = sum + (*this)(i, k) * other(k, j);
            }
            newMatrix(i, j) = sum;
        }
    }
    return newMatrix;
}

Matrix& Matrix::operator*(const int scalar) {
    for (int i = 0; i < m_numOfRow; ++i) {
        for (int j = 0; j < m_numOfCol; ++j) {
            (*this)(i, j) = scalar * (*this)(i, j);
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const int scalar) {
    *this = *this * scalar;
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other;
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    *this = *this * other;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    *this = *this - other;
    return *this;
}

Matrix Matrix::operator-(const Matrix& other) const{
    if(m_numOfCol != other.m_numOfCol || m_numOfRow != other.m_numOfRow)
        exitWithError(MatamErrorType::UnmatchedSizes);
    Matrix newMatrix(m_numOfRow, m_numOfCol);
    for (int i = 0; i < other.m_numOfRow; ++i) {
        for (int j = 0; j < other.m_numOfCol; ++j) {
            newMatrix(i, j) = (*this)(i, j) - other(i, j);
        }
    }
    return newMatrix;
}

Matrix& Matrix::operator-() {
    for (int i = 0; i < m_numOfRow; ++i) {
        for (int j = 0; j < m_numOfCol; ++j) {
            (*this)(i, j) = -(*this)(i, j);
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Matrix& other){
    for (int i = 0; i < other.m_numOfRow; ++i) {
        for (int j = 0; j < other.m_numOfCol; ++j) {
            out << "|" << other(i, j);
        }
        out << "|" << std::endl;
    }
    return out;
}

Matrix& operator*(int scalar, Matrix& other){
    return (other * scalar);
}



Matrix Matrix::rotateClockwise() {
    Matrix newMatrix(m_numOfCol, m_numOfRow);
    for (int i = 0; i < m_numOfRow; i++) {
        for (int j = 0; j < m_numOfCol; ++j) {
            newMatrix(j, m_numOfRow - 1 - i) = (*this)(i, j);
        }
    }
    return newMatrix;
}

Matrix Matrix::rotateCounterClockwise() {
    Matrix newMatrix(m_numOfCol, m_numOfRow);
    for (int i = 0; i < m_numOfRow; i++) {
        for (int j = 0; j < m_numOfCol; ++j) {
            newMatrix(m_numOfCol - 1 - j, i) = (*this)(i, j);
        }
    }
    return newMatrix;
}

Matrix Matrix::transpose() {
    Matrix newMatrix(m_numOfCol, m_numOfRow);
    for (int i = 0; i < m_numOfRow; ++i) {
        for (int j = 0; j < m_numOfCol; ++j) {
            newMatrix(i, j) = (*this)(j, i);
        }
    }
    return newMatrix;
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






