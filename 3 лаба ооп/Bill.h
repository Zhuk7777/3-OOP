#pragma once
#include<string>
#include"Time.h"
#include<iostream>
class Bill
{
	std::string surname;
	std::string phone;
	double rate;
	int discount;
	Time beg;
	Time end;
	double pay;
public:
	Bill(std::string s, std::string p, double r, int d, Time b, Time e, double pa);
	Bill();

	void setSurname(std::string s);
	void setPhone(std::string p);
	void setRate(double r);
	void setDiscount(int d);
	void setBeg(std::string b);
	void setEnd(std::string e);
	void setPay(double pa);

	std::string getSurname();
	std::string getPhone();
	double getRate();
	int getDiscount();
	Time getBeg();
	Time getEnd();
	double getPay();

	int talkTimeMinute();

	std::string toString();

	friend std::ostream& operator<< (std::ostream& out, Bill& obj);
};
