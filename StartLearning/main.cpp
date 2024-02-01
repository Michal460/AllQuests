#include "iostream"
#include "string"

class Person{
private:
    std::string name;
    int age;
public:
    Person(std::string n, int a) : age(a), name(n) {};
    void getInfo(){ std::cout << name << " " << age << " "; }
};

class Student : public Person{
private:
    int studentID;
public:
    Student(std::string n, int a, int id) : Person(n,a), studentID(id) {};
    void getInfo(){
        Person::getInfo();
        std::cout << studentID;
    }
};

int main(){
    Student st("Michael", 18, 1153);
    st.getInfo();
}