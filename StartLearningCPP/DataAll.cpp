// //alt201 alt205 alt186
#include "DataAll.h"
//#include "Header2.h"

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
		std::cout << "║ " << std::left << std::setw(2) << count++ << " ║ " << std::setw(14) << std::left << surname << " ║ " << std::setw(10) << std::left << name << " ║ " << std::setw(24) << std::left << secname << " ║ " << std::setw(5)
			<< std::left << data_day << " ║ " << std::setw(5) << std::left << data_month
			<< " ║ " << std::setw(5) << std::left << data_year << " ║ " << std::setw(11) << std::left << job_title << " ║ " << std::setw(8) << std::left << salary << " ║" << std::endl;

		std::cout << "╠════╬════════════════╬════════════╬══════════════════════════╬═══════╬═══════╬═══════╬═════════════╬══════════╣" << std::endl;
	}
}

void EmpList::inputFile(std::string nameFile)
{
	std::ifstream file(nameFile);
	std::string surname, name, secname, job_title;
	int data_day, data_month, data_year, salary;
	if (file.is_open()) {
		while(file >> surname >> name >> secname >> data_day >> data_month >> data_year >> job_title >> salary)
		{
			Personal_Data* Emp = new Personal_Data(surname, name, secname, data_day, data_month, data_year, job_title, salary);
			addData(*Emp);
		}
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
			Emp.getJobTitle(job_title);
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
	std::cout << "╔════╦════════════════════════════════════════════════════════════════════════════════╦═════════════╦══════════╗" << std::endl;
	std::cout << "║    ║                Личные данные                                                   ║             ║          ║" << std::endl;
	std::cout << "║    ╠════════════════╦════════════╦══════════════════════════╦═══════════════════════╣  Должность  ║ Зарплата ║" << std::endl;
	std::cout << "║ №  ║ Фамилия        ║ Имя        ║ Отчество                 ║  Дата рождения        ║             ║          ║" << std::endl;
	std::cout << "║    ║                ║            ║                          ╠═══════╦═══════╦═══════╣             ║          ║" << std::endl;
	std::cout << "║    ║                ║            ║                          ║ Число ║ Месяц ║ Год   ║             ║          ║" << std::endl;
	std::cout << "╠════╬════════════════╬════════════╬══════════════════════════╬═══════╬═══════╬═══════╬═════════════╬══════════╣" << std::endl;
}

void EmpList::deleteData(std::string name)
{
	if(flag == true)
	{
		int i = 0;
		for (i; i < data.size(); i++)
		{
			std::string tempName;
			data[i].getName(tempName);
			if (tempName == name) break;
		}
		data.erase(data.begin() + i);
		return;
	}
	std::cout << "У вас нет доступа к удалению" << std::endl;
}

void EmpList::checkPassword(std::string pass)
{
	if(pass == password)
	{
		std::cout << "Пароль верен, теперь вы можете редактировать данные" << std::endl;
		flag = true;
		return;
	}
	std::cout << "Доступ к редактированию запрещён" << std::endl;
}

void EmpList::UserAddData(Personal_Data Emp)
{
	if(flag == true)
	{
		addData(Emp);
		return;
	}
	std::cout << "Доступ к редактированию запрещён" << std::endl;
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

void EmpList::sortAge() 
{ 
	if(flag == true)
	{
		std::sort(data.begin(), data.end(), sortAgeDown); 
		return;
	}
	std::cout << "Доступ к редактированию запрещён" << std::endl;
}

int main() {
	setlocale(LC_ALL, "");
	EmpList L1;

	int flag = 0;
    // L1.addData(Personal_Data("Ivanov", "Ivan", "Ivanich", 12, 3, 1985, "Menedjer", 50000));
	// L1.addData(Personal_Data("Petrova", "Anna", "Sergeevna", 5, 1, 1990, "Analitic", 60000));
	// L1.addData(Personal_Data("Smirnov", "Pavel", "Vladimirovich", 20, 9, 1982, "Developer", 70000));
	// L1.addData(Personal_Data("Kozlova", "Elena", "Alecsandrovna", 8, 12, 1988, "Disainer", 55000));
	// L1.addData(Personal_Data("Mihailov", "Dmitriy", "Ptrovics", 15, 6, 1978, "Buhgalter", 65000));
    // L1.addData(Personal_Data("Akima", "Sergey", "Sergeevich", 6, 3, 1965, "Diavol", 666666));
    // L1.addData(Personal_Data("Denisov", "B'ern", "Vizarevich", 19, 2, 1993, "Mainer", 8000));
    // L1.addData(Personal_Data("Straustrup", "B'ern", "-", 8, 8, 1962, "Jesus", 777777));
    // L1.addData(Personal_Data("Balakirev", "Sergey", "Kanerevich", 28, 5, 1977, "Prider", 444444));
    // L1.addData(Personal_Data("Tsal'", "Vitalya", "Papichev", 17, 11, 1989, "Besterst", 0));
	
	while (flag != 5)
	{
		system("clear");
		std::cout << "1. Ввод" << std::endl;
		std::cout << "2. Вывод" << std::endl;
		std::cout << "3. Редактирование" << std::endl;
		std::cout << "4. Обработка" << std::endl;
		std::cout << "5. Выход" << std::endl;
		std::cout << "Введите номер действия:" << std::endl;
		std::cin >> flag;
        system("clear");
		if (flag == 5) continue;
		if (flag == 1)
		{
			int flag1 = 0;
			std::cout << "1. Клавиатура" << std::endl;
			std::cout << "2. Файл" << std::endl;
			std::cout << "Введите номер действия:" << std::endl;
			std::cin >> flag1;
            system("clear");
			if (flag1 == 1)
			{
				std::cout << "Введите пароль: ";
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
            system("clear");
			if (flag1 == 1)
			{
				char pause;
                L1.table();
				L1.outputConsole();
				std::cout << "Введите любой символ, чтобы продолжить" << std::endl;
				std::cin >> pause;
			}
			if (flag1 == 2)
			{
				std::string name;
				std::cout << "Введите название файла, в который будет произведено вывод данных(с расширением):" << std::endl;
				std::cin >> name;
				L1.outputFile(name);
			}
		}
		if (flag == 3)
		{
			int flag1 = 0;
			std::cout << "1. Добавление" << std::endl;
			std::cout << "2. Удаление" << std::endl; 
		}
	}

	return 0;
}
