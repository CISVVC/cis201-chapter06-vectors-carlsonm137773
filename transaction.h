/*
file name: transaction.h
description: Header file for transaction.h
author: Matthew Carlson
date of creation: 05/11/2018
*/
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<string>

class Transaction
{
public:
	Transaction(); // default constructor
	Transaction(int _day, double _amount);
	void read(); // inputs m_day m_amount m_description
	int get_day(); // returns m_day
	double get_amount(); // returns m_amount
	void print(); // prints m_day m_amount m_description and ends the line
private:
	std::string m_description;
	int m_day;
	double m_amount;
};

#endif
