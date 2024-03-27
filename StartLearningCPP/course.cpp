#include "DataAll.h"

int main(){
	Personal_Data Emp1("Q", "q", "a", 1, 1, 2005, "a", 8);
	std::string surname, name, secname, job_title;
	int data_day, data_month, data_year, salary;
	Emp1.getSurname(surname);
	Emp1.getName(name);
	Emp1.getSecname(secname);
	Emp1.getDay(data_day);
	Emp1.getMonth(data_month);
	Emp1.getYear(data_year);
	Emp1.getJobTitle(job_title);
	Emp1.getSalary(salary);
	std::cout << surname << " " << name << " " << secname << " " << data_day 
	<< " " << data_month << " " << data_year << " " << job_title << " " << salary << std::endl;
}