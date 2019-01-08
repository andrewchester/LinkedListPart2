#include <iostream>
#include <string.h>

#include "node.h"
#include "list.h"
#include "student.h"

void add(LinkedList* list);
void print(LinkedList* list);

int main(){
	LinkedList* list = new LinkedList();
	add(list);
	
	print(list);
	
	return 0;
}
void print(LinkedList* list){
	for(int i = 0; i < list->size(); i++){
		Student* s = list->at(i)->getValue();
		std::cout << s->getFirstName() << " " << s->getLastName() << ", " << *(s->getID()) << ", " << *(s->getGPA()) << std::endl;
	}
}

void add(LinkedList* list){
	Student* s = new Student();
	char fname[20];
	char lname[20];
	std::cout << "Enter the student's first name: ";
	std::cin.get(fname, 20);
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "Enter the student's last name: ";
	std::cin.get(lname, 20);
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "Enter the student's id: ";
	std::cin >> *(s->getID());
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "Enter the student's gpa: ";
	std::cin >> *(s->getGPA());
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	
	strcpy(s->getFirstName(), fname);
	strcpy(s->getLastName(), lname);
	
	std::cout << fname << std::endl;
	std::cout << s->getFirstName() << std::endl;
	
	list->append(s);
}