#include "MyPractice2.h"
#include <sstream>

matrix::matrix(int i, int j) { if(i>0) this->i = i; if(j>0) this->j = j; arr = new int[i*j]; }
matrix::matrix(const matrix& obj) : matrix(obj.i, obj.j) { for(int h = 0; h < obj.i*obj.j; h++) arr[h] = obj.arr[h]; }
matrix::matrix(matrix&& obj) noexcept : matrix(obj.i, obj.j) { arr = obj.arr; obj.arr = nullptr; }
matrix::~matrix(){ delete [] arr; }

ostream& operator<<(ostream &stream, const matrix& obj)
{
    for(int h1 = 0; h1 < obj.i; h1++)
    {
        for(int h2 = 0; h2 < obj.j; h2++)
        {
            stream << obj.arr[h1*obj.i+h2] << " ";
        }
        stream << endl;
    }
    return stream;
}

istream& operator>>(istream &stream, matrix& obj)
{
    for(int h = 0; h < obj.i*obj.j; h++) stream >> obj.arr[h];
    return stream;
}

string matrix::toString() const
{
    stringstream ss;
    for(int h1 = 0; h1 < i; h1++)
    {
        for(int h2 = 0; h2 < j; h2++)
        {
            ss << arr[h1*j + h2] << ' ';
        }
        ss << '\n';
    }
    return ss.str();
}

void matrix::set_i_j(const int& i, const int& j)
{
    this->i = i;
    this->j = j;
    this->arr = nullptr;
    this->arr = new int[this->i*this->j]; 
}

void matrix::fromString(const string& str)
{
    stringstream ss(str);
    for(int h1 = 0; h1 < i; h1++)
    {
        for(int h2 = 0; h2 < j; h2++)
        {
            ss >> arr[h1*j + h2];
        }
    }
}

matrix matrix::operator+(const matrix& obj)
{
    if(this->i != obj.i || this->j != obj.j) throw invalid_argument("Error: matrix1 row and width not equal matrix2 row and width");

    matrix newobj(obj.i, obj.j);
    for(int h = 0; h < obj.i*obj.j; h++) newobj.arr[h] = this->arr[h] + obj.arr[h];
    return newobj;
}

matrix matrix::operator-(const matrix& obj)
{
    if(this->i != obj.i || this->j != obj.j) throw invalid_argument("Error: matrix1 row and width not equal matrix2 row and width");

    matrix newobj(obj.i, obj.j);
    for(int h = 0; h < obj.i*obj.j; h++) newobj.arr[h] = this->arr[h] - obj.arr[h];
    return newobj;
}

bool matrix::operator==(const matrix& obj)
{
    if(this->i == obj.i && this->j == obj.j)
    { for(int h = 0; h < obj.i*obj.j; h++) if(this->arr[h] != obj.arr[h]) return 0; return 1;}
    return 0;
}

bool matrix::operator!=(const matrix& obj)
{
    if(this->i == obj.i && this->j == obj.j)
    { for(int h = 0; h < obj.i*obj.j; h++) if(this->arr[h] != obj.arr[h]) return 1; return 0;}
    return 1;
}

matrix matrix::operator/(const int& num)
{
    matrix newobj(this->i, this->j);
    for(int h = 0; h < this->i*this->j; h++) newobj.arr[h] = this->arr[h] / num;
    return newobj;
}

matrix matrix::operator*(const matrix& obj) 
{
    if (this->j != obj.i) 
        throw invalid_argument("Width of first matrix must be equal to height of second matrix");

    matrix newobj(this->i, obj.j);
    for(int i = 0; i < this->i*obj.j; i++) newobj.arr[i] = 0;
    for (int h = 0; h < this->i; h++) {
        for (int g = 0; g < obj.j; g++) {
            for (int k = 0; k < this->j; k++) {
                newobj.arr[obj.j * h + g] += (this->arr[this->j * h + k] * obj.arr[obj.j * k + g]);
            }
        }
    }
    return newobj;
}


matrix& matrix::operator+=(const matrix& obj)
{

    for(int h = 0; h < obj.i*obj.j; h++) this->arr[h] += obj.arr[h];
    return *this;
}

matrix& matrix::operator-=(const matrix& obj)
{

    for(int h = 0; h < obj.i*obj.j; h++) this->arr[h] -= obj.arr[h];
    return *this;
}

matrix& matrix::operator=(matrix& obj)
{
    this->i = obj.i;
    this->j = obj.j;
    this->arr = nullptr;
    this->arr = new int[i*j];
    for(int h = 0; h < obj.i*obj.j; h++) this->arr[h] = obj.arr[h];
    return *this;
}

// int main(void)
// {
//     matrix obj1(2, 2);
//     cin >> obj1;
//     matrix obj2(2, 2);
//     cin >> obj2;
//     // matrix obj3(3, 3);
//     // cin >> obj3;

//     matrix ob = obj1 * obj2;
//     cout << ob;
//     return 0;
// }
