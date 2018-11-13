/*
file: main.cpp
description: prompts the user for transactions using the Statement class and outputs a statement using both minimum daily blance and average daily balance 
author: Matthew Carlson
email: carlsonm137773@student.vvc.edu
date of creation: 5/11/2018
*/

#include<iostream>
#include<string>
#include<vector>

#include"transaction.h"
#include"statement.h"

int main()
{
	const double RATE = 0.005;
	const int TOTAL_DAYS = 30;

	Statement x = Statement(TOTAL_DAYS, RATE);

	x.read();

	x.print();

	return 0;
}
