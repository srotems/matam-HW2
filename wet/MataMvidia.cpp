//
// Created by User on 13/11/2025.
//

#include "MataMvidia.h"

#include "Utilities.h"

MataMvidia::MataMvidia(const std::string& movieName,
                       const std::string& creatorName,
                       Matrix* frames,
                       int numFrames) : m_movieName(movieName),
                                        m_creatorName(creatorName),
                                        m_frames(frames),
                                        m_numFrames(numFrames) {
    m_frames = new Matrix[m_numFrames];
    for (int i = 0; i < m_numFrames; ++i) {
        m_frames[i] = frames[i];
    }
}

MataMvidia::MataMvidia(const MataMvidia& other): m_movieName(other.m_movieName), m_creatorName(other.m_creatorName), m_numFrames(other.m_numFrames){
    m_frames = new Matrix[m_numFrames];
    for (int i = 0; i < m_numFrames; i++) {
        m_frames[i] = other.m_frames[i];
    }
}

MataMvidia::~MataMvidia(){
    delete[] m_frames;
}
MataMvidia& MataMvidia::operator=(const MataMvidia& other){
    if (this == &other)
        return *this;
    delete[] m_frames;

    m_numFrames = other.m_numFrames;
    m_creatorName = other.m_creatorName;
    m_movieName = other.m_movieName;

    m_frames = new Matrix[m_numFrames];
    for (int i = 0; i < m_numFrames; i++) {
        m_frames[i] = other.m_frames[i];
    }
    return *this;
}



Matrix& MataMvidia::operator[](const int i){
    if (i >= m_numFrames) {
        exitWithError(MatamErrorType::OutOfBounds);
    }

    return m_frames[i];
}

MataMvidia& MataMvidia::operator+=(const MataMvidia& other){
    Matrix* newFrames = new Matrix[m_numFrames + other.m_numFrames];
    int i = 0;
    for (; i < m_numFrames; ++i) {
        newFrames[i] = m_frames[i];
    }
    for (int j = 0; j < other.m_numFrames; j++, i++) {
        newFrames[i] = other.m_frames[j];
    }

    delete[] m_frames;
    m_frames = newFrames;
    m_numFrames += other.m_numFrames;
    return *this;
}

MataMvidia MataMvidia::operator+(const MataMvidia& other) {
    Matrix* newFrames;
    newFrames = new Matrix[m_numFrames + other.m_numFrames];
    int i = 0;
    for (; i < m_numFrames; ++i) {
        newFrames[i] = m_frames[i];
    }
    for (int j = 0; j < other.m_numFrames; j++, i++) {
        newFrames[i] = other.m_frames[j];
    }
    int newNumFrames = m_numFrames + other.m_numFrames;
    MataMvidia newMataMvidia(m_movieName, m_creatorName, newFrames, newNumFrames);
    delete[] newFrames;
    return newMataMvidia;
}

MataMvidia& MataMvidia::operator+=(const Matrix& frame){
    Matrix* newFrames;
    newFrames = new Matrix[m_numFrames + 1];
    int i = 0;
    for (; i < m_numFrames; ++i) {
        newFrames[i] = m_frames[i];
    }
    newFrames[m_numFrames] = frame;
    delete[] m_frames;
    m_frames = newFrames;
    ++m_numFrames;
    return *this;
}


std::ostream& operator<<(std::ostream& out, const MataMvidia& other){
    out << "Movie Name: " << other.m_movieName << std::endl;
    out << "Author: " << other.m_creatorName << std::endl;
    for (int i = 0; i < other.m_numFrames; ++i) {
        out << "Frame " << i << ":" << std::endl;
        out << other.m_frames[i] << std::endl;
    }
    out << "-----End of Movie -----" << std::endl;
    return out;
}
