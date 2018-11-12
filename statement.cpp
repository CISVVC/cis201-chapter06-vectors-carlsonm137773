/*
file: statement.cpp
description:
author: Matthew Carlson
email: carlsonm137773@student.vvc.edu
date of creation: 10/11/2018
*/

#include<iostream>
#include<vector>
#include<string>

#include"statement.h"

Statement::Statement()
{
	minimum_daily_bal = 0;
	average_daily_bal = 0;
	balance = 0;
}

void Statement::print()
{
	std::cout << "daily balance" << std::endl;

	for(int i=0; i < daily_balance.size(); i++)
		daily_balance[i].print();

	std::cout << "tlog" << std::endl;

	for(int i=0; i<t_log.size(); i++)
		t_log[i].print();
}

void Statement::read()
{
	bool more = true;
	int current_day = 1;

	while(more) // need to add logic for the daily log 
	{
		Transaction x;
		x.read();
		balance = balance + x.get_amount();
		t_log.push_back(x);

		while (!(current_day == x.get_day()))
		{
			daily_balance.push_back(Transaction(current_day, balance));
			current_day ++;
		}

		std::cout << "more input y/n ";
		char answer;
		std::cin >> answer;
		if((answer == 'Y') || (answer == 'y'))
		{
			more = true;
		}
		else
		{
			more = false;
		}
	}
}

double Statement::get_minimum_bal()
{
	return minimum_daily_bal;
}

double Statement::get_average_bal()
{
	return average_daily_bal;
}
