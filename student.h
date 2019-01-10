#pragma once
class Student{
	private:
		char* lname;
		char* fname;
		int id, gpa;
	public:
		Student();
		~Student();
	
		char* getLastName();
		char* getFirstName();
		int getID();
		int getGPA();
		
		void setID(int id);
		void setGPA(int gpa);
};