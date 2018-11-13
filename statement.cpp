/*
file: statement.cpp
description: Statement class vectors for daily balance and transaction log
author: Matthew Carlson
email: carlsonm137773@student.vvc.edu
date of creation: 10/11/2018
*/

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

#include"statement.h"

Statement::Statement(int _days, double _rate)
{
	balance = 0;
	total_days = _days;
	rate = _rate;
}

void Statement::print()
{
	const int DAY_WIDTH = 5;
	const int AMOUNT_WIDTH = 12;
	const int DESCRIPTION_WIDTH = 25;
	const int TOTAL_WIDTH = DAY_WIDTH + AMOUNT_WIDTH + DESCRIPTION_WIDTH;
	const std::string LINE = std::string(TOTAL_WIDTH, '-');
	
//formated output
//	balance_print(t_log[0]);
	bool test = false;

	for(int day = 1; day -1 < total_days; day++)
	{

		for(int i = 0; i<t_log.size(); i++)
		{
			if(t_log[i].get_day() == day)
			{
				if(!test)
				{
					transaction_header(DAY_WIDTH, AMOUNT_WIDTH, DESCRIPTION_WIDTH, LINE);
					test = true;
				}
				std::cout << std::setw(DAY_WIDTH) << t_log[i].get_day() << std::setw(AMOUNT_WIDTH) << t_log[i].get_amount()
				<< std::setw(DESCRIPTION_WIDTH) << t_log[i].get_description() << std::endl;
			}
		}
		std::cout << LINE << std::endl;
		balance_print(daily_balance[day-1]);
		test = false;
	}

	std::cout << LINE << std::endl << "Average Daily Balance: " << std::setw(AMOUNT_WIDTH) << average_daily_bal() 
		<< " Interest: " << int_av_daily_bal() << std::endl;

	std::cout << std::endl << "Minimum Daily Balance: " << std::setw(AMOUNT_WIDTH) << min_daily_bal() 
		<< " Interest: " << int_min_daily_bal() << std::endl;
#if 0
	std::cout << "daily balance" << std::endl;

	for(int i=0; i < daily_balance.size(); i++)
		daily_balance[i].print();

	std::cout << "tlog" << std::endl;

	for(int i=0; i<t_log.size(); i++)
		t_log[i].print();
#endif
}
void Statement::read()
{
	int current_day = 1;
	bool more = true;
	
	std::cout << "enter day amount description seperated by a space" << std::endl; // prompt for input
	while(more)
	{
		//get transaction
		Transaction x;
		x.read();
		t_log.push_back(x);
		//daily balance
		if(x.get_day() == current_day)
		{
			balance = balance + x.get_amount();
		}
		if(x.get_day() > current_day)
		{
			while(x.get_day() != current_day)
			{
				daily_balance.push_back(Transaction(current_day, balance));

				current_day ++;
			}

			balance = balance + x.get_amount();
		}

		//ask if more input 
		std::cout << "More input y/n ";
		char answer;
		std::cin >> answer;
		if((answer == 'y') || (answer == 'Y')) 
		{
			more = true;
		}
		else
		{
			more = false;
		}
	}
	while(daily_balance.size() != total_days)
	{
		daily_balance.push_back(Transaction(daily_balance.size()+1, balance));
	}
}

double Statement::min_daily_bal()
{
	double min = daily_balance[0].get_amount();
	for(int i = 1; i < daily_balance.size(); i++)
	{
		if(daily_balance[i].get_amount() > min)
		{
			min = daily_balance[i].get_amount();
		}
	}
	return min;
}

double Statement::average_daily_bal()
{
	double number = 0.0;

	for(int i = 0; i < daily_balance.size(); i++)
	{
		number = daily_balance[i].get_amount() + number;	
	}
	
	return number / daily_balance.size();
}

void Statement::transaction_header(int day_W, int amount_w, int description_w, std::string line)
{
	std::cout << line << std::endl;
	std::cout << std::setw(day_W) << "Day" << std::setw(amount_w) << "Amount" << std::setw(description_w) << "Description"<< std::endl;
	std::cout << line << std::endl;
}

void Statement::balance_print(Transaction t)
{
	std::cout << "Balance for day " << t.get_day() << ": " << t.get_amount() << std::endl;
}
double Statement::int_av_daily_bal()
{
	return average_daily_bal() * rate;
}

double Statement::int_min_daily_bal()
{
	return min_daily_bal() * rate;
}
