
//Nhan Bui	
//Lab 4 out

#include <iostream>
#include <string>
#include <cctype>
#include "graph1.h"

using namespace std;



string getString(string prompt);
bool validateName(string name);
bool validateAddress(string address);
bool validateCity(string city);
bool validateState(string state);
bool validateZip(string zip);
string convertToUpper(string input);
void displayLetter(string fn, string ln, string addr, string city, string state, string zip, int weight);

int main ()
{
	
	string fn ;
	string ln ;
	string addr ;
	string city ;
	string state ;
	string zip ;
	int weight = 0;
	string w ;
	bool res = false;
	string repeat = "y";

	//Display graphics window
	displayGraphics();
	do
	{

		//Process name info
		do
		{
			//Prompt for the name  
			fn = getString("Enter First Name: ");

			//validates name
			res = validateName(fn);

		} while (!res);

		do
		{
			//Prompt for the name  
			ln = getString("Enter Last Name: ");

			//validates name
			res = validateName(ln);

		} while (!res);

		//Processes the address info
		do
		{
			//Gets the address
			addr = getString("Enter Street Address: ");

			//validates address
			res = validateAddress(addr);

		} while (!res);

		//Processes city info
		do
		{
			city = getString("Enter City: ");

			//validates city
			res = validateCity(city);

		} while (!res);

		//Processes State info
		do
		{
			state = getString("Enter State: ");

			//validates state
			res = validateState(state);

		} while (!res);

		//Processes Zip info
		do
		{
			zip = getString("Enter Zip Code: ");

			//validate Zip Code
			res = validateZip(zip);

		} while (!res);

		//Prompts user for weight
		do
		{
			cout << "Enter Weight: ";
			getline (cin,w);
			weight = stoi(w);

			if (weight < 1 || weight > 6)
			{
				cout << "ERROR, weight must be betwwen 1 and 6";
			}

		} while (weight < 1 || weight > 6);
		

		//Converts the state to all uppercase
		state = convertToUpper(state);

		//Displays output
		displayLetter(fn, ln, addr, city, state, zip, weight);


		//Prompt for repeat

		cout << "Do you want to repeat?: ";
		getline(cin, repeat);

		clearGraphics();
		system("cls");

	} while (repeat[0] == 'y' || repeat[0] == 'Y');

	return 0;

}

string getString(string prompt)
{
	string user_ans ;
	//Prompt user for name using getline (prompt contains the message displayed to user))
	cout << prompt;
	getline(cin, user_ans);

	return user_ans;
}

//Validates characters of name
bool validateName(string name)
{
	//Validate the name – return true if valid, false if not
	bool res = true;
	int i = 0;
	for (i = 0; i < name.length(); i++)
	{
		if (isalpha(name[i]) == 0)
		{
			cout << "Error, name entered is invalid. Try again. ";
			res = false;
			break;
		}
	}

	return res;
}

//Validates characters of address
bool validateAddress(string address)
{
	bool res = true;
	int i = 0;
	for (i = 0; i < address.length(); i++)
	{
		if (isalnum(address[i]) == 0)
		{
			if (isspace(address[i]) == 0)
			{
				cout << "Error, address entered is invalid. Try again. ";
				res = false;
				break;
			}
		}
	}

	return res;

}

//Validates characters of city
bool validateCity(string city)
{
	bool res = true;
	int i = 0;

	if (city[0] >= 97 && city[0] <= 122)
	{
		cout << "Error, the first letter must be Uppercase. Try again.";
		res = false;	
	}
	else
	{
		for (i = 0; i < city.length(); i++)
		{
			if (isalpha(city[i]) == 0)
			{
			
				cout << "Error, city entered is invalid. Try again.";
				res = false;
				break;
				
			}
		}
	}

	return res;
}

//Validates characters of State
bool validateState(string state)
{
	bool res = true;
	int i = 0;

	if (state.length() != 2)
	{
		cout << "Error, enter abbreviation. Try again. ";
		res = false;
	}
	
	else
	{
		for (i = 0; i < state.length(); i++)
		{
			if (isalpha(state[i]) == 0)
			{
				cout << "Error, state entered is invalid. Try again.";
				res = false;
				break;
			}
		}
	}
	return res;
}

//Validates characters of zip
bool validateZip(string zip)
{
	bool res = true;
	int i = 0;
	if (zip.length() != 5)
	{
		cout << "Error, zip code entered is invalid. Try again. ";
		res = false;
	}
	else
	{
		for (i = 0; i < 5; i++)
		{
			if (isdigit(zip[i]) == 0)
			{
				cout << "Error, Zip Code entered is invalid. Try again. ";
				res = false;
				break;
			}
		}
	}
	return res;
}

//Converts State's Abbreviation to Uppercase
string convertToUpper(string input)
{
	int i = 0;
	for (i = 0; i < input.length(); i++)
	{
		input[i] = toupper(input[i]);
	}

	return input;
}

//Displays Output
void displayLetter(string fn, string ln, string addr, string city, string state, string zip, int weight)
{
	int i = 0;
	int x = 525;
	int y = 20;
	int stampCost = 47;
	double totalCost = 0;

	displayBMP("envelope.bmp", 0, 0);
	displayBMP("returnAddress.bmp", 43, 26);

	for (i = 0; i < weight; i++)
	{
		
		if ((i+1) <= 3)
		{
			displayBMP("stamp.bmp", x, y);
			x -= 75;
		}
		else if ((i + 1) == 4)
		{
			y += 79;
			x = 525;
			displayBMP("stamp.bmp", x, y);
		}
		else
		{
			x -= 75;
			displayBMP("stamp.bmp", x, y);
		}

		gout << setPos(315, 210) << setColor(0, 255, 0) << fn << " " << ln << endg;
		gout << setPos(315, 225) << setColor(0, 255, 0) << addr << endg;
		gout << setPos(315, 240) << setColor(0, 255, 0) << city << " " << state << ", " << zip << endg;

		drawLine(200, 385, 490, 385, 1);
		drawLine(490, 385, 490, 470, 1);
		drawLine(490, 470, 200, 470, 1);
		drawLine(200, 470, 200, 385, 1);

		totalCost = weight * 0.47;

		gout << setPos(210, 400) << setColor(0, 255, 0) << "Weight: " << weight << " ounces" << endg;
		gout << setPos(210, 425) << setColor(0, 255, 0) << "Cost of First Class Stamp: " << stampCost << " Cents" << endg;
		gout << setPos(210, 450) << setColor(0, 255, 0) << "Total Mailing Cost: $" << setPrecision(2)  << totalCost << endg;

	}
}