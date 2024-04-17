#include <iostream>

class TMyMatrix {
private:
    int total, count;
    int* matrix;

public:
    TMyMatrix(int t, int c) : total(t), count(c) { matrix = new int[total*count]{0}; }
    TMyMatrix(int* m, int t, int c) : TMyMatrix(t, c) { set_coords(m, total, count); }
    TMyMatrix(const TMyMatrix& other) : TMyMatrix(other.matrix, other.total, other.count) {}

    void set_coords(int* m, int len, int con) { for(int i = 0; i < total*con; i++) matrix[i] = (i<len*con) ? m[i] : 0; }

    int* get_coords() { return matrix; }
    void totalM(int& t) { t = total; }
    void countM(int& c) { c = count; }

    TMyMatrix operator+=(const TMyMatrix& other) { for(int i = 0; i < other.total*other.count; i++) matrix[i] += other.matrix[i]; }
    TMyMatrix operator-=(const TMyMatrix& other) { for(int i = 0; i < other.total*other.count; i++) matrix[i] -= other.matrix[i]; }
    TMyMatrix operator*=(const int& num) { for(int i = 0; i < total*count; i++) matrix[i] *= num; }
    TMyMatrix operator/=(const int& num) { for(int i = 0; i < total*count; i++) matrix[i] /= num; }
    bool operator==(const TMyMatrix& other) { for(int i = 0; i < other.total*other.count; i++) if(matrix[i] != other.matrix[i]) return 0; return 1; }
    bool operator!=(const TMyMatrix& other) { for(int i = 0; i < other.total*other.count; i++) if(matrix[i] == other.matrix[i]) return 0; return 1; }

    TMyMatrix operator/(const int num);
    TMyMatrix operator+(const TMyMatrix& other);
    TMyMatrix operator-(const TMyMatrix& other);
    TMyMatrix operator*(const TMyMatrix& other);

    ~TMyMatrix(){}
};

TMyMatrix TMyMatrix::operator/(const int num){
    if(num == 0) return;
    for(int i = 0; i < total*count; i++) matrix[i] = matrix[i]/num;
    return *this;
}

TMyMatrix TMyMatrix::operator+(const TMyMatrix& other){
    if(other.total != total || other.count != count) return;
    TMyMatrix res(total, count); 
    for(int i = 0; i < other.total*other.count; i++) res.matrix[i] = matrix[i] + other.matrix[i];
    return *this;
}

TMyMatrix TMyMatrix::operator-(const TMyMatrix& other){
    if(other.total != total || other.count != count) return;
    TMyMatrix res(total, count); 
    for(int i = 0; i < other.total*other.count; i++) res.matrix[i] = matrix[i] - other.matrix[i];
    return res;
}

TMyMatrix TMyMatrix::operator*(const TMyMatrix& other)
{
    if(other.total != count) return;
    TMyMatrix res(total, other.count);
    for(int i = 0; i < total; i++){
        for(int j = 0; j < other.count; j++){
            for(int k = 0; k < other.total; k++){
                res.matrix[total*i+j] += (matrix[total*i+k]*other.matrix[total*k+j]);
            }
        }
    }
    return res;
}

int main(void)
{
    int ar1[] = {1, 2, 3, 6, 5, 4, 7, 8, 9};
    int ar2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    TMyMatrix* matrix1 = new TMyMatrix(ar1, 3, 3);
    TMyMatrix* matrix2 = new TMyMatrix(ar2, 3, 3);
    //(*matrix1)+=(*matrix2);

    TMyMatrix res = *matrix1 * *matrix2;

    int* ares = res.get_coords();

    for(int i = 0; i < 9; i++) std::cout << ares[i] << " ";

    return 0;
}
