#pragma once
class Student{
	private:
		char* lname;
		char* fname;
		int* id;
		int* gpa;
	public:
		Student();
		~Student();
	
		char* getLastName();
		char* getFirstName();
		int* getID();
		int* getGPA();
};