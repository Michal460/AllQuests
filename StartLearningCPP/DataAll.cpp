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

void EmpList::addData(Personal_Data Emp) { data.push_back(Emp); }
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

bool EmpList::sortAgeDown(Personal_Data &p1, Personal_Data &p2)
{
    int year1, year2, month1, month2, day1, day2;
    p1.getYear(year1);
    p2.getYear(year2);
    p1.getMonth(month1);
    p2.getMonth(month2);
    p1.getDay(day1);
    p2.getDay(day2);
    if(year1 == year2)
    {
        return month1 >= month2 ? 0 : 1;
        if(month1 == month2)
        {
            return day1 >= day2 ? 0 : 1;
        }
    }
    return year1 >= year2 ? 0 : 1;
}

void EmpList::sortAge(){ std::sort(data.begin(), data.end(), sortAgeDown); }

int main(){
	std::string surname, name, secname, job_title;
	int data_day, data_month, data_year, salary;
	EmpList L1;
    L1.addData(Personal_Data("Q", "q", "a", 91, 10, 2005, "w", 8000));
    Personal_Data Emp1("Q1", "q1", "a1", 21, 13, 2005, "a1", 8);
    Personal_Data Emp2("Q2", "q2", "a2", 65, 34, 213530, "a2", 8);
    Personal_Data Emp3("Q3", "q3", "a3", 42, 64, 208, "a3", 8);
    Personal_Data Emp4("Q4", "q4", "a4", 68, 91, 20042, "a4", 8);
    L1.addData(Emp1);
    L1.addData(Emp2);
    L1.addData(Emp3);
    L1.addData(Emp4);

    L1.sortAge();

    L1.table();
    L1.outputConsole();

	std::cout << char(205) << char(201) << std::endl;

	return 0;
}
