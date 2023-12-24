#include <iostream>
#include "Windows.h"
#include <stdio.h>
#include <fstream>
#include "course.h"

using std::cout;
using std::cin;

const int L = 50, M = 10;

int mySize(char* str) {
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}

void edit(char* str, int N)
{
	const int K = 8;
	char marks[] = "!,.?-: ;";
	str[0] = toupper(str[0]);
	for (int i = 0, j = 0; i < N; i++, j++) {
		if ((i < (N - 3)) && (str[i] == '.') && (str[i + 1] == '.') && (str[i + 2] == '.') && (str[i + 3] != '.')) {
			str[j] = str[i]; i++; j++;
			str[j] = str[i]; i++; j++;
		}
		for (int k = 0; k < K; k++) {
			while ((i < (N - 1)) && (str[i] == str[i + 1]) && (str[i] == marks[k])) {
				i++;
			}
		}
		if ((i < (N - 2)) && (str[i] == '.') && (str[i + 1] == ' ')) {
			str[i + 2] = toupper(str[i + 2]);
		}
		else if ((i < (N - 1)) && (str[i] == '.') && (((str[i + 1] >= 'a') && (str[i + 1] <= 'z')) || ((str[i + 1] >= '�') && (str[i + 1] <= '�')))) {
			str[i + 1] = toupper(str[i + 1]);
		}
		else if ((i < (N - 1)) && (('A' <= str[i + 1] <= 'Z') || ('�' <= str[i + 1] <= '�'))) {
			str[i + 1] = tolower(str[i + 1]);
		}
		str[j] = str[i];
	}
	cout << str << '\n';
}

void showWithOutNumbers(char* str, int N)
{
	//C:\\Users\\nmoln\\OneDrive\\������� ����\\�����\\Stepik\\������ �������������� � ���������������� �� ����� �++\\PR4\\PR4\\input.txt
	char sentence[L][M] = {};
	int j = 0, last = -1;
	for (int i = 0; i < mySize(str); i++) {
		if (str[i] == ' ') {
			if (!((i >= 1) && str[i - 1] == ' ')) {
				j++;
			}
			last = i;
		}
		else if (j >= L) {
			break;
		}
		else {
			sentence[j][i - last - 1] = str[i];
		}
	}

	int isNumber = false;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < M; j++) {
			if ((sentence[i][j] >= '0') && (sentence[i][j] <= '9')) {
				isNumber = true;
				break;
			}
		}
		if (!isNumber) {
			cout << sentence[i] << " ";
		}
		else {
			isNumber = false;
		}
	}

	cout << '\n';
}

void showCollumn(char* str, int N)
{
	char sentence[L][M] = {};
	int j = 0, last = -1;
	for (int i = 0; i < mySize(str); i++) {
		if (str[i] == ' ') {
			if (!((i >= 1) && str[i - 1] == ' ')) {
				j++;
			}
			last = i;
		}
		else if (j >= L) {
			break;
		}
		else {
			sentence[j][i - last - 1] = str[i];
		}
	}

	for (int i = 0; i < j; i++) {
		cout << sentence[i] << " ";
		if ((i + 1) % 3 == 0) {
			cout << '\n';
		}
	}

	cout << '\n';

}

int linearSearchSubstring(char* str, char* sub) {
	int n = mySize(str);
	int m = mySize(sub);
	for (int i = 0; i <= n - m; ++i) {
		int j;
		for (j = 0; j < m; ++j)
			if (str[i + j] != sub[j])
				break;
		if (j == m)
			return i;
	}
	return -1;
}
void output() {
	cout << "����������, �� ������� ������� ����� � ���� �����!!! ����������, �� ������� ����� �������� ����� 10 ����!!! ���� � ����� ����� ������������ ������� �����, �� ��������� ��� ���������!!!\n"
		<< "e) �����\n"
		<< "h) ��������\n"
		<< "s) �������� ������������������\n"
		<< "1) ������ ������������������ � ���������� ��� � ����� (�������: 1a ��� 1b; ���� �� ����� 1a, �� ����� �� ������� ������������������; ������: 1aJGNJGNjng akgargng 2n2job4o2b)\n"
		<< "2) ��������������� ������� �����\n"
		<< "3) ������� �� ����� ����� ������������������, �� ���������� ����\n"
		<< "4) ������� �� ����� ��� ����� ������������������ � ��� ��� ��� ������� (� ����������� �� ���������� ����) � ������������� ���� �� ������ ������� �������.\n"
		<< "5) ������� ������ ������� ��������� ���������, ������� �� ������(�������� �����)\n";
}

void launch()
{
	const int N = 1000;
	char str[N] = "";
	char task = ' ';

	std::ifstream file;

	output();
	do {
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
		cout << "������� ������(h - ��������): ";
		cin >> task;

		if (task == 'h') {
			output();
		}
		else if (task == 's') {
			cout << str << '\n';
		}
		else if (task == '1') {
			cin >> task;
			if (task == 'a') {
				cin.getline(str, N);
				cout << "������� Enter";
			}
			else if (task == 'b') {
				char url[1000] = "";
				cout << "������� ���� � �����(� �������� \\ � ����� ��� ������� ����): ";
				cin >> url;
				cout << url << '\n';
				file.open(url);
				if (file.is_open()) {
					file.getline(str, N);
					cout << "������������������ ���� ������� �� �����\n";
				}
				else {
					cout << "������������������ �� ���� ������� �� �����\n";
				}
			}
		}
		else if (task == '2') {
			edit(str, N);
		}
		else if (task == '3') {
			showWithOutNumbers(str, N);
		}
		else if (task == '4') {
			showCollumn(str, N);
		}

		else if (task == '5') {
			char sub[100] = {};
			cout << "������� ������: ";
			cin >> sub;
			int res = linearSearchSubstring(str, sub);
			cout << "������ ������ ��������� ���������: " << res << '\n';
		}

		cin.clear();
		cin.ignore(10000, '\n');

	} while (task != 'e');
}

void laba4()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	launch();
}