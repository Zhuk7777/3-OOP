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
		std::cout << "нужно ввести число" << std::endl;
		std::cin >> x;
	}
	return x;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Time b("23:56:05"), e("00:32:26");
	Bill a("фамили€", "892099999", 2.32, 5, b, e, 123);

	int menu = 1;
	int ind;

	while (menu) {
		std::cout << "1-изменить номер телефона\n2-изменить тариф\n3-изменить скидку\n4-изменить врем€ начала разговора\n5-изменить врем€ окончани€ разговора\n6-изменить сумму к полате\n7-узнать фамилию\n8-узнать номер\n9-узнать тариф\n10-узнать скидку\n11-узнать врем€ начала разговора\n12-узнать врем€ окончани€ разговора\n13-узнать врем€ разговора\n14- узнать сумму к оплате\n";

		ind = check();
		while (ind < 1 || ind>14)
		{
			std::cout << "Ќужно ввести число от 1 до 14(включительно)\n";
			ind = check();
		}

		switch (ind) {
		case 1:

		}
	}
	return 0;
}