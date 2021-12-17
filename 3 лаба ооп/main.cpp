#include"Time.h"
#include"Bill.h"
#include<iostream>
#include <Windows.h>

int check();
void menu();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Time b("23:56:05"), e("00:35:26"), c;

	Bill a("Петров", "892099999", 1, 5, b, e);//фамилия, телефон, тариф, скидка, время начала разговора, время конца разговора

	int chose = 1;

	std::string str;
	int data;
	double data2;

	while (chose) {
	
		menu();
		chose = check();
		while (chose < 1 || chose>15)
		{
			std::cout << "Нужно ввести число от 1 до 15(включительно)\n";
			chose = check();
		}

		switch (chose) {

		case 1:
			std::cout << "Введите новую фамилию\n";
			std::cin >> str;
			a.setSurname(str);
			break;

		case 2:
			std::cout << "Введите новый номер\n";
			std::cin >> str;
			a.setPhone(str);
			break;

		case 3:
			std::cout << "Введите новый тариф\n";
			std::cin >> data2;
			a.setRate(data2);
			break;

		case 4:
			std::cout << "Введите новую скидку\n";
			std::cin >> data;
			a.setDiscount(data);
			break;

		case 5:
			std::cout << "Введите новое время начала разговора\n";
			std::cin >> str;
			a.setBeg(str);
			break;

		case 6:
			std::cout << "Введите новое время конца разговора\n";
			std::cin >> str;
			a.setEnd(str);
			break;

		case 7:
			std::cout << a.getSurname() << std::endl;
			break;

		case 8:
			std::cout << a.getPhone() << std::endl;
			break;

		case 9:
			std::cout << a.getRate() << std::endl;
			break;

		case 10:
			std::cout << a.getDiscount() << "%\n";
			break;

		case 11:
			c = a.getBeg();
			std::cout << c << "\n";
			break;

		case 12:
			c = a.getEnd();
			std::cout << c << "\n";
			break;

		case 13:
			std::cout << a.talkTimeMinute() << "\n";
			break;

		case 14:
			std::cout << a.toString() << "\n";
			break;

		case 15:
			std::cout << a;
			break;
		}

		std::cout << "0-завершить работу программы, 1-продолжить\n";
		chose = check();

		while (chose < 0 || chose>1)
		{
			std::cout << "Нужно ввести 0 или 1\n";
			chose = check();
		}
	}
	return 0;
}

int check()
{
	int x;
	std::cin >> x;
	while (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "нужно ввести число" << std::endl;
		std::cin >> x;
	}
	return x;
}

void menu()
{
	std::cout << "1-изменить фамилию\n2-изменить номер телефона\n3-изменить тариф\n"
		<<"4-изменить скидку\n5-изменить время начала разговора\n6-изменить время окончания разговора\n"
		<<"7-узнать фамилию\n8-узнать номер\n9-узнать тариф\n10-узнать скидку\n"
		<<"11-узнать время начала разговора\n12-узнать время окончания разговора\n13-узнать время разговора в минутах\n"
		<<"14- узнать сумму к оплате\n15-вся информация об объекте\n";

}