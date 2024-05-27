#include <iostream>
#include <string>

class matrix{
    int *arr = nullptr;
    int i, j;

public:
    explicit matrix(int i = 1, int j = 1) { if(i>0) this->i = i; if(j>0) this->j = j; arr = new int[i*j]; }
    matrix(int* m) { if(sizeof(m) == 4*i*j) for(int i = 0; i < i*j; i++) arr[i] = m[i]; }
    matrix(const matrix& obj) : matrix(obj.i, obj.j) { for(int h = 0; h < obj.i*obj.j; h++) arr[h] = obj.arr[h]; }
    matrix(matrix&& obj) noexcept : matrix(obj.i, obj.j) { arr = obj.arr; obj.arr = nullptr; }
    ~matrix() {delete [] arr; }

    friend std::ostream& operator<<(std::ostream &stream, const matrix& obj);
    friend std::istream& operator>>(std::istream &stream, matrix& obj);

    matrix operator+(const matrix& obj){
        if(this->i != obj.i || this->j != obj.j) throw std::invalid_argument("Error: matrix1 row and width not equal matrix2 row and width");

        matrix newobj(obj.i, obj.j);
        for(int h = 0; h < obj.i*obj.j; h++) newobj.arr[h] = this->arr[h] + obj.arr[h];
        return newobj;
    }
    matrix operator-(const matrix& obj){
        if(this->i != obj.i || this->j != obj.j) throw std::invalid_argument("Error: matrix1 row and width not equal matrix2 row and width");

        matrix newobj(obj.i, obj.j);
        for(int h = 0; h < obj.i*obj.j; h++) newobj.arr[h] = this->arr[h] - obj.arr[h];
        return newobj;
    }
    matrix& operator=(matrix& obj){
        this->i = obj.i;
        this->j = obj.j;
        this->arr = nullptr;
        this->arr = new int[i*j];
        for(int h = 0; h < obj.i*obj.j; h++) this->arr[h] = obj.arr[h];
        return *this;
    }
    matrix operator*(const matrix& obj){
        if (this->j != obj.i) throw std::invalid_argument("Width of first matrix must be equal to height of second matrix");

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
    matrix operator/(const int& num){
        matrix newobj(this->i, this->j);
        for(int h = 0; h < this->i*this->j; h++) newobj.arr[h] = this->arr[h] / num;
        return newobj;
    }
    matrix& operator+=(const matrix& obj){ for(int h = 0; h < obj.i*obj.j; h++) this->arr[h] += obj.arr[h]; return *this;}
    matrix& operator-=(const matrix& obj){for(int h = 0; h < obj.i*obj.j; h++) this->arr[h] -= obj.arr[h]; return *this;}
    bool operator==(const matrix& obj){
        if(this->i == obj.i && this->j == obj.j)
        { for(int h = 0; h < obj.i*obj.j; h++) if(this->arr[h] != obj.arr[h]) return 0; return 1;}
        return 0;
    }
    bool operator!=(const matrix& obj){
        if(this->i == obj.i && this->j == obj.j)
        { for(int h = 0; h < obj.i*obj.j; h++) if(this->arr[h] != obj.arr[h]) return 1; return 0;}
        return 1;
    }
};

std::ostream& operator<<(std::ostream &stream, const matrix& obj){
    for(int h1 = 0; h1 < obj.i; h1++)
    {
        for(int h2 = 0; h2 < obj.j; h2++)
        {
            stream << obj.arr[h1*obj.i+h2] << " ";
        }
        stream << std::endl;
    }
    return stream;
}

std::istream& operator>>(std::istream &stream, matrix& obj)
{
    for(int h = 0; h < obj.i*obj.j; h++) stream >> obj.arr[h];
    return stream;
}

int main(){
    matrix* obj1 = new matrix(2, 2);
    matrix* obj2 = new matrix(3, 1);
    std::cin >> *obj1 >> *obj2;
    matrix obj = (*obj1)*(*obj2);
    std::cout << obj;

    return 0;
}
