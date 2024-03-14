//alt201 alt205 alt186
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Personal_Data {
private:
	std::string surname;
	std::string name;
	std::string secname;
	int data_day;
	int data_month;
	int data_year;
	std::string job_title;
	int salary;
public:
	Personal_Data(std::string srn, std::string n, std::string scn, int dd, int dm, int dy, std::string jb, int s) {
		surname = srn;
		name = n;
		secname = scn;
		data_day = dd;
		data_month = dm;
		data_year = dy;
		job_title = jb;
		salary = s;
	}
	void input() {
		std::cout << surname << " " << name << " " << secname << " " << data_day << " " << data_month << " " << data_year << " " << job_title << " " << salary << std::endl;
	}
};

class EmpList {
private:
	std::vector<Personal_Data> Emp;
public:
	void add(Personal_Data Em) {
		Emp.push_back(Em);
	}
	void outputConsole() {
		std::cout << "╔═════════════════════════════════════════════════════════════════╗" << std::endl;
		setlocale(0, "rus");
		for (Personal_Data e : Emp) e.input();
	}
	void inputFile() {
		std::string nameFile;
		std::cin >> nameFile;
		std::ifstream file(nameFile);
		if (file.is_open()) {
			std::string surname;
			std::string name;
			std::string secname;
			int data_day, data_month, data_year;
			std::string job_title;
			int salary;
			while (file >> surname >> name >> secname >> data_day >> data_month >> data_year >> job_title >> salary) {
				Emp.push_back(Personal_Data(surname, name, secname, data_day, data_month, data_year, job_title, salary));
			}
		}
		else std::cout << "File didnt open" << std::endl;
	}

};

int main() {
	//setConsoleInput();
	//setConsoleOutput();
	EmpList list1;
	list1.inputFile();
	list1.outputConsole();
	return 0;
	std::cout << "═ ╣ ║ ╗ ╝ ╚ ╔ ╩ ╦ ╠ ═ ╬ ";
}
