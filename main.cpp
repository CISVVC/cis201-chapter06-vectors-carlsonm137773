/*
file: main.cpp
description: Takes inputs for the Transaction class and stores them in a vector
			 calculates interest 
			 outputs a statement

author: Matthew Carlson
email: carlsonm137773@student.vvc.edu
date of creation: 5/11/2018
*/

#include<iostream>
#include<string>
#include<vector>

#include"transaction.h"

void print_statement(std::vector<Transaction> x);
double interest_min_daily_balance();
double interest_average_daily_balance(std::vector<Transaction> t);
double interest_month();

const double RATE = 0.05; //interest rate per month
const int DAYS_IN_MONTH = 30; //days in the statement period

int main()
{

	std::vector<Transaction> transaction;
	bool more;

	do
	{
		Transaction x;
		x.read();
		transaction.push_back(x);
		std::cout << "More input? Y/N? ";
		char answer;
		std::cin >> answer;
		if(answer == 'y' || answer == 'Y')
		{
			more = true;
		}
		else
		{
			more = false;
		}
	}
	while(more);
	print_statement(transaction);
	return 0;
}

/*
Prints a statement of a vector of the Transaction class
@peram x a vector of the transaction class
*/
void print_statement(std::vector<Transaction> x)
{
	double total = 0;

	for(int i=0; i<x.size(); i++)
	{
		x[i].print();
		total = total + x[i].get_amount();
	}
	
	std::cout << "Ending balace: " << total << std::endl;
	std::cout << "Interest using average daily balance: " << interest_average_daily_balance(x);
}

double interest_min_daily_balance()
{

}

/*
calculates interest using the average daily balance
@peram t A vector of the Transaction class
@return interest using the average daily balance
*/
double interest_average_daily_balance(std::vector<Transaction> t)
{
	std::vector<double> x;

	for(int i=0; i<t.size(); i++)
	{
		double total = 0;

		for(int day=0; day < DAYS_IN_MONTH; day++)
		{
			if(t[i].get_day() == day)
			{
				total = total + t[i].get_amount();
			}
		}
		x.push_back(total);
	}
	
	double n = 0;

	for(int i=0; i<x.size(); i++)
	{
		n = x[i] + n;
	}

	return (n / DAYS_IN_MONTH) * RATE; 
}

double interest_month()
{

}

