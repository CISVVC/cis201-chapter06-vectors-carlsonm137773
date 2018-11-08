/*
file: main.cpp
description:
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
double interest_average_daily_balance(double t);
double interest_month();

const double RATE = 0.05;

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

void print_statement(std::vector<Transaction> x)
{
	double total = 0;

	for(int i=0; i<x.size(); i++)
	{
		x[i].print();
		total = total + x[i].get_amount();
	}
	
	std::cout << "Ending balace: " << total << std::endl;
	std::cout << "Interest using average daily balance: " << interest_average_daily_balance(total);
}

double interest_min_daily_balance()
{

}

double interest_average_daily_balance(double t)
{
	return (t / 30) * RATE; 
}

double interest_month()
{

}

