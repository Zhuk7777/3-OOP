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

	Time b("23:56:05"), e("00:32:26");
	Bill a("�������", "892099999", 2.32, 5, b, e, 123);

	int menu = 1;
	int ind;

	while (menu) {
		std::cout << "1-�������� ����� ��������\n2-�������� �����\n3-�������� ������\n4-�������� ����� ������ ���������\n5-�������� ����� ��������� ���������\n6-�������� ����� � ������\n7-������ �������\n8-������ �����\n9-������ �����\n10-������ ������\n11-������ ����� ������ ���������\n12-������ ����� ��������� ���������\n13-������ ����� ���������\n14- ������ ����� � ������\n";

		ind = check();
		while (ind < 1 || ind>14)
		{
			std::cout << "����� ������ ����� �� 1 �� 14(������������)\n";
			ind = check();
		}

		switch (ind) {
		case 1:

		}
	}
	return 0;
}