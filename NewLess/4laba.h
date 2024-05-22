#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

class matrix{
    int *arr = nullptr;
    int i, j;

public:
    explicit matrix(int i = 1, int j = 1);
    matrix(const matrix& obj);
    matrix(matrix&& obj) noexcept;
    ~matrix();

    friend ostream& operator<<(ostream &stream, const matrix& obj);
    friend istream& operator>>(istream &stream, matrix& obj);

    string toString() const;
    void fromString(const string& str);
    void set_i_j(const int& i, const int& j);

    matrix operator+(const matrix& obj);
    matrix operator-(const matrix& obj);
    matrix& operator=(matrix& obj);
    matrix operator*(const matrix& obj);
    matrix operator/(const int& num);
    matrix& operator+=(const matrix& obj);
    matrix& operator-=(const matrix& obj);
    bool operator==(const matrix& obj);
    bool operator!=(const matrix& obj);
};

#endif //MATRIX_H
