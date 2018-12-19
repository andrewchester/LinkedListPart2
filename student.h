#ifndef STUDENT_H
#define STUDENT_H

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

#endif