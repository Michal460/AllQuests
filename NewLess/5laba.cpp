#include <iostream>

class Triad{
    int x1, x2, x3;

public:
    void up_x1(){ x1++; }
    void up_x2(){ x2++; }
    void up_x3(){ x3++; }
};

class Time: public Triad{
    unsigned hours, minutes, seconds;

public:
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    void up_x1(){ hours == 23 ? hours = 0 : hours++; }
    void up_x2(){ if(minutes == 59) { minutes = 0; up_x1(); } else minutes++; }
    void up_x3(){ if(seconds == 59) { seconds = 0; up_x2(); } else seconds++; }

    void set_time(unsigned int h, unsigned int m, unsigned int s){ hours = h; minutes = m; seconds = s; }
    void get_time(unsigned int& h, unsigned int& m, unsigned int& s){ h = hours; m = minutes; s = seconds; }

    ~Time(){}
};

int main(void){
    unsigned hours, minutes, seconds;
    Time* t1 = new Time(1, 17, 59);
    t1->up_x3();
    t1->up_x2();
    t1->up_x1();
    t1->get_time(hours, minutes, seconds);

    printf("%.2d:%.2d:%.2d", hours, minutes, seconds);
}
