#ifndef DATAALL_H
#define DATAALL_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <Windows.h>

class Personal_Data {
private:
	std::string surname, name, secname, job_title;
	int data_day, data_month, data_year, salary;
public:
	Personal_Data(std::string srn, std::string n, std::string scn, int dd, int dm, int dy, std::string jt, int s);

	void getSurname(std::string& srn);
	void getName(std::string& n);
	void getSecname(std::string& scn);
	void getDay(int& day);
	void getMonth(int& month);
	void getYear(int& year);
	void getJobTitle(std::string& jt);
	void getSalary(int& sal);

	void setSurname(std::string srn);
	void setName(std::string n);
	void setSecname(std::string scn);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setJobTitle(std::string jt);
	void setSalary(int sal);

	~Personal_Data();
};

class EmpList {
private:
	std::vector<Personal_Data> data;
public:
	void addData(Personal_Data Emp);
	void outputConsole();
	void inputFile(std::string);
	void outputFile(std::string);
	void inputConsole();
	void deleteData(std::string name);
	void sortAge();
	static bool sortAgeDown(Personal_Data& p1, Personal_Data& p2);
	void table();
};

#endif
