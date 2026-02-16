//Paige Ingram
//Lab 4 in
//Creates a form for inputting/validating information

#include <iostream>
#include <string>
#include <cctype>
#include "graph1.h"

using namespace std;

//Prototypes are below
string getString(string prompt);
bool validateName(string name);
bool validateAddress(string address);
bool validatePhone(string phone);
string convertToUpper(string string);
void displayFields(string name, string address, string phone);


int main()
{
	//Variable Declaration/Initialization
	string name = "";
	string address = "";
	string phone = "";
	string upperName = "";
	bool res = false;
	string repeat;
	do{

		//Display graphics window
		displayGraphics();

	//Process name info
	do
	{
		//Prompt for the name - 
		name = getString("Enter Name: ");

		//validate the name
		res = validateName(name);

	} while (!res);

	//Process the address info
	do
	{
		//Get the address
		address = getString("Enter Address: ");

		//validate the address
		res = validateAddress(address);

	} while (!res);

	//Process phone info
	do
	{
		//Get the phone
		phone = getString("Enter Phone: ");

		//validate the phone
		res = validatePhone(phone);

	} while (!res);



	//Convert the name to all uppercase
	upperName = convertToUpper(name);

	//Display the fields

	displayFields(name, address, phone);

	cout << "Repeat Program?(y/n)";
	getline(cin, repeat);
} while (repeat == "y" || repeat == "Y");


	return 0;
}




//Prompts for input based on input parameter prompt
string getString(string prompt)
{
	string user_input = "";
	
	//Prompt user for name using getline (prompt contains the message displayed to user))
	cout << prompt;
	getline(cin, user_input);
	return user_input;
}

//Validates characters of name
bool validateName(string name)
{
	bool result = true;
	int i = 0;
	for (i = 0; i < (int)name.length(); i++) 
	{

		if (isalpha(name[i]) == 0) {
			if (isspace(name[i]) == 0) {
				result = false;
				cout << "Error! The name entered is not VALID. Please Re-Enter." << endl;
				break;
			}
		}
	}

	//Validate the name – return true if valid, false if not
	return result;
}

//Validates characters of address
bool validateAddress(string address)
{
	bool result = true;
	int i = 0;
	for (i=0; i < address.length(); i++) {

		if (isalnum(address[i]) == 0) {
			if (isspace(address[i]) == 0) {
				result = false;
				cout << "Error! The address entered is not VALID. Please Re-Enter." << endl;
				break;
			}
		}
	}
	
		return result;
	//Validate the address – return true if valid, false if not
}



//Validates characters of phone number
	bool validatePhone(string phone)
	{
		bool result = true;
		int i = 0;
		if (phone.length() != 10) {
			result = false;
			cout << "Error! The phone entered is not valid. Please Re-Enter. " << endl;
		}
		else {
			for (i=0; i < phone.length(); i++) {

				if (isdigit(phone[i]) == 0) {
					result = false;
					cout << "Error! The phone entered is not valid. Please Re-Enter. " << endl;
					break;
				}
				//Validate the phone – return true if valid, false if not
			}
		}
		return result;
	}

//Converts text to uppercase
string convertToUpper(string input)
{
	for (int i = 0; i < input.length(); i++) {
		input[i] = toupper(input[i]);
	}
	//Convert input to all uppercase
	//Return converted input
	return input;
}

//Displays the information in graphics window
void displayFields(string name, string address, string phone)
{
	

	//Draw the form (rectangles)
	//Display the fields
	int rectangles[3] = {0};
	rectangles[0] = drawRect(230, 85, 170, 20);
	setColor(rectangles[0], 128, 128, 128);
	rectangles[1] = drawRect(230, 125, 325, 20);
	setColor(rectangles[1], 128, 128, 128);
	rectangles[2] = drawRect(230, 165, 125, 20);
	setColor(rectangles[2], 128, 128, 128);
	gout << setPos(150, 100) << setColor(0, 255, 0) << "Name:" << endg;
	gout << setPos(150, 140) << setColor(0, 255, 0) << "Address:" << endg;
	gout << setPos(150, 180) << setColor(0, 255, 0) << "Phone:" << endg;
	gout << setPos(230, 100) << setColor(0, 255, 0) << name << endg;
	gout << setPos(230, 140) << setColor(0, 255, 0) << address << endg;
	gout << setPos(230, 180) << setColor(0, 255, 0) << phone << endg;
}

