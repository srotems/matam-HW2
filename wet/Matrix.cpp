#include <iostream>
#include "Matrix.h"
#include "Utilities.h"
#include <math.h>

Matrix::Matrix() : m_row(0), m_col(0), m_matrixData(nullptr) {}
Matrix::Matrix( int n,  int m, int value) 
    : m_row(n), m_col(m)
{
    m_matrixData = new int[m_row * m_col];
    for (int i = 0; i < m_row * m_col; i++)
        m_matrixData[i] = value;
}
Matrix::Matrix( int n, int m)
    : m_row(n), m_col(m) 
{
    Matrix( m_row, m_col, 0);
}
Matrix::~Matrix() {
    delete[] m_matrixData;
}
Matrix::Matrix(const Matrix& other)     
    : m_row(other.m_row), m_col(other.m_col)    
 {
    m_matrixData = new int[m_row * m_col];
    for(int i = 0; i < m_row * m_col; i++)
        m_matrixData[i] = other.m_matrixData[i];
}

void Matrix::swap(Matrix& other) {
    std::swap(m_row, other.m_row);
    std::swap(m_col, other.m_col);
    std::swap(m_matrixData, other.m_matrixData);
}
Matrix& Matrix::operator=(Matrix other) {
    swap(other);
    return *this;
}

int& Matrix::operator()(int i, int j){
    if (i < 0 || i >= m_row || j < 0 || j >= m_col) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return m_matrixData[i * m_col + j];
}
const int& Matrix::operator()(int i, int j) const {
    if (i < 0 || i >= m_row || j < 0 || j >= m_col) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
        return m_matrixData[i * m_col + j];
}
std::ostream&  operator<<(std::ostream& os, const Matrix& m){

    for (int i = 0; i < m.m_row; i++) {
       os << "|";
         for (int j = 0; j < m.m_col; j++) {
            os << m(i, j) << "|";
         }
            os << "\n";
            
}
    return os;
}

Matrix Matrix::operator-() const{
    Matrix Negtive(m_row, m_col);
    for (int k = 0; k < m_row * m_col; ++k) {
        Negtive.m_matrixData[k] = -m_matrixData[k];
    }
    return Negtive;
}
Matrix& Matrix::operator+=(const Matrix& other){
    if (m_row != other.m_row || m_col != other.m_col) {
        exitWithError(MatamErrorType::UnmatchedSizes);  
        }
    for (int i = 0; i < m_row * m_col; i++)
        m_matrixData[i] += other.m_matrixData[i];
    return *this;
    }
Matrix& Matrix::operator-=(const Matrix& other){
    *this += (-other);
    return *this;
}
Matrix& Matrix::operator*=(const Matrix& other){
    if (m_col != other.m_row) 
        exitWithError(MatamErrorType::UnmatchedSizes);  
    
    Matrix Multi(m_row, other.m_col);
    for (int i = 0; i < m_row; i++) {
        for (int j = 0; j < other.m_col; j++) {
            for (int k = 0; k < m_col; k++) {
                Multi(i, j) += (*this)(i, k) * other(k, j);
            }
        }
    }
    *this = Multi;
    return *this;
}

Matrix operator+(const Matrix& a, const Matrix& b){
    Matrix addition = a;
    addition += b;
    return addition;
}
Matrix operator-(const Matrix& a, const Matrix& b){
    return a + -b;
}
Matrix operator*(const Matrix& a, const Matrix& b){
    Matrix multiplication = a;
    multiplication *= b;
    return multiplication;
}
Matrix& Matrix::operator*=(const int& number){
    for (int i = 0; i < m_row * m_col; i++)
        m_matrixData[i] *= number;
    return *this;
}
Matrix Matrix::operator*(const int& number) const{
    Matrix scalarMulti = *this;
    scalarMulti *= number;
    return scalarMulti;
}
Matrix operator*(const int& number, const Matrix& a){
    return a * number;
}
bool Matrix::operator==(const Matrix& other) const{
    if (m_row != other.m_row || m_col != other.m_col) {
        return false;
    }
    for (int i = 0; i < m_row * m_col; i++) {
        if (m_matrixData[i] != other.m_matrixData[i]) {
            return false;
        }
    }
    return true;
}
bool Matrix::operator!=(const Matrix& other) const{
    return !(*this == other);
}

Matrix Matrix::rotateClockwise() const{
    Matrix rotated(m_col, m_row);
    for (int i = 0; i < m_row; i++) {
        for (int j = 0; j < m_col; j++) {
            rotated(j, m_row - 1 - i) = (*this)(i, j);
        }
    }
    return rotated;
}
Matrix Matrix::rotateCounterClockwise() const{
    Matrix counterRotated(m_col, m_row);
    for (int i = 0; i < m_row; i++) {
        for (int j = 0; j < m_col; j++) {
            counterRotated(m_col - 1 - j, i) = (*this)(i, j);
        }
    }
    return counterRotated;
}
Matrix Matrix::transpose() const {
    Matrix transposed(m_col, m_row);
    for (int i = 0; i < m_row; i++) {
        for (int j = 0; j < m_col; j++) {
            transposed(j, i) = (*this)(i, j);                       
        }
    }
    return transposed;
}

double Matrix::CalcFrobeniusNorm(const Matrix& a) {
    double sum = 0.0;
    for (int i = 0; i < a.m_row * a.m_col; i++) {
        for (int j = 0; j < a.m_col; j++)
        sum += a(i, j) * a(i, j);
    }
    return std::sqrt(sum);
}
