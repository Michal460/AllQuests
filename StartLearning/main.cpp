//межстанционные - Москва-Пассажирская-Казанская — Раменское
#include <string>
#include <iostream>
#include <fstream>

struct Tab {
	std::string name;
	int electrific;
};

struct Tlist {
	Tab t;
	Tlist* next;
	Tlist* prev;
};

Tlist* head = nullptr;
Tlist* last = nullptr;

void add(int x, std::string s){
	Tlist* el1 = new Tlist;
	el1->t.name = s;
	el1->t.electrific = x;
	el1->prev = nullptr;
	el1->next = nullptr;

	if (head == nullptr) {
		head = el1;
		last = el1;
		return;
	} else {
		last->next = el1;
		el1->prev = last;
		last = el1;
	}
}

void del(int x, std::string s) {
	Tlist* h1 = head;
	while (h1->t.name != s && h1->t.electrific != x) {
		h1 = h1->next;
	}
	std::cout << "el founded" << std::endl;
	//изменения не вступают в силу
	h1->prev->next = h1->next;
	h1->next->prev = h1->prev;
	std::cout << "el edited" << std::endl;
	//--------------
}

void outputConsole() {
	Tlist* h1 = head;
	while (h1 != nullptr) {
		std::cout << h1->t.name << " " << h1->t.electrific << std::endl;
		h1 = h1->next;
	}
}

void outputFile() {
	std::string s;
	std::cout << "Ввелите название файла, в который хотите записать данные:" << std::endl;
	std::cin >> s;
	std::ofstream file(s);
	if (file.is_open()) {

	}
	file.close();
}

void inputFile(std::string s) {
	std::ifstream file(s);
	if (file.is_open()) {
		
	}
	else {
		std::cout << "Файл не был открыт" << std::endl;
	}
	file.close();
}

void inputKeyboard() {
	std::cout << "Введите название перегона и наименование электрификации(0,1):" << std::endl;
	std::cout << "Чтобы окончить ввод, введите: Окончить";
	std::string name, flag;
	int elec;
	while(flag != "Окончить"){
		std::cin >> name >> elec;
		add(elec, name);
	}
}

int main() {
	setlocale(0, "Rus");
	add(1, "Q1-Q2");
	add(0, "Q2-Q4");
	add(1, "Q5-Q9");
	add(1, "Q6-Q7");
	del(0, "Q2-Q4");
	outputConsole();
}
