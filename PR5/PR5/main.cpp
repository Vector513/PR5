#include <iostream>
#include "course.h"

using std::cin;
using std::cout;


int main() 
{
	setlocale(LC_ALL, "Russian");
	
	char task = ' ';

	cout << "������� (1, 2, 3, 4) ����� ������� ������������ ������\n";
	do {
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
		cout << "������� ������(h - ��������): ";
		cin >> task;
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";

		if (task == 'h') {
			cout << "������� (1, 2, 3, 4) ����� ������� ������������ ������\n";
		}
		else if (task == '1') {
			laba1();
		}
		else if (task == '2') {
			laba2();
		}
		else if (task == '3') {
			laba3();
		}
		else if (task == '4') {
			laba4();
		}
	

		cin.clear();
		cin.ignore(10000, '\n');

	} while (task != 'e');


	return 0;
}