#include <iostream>
#include <string>

using namespace std;

class Task {
private:
	enum status { start = 0, proceed = 1, end = 2 };
	string title;
	string descript;
	string dateStart;
	string dateEnd;
	status pos;
	Task(const Task&);
	Task& operator=(const Task&);
public:
	Task() {}
	Task(string t, string des, string dS, string dE, status pos)
	: title(t)
	, descript(des)
	, dateStart(dS)
	, dateEnd(dE)
	, pos(start) {}
	Task(Task&& obj) noexcept;

	Task& operator=(Task&& obj);

	static void delObj(Task* obj) { delete obj; cout << "obj is delete" << endl; }

protected:
	~Task(){}
};

Task& Task::operator=(Task&& obj) {

}

Task::Task(Task&& obj) noexcept {
	title = obj.title;
	descript = obj.descript;
	dateStart = obj.dateStart;
	dateEnd = obj.dateEnd;
	pos = obj.pos;
	Task::delObj(&obj);
}

Task& func(Task& obj) { return obj; }

int main(void)
{
	Task* obj1 = new Task();
	Task* obj2 = new Task();
	Task* obj3 = new Task();

	*obj3 = func(*obj2);

	return 0;
}
