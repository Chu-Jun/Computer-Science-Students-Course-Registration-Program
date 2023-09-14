#include <iostream>
#include <iomanip>
#include "RegisteredCourse.h"
using namespace std;

//Copy constructor                                
RegisteredCourse::RegisteredCourse(const RegisteredCourse &listObj)
{
	RegisteredCourseListNode *nodePtr = NULL;

	//Initialize the head pointer.
	head = NULL;

	//Point to the other object's head.
	nodePtr = listObj.head;

	//Traverse the other object.
	while (nodePtr)
   	{
    	//Append a copy of the other object's
    	//node to this list.
    	addRegisteredCourse(nodePtr->courseCode, nodePtr->courseName,nodePtr->courseUnit,nodePtr->courseType);

		//Go to the next node in the other object.
    	nodePtr = nodePtr->next;
    }
}

//Destructor function deletes every node in the list.   
RegisteredCourse::~RegisteredCourse()
{
	destroy();
}


//addRegisteredCourse function appends a node containing the        
//variables passed by arguments, to the end of the list.   
void RegisteredCourse::addRegisteredCourse(string code, string name, int unit, char type)
{
	RegisteredCourseListNode *newNode, *nodePtr = NULL;

	//Allocate a new node & store num
	newNode = new RegisteredCourseListNode;
	newNode->courseCode = code;
	newNode->courseName = name;
	newNode->courseUnit = unit;
	newNode->courseType = type;
	newNode->next = NULL;

	//If there are no nodes in the list
	//make newNode the first node
    if(!head){
    	head = newNode;
    }
    else  //Otherwise, insert newNode at end
    {
    	//Initialize nodePtr to head of list
    	nodePtr = head;

    	//Find the last node in the list
    	while (nodePtr->next)
        	nodePtr = nodePtr->next;

    	//Insert newNode as the last node
    	nodePtr->next = newNode;
    }
}


//The insertRegisteredCourse function inserts a node      
//that contain the variables passed by arguments with ascending order based on the courseCode member.                 
bool RegisteredCourse::insertRegisteredCourse(string code, string name, int unit, char type)
{
	RegisteredCourseListNode *newNode, *nodePtr, *previousNode = NULL;

	//Allocate a new node & store the variables
	newNode = new RegisteredCourseListNode;
	newNode->courseCode = code;
	newNode->courseName = name;
	newNode->courseUnit = unit;
	newNode->courseType = type;
   
	//If there are no nodes in the list
	//make newNode the first node
	if (!head)
    {
    	head = newNode;
		newNode->next = NULL;
	}
    else  //Otherwise, insert newNode
    {
    	
    	//Check whether the course unit of the registered course linked list exceed 21 unit
    	//If the course unit of the registered course has exceed the limit, this function will return false
    	//and the course will not be inserted, so that the user will not exceed the limit
    	if(!checkUnit(newNode->courseUnit)){
    		cout << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
				 << "!!!!!!!!!!" << endl;
			cout << "You have exceeded the limit of course unit, which is 21 unit for one semester." << endl;
			cout << "You should not register any course any more." << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
				 << "!!!!!!!!!" << endl;
			cout << endl;
    		return false;
		}
    	
		//Initialize nodePtr to head of list and
    	//previousNode to a null pointer.
    	nodePtr = head;
		previousNode = NULL;

    	//Skip all nodes whose courseCode member is less
    	//than code, to make the course list is in ascending order.
		while (nodePtr != NULL && nodePtr->courseCode <= code)
    	{  
    		//Check whether the course selected exist in the linked list,
    		//If there is already a node with the same courseCode member,
    		//the course will not be register and message will be shown to the user
      		if(nodePtr->courseCode == code){
      			cout << endl;
      			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
      			cout << "You have already registered this course." << endl;
      			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
      			return false;
			}
			
         	previousNode = nodePtr;
         	nodePtr = nodePtr->next;
      	}

    	//If the new node is to be the 1st in the list,
    	//insert it before all other nodes.
		if (previousNode == NULL)
    	{
        	head = newNode;
        	newNode->next = nodePtr;
    	}
    	else  //Otherwise, insert it after the prev node
    	{
        	previousNode->next = newNode;
        	newNode->next = nodePtr;
      	}
	}
	return true;
}


//The deleteRegisteredCourse function searches for a node     
//that is in the order same as the num variable passed by arguments. 
//If the node is found, it will be deleted from the list and memory.      
void RegisteredCourse::deleteRegisteredCourse(int num)
{
	RegisteredCourseListNode *nodePtr, *previousNode = NULL;
	int numOfNode=1;

    //If the list is empty, do nothing.
   	if (!head)
    	return;
      
   
    //Determine if the first node is the one.
    if (numOfNode == num)
    {
    	nodePtr = head->next;
    	delete head;
    	head = nodePtr;
    }
    else
    {
    	//Initialize nodePtr to head of list
    	nodePtr = head;

    	//Skip all nodes whose order is 
    	//not equal to the num variable passed by arguments
		while (nodePtr != NULL && numOfNode != num)
    	{  
        	previousNode = nodePtr;
        	nodePtr = nodePtr->next;
        	numOfNode++;
    	}
      
      	//If the user enter the number that is bigger than the number of node in the linked list 
      	//Prompt user and no node will be deleted
    	if(num>(numOfNode-1)){
    		cout << endl;
    		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
				 << "!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
      		cout << "The input is not available. Please enter the number in front of the course listed." << endl;
      		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
			  	 << "!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
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


//The printRegistered function displays the variables         
//stored in each node of the linked list          
//pointed to by head.                             
void RegisteredCourse::printRegistered()
{
	cout << "__________________________________________________________________________________________"
		 << "___________________________" << endl;
	cout << "Course Code\t" << left << setw(58) << "Course Name" << "Course Unit\t" << "Course Type\t" << endl;
	cout << "___________________________________________________________________________________________"
		 << "__________________________" << endl;
    RegisteredCourseListNode *nodePtr = NULL;
    int count=1;
    int totalUnit=0;

    nodePtr = head;
    while (nodePtr)
    {
    	totalUnit+=nodePtr->courseUnit;
   		cout << count << ". ";
        cout << left << setw(13) << nodePtr->courseCode << setw(63) << nodePtr->courseName << setw(14) 
	  	     << nodePtr->courseUnit << setw(11) << nodePtr->courseType << endl;
        nodePtr = nodePtr->next;
        count++;
    }
    cout << "____________________________________________________________________________________________"
		 << "_________________________" << endl;
    cout << "The total unit of course registered is: " << totalUnit << endl;
}


//The printCourseByType function will displays all the variables 
//stored in the node of the linked list after comparing its courseType
//to check whether it is the same as the course type that user want to view
void RegisteredCourse::displayByType(char type){
	
    RegisteredCourseListNode *nodePtr = NULL;
    nodePtr = head;
    
    int count=1;
    int totalUnit=0;
    
    //Display the header of the registered course list
    cout << "_________________________________________________________________________________________"
		 << "____________________________" << endl;
	cout << "Course Code\t" << left << setw(58) << "Course Name" << "Course Unit\t" << "Course Type\t" << endl;
	cout << "__________________________________________________________________________________________"
		 << "___________________________" << endl;
    while (nodePtr)
    {
    	//Check whether the course type of the node is the same as the one selected by user
    	//If they are the same, display all the variables in the selected node
    	if(nodePtr->courseType == type){
    		totalUnit+=nodePtr->courseUnit;
   			cout << count << ". ";
        	cout << left << setw(13) << nodePtr->courseCode << setw(63) << nodePtr->courseName << setw(14) 
	  	     	 << nodePtr->courseUnit << setw(11) << nodePtr->courseType << endl;
        	nodePtr = nodePtr->next;
        	count++;
		}
		else{
			nodePtr = nodePtr->next;
		}
    }
	cout << "_________________________________________________________________________________________"
		 << "____________________________" << endl;
   	cout << "The total unit of course registered (for selected course type) is: " << totalUnit << endl;
}


//The destroy function destroys all the nodes     
//in the list.                                    
void RegisteredCourse::destroy()
{
	RegisteredCourseListNode *nodePtr, *nextNode = NULL;

	nodePtr = head;
	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;
    	delete nodePtr;
    	nodePtr = nextNode;
   	}
   	head = NULL;
}


//The checkList function will check whether the linked list is empty, if it is empty there is 
//no course that can be drop
bool RegisteredCourse::checkList(){
	if (!head){
		cout << endl;
		cout << "************************************************************************************" << endl;
		cout << "You haven't register for any course." << endl;
   	    cout << "Drop course function is not available." << endl;
   	    cout << "************************************************************************************" << endl << endl;
   	    return false;
	}
   	return true;
}


//The checkType function check whether there is node with the course type selected by user
//So that the program can show the registered course list if this function returns true
bool RegisteredCourse::checkType(char typeSelected){
	RegisteredCourseListNode *nodePtr = NULL;
    nodePtr = head;

	while (nodePtr)
    {
    	if(nodePtr->courseType == typeSelected){
        	return true;
		}else{
			nodePtr = nodePtr->next;
		}
    }
    return false;
}


//The checkUnit function check whether the total course unit of the registered course exceed the limit which is 21 unit
bool RegisteredCourse::checkUnit(int unit){
	RegisteredCourseListNode *nodePtr = NULL;
    nodePtr = head;

	int unitRegistered=unit;		//declare a unitRegistered variable as 
									//int and initialize it as the course unit of the course that user wants to add
	
	//while it is still not the end of the linked list, the while loop will proceed
	while (nodePtr)
    {
    	unitRegistered += nodePtr->courseUnit;		//sum up the total unit of course registered
    	
    	//If the unitRegistered exceed 21 return false
    	if(unitRegistered>21){
    		return false;
		}else{
			nodePtr = nodePtr->next;
		}
    }
    return true;
}

    

