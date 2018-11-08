#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<string>

class Transaction
{
public:
	Transaction();
	void read();
	int get_day();
	double get_amount();
	void print();
private:
	std::string m_description;
	int m_day;
	double m_amount;
};

#endif
