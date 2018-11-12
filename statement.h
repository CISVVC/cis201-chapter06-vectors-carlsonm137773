/*

*/

#ifndef STATEMENT_H
#define STATEMENT_H

#include<vector>
#include<string>

#include"transaction.h"

class Statement
{
public:
	Statement();
	void print();
	double get_minimum_bal();
	double get_average_bal();
	void read();
private:
	std::vector<Transaction> t_log;
	std::vector<Transaction> daily_balance;
	double minimum_daily_bal;
	double average_daily_bal;
	double balance;
};

#endif
