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
	h1->prev->next = h1->next;
	h1->next->prev = h1->prev;
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
	std::cout << "Ввелите название файла, в который хотите записать данные(с расширением):" << std::endl;
	std::cin >> s;
	std::ofstream file(s);
	if (file.is_open()) {
		Tlist* h1 = head;
		while(h1 != nullptr){
			file << h1->t.name << " " << h1->t.electrific << std::endl;
			h1 = h1->next;
		}
	}
	file.close();
}

void inputFile() {
	std::cout << "Введите название файла, с которого хотите считать данные(с расширением):" << std::endl;
	std::string s;
	std::cin >> s;
	std::ifstream file(s);
	if (file.is_open()) {
		std::string name;
		int electrific;
		while(file >> name >> electrific){
			add(electrific, name);
		}
	}
	else {
		std::cout << "Файл не был открыт" << std::endl;
	}
	file.close();
}

void inputKeyboard() {
	std::cout << "Введите название перегона и наименование электрификации(0,1):" << std::endl;
	std::cout << "Чтобы окончить ввод, введите в наименовании перегона число -1" << std::endl;
	std::string name;
	int elec;
	while(true){
		std::cout << "Ввeдите название перегона и наименование электрофикации:" << std::endl;
		std::cin >> name;
		std::cin >> elec;
		if(elec == -1) break;
		add(elec, name);
	}
}

void search(){
	std::cout << "Введите наименование перегона:" << std::endl;
	std::string n;
	std::cin >> n;
	Tlist* h1 = head;
	while(h1->t.name != n) h1 = h1->next;
	std::cout << h1->t.name << " " << h1->t.electrific << std::endl;
}

int main() {
	setlocale(0, "Rus");
	// add(1, "Q1-Q2");
	// add(0, "Q2-Q4");
	// add(1, "Q5-Q9");
	// add(1, "Q6-Q7");
	// add(0, "Q3-Q1");
	// outputFile();
	int flag = 0;
	while (flag != 5){
		std::cout << "Введите номер команды, которую вы хотите:" << std::endl;
		std::cout << "1. Ввод\n2. Вывод\n3. Редактирование\n4. Поиск\n5. Выход" << std::endl;
		std::cin >> flag;
		if(flag == 1){
			std::cout << "Осуществить ввод:\n1. С файла\n2. С клавиатуры" << std::endl;
			std::cin >> flag;
			if(flag == 1) inputFile();
			if(flag == 2) inputKeyboard();
		}
	}
}
