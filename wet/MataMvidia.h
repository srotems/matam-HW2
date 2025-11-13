//
// Created by User on 13/11/2025.
//

#ifndef MTM_HW2_WET_MATAMVIDIA_H
#define MTM_HW2_WET_MATAMVIDIA_H


#include "Matrix.h"

class MataMvidia {

    std::string movieName;
    std::string creatorName;
    Matrix* frames;
    int numFrames;

public:
    MataMvidia(const std::string& movieName,
               const std::string& creatorName,
               Matrix* frames,
               int numFrames);

    Matrix& operator[](const int i);
    MataMvidia& operator+=(const Matrix& other);

    MataMvidia& operator+(const MataMvidia& other);

    MataMvidia& operator+=(const MataMvidia& other);


    friend std::ostream& operator<<(std::ostream& out, const MataMvidia& other);

};


#endif //MTM_HW2_WET_MATAMVIDIA_H
