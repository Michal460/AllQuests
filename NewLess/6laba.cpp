#include <iostream>
#include <stdio.h>
#include <math.h>
#define MAX_SIZE	255
#pragma warning(disable : 4996)

class Fraction {
protected:
	int lenOst;
	char sing;
public:
	Fraction(int lo, char sing = '+') : lenOst(lo), sing(sing) {}
	void set_values(int l, char s) { lenOst = l; sing = s; }
	void get_values(int& l, char& s) { l = lenOst; s = sing; }
	virtual void func1(double num) { std::cout << "1 prog" << std::endl; }
};

class String : public Fraction {
	char* mas;
	int len;
public:
	String(int lo, char sing, int len) : Fraction(lo, sing), len(len) {}
	void func1(double num, char* mas) 
	{
		double ost = (num - (int)num) * pow(10, lenOst);
		get_values(lenOst, sing);
		sprintf(mas, "%c%.2f", sing, num);
	}
	void get_mas(char* m) { m = mas; }
	void get_len(int& l) { l = len; }
};

int main() {
	String* n1 = new String(3, '-', 15);
	char* mas = new char[255];
	int len;
	n1->func1(2.0 / 3.0, mas);
	n1->get_len(len);
	puts(mas);
}
