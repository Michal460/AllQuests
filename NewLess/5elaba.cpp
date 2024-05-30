#include <iostream>
#include <iomanip>

class Triad {
protected:
    int x1, x2, x3;
public:
    Triad(int x1, int x2, int x3) : x1(x1), x2(x2), x3(x3) {}

    virtual void up_x1() { x1++; }
    virtual void up_x2() { x2++; }
    virtual void up_x3() { x3++; }

    virtual ~Triad(){}
};

class Time : public Triad {
public:
    Time(int hours, int minutes, int seconds) : Triad(hours, minutes, seconds) {}

    virtual void up_x1() override { x1 == 23 ? x1 = 0 : x1++; }
    virtual void up_x2() override { if (x2 == 59) { x2 = 0; up_x1(); } else x2++; }
    virtual void up_x3() override { if (x3 == 59) { x3 = 0; up_x2(); } else x3++; }

    void set_time(int& h, int& m, int& s) { x1 = h; x2 = m; x3 = s; }
    void get_time(int& h, int& m, int& s) { h = x1; m = x2; s = x3; }

    virtual ~Time() override {}

    friend std::istream& operator>>(std::istream& stream, Time& obj);
    friend std::ostream& operator<<(std::ostream& stream, Time& obj);
};

std::istream& operator>>(std::istream& stream, Time& obj)
{
    int h, m, s;
    stream >> h >> m >> s;
    obj.set_time(h, m, s);
    return stream;
}

std::ostream& operator<<(std::ostream& stream, Time& obj)
{
    int h, m, s;
    obj.get_time(h, m, s);
    stream << std::setw(1) << std::setfill('0') << h << ":" << std::setw(2) << std::setfill('0') << m << ":" << std::setw(2) << std::setfill('0') << s << std::endl;
    return stream;
}

int main(void) {
    int hours, minutes, seconds;
    Time* t1 = new Time(1, 17, 59);
    t1->up_x3();
    t1->up_x2();
    t1->up_x1();
    t1->get_time(hours, minutes, seconds);

    std::cout << *t1;

    //printf("%.2d:%.2d:%.2d", hours, minutes, seconds);
}
