
#ifndef MTM_HW2_WET_MATRIX_H
#define MTM_HW2_WET_MATRIX_H
#include <iostream>

class Matrix{
    private:
        int m_row;
        int m_col;
        int* m_matrixData;

    public:
        Matrix();
        Matrix( int n,  int m);
        Matrix( int n,  int m, int value);
        Matrix(const Matrix& other);
        Matrix& operator=(Matrix other);
        ~Matrix();
        void swap(Matrix& other);
        int& operator()(int i, int j);
        const int& operator()(int i, int j) const;
        friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
        Matrix operator-() const;
        Matrix& operator+=(const Matrix& other);
        Matrix& operator-=(const Matrix& other);
        Matrix& operator*=(const Matrix& other);
        Matrix& operator*=(const int& number);
        Matrix operator*(const int& number) const;
        bool operator==(const Matrix& other) const;
        bool operator!=(const Matrix& other) const;

        Matrix rotateClockwise() const;
        Matrix rotateCounterClockwise() const;
        Matrix transpose() const;

        static double CalcFrobeniusNorm(const Matrix& m);   

        
};
Matrix operator+(const Matrix& a, const Matrix& b);
Matrix operator-(const Matrix& a, const Matrix& b);
Matrix operator*(const Matrix& a, const Matrix& b);
Matrix operator*(const int& number, const Matrix& a);

#endif MTM_HW2_WET_MATRIX_H
