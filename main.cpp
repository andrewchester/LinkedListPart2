#include <iostream>
#include <string.h>

#include "node.h"
#include "list.h"
#include "student.h"

void add(LinkedList* list);
void print(LinkedList* list);
void sortinto(LinkedList*, Node*, Student*);
int average(LinkedList* list);
void deletenode(LinkedList*);

int main(){
	LinkedList* list = new LinkedList();
	bool playing = true;
	char input[20];
	while(playing){
		std::cout << "Enter command(ADD, PRINT, AVERAGE, DELETE, EXIT): ";
		std::cin.get(input, 20);
		std::cin.clear();
		std::cin.ignore(100, '\n');
		if(strcmp(input, "add") == 0){
			add(list);
		}else if(strcmp(input, "print") == 0){
			print(list);
		}else if(strcmp(input, "average") == 0){
			std::cout << average(list) << std::endl;
		}else if(strcmp(input, "delete") == 0){
			deletenode(list);
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
	int id, gpa;
	std::cout << "Enter the student's first name: ";
	std::cin.get(s->getFirstName(), 20);
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "Enter the student's last name: ";
	std::cin.get(s->getLastName(), 20);
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

	s->setID(id);
	s->setGPA(gpa);
	
	if(list->size() == 0){
		list->append(s);
		return;
	}
	if(list->at(0)->getValue()->getID() > s->getID()){
		list->insert(0, s);
		return;
	}
	
	sortinto(list, list->at(0), s);
}

void sortinto(LinkedList* list, Node* current, Student* s){
	if(!current){
		list->append(s);
		return;
	}
	
	if(current->getValue()->getID() > s->getID()){
		Node* newnode = new Node(s, current->previousNode(), current);
		current->previousNode()->setNext(newnode);
		current->setPrevious(newnode);
		return;
	}	
	sortinto(list, current->nextNode(), s);
}
void deletenode(LinkedList* list){
	int index;
	int id;
	std::cout << "Enter the ID: ";
	std::cin >> id;
	std::cin.clear();
	std::cin.ignore(100, '\n');
	
	Node* current = list->begin();
	int position = 0;
	while(current->nextNode() != 0){
		if(current->getValue()->getID() == id){
			break;
		}
		current = current->nextNode();
	}
	list->deleteStudent(current->getValue());
}
int average(LinkedList* list){
	int total = 0;
	for(int i = 0; i < list->size(); i++){
		total += list->at(i)->getValue()->getGPA();
	}
	return (total / list->size());
}