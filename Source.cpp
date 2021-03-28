/*
Name: Chris Starks
Filename: Source.cpp
Description: This is a Payroll Management System. (Finish Editing Later)
Edits:
7/19/2020 - Attempting to Add an Input Validation System. Working on Two Methods at the Moment to Implement this,
AddEmployee and InputValidator. Not Fully Successful Quite Yet in Input Validation.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>
#include <cstdlib>


using namespace std;


//Doubly Linked List Class
class Node {
public:
	int employeeCodeNumber;
	string firstName;
	string lastName;
	char address[100];
	char phoneNumber[10];
	string joiningDate;
	char jobDescription[50];

	Node* prev;
	Node* next;
};

Node* AddNewEmployee(Node** refNode);
void ModifyEmployee(Node** refNode);
void DeleteEmployee(Node** refNode);
void PrintSalarySlip(Node** refNode);
void DisplayEmployeeRecord(Node** refNode);
void DisplayAllEmployees(Node** headNode);
void ExitProgram();
bool InputValidator(string input);

int main() {

	//Creating Dummy Head Node
	Node* head;
	head = new Node();

	char userOption;

	do {

		//Option Menu For The User Interface
		cout << "\nWelcome! Please Select from the Following List:\n" << endl;
		cout << "A: Add New Employee\n"
			<< "B: Modify Employee Record\n"
			<< "C: Delete Employee Record\n"
			<< "D: Print Salary Slip\n"
			<< "E: Display Employee Record\n"
			<< "F: Display All Employees\n"
			<< "H: Exit Program\n";

		//User Option Menu Input
		cin >> userOption;
		userOption = toupper(userOption);


		//Switch Conditional for the User Option Menu Input
		switch (userOption) {
		case 'A':

			//Logic behind where to Insert the New Node

			if (head->next == NULL) {
				head->next = AddNewEmployee(&head);
			}
			else if (head->next != NULL) {
				struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
				temp = head->next;
				while (temp->next != NULL) {
					temp = temp->next;
				}
				if (temp->next == NULL) {
					temp->next = AddNewEmployee(&temp);
				}
			}

			break;

			/*
				Working Properly
			*/
		case 'B':
			ModifyEmployee(&head);
			break;

		case 'C':
			DeleteEmployee(&head);
			break;

		case 'D':
			PrintSalarySlip(&head);
			break;

		case 'E':
			DisplayEmployeeRecord(&head);
			break;

		case 'F':
			DisplayAllEmployees(&head);
			break;

		case 'H':
			ExitProgram();
			break;

		default:
			cout << "\nInvalid Input.\n" << endl;
		}

	} while (!(userOption == 'H'));



	return 0;
}

Node* AddNewEmployee(Node** refNode) {

	Node* givenNode;
	givenNode = *refNode;

	//Iterate through the Nodes to find the next Node Entry Spot


	Node* newNode;
	newNode = new Node();


	int codeNumberAddress;
	string codeNumberCheck;
	bool validCodeNumber;
	string first_Name;
	string last_Name;
	char living_address[100];
	char phone_Number;
	string joining_Date;
	char job_Description[50];



	cout << "\nPlease Enter Employee Number: ";
	cin >> codeNumberAddress;

	codeNumberCheck = to_string(codeNumberAddress);
	validCodeNumber = InputValidator(codeNumberCheck);
	cout << "\nValidCodeNumber?: " << validCodeNumber << endl;

	if (validCodeNumber == true) {
		newNode->employeeCodeNumber = codeNumberAddress;
		cout << "Please Enter First Name: ";
		cin >> newNode->firstName;
		cout << "Please Enter Last Name: ";
		cin >> newNode->lastName;
		cout << "Please Enter Living Address: ";
		cin.ignore();
		cin.getline(newNode->address, 100);
		cout << "Please Enter Phone Number. Digits Only: ";
		cin >> newNode->phoneNumber;
		cout << "Please Enter Employment Date: ";
		cin >> newNode->joiningDate;
		cout << "Please Enter Job Description/Title: ";
		cin.ignore();
		cin.getline(newNode->jobDescription, 50);

		newNode->prev = givenNode;
		givenNode->next = newNode;
		return newNode;
	}
	else {
		cout << "\nPlease Enter a Valid ID Number" << endl;
		newNode = nullptr;
		return newNode;
	}

}



void ModifyEmployee(Node** refNode) {
	Node* temp;
	temp = *refNode;

	Node* editNode;
	editNode = temp->next;

	Node* temp2 = NULL;

	char userInput;
	string stringChange;
	char stringChange2[100];
	int numChange;

	int errorCount;
	int employeeNumber;


	if (editNode == nullptr) {
		cout << "\nNo Current Employee Information\n";
		cout << endl;
	}
	else {
		cout << "Please Enter Employee's Code Number: ";
		cin >> employeeNumber;

		if (editNode != NULL) {
			while (editNode->employeeCodeNumber != employeeNumber) {
				editNode = editNode->next;
			}
			if (editNode->employeeCodeNumber == employeeNumber) {
				temp2 = editNode;
				cout << "\nPlease Choose Criteria to Modify:\n"
					<< "A: Employee Code Number\n"
					<< "B: Employee First Name\n"
					<< "C: Employee Last Name\n"
					<< "D: Employee Address\n"
					<< "E: Employee Phone Number\n"
					<< "F: Employee Joining Date\n"
					<< "G: Job Description/Title\n"
					<< "H: Return to Previous Menu\n";

				cin >> userInput;
				userInput = toupper(userInput);

				switch (userInput) {
				case 'A':
					cout << "Enter Employee's New Code Number: ";
					cin >> employeeNumber;

					temp2->employeeCodeNumber = employeeNumber;
					cout << "\nEmployee Code Number Changed to: " << employeeNumber << endl;
					cout << endl;
					break;

				case 'B':
					cout << "Enter Employee's New First Name: ";
					cin >> stringChange;

					temp2->firstName = stringChange;
					cout << "\nEmployee's First Name Changed To: " << stringChange << endl;
					cout << endl;
					break;

				case 'C':
					cout << "Enter Employee's New Last Name: ";
					cin >> stringChange;

					temp2->lastName = stringChange;
					cout << "\nEmployee's Last Name Changed To: " << stringChange << endl;
					cout << endl;
					break;

				case 'D':
					cout << "Enter Employee's New Address: ";
					//cin >> stringChange;
					cin.ignore();
					cin.getline(temp2->address, 100);
					//temp2->address = stringChange;
					cout << "\nEmployee's Address Changed To: " << temp2->address << endl;
					cout << endl;
					break;

				case 'E':
					cout << "Enter Employee's New Phone Number: ";
					//cin >> numChange;
					cin.ignore();
					cin.getline(temp2->phoneNumber, 20);
					//temp2->phoneNumber = numChange;
					cout << "\nEmployee's Phone Number Changed To: " << temp2->phoneNumber << endl;
					cout << endl;
					break;

				case 'F':
					cout << "Enter Employee's New Joining Date: ";
					cin >> stringChange;
					temp2->joiningDate = stringChange;
					cout << "\nEmployee's Joining Date Changed To: " << stringChange << endl;
					cout << endl;
					break;

				case 'G':
					cout << "Enter Employee's New Job Description/Title: ";
					cin.ignore();
					cin.getline(temp2->jobDescription, 50);
					//temp2->jobDescription = stringChange;
					cout << "\nEmployee's New Job Description/Title Changed To: " << temp2->jobDescription << endl;
					cout << endl;
					break;

				case 'H':
					break;

				default:
					cout << "\nInvalid Input\n";
				}
			}
			else {
				cout << "\nEmployee Code Number Does Not Exist\n";
				cout << endl;
			}
		}
	}



}

void DeleteEmployee(Node** refNode) {
	Node* dummyNode;
	dummyNode = *refNode;

	Node* temp;
	temp = new Node();
	if (dummyNode->next != NULL) {
		temp = dummyNode->next;
	}
	else {
		cout << "\nNo Employee Exists. Returning to Menu\n" << endl;
		return;
	}

	int employeeNumber;
	char userInput;

	cout << "\nPlease Enter Employee's Code Number: " << endl;
	cin >> employeeNumber;


	while (temp->employeeCodeNumber != employeeNumber) {
		temp = temp->next;
	}

	if (temp->employeeCodeNumber == employeeNumber) {
		cout << "\nConfirm Employee Deletion?: \n"
			<< "Click Y for Yes, N For No\n";
		cin >> userInput;

		userInput = toupper(userInput);

		switch (userInput) {
		case 'Y':

			//Deleting the Head
			if (temp == dummyNode->next && temp->next == NULL) {
				delete temp;
				dummyNode->next = NULL;
				return;
			}

			//Deleting Head with Remaining Nodes After
			if (temp == dummyNode->next && temp->next != NULL) {
				dummyNode->next = temp->next;
				delete temp;
				temp = nullptr;
				return;
			}

			//If the Node being Deleted is between Two other Nodes
			if (temp->prev != dummyNode && temp->prev != nullptr && temp->next != nullptr) {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
				temp = nullptr;
				return;
			}

			//Deleting the Tail
			if (temp->prev != dummyNode && temp->prev != nullptr && temp->next == nullptr) {
				temp->prev->next = nullptr;
				delete temp;
				temp = nullptr;
				return;
			}

			break;

		case 'N':
			cout << "\nReturning To Main Menu\n";
			cout << endl;
			break;

		default:
			cout << "\nInvalid Input. Returning to Main Menu\n";
			cout << endl;
			break;
		}
	}


	/*
	if (temp != NULL) {
		if (temp->employeeCodeNumber == employeeNumber) {
			cout << "\nAre You Sure You Want to Delete This Employee Information?: ";
			cin >> userInput;

			switch (userInput) {
			case 'Y':
				temp->next = NULL;
				temp->prev = NULL;
				free(temp);
				break;

			case 'N':
				break;
			}
		}
	}
	*/
}

void PrintSalarySlip(Node** refNode) {
	const double ENGINEER_SALARY = 40.50;
	const double SOFTWARE_ENGINEER_SALARY = 40.50;
	const double PROGRAMMER_SALARY = 30.50;
	const double WEB_DEVELOPER_SALARY = 30.50;
	const double OVERTIME_MULTIPLYER = 1.5;
	const double ANNUAL_WORK_HOURS = 2080;
	const double BIWEEKLY_WORK_HOURS = 80;

	const string softwareEngineer = "Software Engineer";
	const string engineer = "Engineer";
	const string programmer = "Programmer";
	const string webDev = "Web Developer";

	Node* dummyNode;
	dummyNode = *refNode;

	Node* temp;
	temp = dummyNode->next;

	int employeeNumber;
	int overtimeHours;

	char userInput;

	if (temp == nullptr) {
		cout << "\nNo Exmployee Information Exists. Returning to Main Menu\n" << endl;
		return;
	}

	if (temp != nullptr) {
		cout << "\nPleae Enter the Employee's Code Number: ";
		cin >> employeeNumber;

		if (temp->employeeCodeNumber != employeeNumber && temp->next != nullptr) {
			while (temp->employeeCodeNumber != employeeNumber) {
				temp = temp->next;
				if (temp == nullptr) {
					cout << "\nEmployee Code Does Not Exist. Returning to Main Menu\n" << endl;
					return;
				}
			}
		}
	}

	if (temp->employeeCodeNumber == employeeNumber) {
		cout << "\nDid Employee Work Overtime?: ";
		cin >> userInput;
		userInput = toupper(userInput);

		switch (userInput) {
		case 'Y':
			cout << "\How Many Hours of Overtime did Employee Work?: ";
			cin >> overtimeHours;

			cout << "\nEmployee Information::  Employee Code Number    First Name      Last Name      Job Description    Predicted Gross Annual Salary ||  Payday Amount for Bi-Weekly Cycle" << endl;
			cout.width(36);
			cout << temp->employeeCodeNumber;
			cout.width(18);
			cout << temp->firstName;
			cout.width(16);
			cout << temp->lastName;
			cout.width(25);
			cout << temp->jobDescription;
			cout.width(15);
			if (temp->jobDescription == softwareEngineer) {
				cout << "$" << (SOFTWARE_ENGINEER_SALARY * ANNUAL_WORK_HOURS) + (SOFTWARE_ENGINEER_SALARY * OVERTIME_MULTIPLYER * overtimeHours);
				cout.width(28);
				cout << "$" << (SOFTWARE_ENGINEER_SALARY * BIWEEKLY_WORK_HOURS) + (SOFTWARE_ENGINEER_SALARY * OVERTIME_MULTIPLYER * overtimeHours);
			}

			if (temp->jobDescription == engineer) {
				cout << "$" << (ENGINEER_SALARY * ANNUAL_WORK_HOURS) + (ENGINEER_SALARY * OVERTIME_MULTIPLYER * overtimeHours);
				cout.width(25);
				cout << "$" << (ENGINEER_SALARY * BIWEEKLY_WORK_HOURS) + (ENGINEER_SALARY * OVERTIME_MULTIPLYER * overtimeHours);
			}

			if (temp->jobDescription == programmer) {
				cout << "$" << (PROGRAMMER_SALARY * ANNUAL_WORK_HOURS) + (PROGRAMMER_SALARY * OVERTIME_MULTIPLYER * overtimeHours);
				cout.width(25);
				cout << "$" << (PROGRAMMER_SALARY * BIWEEKLY_WORK_HOURS) + (PROGRAMMER_SALARY * OVERTIME_MULTIPLYER * overtimeHours);
			}

			if (temp->jobDescription == webDev) {
				cout << "$" << (WEB_DEVELOPER_SALARY * ANNUAL_WORK_HOURS) + (WEB_DEVELOPER_SALARY * OVERTIME_MULTIPLYER * overtimeHours);
				cout.width(25);
				cout << "$" << (WEB_DEVELOPER_SALARY * BIWEEKLY_WORK_HOURS) + (WEB_DEVELOPER_SALARY * OVERTIME_MULTIPLYER * overtimeHours);
			}
			break;

		case 'N':
			cout << "\nEmployee Information::  Employee Code Number    First Name      Last Name      Job Description        Annual Salary || Gross Payday Amount for Bi-Weekly Cycle" << endl;
			cout.width(36);
			cout << temp->employeeCodeNumber;
			cout.width(18);
			cout << temp->firstName;
			cout.width(16);
			cout << temp->lastName;
			cout.width(25);
			cout << temp->jobDescription;
			cout.width(12);
			if (temp->jobDescription == softwareEngineer) {
				cout << "$" << (SOFTWARE_ENGINEER_SALARY * ANNUAL_WORK_HOURS);
				cout.width(25);
				cout << "$" << (SOFTWARE_ENGINEER_SALARY * BIWEEKLY_WORK_HOURS);
			}

			if (temp->jobDescription == engineer) {
				cout << "$" << (ENGINEER_SALARY * ANNUAL_WORK_HOURS);
				cout.width(25);
				cout << "$" << (ENGINEER_SALARY * BIWEEKLY_WORK_HOURS);
			}

			if (temp->jobDescription == programmer) {
				cout << "$" << (PROGRAMMER_SALARY * ANNUAL_WORK_HOURS);
				cout.width(25);
				cout << "$" << (PROGRAMMER_SALARY * BIWEEKLY_WORK_HOURS);
			}

			if (temp->jobDescription == webDev) {
				cout << "$" << (WEB_DEVELOPER_SALARY * ANNUAL_WORK_HOURS);
				cout.width(25);
				cout << "$" << (WEB_DEVELOPER_SALARY * BIWEEKLY_WORK_HOURS);
			}


			break;

		default:
			cout << "\nInvalid Input. Returning to Main Menu\n" << endl;
		}
	}
	else {
		cout << "\nEmployee Code Does Not Exist. Returning to Main Menu\n" << endl;
	}
	return;
}

void DisplayEmployeeRecord(Node** refNode) {
	Node* dummyNode;
	dummyNode = *refNode;

	Node* temp;
	temp = dummyNode->next;

	int employeeNumber;

	if (temp == nullptr) {
		cout << "\nNo Exmployee Information Exists. Returning to Main Menu\n" << endl;
		return;
	}

	if (temp != nullptr) {
		cout << "\nPleae Enter the Employee's Code Number: ";
		cin >> employeeNumber;

		if (temp->employeeCodeNumber != employeeNumber && temp->next != nullptr) {
			while (temp->employeeCodeNumber != employeeNumber) {
				temp = temp->next;
				if (temp == nullptr) {
					cout << "\nEmployee Code Does Not Exist. Returning to Main Menu\n" << endl;
					return;
				}
			}
		}
		if (temp->employeeCodeNumber == employeeNumber) {
			cout << "Employee Information::  Employee Code Number    First Name      Last Name          Address           Phone Number    Joining Date    Job Description" << endl;
			cout.width(36);
			cout << temp->employeeCodeNumber;
			cout.width(19);
			cout << temp->firstName;
			cout.width(17);
			cout << temp->lastName;
			cout.width(16);
			cout << temp->address;
			cout.width(22);
			cout << temp->phoneNumber;
			cout.width(17);
			cout << temp->joiningDate;
			cout.width(18);
			cout << temp->jobDescription;
			cout << endl;
			return;
		}
		else {
			cout << "\nNo Such Employee Code Exists. Returning to Main Menu\n" << endl;
			return;

		}
	}


}

/*
Description: Prints out a List of all Current Employees
*/
void DisplayAllEmployees(Node** refNode) {

	Node* startNode;
	startNode = *refNode;

	Node* temp;
	temp = startNode->next;

	//Checking to See if the Node AFTER the Dummy Node is Null.
	if (temp == NULL) {
		cout << "\n No Curret Employee Information\n";
	}
	/*
		if (startNode->address == "") {
			cout << "No Current Employee Information";
		}
		*/
	if (temp != NULL) {

		cout << "Employee Information::  Employee Code Number    First Name      Last Name          Address           Phone Number    Joining Date    Job Description" << endl;
		while (temp != NULL) {
			cout.width(36);
			cout << temp->employeeCodeNumber;
			cout.width(19);
			cout << temp->firstName;
			cout.width(17);
			cout << temp->lastName;
			cout.width(16);
			cout << temp->address;
			cout.width(22);
			cout << temp->phoneNumber;
			cout.width(17);
			cout << temp->joiningDate;
			cout.width(18);
			cout << temp->jobDescription;
			cout << endl;

			temp = temp->next;
		}
	}

	cout << "\nEmployee Record Printing Completed\n";
	cout << endl;

}

void ExitProgram() {

	cout << "Have a Wonderful Day" << endl;

	exit(0);
}

bool InputValidator(string input) {
	int isAllDigits = 0;


	for (int i = 0; i < input.size(); i++) {
		if ((isdigit(input.at(i)))) {
			//cout << "\nDigit At Iteration i: " << input.at(i) << endl;
			isAllDigits++;
		}
		else {
			return false;
			break;
		}
	}


	if (isAllDigits == input.length()) {
		cout << input.size();
		cout << isAllDigits << endl;
		return true;
	}
	else {
		cout << "\nIsAllDigits Returning False" << endl;
		return false;
	}

}