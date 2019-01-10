#include <iostream>
#include <string.h>

#include "node.h"
#include "list.h"
#include "student.h"

void add(LinkedList* list);
void print(LinkedList* list);
void sortinto(LinkedList* list, Student* s, int index);

int main(){
	LinkedList* list = new LinkedList();
	bool playing = true;
	char input[20];
	while(playing){
		std::cout << "Enter command(ADD, PRINT, EXIT): ";
		std::cin.get(input, 20);
		std::cin.clear();
		std::cin.ignore(100, '\n');
		if(strcmp(input, "add") == 0){
			add(list);
		}else if(strcmp(input, "print") == 0){
			print(list);
		}else if(strcmp(input, "exit") == 0){
			return 0;
		}
	}
	
	return 0;
}
void print(LinkedList* list){
	std::cout << "----------------------------" << std::endl;
	for(int i = 0; i < list->size(); i++){
		Student* s = list->at(i)->getValue();
		std::cout << s->getFirstName() << " " << s->getLastName() << ", " << s->getID() << ", " << s->getGPA() << std::endl;
	}
	std::cout << "----------------------------" << std::endl;
}

void add(LinkedList* list){
	Student* s = new Student();
	char* fname = s->getFirstName();
	char* lname = s->getLastName();
	int id, gpa;
	std::cout << "Enter the student's first name: ";
	std::cin.get(fname, 20);
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "Enter the student's last name: ";
	std::cin.get(lname, 20);
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "Enter the student's id: ";
	std::cin >> id;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "Enter the student's gpa: ";
	std::cin >> gpa;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	
	
	strcpy(s->getFirstName(), fname);
	strcpy(s->getLastName(), lname);
	s->setID(id);
	s->setGPA(gpa);
	
	sortinto(list, s, 0);
}

void sortinto(LinkedList* list, Student* s, int index){
	if(list->size() == 0){
		list->append(s);
		return;
	}
	if(list->at(index)->getValue()->getID() > s->getID()){
		list->insert(index, s);
		return;
	}
	sortinto(list, s, index++);
}