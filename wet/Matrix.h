//
// Created by User on 13/11/2025.
//

#ifndef MTM_HW2_WET_MATRIX_H
#define MTM_HW2_WET_MATRIX_H
#include <ostream>

class Matrix
{
private:
    int m_numOfRow;
    int m_numOfCol;
    int* m_matrixData;
public:
    Matrix();
    Matrix(int m_numOfRow, int m_numOfCol);
    Matrix(int m_numOfRow, int m_numOfCol, int value);
    Matrix(const Matrix& other);
    ~Matrix();


    Matrix& operator=(const Matrix& other);
    Matrix& operator=(const int i);
    Matrix& operator+(const Matrix& other);
    Matrix& operator()(const int x, const int y);
    bool operator==(const Matrix& other);
    bool operator==(const int i);
    Matrix& operator*(const Matrix& other);
    Matrix& operator*(const int i);
    Matrix& operator*=(const int i);
    Matrix& operator+=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator-(const Matrix& other);
    Matrix& operator-();
    friend std::ostream& operator<<(std::ostream& out, const Matrix& other);
    // Matrix& operator*(const int x, const Matrix m);
    //  Matrix operator*(int scalar, const Matrix& other);
    Matrix& rotateClockwise();

    Matrix &rotateCounterClockwise();

    Matrix &transpose();
};



#endif //MTM_HW2_WET_MATRIX_H
