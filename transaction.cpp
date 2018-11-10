/*
file: transaction.cpp
description: Transaction class for a bank statement
author: Matthew Carlson
email: carlsonm137773@student.vvc.edu
date of creation: 5/11/2018
*/

#include<string>
#include<iostream>

#include"transaction.h"

Transaction::Transaction()
{
	m_day = 0;
	m_amount = 0;
}

void Transaction::read()
{
	std::cin >> m_day;
	std::cin >> m_amount;
	std::cin.ignore();
	std::getline(std::cin, m_description);
}

void Transaction::print()
{
	std::cout << m_day << " " << m_amount << " " << m_description << std::endl;
}

double Transaction::get_amount()
{
	return m_amount;
}

int Transaction::get_day()
{
	return m_day;
}


