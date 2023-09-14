#include <string>
#include "RegisteredCourse.h"
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

class Student{
	private:
		string name;				//declare variable name as string
		int matricNum, year;		//declare variable matricNum and year as int
		long int phoneNum;			//declare variable phoneNum as long int
		RegisteredCourse registerC;	//create object of RegisteredCourse class (COMPOSITION)

	public:
	
		//function prototype for all functions in Student class
		//Constructor
		Student();
	
		//Constructor with pass arguments
		Student(string, int, int, long int);
	
		//Destructor
		~Student();
		
		//Mutator Function for each of the variable
		void setInfo(string, int, int, long int);
		void setName(string);
		void setMatric(int);
		void setPhoneNum(long int);
		void setYear(int);
	
		//Accessor Function to reach each of the variable
		string getName();
		int getMatric();
		long int getPhoneNum();
		int getYear();
		void getInfo(string&, int&, int&, long int&);
	
		//Function to make use of function in RegisteredCourse class
		void registerManual(string, string, int, char);
		void dropCourse(int);
		bool checkNull();
		void print();
		void printByType(int);
	
		//Function to display the student's (user) information
		void studentInfoPrint();	
};
#endif
