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
#include"statement.h"

int main()
{
	Statement x;

	x.read();

	x.print();

	return 0;
}
