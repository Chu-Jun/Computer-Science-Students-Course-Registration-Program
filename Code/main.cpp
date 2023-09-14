/*2022 CPT113 Assignment 2
Program Name: Computer Science Student Course Registration Program
Group Number: Group 28
This program will read the textfile according to the filename entered by the user and 
ask user select the service needed, such as register course, drop course, view course
The user is also able to view the course list according to course type selected by user.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Student.h"	
#include "Course.h"

int main() {
	Course course;		//create object of Course class
	Student student;	//create object of Student class
	ifstream inputFile; //create object to read text file
	
	string filename, studentName, 		//declare variable filename and studentName as string
		   cName, cCode, 				//declare variable cName and cCode as string
		   cType, registerCode;			//declare variable cType and registerCode as string
		   
	int matricNumber, 					//declare matricNumber as int
		yearOfStudy, cUnit, dropCode, 	//declare yearOfStudy, cUnit and dropCode as int
		typeToView, addDrop;			//declare variable typeToView and addDrop as int
		
	long int phoneNumber;				//declare variable phoneNumber as long int
	
	char courseType;					//declare variable courseType as char
	
	char choice = 'Y';					//declare variable choice as char and initialize it as 'Y'

	//ask user to input the filename that includes the students' information
	cout << "Enter the filename: ";  
	cin >> filename;  

	//open the file from user
	inputFile.open(filename.c_str()); 
	
	//check whether the file entered by user can be open using while loop, if the input file can be open, 
	//it will continue with the program, else it will show error and ask the user to enter the filename again
	while (!inputFile)
	{	
		cout << "\nOops! Error in opening the file.\n"; 
		cout << "Please enter a valid file name :\n";
		cin >> filename;
		inputFile.open(filename.c_str());
		
	}
	
	//while we can still get input from the file selected, the loop will proceed
	while (inputFile) {
		getline(inputFile, cCode, '\t');
		getline(inputFile, cName, '\t');			
		inputFile >> cUnit;	
		getline(inputFile, cType);	
		
		//insert the information from text file into the linked list in Course class								
		course.insertCourse(cCode, cName, cUnit, cType);
	}
	
	//Ask user to enter his/her personal information
	cin.ignore();
	cout << "\t\t\t\t\tCOURSE REGISTRATION SYSTEM" << endl;
	cout << "_______________________________________________________________________________________"
		 << "______________________" << endl;
	cout << "Enter your name: ";
	getline(cin, studentName);
	cout << "Enter your matric number: ";
	cin >> matricNumber;
	cout << "Enter your year of study: ";
	cin >> yearOfStudy;
	
	//input validation to make sure user didn't enter the wrong input for yearOfStudy
	while(yearOfStudy<1 || yearOfStudy>4){
		cout << "You might entered the wrong value. Please enter your year of study: " ;
		cin >> yearOfStudy;
	}
	
	cout << "Enter your phone number: ";
	cin >> phoneNumber;
	
	
	//Call the setInfo function in Student class and pass the 
	//variable: studentName, matricNumber, yearOfStudy and phoneNumber to the function by passing argument
	student.setInfo(studentName, matricNumber, yearOfStudy, phoneNumber);
	
	cout << endl;
	
	//While choice variable is 'y' or 'Y', which means the user want to continue the program,
	//the program will not end
	while(choice=='Y' || choice=='y'){
		
		//Show user the list of services available in this program
		cout << "Below are the list of service provided in this Course Registration System: "<< endl;
		cout << "1. Register Course" << endl;
		cout << "2. Register Course By Course Type" << endl;
		cout << "3. Drop Course" << endl;
		cout << "4. View Course That Are Registered" << endl;
		cout << "5. View Course That Are Registered By Type" << endl;
		cout << "Enter the number in front of the service needed: ";
		cin >> addDrop;
		
		//Input Validation to check whether the addDrop variable input by user is available
		while(addDrop<1 || addDrop>5){
			cout << "The option is not available. "
				 << "Please enter the number in front of the service needed.(Only 1-5 is available): " << endl;
			cin >> addDrop;
		}
		
		//If the variable addDrop is equal to 1, the user want to register course
		if(addDrop == 1){
			
			//Show user the list of course available (the content of list is from the text file 
			cout << endl;
			cout << endl;
			cout << "This is the list of course provided." << endl;
			cout << "You can choose courses to register according to the list of course provided." << endl;
			cout << "The course type offer are listed. Please choose the correct course type. " << endl;
			cout << "________________________________________________________________________________________"
				 << "____________________________" << endl;
			cout << "Course Code\t" << left << setw(58) << "Course Name" << left << setw(15) <<"Course Unit\t" 
				 << "Course Type\t" << endl;
			cout << "_________________________________________________________________________________________"
				 << "___________________________" << endl;
			cout << endl;
			//Print the course list by calling print() function in Course class
			course.print();
			
			//Ask user to enter the course code of the course that the user want to register
			cout << "------------------------------------------------------------------------------------------"
				 << "-------------------------" << endl;
			cout << "Enter the course code of the course you want to register: ";
			cin >> registerCode;
			
			//Let user enter the course type that he/she wants for the course selected
			cout << "Enter the course type for this selected course";
			cout << "(Please choose the correct course type offer by each course!!!) : ";
			cin >> courseType;
			
			string tempName;		//declare variable tempName as string to save the course name
			int tempUnit;			//declare variable tempUnit as int to save the course unit
			
			//Check whether the course code input by user is exist, 
			//if not the course will not be registered and user will be notified that the course is not available
			if(course.search(registerCode, courseType, tempName, tempUnit)){
				
				//If the course.search() function return true, which means the course code is exist and available
				//insert the course selected by user into the linked list of RegisteredCourse class
				//by calling registerManual() function in Student class
				student.registerManual(registerCode, tempName, tempUnit, courseType);
				
			}else{
				
				//Notify user that the course code is not available, if the course.search() function return false,
				//as it means that the course selected by user is not exist in the course available linked list
				cout << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
					 << "!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Course Registration Unsuccessful. Please Enter the Course Code provided in the course list." 
					 << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
					 << "!!!!!!!!!!!!!!!!1!!!!!!!" << endl;
				cout << endl;
			}
		}
		else if(addDrop == 2)		
		{
			//Let user choose what type of course the user want to view, before registering the course
			cout << endl;
			cout << "List of Course Type:" << endl;
			cout << "1. E" << endl;
			cout << "2. M" << endl;
			cout << "3. T" << endl;
			cout << "4. U" << endl;
			cout << "5. Z" << endl;
			cout << "Enter the number in front of the course type that you want to view: ";
			cin >> typeToView;
			
			//Input validation to check whether the input is available
			while(typeToView<1 || typeToView>5){
				cout << "The option is not available. Please enter the number 1-5 according to the course type "
					 << "that you prefer: ";
				cin >> typeToView;
			}
			
			//Print the header of the list of course available
			cout << endl;
			cout << endl;
			cout << "This is the list of course provided." << endl;
			cout << "You can choose courses to register according to the list of course provided." << endl;
			cout << "The course type offer are listed. Please choose the correct course type. " << endl;
			cout << "___________________________________________________________________________________________"
				 << "_________________________" << endl;
			cout << "Course Code\t" << left << setw(58) << "Course Name" << left << setw(15) <<"Course Unit\t" 
				 << "Course Type\t" << endl;
			cout << "____________________________________________________________________________________________"
				 << "________________________" << endl;
			cout << endl;
			
			//Display the course list according to the course type 
			//chosen by user by calling the printCourseByType function in Course class
			course.printCourseByType(typeToView);
			
			//Ask user to enter the course code of the course he/she want to register
			cout << "---------------------------------------------------------------------------------------------"
				 << "----------------------" << endl;
			cout << "Enter the course code of the course you want to register: ";
			cin >> registerCode;
			
			//Let user enter the course type that he/she wants for the course selected
			cout << "Enter the course type for this selected course";
			cout << "(Please choose the correct course type offer by each course!!!) : ";
			cin >> courseType;
			
			//Check whether the course code input by user is exist, 
			//if not the course will not be registered and user will be notified that the course is not available
			string tempName;
			int tempUnit;
			if(course.search(registerCode, courseType, tempName, tempUnit)){
				
				student.registerManual(registerCode, tempName, tempUnit, courseType);
				
			}else{
				
				cout << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
					 << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				cout << "Course Registration Unsuccessful. Please Enter the Course Code provided in the "
					 << "course list." << endl;
				cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
					 << "!!!!!!!!!!!!!!!!!!!!!!!!!1!!!!!!!" << endl;
				cout << endl;
			}
		}
		else if(addDrop == 3)
		{
			//Check whether the linked list of RegisteredCourse class is empty, if it is empty,
			//no course can be drop, therefore the loop will stop and ask user to proceed with other services
			if(!student.checkNull()){
				continue;
			}
			
			//Display the list of course that was registered by the user
			cout << endl;
			cout << "Below is the course list that you have registered: " << endl;
			student.print();
			cout << "Enter the number in front of the course you want to drop: ";
			cin >> dropCode;
			
			//Delete the linked list node that is selected by user by calling the dropCourse() function in 
			//Student class
			student.dropCourse(dropCode);
			
			//Display the latest registered course list to let user check whether he/she drop the correct course
			cout << endl;
			cout << "The latest course list registered is: "<< endl;
			student.print();
			
		}
		else if(addDrop == 4)
		{
			//Display the registered course list by calling the print() function in Student class
			cout << endl;
			student.print();
			cout << endl;
		}
		else if(addDrop == 5)
		{
			//Let user choose the course type that he/she wants, 
			//to view the registered course list according to the course type
			cout << endl;
			cout << "List of Course Type:" << endl;
			cout << "1. E" << endl;
			cout << "2. M" << endl;
			cout << "3. T" << endl;
			cout << "4. U" << endl;
			cout << "5. Z" << endl;
			cout << "Enter the number in front of the course type that you want to view: ";
			cin >> typeToView;
			
			//Input validaton to check whether the input is available
			while(typeToView<1 || typeToView>5){
				cout << "The option is not available. Please enter the number 1-5 according "
					 << "to the course type that you prefer: ";
				cin >> typeToView;
			}
			
			//Display the registered course list according to the course type chosen by user
			//by calling the printByType() function in Student class
			student.printByType(typeToView);
		}
		else
		{
			//If the addDrop variable input by user is not 1-5, 
			//the input is not available and this message will be shown to notify the user
			cout << "The option is unavailable. Please enter either 1 of 2, according to the service needed.";
		}
		
		//Ask user whether he/she wants to continue the program
		//Enter 'Y' or 'y' for yes and 'N' or 'n' for no
		cout << endl;
		cout << "Do you want to continue the registration?" << endl;
		cout << "Enter y or Y for continue." << endl;
		cout << "Enter n or N to end this program." << endl;
		cin>> choice;
		
		//Input validation to check whether the user enter character other than y and n
		//If the user enter the value other than y and n ask the user to enter a new input
		while(choice!='Y' && choice!='y' && choice!='N' && choice!='n'){
			cout << endl;
			cout << "You have entered a wrong choice. Please enter Y or y to continue / enter N or n to end "
				 << "the program: ";
			cin >> choice;
		}
		
		//Clear the concole to ensure a clear and neat view for user
		system("CLS");
	}
	
	//Show the student's information and course registered at the end of the program
	cout << "Here are the student information entered and the list of course registered: " << endl;
	cout << endl;
	student.studentInfoPrint();
	cout << endl;
	student.print();
	
}
