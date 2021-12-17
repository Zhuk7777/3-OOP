#include "Bill.h"

Bill::Bill(std::string s, std::string p, double r, int d, Time b, Time e)
{
	surname = s;
	phone = p;
	rate = r;
	discount = d;
	beg = b;
	end = e;
	pay = 0;
}

Bill::Bill()
{
	surname = "";
	phone = "";
	beg = "00:00:00";
	end = "00:00:00";
	rate = 0;
	discount = 0;
	pay = 0;
}

Bill::Bill(const Bill& obj)
{
	surname = obj.surname;
	phone = obj.phone;
	rate = obj.rate;
	discount = obj.discount;
	beg = obj.beg;
	end = obj.end;
	pay = obj.pay;
}

void Bill::setSurname(std::string s)
{
	surname = s;
}

void Bill::setPhone(std::string p)
{
	phone = p;
}

void Bill::setRate(double r)
{
	rate = r;
}

void Bill::setDiscount(int d)
{
	discount = d;
}

void Bill::setBeg(std::string b)
{
	beg = b;
}

void Bill::setEnd(std::string e)
{
	end = e;
}

std::string Bill::getSurname()
{
	return surname;
}

std::string Bill::getPhone()
{
	return phone;
}

double Bill::getRate()
{
	return rate;
}

int Bill::getDiscount()
{
	return discount;
}

Time Bill::getBeg()
{
	return beg;
}

Time Bill::getEnd()
{
	return end;
}

double Bill::getPay()
{
	pay = rate * talkTimeMinute();
	pay = round(pay);
	pay -= pay * discount / 100;
	return pay;
}

int Bill::talkTimeMinute()
{
	Time newObj;

	newObj = end - beg;
	return newObj.toMin();
}

std::string Bill::toString()
{
	pay = rate * talkTimeMinute();
	pay = round(pay);
	pay -= pay * discount / 100;

	int intpart = pay;

	double fractpart2 = pay - intpart;
	fractpart2 *= 100;
	int fractpart = fractpart2;

	return  std::to_string(intpart) + " руб " + std::to_string(fractpart) + " коп"; 
}

std::ostream& operator<<(std::ostream& out, Bill& obj)
{
	out << obj.surname << " " << obj.phone << "\nТариф - " << obj.rate << "\nCкидка - " << obj.discount << "%\nРазговор начался в " << obj.beg << "\nРазговор закончился в " << obj.end << "\nСумма к оплате " << obj.toString() << "\n";
	return out;
}
