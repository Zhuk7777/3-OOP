#pragma once
#include<string>
#include<ctime>
class Time {
	int hour;
	int minute;
	int second;
public:
	Time(int _hour, int _minute, int _second );
	Time(std::string str);
	Time(int second);
	Time(double realTime);
	Time();

	Time(const Time& obj);

	void setHour(int h);
	void setMin(int m);
	void setSec(int s);

	int getHour();
	int getMin();
	int getSec();
	std::string toStr();

	int toSec();
	int toMin();

	void addSec(int s);
	
	void minusSec(int s);

	int minusResSec(const Time& obj);
	Time operator -(const Time& obj);

	Time operator+(const Time& obj);

	bool operator<(const Time& obj);
	bool operator>(const Time& obj);
	bool operator==(const Time& obj);
	Time& operator=(const Time& obj);
	Time& operator=(const std::string str);

	friend std::ostream& operator<< (std::ostream& out, Time& obj);
	friend std::istream& operator>> (std::istream& in, Time& obj);
};