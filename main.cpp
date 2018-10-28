/*

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
	getline(cin, description);
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
//get valid input number >= min && number <= max || cin.fail()
    int number;
    cout << prompt;
	cin >> number;

	return number;
}

double Transaction::get_double(string prompt)
{
// get valid input cin.fail()
    double number;
	cout << prompt;
	cin >> number;

	return number;
}

int main()
{
#if 0 // main 
// intil array Transaction

// get input

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
