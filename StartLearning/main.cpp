#include <string>

struct Tab{
    std::string name;
    int salary;
};
struct Tlist{
    Tab t;
    Tlist* next;
    Tlist* prev;
}

Tlist* last;
Tlist* first;

void add(int x, std::string y){
    

int main(){
