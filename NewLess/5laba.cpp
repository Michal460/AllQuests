#include <iostream>

class Triad {
protected:
    unsigned hours, minutes, seconds;
public:
    Triad(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
    virtual void up_x1() { hours++; }
    virtual void up_x2() { minutes++; }
    virtual void up_x3() { seconds++; }
};

class Time : public Triad {

public:
    Time(int h, int m, int s) : Triad(h, m, s) {}

    virtual void up_x1() override { hours == 23 ? hours = 0 : hours++; }
    virtual void up_x2() override { if (minutes == 59) { minutes = 0; up_x1(); } else minutes++; }
    virtual void up_x3() override { if (seconds == 59) { seconds = 0; up_x2(); } else seconds++; }

    void set_time(unsigned int h, unsigned int m, unsigned int s) { hours = h; minutes = m; seconds = s; }
    void get_time(unsigned int& h, unsigned int& m, unsigned int& s) { h = hours; m = minutes; s = seconds; }

    ~Time() {}
};

int main(void) {
    unsigned hours, minutes, seconds;
    Time* t1 = new Time(1, 17, 59);
    t1->up_x3();
    t1->up_x2();
    t1->up_x1();
    t1->get_time(hours, minutes, seconds);

    printf("%.2d:%.2d:%.2d", hours, minutes, seconds);
}
