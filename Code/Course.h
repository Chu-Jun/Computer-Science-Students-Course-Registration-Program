#include <iostream>
#ifndef COURSE_H
#define COURSE_H
using namespace std;

class Course
{
	private:
   		//Declare a structure for the list
   		struct ListNode
   		{
      		string courseCode;
      		string courseName;
      		int courseUnit;
      		string courseType;
      		struct ListNode *next;
  		}; 

   		ListNode *headCourse;   //List head pointer

  		//Destroy function
   		void destroy();

	public:
   		//Constructor
   		Course()
      	{ headCourse = NULL; }

   		//Copy constructor
   		Course(const Course &);

   		//Destructor
   		~Course();

   		//List operations
   		void addCourse(string, string, int, string);
   		void insertCourse(string, string, int, string);
   		void deleteCourse(int);
   		
   		//Function to display the list of course available
   		void print();
   		void printCourseByType(int);
   		
   		//Function to search whether the course code input 
		//by user is exist in the course available
   		bool search(string, char, string&, int&);
};
#endif
