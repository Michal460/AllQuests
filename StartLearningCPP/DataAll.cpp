// //alt201 alt205 alt186
//#include "DataAll.h"
#include "Header2.h"

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

void EmpList::inputConsole()
{
	std::string surname, name, secname, job_title;
	int data_day, data_month, data_year, salary;

	while (std::cin >> surname >> name >> secname >> data_day >> data_month >> data_year >> job_title >> salary)
	{
		addData(Personal_Data(surname, name, secname, data_day, data_month, data_year, job_title, salary));
	}
}

void EmpList::outputConsole()
{
	int count = 1;
	for (Personal_Data Emp : data) {
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
		std::cout << "║ " << count++ << " ║ " << std::setw(10) << std::left << surname << " ║ " << std::setw(10) << std::left << name << " ║ " << std::setw(24) << std::left << secname << " ║ " << std::setw(5)
			<< std::left << data_day << " ║ " << std::setw(5) << std::left << data_month
			<< " ║ " << std::setw(5) << std::left << data_year << " ║ " << std::setw(11) << std::left << job_title << " ║ " << std::setw(8) << std::left << salary << " ║" << std::endl;
		std::cout << "╠═══╬════════════╬════════════╬══════════════════════════╬═══════╬═══════╬═══════╬═════════════╬══════════╣" << std::endl;
	}
}
void EmpList::inputFile(std::string nameFile)
{
	std::ifstream file(nameFile);
	std::string surname, name, secname, job_title;
	int data_day, data_month, data_year, salary;
	if (file.is_open()) {
		file >> surname >> name >> secname >> data_day >> data_month >> data_year >> job_title >> salary;
		Personal_Data* Emp = new Personal_Data(surname, name, secname, data_day, data_month, data_year, job_title, salary);
		addData(*Emp);
	}
	else std::cout << "Файл не был открыт" << std::endl;
}
void EmpList::outputFile(std::string nameFile)
{
	std::ofstream file(nameFile);
	if (file.is_open()) {
		for (Personal_Data Emp : data) {
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
			file << surname << " " << name << " " << secname << " " << data_day << " " << data_month << " " << data_year << " " << job_title << " " << salary << std::endl;
		}
	}
	else std::cout << "Файл не был создан для записи данных" << std::endl;
}
void EmpList::table()
{
	// std::cout << "═ ╣ ║ ╗ ╝ ╚ ╔  ╦ с ═ ╬ ╠ ";
	//std::cout << char(201) << std::setfill(char(205)) << std::setw(4) << char(203) << std::setfill(char(205)) << std::setw(13) << char(203) << std::setfill(char(205)) << std::setw(13) << char(203)
	//<< std::setfill(char(205)) << std::setw(27) << char(203) << std::setfill(char(205)) << std::setw(20) << std::setfill(char(205)) << std::setw(24) << char(203) << std::setfill(char(205)) << std::setw(14) << char(203)
	//<< std::setfill(char(205)) << std::setw(11) << char(187) << std::endl;
	//std::cout << char(201) << std::setfill(char(205)) << std::setw(30) << char(209) << std::endl;
	std::cout << "╔═══╦════════════════════════════════════════════════════════════════════════════╦═════════════╦══════════╗" << std::endl;
	std::cout << "║   ║            Личные данные                                                   ║             ║          ║" << std::endl;
	std::cout << "║   ╠════════════╦════════════╦══════════════════════════╦═══════════════════════╣  Должность  ║ Зарплата ║" << std::endl;
	std::cout << "║ № ║ Фамилия    ║ Имя        ║ Отчество                 ║  Дата рождения        ║             ║          ║" << std::endl;
	std::cout << "║   ║            ║            ║                          ╠═══════╦═══════╦═══════╣             ║          ║" << std::endl;
	std::cout << "║   ║            ║            ║                          ║ Число ║ Месяц ║ Год   ║             ║          ║" << std::endl;
	std::cout << "╠═══╬════════════╬════════════╬══════════════════════════╬═══════╬═══════╬═══════╬═════════════╬══════════╣" << std::endl;
}
void EmpList::deleteData(std::string name)
{
	int i = 0;
	for (i; i < data.size(); i++)
	{
		std::string tempName;
		data[i].getName(tempName);
		if (tempName == name) break;
	}
	data.erase(data.begin() + i);
}

bool EmpList::sortAgeDown(Personal_Data& p1, Personal_Data& p2)
{
	int year1, year2, month1, month2, day1, day2;
	p1.getYear(year1);
	p2.getYear(year2);
	p1.getMonth(month1);
	p2.getMonth(month2);
	p1.getDay(day1);
	p2.getDay(day2);
	if (year1 == year2)
	{
		return month1 >= month2 ? 0 : 1;
		if (month1 == month2)
		{
			return day1 >= day2 ? 0 : 1;
		}
	}
	return year1 >= year2 ? 0 : 1;
}

void EmpList::sortAge() { std::sort(data.begin(), data.end(), sortAgeDown); }

int main() {
	EmpList L1;

	int flag = 0;

	while (flag != 5)
	{
		std::cout << "1. Ввод" << std::endl;
		std::cout << "2. Вывод" << std::endl;
		std::cout << "3. Редактирование" << std::endl;
		std::cout << "4. Обработка" << std::endl;
		std::cout << "5. Выход" << std::endl;

		std::cout << "Введите номер действия:" << std::endl;
		std::cin >> flag;
		if (flag == 5) continue;
		if (flag == 1)
		{
			int flag1 = 0;
			std::cout << "1. Клавиатура" << std::endl;
			std::cout << "2. Файл" << std::endl;
			std::cout << "Введите номер действия:" << std::endl;
			std::cin >> flag1;
			if (flag1 == 1)
			{
				std::cout << "Введите данные, которые хотите занести в таблицу" << std::endl;
				L1.inputConsole();
			}
			if (flag1 == 2)
			{
				std::string name;
				std::cout << "Введите название файла, с которого произойдёт считывание данных(с расширением):" << std::endl;
				std::cin >> name;
				L1.inputFile(name);
			}
		}
		if (flag == 2)
		{
			int flag1 = 0;
			std::cout << "1. Консоль" << std::endl;
			std::cout << "2. Файл" << std::endl;
			std::cout << "Введите номер действия:" << std::endl;
			std::cin >> flag1;
			if (flag1 == 1)
			{
				L1.outputConsole();
			}
			if (flag1 == 2)
			{
				std::string name;
				std::cout << "Введите название файла, в который будет произведено вывод данных(с расширением):" << std::endl;
				std::cin >> name;
				L1.outputFile(name);
			}
		}
	}

	std::cout << char(205) << char(201) << std::endl;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	L1.addData(Personal_Data("Привет", "q", "a", 91, 10, 2005, "w", 8000));
	L1.addData(Personal_Data("Q1", "q1", "a1", 21, 13, 2005, "a1", 8));
	L1.addData(Personal_Data("Q2", "q2", "a2", 65, 34, 21353, "a2", 8));
	L1.addData(Personal_Data("Q3", "q3", "a3", 42, 64, 208, "a3", 8));
	L1.addData(Personal_Data("Q4", "q4", "a4", 68, 91, 20042, "a4", 8));

	L1.table();

	L1.outputConsole();

	return 0;
}
