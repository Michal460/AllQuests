#include <iostream>
#include <math.h>
#include <string>

#define PI 3.1415

class TTriangle
{
private:
    int lengths[3];

public:
    TTriangle() {}
    TTriangle(int a = 0, int b = 0, int c = 0) { lengths[0] = a; lengths[1] = b; lengths[2] = c; }
    TTriangle(const TTriangle& other) { lengths[0] = other.lengths[0]; lengths[1] = other.lengths[1]; lengths[2] = other.lengths[2]; }

    int Perimetr() { return lengths[0] + lengths[1] + lengths[2]; }

    double Area() { double p = Perimetr() / 2.0; return sqrt(p * (p - lengths[0]) * (p - lengths[1]) * (p - lengths[2])); }

    double AngleA() { return (180 / PI) * acos((double)(lengths[1] * lengths[1] + lengths[2] * lengths[2] - lengths[0] * lengths[0]) / (double)(2 * lengths[1] * lengths[2])); }
    double AngleB() { return (180 / PI) * acos((double)(lengths[0] * lengths[0] + lengths[2] * lengths[2] - lengths[1] * lengths[1]) / (double)(2 * lengths[0] * lengths[2])); }
    double AngleC() { return (180 / PI) * acos((double)(lengths[0] * lengths[0] + lengths[1] * lengths[1] - lengths[2] * lengths[2]) / (double)(2 * lengths[1] * lengths[0])); }

    std::string TType()
    {
        if (lengths[0] == lengths[1] && lengths[0] == lengths[2]) return "равносторонний";
        if (lengths[0] == lengths[1] && lengths[0] != lengths[2] || lengths[0] == lengths[2] && lengths[0] != lengths[1] || lengths[1] == lengths[2] && lengths[1] != lengths[0])
            return "равнобедренный";
        if (round(AngleA()) == 90 || round(AngleB()) == 90 || round(AngleC()) == 90) return "прямоугольный";
        if (lengths[0] + lengths[1] > lengths[2] && lengths[0] + lengths[2] > lengths[1] && lengths[1] + lengths[2] > lengths[0]) return "общего вида";
        return "не треугольник";
    }

    bool operator>=(TTriangle& obj) { this->Perimetr() >= obj.Perimetr() ? 1 : 0; }
    bool operator<=(TTriangle& obj) { this->Perimetr() <= obj.Perimetr() ? 1 : 0; }

    ~TTriangle() {}
};

int main(void)
{
    TTriangle* tr1 = new TTriangle(3, 3, 3);
    TTriangle tr2{ *tr1 };

    std::cout << tr1->AngleC() << std::endl;
    std::cout << tr1->TType() << std::endl;
    std::cout << tr1->Area() << std::endl;
    std::cout << tr1->Perimetr() << std::endl;

    std::cout << tr2.AngleC() << std::endl;
    std::cout << tr2.TType() << std::endl;
    std::cout << tr2.Area() << std::endl;
    std::cout << tr2.Perimetr() << std::endl;

    delete tr1;

    return 0;
}
