//
// Created by User on 13/11/2025.
//

#include "MataMvidia.h"

MataMvidia::MataMvidia(const std::string& movieName,
           const std::string& creatorName,
           Matrix* frames,
           int numFrames) : movieName(movieName), creatorName(creatorName), frames(frames), numFrames(numFrames){

}


Matrix& MataMvidia::operator[](const int i){
    return *(new Matrix ());
}

MataMvidia& MataMvidia::operator+=(const Matrix& other){
    return *this;
}

MataMvidia& MataMvidia::operator+(const MataMvidia& other) {
    return *this;
}

MataMvidia& MataMvidia::operator+=(const MataMvidia& other){
    return *this;
}


std::ostream& operator<<(std::ostream& out, const MataMvidia& other){
    return out;
}
