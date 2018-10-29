/*
Description:
Author: Matthew Carlson
Email: carlsonm137773@student.vvc.edu
Date of creation: 10/29/2018
*/

#include<iostream>
#include<string>

using namespace std;

class Transaction
{
public:
    Transaction();
	Transaction(int _day, double _amount, string description);
	void read();
	void print();
	int get_day();
	double get_amount();
	string get_description();
private:
    int day;
    double amount;
    string description;
	int get_int(string prompt, int min, int max);
    double get_double(string prompt);
};

Transaction::Transaction()
{
    day = 0;
	amount = 0;
}
Transaction::Transaction(int _day, double _amount, string _description)
{
    day = _day;
	amount = _amount;
	description = _description;
}

void Transaction::read()
{
    day = get_int("Day:", 1, 30);
	amount = get_double("Amount: ");
	cout << "Description: ";
	cin >> description; //dosent allow input without the extra input for some reason
	getline(cin, description);
	// problem with this function
	// prompts for all and takes input for int and double but skips the input for the string
}

void Transaction::print()
{
    cout << day << " " << amount << " " << description;
}

int Transaction::get_day()
{
    return day;
}

double Transaction::get_amount()
{
    return amount;
}

string Transaction::get_description()
{
    return description;
}

int Transaction::get_int(string prompt, int min, int max)
{
    int number;
	string invalid = "Invalid input try again";
    do
	{
	    cout << prompt;
		cin >> number;

		if(cin.fail() || number < min || number > max)
		{
		    if(cin.fail())
			{
			    cin.clear();
				string e;
				cin >> e;
			    cout << invalid;
			}
			else
			{
			    cout << "Invaldi input please eneter a number between " << min << " and " << max << endl;
			}
		}
	}while(cin.fail() || number < min || number > max);


	return number;
}

double Transaction::get_double(string prompt)
{
    double number;
	string invalid ="Invalid input try again ";
	do
	{
	    cout << prompt;
		cin >> number;

		if(cin.fail())
		{
		    cin.clear();
			string e;
			cin >> e;
		    cout << invalid << endl;
		}
	}while(cin.fail());

	return number;
}

bool answer(string prompt);

int main()
{
#if 0 // main 
// intil array Transaction

// get input
    do
	{
	
	}while(answer("more input?"));
// sort

// calc interest

// output
#endif
#if 1 // class test
    Transaction next;
	next.read();
    next.print();
#endif

    return 0;
}

bool answer(string prompt)
{
    int number;
    cout << prompt << " 0 for no ";
	cin >> number;
	if(number == 0)
	{
	    return false;
	}
	else
	{
	    return true;
	}
}
