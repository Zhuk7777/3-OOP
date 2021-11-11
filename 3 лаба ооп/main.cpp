#include"Time.h"
#include"Bill.h"
#include<iostream>
#include <Windows.h>

int check() {
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

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Time b("23:56:05"), e("00:32:26"), c;

	Bill a("�������", "892099999", 2.32, 5, b, e, 123);

	int menu = 1;
	int ind;

	std::string str;
	int data;
	double data2;

	while (menu) {
		std::cout << "0-�������� �������\n1-�������� ����� ��������\n2-�������� �����\n3-�������� ������\n4-�������� ����� ������ ���������\n5-�������� ����� ��������� ���������\n6-�������� ����� � ������\n7-������ �������\n8-������ �����\n9-������ �����\n10-������ ������\n11-������ ����� ������ ���������\n12-������ ����� ��������� ���������\n13-������ ����� ���������\n14- ������ ����� � ������\n15-��� ���������� �� �������\n";

		ind = check();
		while (ind < 0 || ind>15)
		{
			std::cout << "����� ������ ����� �� 0 �� 15(������������)\n";
			ind = check();
		}

		switch (ind) {

		case 0:
			std::cout << "������� ����� �������\n";
			std::cin >> str;
			a.setSurname(str);
			break;

		case 1:
			std::cout << "������� ����� �����\n";
			std::cin >> str;
			a.setPhone(str);
			break;

		case 2:
			std::cout << "������� ����� �����\n";
			std::cin >> data2;
			a.setRate(data2);
			break;

		case 3:
			std::cout << "������� ����� ������\n";
			std::cin >> data;
			a.setDiscount(data);
			break;

		case 4:
			std::cout << "������� ����� ����� ������ ���������\n";
			std::cin >> str;
			a.setBeg(str);
			break;

		case 5:
			std::cout << "������� ����� ����� ����� ���������\n";
			std::cin >> str;
			a.setEnd(str);
			break;

		case 6:
			std::cout << "������� ����� � ������\n";
			std::cin >> data2;
			a.setPay(data2);
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
		menu = check();

		while (menu < 0 || menu>1)
		{
			std::cout << "����� ������ 0 ��� 1\n";
			menu = check();
		}
	}
	return 0;
}