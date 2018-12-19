#include "student.h"

Student::Student(){

}

Student::~Student(){
	delete id;
	delete gpa;
	delete fname;
	delete lname;
}

char* Student::getLastName(){
	return lname;
}
char* Student::getFirstName(){
	return fname;
}
int* Student::getID(){
	return id;
}
int* Student::getGPA(){
	return gpa;
}