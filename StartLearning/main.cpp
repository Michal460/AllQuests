//alt201 alt205 alt186
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

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

void add(int x, std::string s) {
	Tlist* el1 = new Tlist;
	el1->t.name = s;
	el1->t.electrific = x;
	el1->prev = nullptr;
	el1->next = nullptr;

	if (head == nullptr) {
		head = el1;
		last = el1;
		return;
	}
	else {
		last->next = el1;
		el1->prev = last;
		last = el1;
	}
}

void del(std::string s) {
	Tlist* h1 = head;
	while (h1->t.name != s) {
		h1 = h1->next;
	}
	if (h1 != head && h1 != last) {

		h1->prev->next = h1->next;
		h1->next->prev = h1->prev;
	}
	if (h1 == head) {
		head = h1->next;
	}
	if (h1 == last) {
		h1->prev->next = nullptr;
	}
}

void outputConsole() {
	Tlist* h1 = head;
	while (h1 != nullptr) {
		std::cout << h1->t.name << " " << h1->t.electrific << std::endl;
		h1 = h1->next;
	}
	system("pause");
}

void outputFile() {
	std::string s;
	std::cout << "Введите название файла, в который хотите записать данные(с расширением):" << std::endl;
	std::cin >> s;
	std::ofstream file(s);
	if (file.is_open()) {
		Tlist* h1 = head;
		while (h1 != nullptr) {
			file << h1->t.name << " " << h1->t.electrific << std::endl;
			h1 = h1->next;
		}
	}
	file.close();
}

void inputFile() {
	head = nullptr;
	last = nullptr;
	std::cout << "Введите название файла, с которого хотите считать данные(с расширением):" << std::endl;
	std::string s;
	std::cin >> s;
	std::ifstream file(s);
	if (file.is_open()) {
		std::string name;
		int electrific;
		while (file >> name >> electrific) {
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
	while (true) {
		std::cout << "Ввeдите название перегона и наименование электрофикации:" << std::endl;
		std::cin >> name;
		std::cin >> elec;
		if (elec == -1) break;
		add(elec, name);
	}
}

void search() {
	std::cout << "Введите наименование перегона:" << std::endl;
	std::string n;
	std::cin >> n;
	Tlist* h1 = head;
	while (h1 != nullptr) {
		if (h1->t.name == n) {
			break;
		}
		h1 = h1->next;
	}
	if (h1 == nullptr) {
		std::cout << "Данный элемент не найден" << std::endl;
		system("pause"); 
		system("cls");
		return;
	}
	std::cout << h1->t.name << " " << h1->t.electrific << std::endl;
	system("pause");
	system("cls");
}

bool presort1(Tab& a, Tab& b) {
	return a.name < b.name;
}

bool presort2(Tab& a, Tab& b) {
	return a.name > b.name;
}

void sort() {
	int flag;
	std::cout << "Сортировка по:\n1. Названию перегона\n2. Числу электрофикации" << std::endl;
	std::cin >> flag;
	std::vector<Tab> temp;
	if (flag == 1) {
		std::cout << "Сортировка по:\n1. от а - до я\n2. от я - до а" << std::endl;
		std::cin >> flag;
		if (flag == 1) {
			for (Tlist* cur = head; cur != nullptr; cur = cur->next) temp.push_back(cur->t);
			std::sort(temp.begin(), temp.end(), presort1);
			head = nullptr;
			last = nullptr;
			for (Tab t : temp) add(t.electrific, t.name);
		}
		if (flag == 2) {
			for (Tlist* cur = head; cur != nullptr; cur = cur->next) temp.push_back(cur->t);
			std::sort(temp.begin(), temp.end(), presort2);
			head = nullptr;
			last = nullptr;
			for (Tab t : temp) add(t.electrific, t.name);
		}
		return;
	}
	if (flag == 2) {
		std::cout << "Сортировка по:\n1. По возрастанию\n2. По убыванию" << std::endl;
		std::cin >> flag;
		if (flag == 1) {
			for (Tlist* cur = head; cur != nullptr; cur = cur->next) temp.push_back(cur->t);
			head = nullptr;
			last = nullptr;
			for (Tab t : temp) if (t.electrific == 0) add(t.electrific, t.name);
			for (Tab t : temp) if (t.electrific == 1) add(t.electrific, t.name);
		}
		if (flag == 2) {
			for (Tlist* cur = head; cur != nullptr; cur = cur->next) temp.push_back(cur->t);
			head = nullptr;
			last = nullptr;
			for (Tab t : temp) if (t.electrific == 1) add(t.electrific, t.name);
			for (Tab t : temp) if (t.electrific == 0) add(t.electrific, t.name);
		}
		return;
	}
}

int main() {
	setlocale(0, "Rus");
	int flag = 0;
	while (flag != 5) {
		std::cout << "Введите номер команды, которую вы хотите:" << std::endl;
		std::cout << "1. Ввод\n2. Вывод\n3. Редактирование\n4. Поиск\n5. Выход" << std::endl;
		int x;
		std::string n;
		std::cin >> flag;
		system("cls");
		if (flag == 1) {
			std::cout << "Осуществить ввод:\n1. С файла\n2. С клавиатуры" << std::endl;
			std::cin >> flag;
			if (flag == 1) inputFile();
			if (flag == 2) inputKeyboard();
			system("cls");
		}
		if (flag == 2) {
			std::cout << "Осуществить вывод:\n1. В файл\n2. В консоль" << std::endl;
			std::cin >> flag;
			if (flag == 1) outputFile();
			if (flag == 2) outputConsole();
			system("cls");
		}
		if (flag == 3) {
			std::cout << "Осуществить:\n1. Добавление\n2. Удаление\n3. Сортировка" << std::endl;
			std::cin >> flag;
			if (flag == 1) {
				std::cout << "Введите наименование электрофикации и название перегона:" << std::endl;
				std::cin >> x >> n;
				add(x, n);
			}
			if (flag == 2) {
				std::cout << "Введите название перегона:" << std::endl;
				std::cin >> n;
				del(n);
			}
			if (flag == 3) sort();
			system("cls");
		}
		if (flag == 4) search();
	}
	return 0;
}
