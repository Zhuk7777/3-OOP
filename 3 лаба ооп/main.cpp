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

	Bill a("������", "892099999", 1, 5, b, e);//�������, �������, �����, ������, ����� ������ ���������, ����� ����� ���������

	int chose = 1;

	std::string str;
	int data;
	double data2;

	while (chose) {
	
		menu();
		chose = check();
		while (chose < 1 || chose>15)
		{
			std::cout << "����� ������ ����� �� 1 �� 15(������������)\n";
			chose = check();
		}

		switch (chose) {

		case 1:
			std::cout << "������� ����� �������\n";
			std::cin >> str;
			a.setSurname(str);
			break;

		case 2:
			std::cout << "������� ����� �����\n";
			std::cin >> str;
			a.setPhone(str);
			break;

		case 3:
			std::cout << "������� ����� �����\n";
			std::cin >> data2;
			a.setRate(data2);
			break;

		case 4:
			std::cout << "������� ����� ������\n";
			std::cin >> data;
			a.setDiscount(data);
			break;

		case 5:
			std::cout << "������� ����� ����� ������ ���������\n";
			std::cin >> str;
			a.setBeg(str);
			break;

		case 6:
			std::cout << "������� ����� ����� ����� ���������\n";
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

		std::cout << "0-��������� ������ ���������, 1-����������\n";
		chose = check();

		while (chose < 0 || chose>1)
		{
			std::cout << "����� ������ 0 ��� 1\n";
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
		std::cout << "����� ������ �����" << std::endl;
		std::cin >> x;
	}
	return x;
}

void menu()
{
	std::cout << "1-�������� �������\n2-�������� ����� ��������\n3-�������� �����\n"
		<<"4-�������� ������\n5-�������� ����� ������ ���������\n6-�������� ����� ��������� ���������\n"
		<<"7-������ �������\n8-������ �����\n9-������ �����\n10-������ ������\n"
		<<"11-������ ����� ������ ���������\n12-������ ����� ��������� ���������\n13-������ ����� ��������� � �������\n"
		<<"14- ������ ����� � ������\n15-��� ���������� �� �������\n";

}