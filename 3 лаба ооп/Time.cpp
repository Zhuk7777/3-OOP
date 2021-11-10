#include "Time.h"
#include<cmath>
#include<iostream>
#pragma warning(disable : 4996)
Time::Time(int _hour, int _minute, int _second)
{
	hour = _hour;
	minute = _minute;
	second = _second;
}

Time::Time(std::string str)
{
	int i = 0;
	hour = stoi(str.substr(i, 2));
	i += 3;
	minute = stoi(str.substr(i, 2));
	i += 3;
	second = stoi(str.substr(i, 2));
}

Time::Time(int _second)
{
	hour = _second / 3600;
	hour %= 24;
	_second %= 3600;
	minute = _second / 60;
	_second %= 60;
	second = _second;


}

Time::Time(double realTime)
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	hour = timeinfo->tm_hour;
	minute = timeinfo->tm_min;
	second = timeinfo->tm_sec;
}

Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}

void Time::setHour(int h)
{
	hour = h;
}

void Time::setMin(int m)
{
	minute = m;
}

void Time::setSec(int s)
{
	second = s;
}

int Time::getHour()
{
	return hour;
}

int Time::getMin()
{
	return minute;
}

int Time::getSec()
{
	return second;
}

std::string Time::toStr()
{
	std::string result;

	if (hour < 10)
		result += '0';
	result+= std::to_string(hour);
	result += ":";

	if (minute < 10)
		result += '0';
	result += std::to_string(minute);
	result += ':';

	if (second < 10)
		result += '0';
	result += std::to_string(second);

	return result;
}

int Time::toSec()
{
	return second + 60 * (minute)+60 * 60 * (hour);
}

int Time::toMin()
{
	double sec = second;
	sec/=60;
	return minute + 60 * hour + (ceil(sec));
}

void Time::addSec(int s)
{
	second += s;
	if (second >= 60)
	{
		minute += second / 60;
		second %= 60;
		if (minute >= 60) {
			hour += minute / 60;
			minute %= 60;
			hour %= 24;
		}
	}
}

void Time::minusSec(int s)
{
	if (hour < s/3600) {
		if ((hour + 24 - s / 3600) < (s / 3600 - hour))
			hour += 24;
	}

	int sec = toSec();

	sec -= s;
	hour = sec / 3600;
	hour %= 24;
	sec %= 3600;
	minute = sec / 60;
	sec %= 60;
	second = sec;

}

int Time::minusResSec(const Time& obj)
{
	Time newObj(hour, minute, second);

	if (newObj.hour < obj.hour) {
		if ((newObj.hour + 24 - obj.hour) < (obj.hour - newObj.hour))
			newObj.hour += 24;
	}
	int secObj = obj.second + 60 * (obj.minute) + 60 * 60 * (obj.hour);
	int secNew = newObj.toSec();

	return abs(secNew - secObj);
}

Time Time::operator-(const Time& obj)
{
	Time newObj(hour, minute, second);

	if (newObj.hour < obj.hour) {
		if ((newObj.hour + 24 - obj.hour) < (obj.hour - newObj.hour))
			newObj.hour += 24;
	}
	int secObj= obj.second + 60 * (obj.minute) + 60 * 60 * (obj.hour);
	int secNew = newObj.toSec();

	return Time(abs(secNew - secObj));
}

Time Time::operator+(const Time& obj)
{
	int result;
	int sec = second + 60 * (minute)+60 * 60 * (hour);
	int  secObj = obj.second + 60 * (obj.minute) + 60 * 60 * (obj.hour);
	result = sec + secObj;
	return Time(result);
}

bool Time::operator<(const Time& obj)
{
	return second + 60 * (minute)+60 * 60 * (hour) < (obj.second + 60 * (obj.minute) + 60 * 60 * (obj.hour));
}

bool Time::operator>(const Time& obj)
{
	return second + 60 * (minute)+60 * 60 * (hour) > (obj.second + 60 * (obj.minute) + 60 * 60 * (obj.hour));
}

bool Time::operator==(const Time& obj)
{
	return second + 60 * (minute)+60 * 60 * (hour) == (obj.second + 60 * (obj.minute) + 60 * 60 * (obj.hour));
}

Time& Time::operator=(const Time& obj)
{
	if (this == &obj) return *this;
	hour = obj.hour;
	minute = obj.minute;
	second = obj.second;
	return *this;
}

Time& Time::operator=(const std::string str)
{
	if (str == "") {
		hour = 0;
		minute = 0;
		second = 0;
	}
	else {
		int i = 0;
		hour = stoi(str.substr(i, 2));
		i += 3;
		minute = stoi(str.substr(i, 2));
		i += 3;
		second = stoi(str.substr(i, 2));
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, Time& obj)
{
	out << obj.toStr();
	return out;
}

std::istream& operator>>(std::istream& in, Time& obj)
{
	in >> obj.hour;
	in >> obj.minute;
	in >> obj.second;
	return in;
}
