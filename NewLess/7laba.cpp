//z = x+i*y
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>

struct zArg{
    double a, b;
};

struct zTrig{
    double radius, angle;
};

class ZeroDivisionError : public std::exception{
    std::string msg;
public:
    ZeroDivisionError(const char* err) : msg(err) {}
    ZeroDivisionError(const ZeroDivisionError& obj) : msg(obj.msg) {}
    ~ZeroDivisionError() noexcept override {}

    const char* what() const noexcept override { return msg.c_str(); }
};

zTrig transform(zArg& obj) {
    zTrig newobj;
    newobj.radius = std::sqrt(obj.a*obj.a + obj.b*obj.b);
    if(obj.a == 0) throw ZeroDivisionError("You cannot div on zero!");
    newobj.angle = std::asin(obj.b/obj.a);
    return newobj;
}

int main()
{
    zArg obj{0.0, 1.0};
    zTrig nObj;
    try{
        nObj = transform(obj);
    }
    catch(ZeroDivisionError& obj){
        std::cout << obj.what() << std::endl;
        return 1;
    }

    std::cout << nObj.radius << " " << nObj.angle;

    return 0;
}
