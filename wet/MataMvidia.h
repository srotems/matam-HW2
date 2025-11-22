//
// Created by User on 13/11/2025.
//

#ifndef MTM_HW2_WET_MATAMVIDIA_H
#define MTM_HW2_WET_MATAMVIDIA_H


#include "Matrix.h"

class MataMvidia {

    std::string m_movieName;
    std::string m_creatorName;
    Matrix* m_frames;
    int m_numFrames;

public:
    MataMvidia(const std::string& movieName,
               const std::string& creatorName,
               Matrix* frames,
               int numFrames);

    MataMvidia(const MataMvidia& other);
    ~MataMvidia();
    MataMvidia& operator=(const MataMvidia& other);
    Matrix& operator[](const int i);
    const Matrix& operator[](const int i) const;
    MataMvidia& operator+=(const MataMvidia& other);
    MataMvidia& operator+=(const Matrix& frame);
    MataMvidia operator+(const MataMvidia& other);
    friend std::ostream& operator<<(std::ostream& out, const MataMvidia& other);


    std::string getName() const { return m_movieName; }
    std::string getCreator() const { return m_creatorName; }
    int getNumFrames() const { return m_numFrames; }
};


#endif //MTM_HW2_WET_MATAMVIDIA_H
