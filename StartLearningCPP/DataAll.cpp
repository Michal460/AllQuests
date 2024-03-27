// //alt201 alt205 alt186
#include "DataAll.h"

Personal_Data::Personal_Data(std::string srn, std::string n, std::string scn, int dd, int dm, int dy, std::string jt, int s) : surname(srn),
	name(n), secname(scn), data_day(dd), data_month(dm), data_year(dy), job_title(jt), salary(s) {};

void Personal_Data::getSurname(std::string& srn) { srn = surname; }
void Personal_Data::getName(std::string& n) { n = name; }
void Personal_Data::getSecname(std::string& scn) { scn = secname; }
void Personal_Data::getDay(int& day) { day = data_day; }
void Personal_Data::getMonth(int& month) { month = data_month; }
void Personal_Data::getYear(int& year) { year = data_year; }
void Personal_Data::getJobTitle(std::string& jt) { jt = job_title; }
void Personal_Data::getSalary(int& sal) { sal = salary; }

void Personal_Data::setSurname(std::string srn) { surname = srn; }
void Personal_Data::setName(std::string n) { name = n; }
void Personal_Data::setSecname(std::string scn) { secname = scn; }
void Personal_Data::setDay(int day) { data_day = day; }
void Personal_Data::setMonth(int month) { data_month = month; }
void Personal_Data::setYear(int year) { data_year = year; }
void Personal_Data::setJobTitle(std::string jt) { job_title = jt; }
void Personal_Data::setSalary(int sal) { salary = sal; }

Personal_Data::~Personal_Data() {};

void EmpList::addData(Personal_Data& Emp) { data.push_back(Emp); }
void EmpList::outputConsole()
{
    for(Personal_Data Emp: data){
		std::string surname, name, secname, job_title;
		int data_day, data_month, data_year, salary;
		Emp.getSurname(surname);
		Emp.getName(name);
		Emp.getSecname(secname);
		Emp.getDay(data_day);
		Emp.getMonth(data_month);
		Emp.getYear(data_year);
		Emp.getJobTitle(job_title);
		Emp.getSalary(salary);
		std::cout << "║ " << std::setw(15) << std::left << surname << " ║ " << name << std::setw(10) << std::left << " ║ " << secname << " ║ " << data_day << " ║ " << data_month 
		<< " ║ " << data_month << " ║ " << data_year << " ║ " << job_title << " ║ " << salary << " ║" << std::endl;
	}
}
void EmpList::inputFile()
{
    std::string nameFile;
	std::cout << "Введите название файла с расширением: " << std::endl;
	std::cin >> nameFile;
	std::ifstream file(nameFile);
	std::string surname, name, secname, job_title;
	int data_day, data_month, data_year, salary;
	if(file.is_open()){
		file >> surname >> name >> secname >> data_day >> data_month >> data_year  >> job_title >> salary;
		Personal_Data* Emp = new Personal_Data(surname, name, secname, data_day, data_month, data_year, job_title, salary);
		addData(*Emp);
	}
	else std::cout << "Файл не был открыт" << std::endl;
}
void EmpList::outputFile()
{
    std::string nameFile;
	std::cout << "Введите название файла с расширением: " << std::endl;
	std::cin >> nameFile;
	std::ofstream file(nameFile);
	if(file.is_open()){
		for(Personal_Data Emp: data){
			std::string surname, name, secname, job_title;
			int data_day, data_month, data_year, salary;
			Emp.getSurname(surname);
			Emp.getName(name);
			Emp.getSecname(secname);
			Emp.getSalary(salary);
			Emp.getDay(data_day);
			Emp.getMonth(data_month);
			Emp.getYear(data_year);
			Emp.getSalary(salary);
			file << surname << name << secname << data_day << data_month << data_year << job_title << salary;
		}
	}
	else std::cout << "Файл не был создан для записи данных" << std::endl;
}
void EmpList::table()
{
    // std::cout << "═ ╣ ║ ╗ ╝ ╚ ╔  ╦ с ═ ╬ ╠ ";
    std::cout << "╔═══╦═══════════════════════════════════════════════════════════════════════════╦═════════════╦══════════╗" << std::endl;
    std::cout << "║   ║            Личные данные                                                  ║             ║          ║" << std::endl;
    std::cout << "║   ╠════════════╦════════════╦══════════════════════════╦══════════════════════╣  Должность  ║ Зарплата ║" << std::endl;
    std::cout << "║ № ║ Фамилия    ║ Имя        ║ Отчество                 ║  Дата рождения       ║             ║          ║" << std::endl;
    std::cout << "║   ║            ║            ║                          ╠═══════╦═══════╦══════╣             ║          ║" << std::endl;
    std::cout << "║   ║            ║            ║                          ║ Число ║ Месяц ║ Год  ║             ║          ║" << std::endl;
    std::cout << "╠═══╬════════════╬════════════╬══════════════════════════╬═══════╬═══════╬══════╬═════════════╬══════════╣" << std::endl;
}
void EmpList::deleteData(std::string name)
{
	int i = 0;
	for(i; i < data.size();i++)
	{
		std::string tempName;
		data[i].getName(tempName);
		if(tempName == name) break;
	}
	data.erase(data.begin() + i);
}

int EmpList::sortAgeD(int day1, int month1, int year1, int day2, int month2, int year2)
{
	if(year1 > year2) return 1;
	if(year1 == year2)
	{
		if(month1 > month2) return 1;
		if(month1 == month2)
		{
			if(day1 > day2) return 1;
		}
	}
	return 0;
}

int EmpList::sortAgeH(int day1, int month1, int year1, int day2, int month2, int year2)
{
	if(year1 < year2) return 1;
	if(year1 == year2)
	{
		if(month1 < month2) return 1;
		if(month1 == month2)
		{
			if(day1 < day2) return 1;
		}
	}
	return 0;
}

void EmpList::sortDataAge(int (*arr) (int, int, int, int, int, int))
{
	for(int i = 0; i < data.size() - 1; i++)
	{	
		int day1, month1, year1;
		data[i].getDay(day1);
		data[i].getMonth(month1);
		data[i].getYear(year1);
		int tmpD1 = day1, tmpM1 = month1, tmpY1 = year1;
		int j_counter;
		for(int j = i + 1; j < data.size(); j++)
		{
			int day2, month2, year2;
			data[j].getDay(day2);
			data[j].getMonth(month2);
			data[j].getYear(year2);
			if(arr(day1, month1, year1, day2, month2, year2))
			{
				day1 = day2;
				month1 = month2;
				year1 = year2;
				j_counter = j;
			}
		}
		if(day1 != tmpD1 && month1 != tmpM1 && year1 != tmpY1)
		{
			Personal_Data temp = data[i];
			data[i] = data[j_counter];
			data[j_counter] = temp;
		}
	}
}

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
	EmpList L1;
	L1.table();
	// std::cout << surname << " " << name << " " << secname << " " << data_day 
	// << " " << data_month << " " << data_year << " " << job_title << " " << salary << std::endl;
	// std::cout << "Programm is end" << std::endl;

	return 0;
}
