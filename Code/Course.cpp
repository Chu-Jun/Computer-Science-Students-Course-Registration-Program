#include <iostream>
#include <iomanip>
#include "Course.h"
using namespace std;

//Copy constructor                                
Course::Course(const Course &listObj)
{
    ListNode *nodePtr = NULL;

    //Initialize the head pointer.
    headCourse = NULL;

    //Point to the other object's head.
    nodePtr = listObj.headCourse;

    //Traverse the other object.
    while (nodePtr)
    {
    	//Append a copy of the other object's
    	//node to this list.
    	addCourse(nodePtr->courseCode, nodePtr->courseName,nodePtr->courseUnit,nodePtr->courseType);

		//Go to the next node in the other object.
    	nodePtr = nodePtr->next;
    }
}

//Destructor function to delete every node in the list.   
Course::~Course()
{
	//call the destroy() function to delete the node
	destroy();
}


//addCourse function appends a node that contain the        
//value passed by arguments, to the end of the list.   
void Course::addCourse(string code, string name, int unit, string type)
{
	ListNode *newNode, *nodePtr = NULL;

	//Allocate a new node & store the variables
	newNode = new ListNode;
	newNode->courseCode = code;
	newNode->courseName = name;
	newNode->courseUnit = unit;
	newNode->courseType = type;
	newNode->next = NULL;

	//If there are no nodes in the list
	//make newNode the first node
	if (!headCourse)
    	headCourse = newNode;
	else  //Otherwise, insert newNode at end
    {
    	//Initialize nodePtr to head of list
    	nodePtr = headCourse;

    	//Find the last node in the list
    	while (nodePtr->next)
        	nodePtr = nodePtr->next;

    	//Insert newNode as the last node
    	nodePtr->next = newNode;
    }
}


//The insertCourse function inserts a node with     
//that contain the variables passed by arguments according to ascending order                 
void Course::insertCourse(string code, string name, int unit, string type)
{
	ListNode *newNode, *nodePtr, *previousNode = NULL;

	//Allocate a new node & store variables
	newNode = new ListNode;
	newNode->courseCode = code;
	newNode->courseName = name;
	newNode->courseUnit = unit;
	newNode->courseType = type;
   
	//If there are no nodes in the list
	//make newNode the first node
	if (!headCourse)
    {
    	headCourse = newNode;
		newNode->next = NULL;
	}
    else  //Otherwise, insert newNode
    {
    	//Initialize nodePtr to head of list and
    	//previousNode to a null pointer.
    	nodePtr = headCourse;
		previousNode = NULL;

    	//Skip all nodes whose courseCode member is less
    	//than the code variable that was passed into the arguments.
		while (nodePtr != NULL && nodePtr->courseCode <= code)
    	{  
    		//check whether the code is already exist in the linked list,
    		//if it already exist the course shouldn't be add again
      		if(nodePtr->courseCode == code){
      			return;
			}
		
			//otherwise continue traversing the linked list
        	previousNode = nodePtr;
        	nodePtr = nodePtr->next;
    	}

    	//If the new node is to be the 1st in the list,
    	//insert it before all other nodes.
		if (previousNode == NULL)
        {
        	headCourse = newNode;
        	newNode->next = nodePtr;
    	}
    	else  //Otherwise, insert it after the previous node
    	{
        	previousNode->next = newNode;
        	newNode->next = nodePtr;
    	}
    }
}


//The deleteCourse function searches for a node     
//that is in the order same as the num variable passed by arguments. 
//If the node is found, it will be deleted from the list and memory.          
void Course::deleteCourse(int num)
{
	ListNode *nodePtr, *previousNode = NULL;
	int numOfNode=1;

	//If the list is empty, do nothing.
	if (!headCourse)
    	return;
      
	//Determine if the first node is the one that the user want to delete.
	if (numOfNode == num)
	{
		nodePtr = headCourse->next;
    	delete headCourse;
    	headCourse = nodePtr;
	}
	else
	{
    	//Initialize nodePtr to head of list
    	nodePtr = headCourse;

    	//Skip all nodes whose order is 
    	//not equal to num variable
		while (nodePtr != NULL && numOfNode != num)
    	{  
        	previousNode = nodePtr;
        	nodePtr = nodePtr->next;
        	numOfNode++;
    	}

    	//If nodePtr is not at the end of the list, 
    	//link the previous node to the node after
    	//nodePtr, then delete nodePtr.
    	if (nodePtr)
    	{
    		previousNode->next = nodePtr->next;
        	delete nodePtr;
    	}
   	}
}


//The print function displays the all the variables         
//stored in each node of the linked list          
//pointed to by head.                             
void Course::print()
{
	ListNode *nodePtr = NULL;

	nodePtr = headCourse;
	while (nodePtr)
	{
    	cout << left << setw(16) << nodePtr->courseCode << setw(63) << nodePtr->courseName << setw(12) 
	  	     << nodePtr->courseUnit << setw(11) << nodePtr->courseType << endl;
    	nodePtr = nodePtr->next;
	}
}


//The printCourseByType function will displays all the variables 
//stored in the node of the linked list after comparing its courseType
//to check whether it is the same as the course type that user want to view
void Course::printCourseByType(int choiceSelected){
	
	char chosenType;		//declare a chosenType variable as char 
	
	//Save the corresponding course type into chosenType variable 
	//based on the choiceSelected variable that was passed by arguments
	if(choiceSelected==1){
		chosenType = 'E';
	}else if(choiceSelected==2){
		chosenType = 'M';
	}else if(choiceSelected==3){
		chosenType = 'T';
	}
	else if(choiceSelected==4){
		chosenType = 'U';
	}else{
		chosenType = 'Z';
	}
	
	ListNode *nodePtr = NULL;

	nodePtr = headCourse;
	
	//while it is still not the end of the linked list, the loop will still proceed
	while (nodePtr)
	{	
		
		//create a temp variable as char 
		char temp[nodePtr->courseType.length()];
 
 		//separate the content of a string into char array and check 
		 //whether it contains the character that is same as the courseType chosen by user
    	for (int i = 0; i < sizeof(temp); i++) {
        	temp[i] = nodePtr->courseType[i];
        	
        	//If there is a character that is same as the coursetype chosen by user, 
			//display the variables of the selected node
        	if(temp[i] == chosenType){
				cout << left << setw(16) << nodePtr->courseCode << setw(63) << nodePtr->courseName << setw(12) 
	  	     		 << nodePtr->courseUnit << setw(11) << nodePtr->courseType << endl;
			}
    	}
    	nodePtr = nodePtr->next;
	}	
}


//The destroy function destroys all the nodes     
//in the list.                                    
void Course::destroy()
{
	ListNode *nodePtr, *nextNode = NULL;

	nodePtr = headCourse;
	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;
    	delete nodePtr;
    	nodePtr = nextNode;
	}

	headCourse = NULL;
}


//The search function will check whether the course code entered by 
//user is exist in the course available.
//If yes, the course name and course unit of the selected course will 
//be assigned to the reference variable.
//If no, the function will return false, and in the main program, 
//message will be shown to the user that the course registration 
//is unsuccessful as there are no such course exist.
bool Course::search(string code, char type, string &courseN, int &unit)
{
	ListNode *nodePtr, *nextNode = NULL;
    nodePtr = headCourse;
    while (nodePtr)
    {
        if( nodePtr->courseCode == code)
        {
      		courseN = nodePtr->courseName;
      		unit = nodePtr->courseUnit;
         	return true;
        }
        else
        {
            nodePtr = nodePtr->next;
        }
    }
	return false;
}


