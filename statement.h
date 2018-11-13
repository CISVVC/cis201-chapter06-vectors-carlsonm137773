/*
file: statement.h
description:
author: Matthew Carlson
email: carlsonm13773@student.vvc.edu
date of creation: 10/11/2018
*/

#ifndef STATEMENT_H
#define STATEMENT_H

#include<vector>
#include<string>

#include"transaction.h"

class Statement
{
public:
	Statement(int _days, double _rate); //constructor with paramaters
	void print();
	void read();
	double int_min_daily_bal(); //calculates the interest using minimum daily blance
	double int_av_daily_bal(); // calculates the interest using average daily balance
	double min_daily_bal(); // returns the minimum daily balance
	double average_daily_bal(); // returns the average daily balance
private:
	std::vector<Transaction> t_log;
	std::vector<Transaction> daily_balance;
	double balance;
	void transaction_header(int day_W, int amount_w, int description_w, std::string line); // header for transaction output
	void balance_print(Transaction t); // output "Balance for day x: bal"
	int total_days;
	double rate;
};

#endif
