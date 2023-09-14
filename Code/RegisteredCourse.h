#include <iostream>
#ifndef REGISTEREDCOURSE_H
#define REGISTEREDCOURSE_H
#include "Course.h"
using namespace std;

class RegisteredCourse: public Course
{
	private:
   		//Declare a structure for the list
   		struct RegisteredCourseListNode
   		{
      		string courseCode;
      		string courseName;
      		int courseUnit;
      		char courseType;
      		struct RegisteredCourseListNode *next;
  		}; 

   		RegisteredCourseListNode *head;   //List head pointer

  		//Destroy function
   		void destroy();

	public:
   		//Constructor
   		RegisteredCourse()
      	{ head = NULL; }

   		//Copy constructor
   		RegisteredCourse(const RegisteredCourse &);

   		//Destructor
   		~RegisteredCourse();

   		//List operations
   		void addRegisteredCourse(string, string, int, char);
   		bool insertRegisteredCourse(string, string, int, char);
   		void deleteRegisteredCourse(int);
   		
   		//Function to display the registered course list
   		void printRegistered();
   		void displayByType(char);
   		
   		//Function to check whether the course needed exist in the linked list
   		bool checkList();
   		bool checkType(char);
   		bool checkUnit(int);
};
#endif
