//межстанционные - Москва-Пассажирская-Казанская — Раменское
#include <string>
#include <iostream>


struct Tab {
	std::string name;
	int salary;
};

struct Tlist {
	Tab t;
	Tlist* next;
	Tlist* prev;
};

Tlist* head = nullptr;
Tlist* last = nullptr;

void add(int x1, std::string s1){
	Tlist* el1 = new Tlist;
	el1->t.name = s1;
	el1->t.salary = x1;
	el1->prev = nullptr;
	el1->next = nullptr;

	if (head == nullptr) {
		head = el1;
		last = el1;
		return;
	}
	if (head != nullptr) {
		last->next = el1;
		el1->prev = last;
		last = el1;
	}
}

void print() {
	Tlist* h1 = head;
	while (h1 != nullptr) {
		std::cout << h1->t.name << " " << h1->t.salary << std::endl;
		h1 = h1->next;
	}
}

int main() {
	add(2000, "M");
	add(20000, "N");
	add(60000, "S");
	print();
}
