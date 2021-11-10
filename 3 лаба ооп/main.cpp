#include"Time.h"
#include<iostream>
int main()
{
	std::string s;
	std::cin >> s;
	Time a(s), b(125);
	a = b;
	std::cout << a;
	return 0;
}