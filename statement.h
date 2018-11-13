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
	Statement(int _days, double _rate);
	void print();
	void read();
	double int_min_daily_bal();
	double int_av_daily_bal();
	double min_daily_bal();
	double average_daily_bal();
private:
	std::vector<Transaction> t_log;
	std::vector<Transaction> daily_balance;
	double balance;
	void transaction_header(int day_W, int amount_w, int description_w, std::string line);
	void balance_print(Transaction t);
	int total_days;
	double rate;
};

#endif
