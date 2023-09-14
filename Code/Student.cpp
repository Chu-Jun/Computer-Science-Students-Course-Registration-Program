#include <iomanip>
#include <iostream>
#include "Student.h"
using namespace std;

//Student class constructor that does not have any parameter
Student::Student(){
	name = "";
	matricNum = 0;
	year = 0;
	phoneNum = 0;
}

//Student class constructor that has all the information to be set
Student::Student(string studentName, int matric, int yearNum, long int hpNum) {
	name = studentName;
	matricNum = matric;
	year = yearNum;
	phoneNum = hpNum;
}

//Student class destructor
Student::~Student() {
	name = "";
	matricNum = 0;
	year = 0;
	phoneNum = 0;
}

//setInfo function in Student class to assign all the variable needed including variable 
//in other composition class
void Student::setInfo(string studentName, int matric, int yearNum, long int hpNum) {
	name = studentName;
	matricNum = matric;
	year = yearNum;
	phoneNum = hpNum;
}

//Mutator function of Student class for variable name
void Student::setName(string studentN) {
	name = studentN;
}

//Mutator function of Student class for variable matricNo
void Student::setMatric(int matricNo) {
	matricNum = matricNo;
}

//Mutator function of Student class for variable phoneNum
void Student::setPhoneNum(long int hpNo) {
	phoneNum = hpNo;
}

//Mutator function of Student class for variable year
void Student::setYear(int studentYear) {
	year = studentYear;
}

//Accessor function of the Student class to return the variable name
string Student::getName() {
	return name;
}

//Accessor function of the Student class to return the variable matricNum
int Student::getMatric() {
	return matricNum;
}

//Accessor function of the Student class to return the variable phoneNum
long int Student::getPhoneNum() {
	return phoneNum;
}

//Accessor function of the Student class to return the variable year
int Student::getYear() {
	return year;
}

//Function that pass all information available by assigning the value to the parameter pass by references
void Student::getInfo(string &nameOfStudent, int &matricNumber, int &yearOfStudent, long int &hpNumber) {
	nameOfStudent = name;
	matricNumber = matricNum;
	hpNumber = phoneNum;
	yearOfStudent = year;
}

//function to register the course by typing all info manually
void Student::registerManual(string code, string name, int unit, char type){
	if(registerC.insertRegisteredCourse(code, name, unit, type)){
		cout << endl;
		cout << "***********************************************************************************"
			 << "*************" << endl;
		cout << "Course Register Succesfully!" << endl;
		cout << "************************************************************************************"
			 << "************" << endl;
		cout << endl;
	}
}

//Function to drop course by calling the deleteRegisteredCourse() function in RegisteredCourse class
void Student::dropCourse(int num){
	
	//Call the deleteRegisteredCourse function in registerCourse class and pass the number 
	//of course that the user want to delete by passing it in the parameter list
	registerC.deleteRegisteredCourse(num);
}

//The checkNull function will check whether the linked list of the RegisteredCourse class is empty
bool Student::checkNull(){
	
	//Call the checkList function in RegisteredCourse class and return bool value
	return(registerC.checkList());
}

//The print function will display the registered course list 
//by calling the printRegistered function in RegisteredCourse class
void Student::print(){
	registerC.printRegistered();
}

//The printByType function will convert the user selection on course type from int to char
//and pass it into the displayByType function in the RegisteredCourse class
//So that the registered course list will be display according to the course type selected by user
void Student::printByType(int choiceSelected){
	
	char chosenType;			//declare a chosenType variable as char
	
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
	
	//Check whether the registered course list contain the course with the course type chosen by user
	if(registerC.checkType(chosenType)){
		
		//If the course type is available, displayByType function will be call
		//and all the registered course of the selected course type will be displayed
		registerC.displayByType(chosenType);
	}
	else{
		
		//If there is no course with the course type selected, the message will be shown to the user
		cout << endl;
		cout << "************************************************************************************" 
			 << endl;
		cout << "You haven't register any course for the selected course type." << endl;
   	    cout << "************************************************************************************" 
		   	 << endl << endl;
	}
	
}

//The studentInfoPrint function display the student's (User) information
void Student::studentInfoPrint(){
	cout << "Student Name: " << name << endl;
	cout << "Matric Number: " << matricNum << endl;
	cout << "Year Of Study: " << year << endl;
	cout << "Phone Number of Student: 0" << phoneNum << endl;
}
