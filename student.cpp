#include "student.h"

Student::Student(){
	fname = new char[20];
	lname = new char[20];
}

Student::~Student(){
	delete fname;
	delete lname;
}

char* Student::getLastName(){
	return lname;
}
char* Student::getFirstName(){
	return fname;
}
int Student::getID(){
	return id;
}
int Student::getGPA(){
	return gpa;
}
void Student::setID(int newid){
	this->id = newid;
}
void Student::setGPA(int newgpa){
	this->gpa = newgpa;
}