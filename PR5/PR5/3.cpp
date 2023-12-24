#include <iostream>
#include <Windows.h>
#include <time.h>
#include "course.h"

using std::cin;
using std::cout;
using std::swap;

HANDLE hConsole;

int getNumber(int N)
{
	return rand() % (N * N) + 1;
}

void clearArray(int* arr, int N)
{
	for (int* current = arr; current <= arr + N * N - 1; current++) {
		*current = 0;
	}
}

void showFilling(int* arr, int N)
{
	for (int* current = arr; current <= arr + N * N - 1; current++) {
		/**if (!(*current)) {
			cout << "\t";
		}*/
		//else {
		cout << *current << '\t';
		//}
		if (((current - arr) + 1) % N == 0) {
			cout << '\n';
		}
	}
}

void showPermutations(int* arr, int N, char type) //12 10 3 6
{
	int colors[4] = { 12, 10, 3, 6 };
	switch (type) {
	case 'a':
		colors[0] = 3; colors[1] = 12; colors[2] = 6; colors[3] = 10;
		// 10 3 6 12
		break;
	case 'b':
		colors[0] = 6; colors[1] = 3; colors[2] = 10; colors[3] = 12;
		break;
	case 'c':
		colors[0] = 3; colors[1] = 6; colors[2] = 12; colors[3] = 10;
		break;
	case 'd':
		colors[0] = 10; colors[1] = 12; colors[2] = 6; colors[3] = 3;
		break;
	default:
		break;
	}

	int* end = arr + N * N - 1;
	for (int* current = arr; current <= end; current++) {
		if ((current - arr) % N <= (N / 2 - 1) && (current - arr) / N <= (N / 2 - 1)) SetConsoleTextAttribute(hConsole, colors[0]);
		else if ((current - arr) % N > (N / 2 - 1) && (current - arr) / N <= (N / 2 - 1)) SetConsoleTextAttribute(hConsole, colors[1]);
		else if ((current - arr) % N <= (N / 2 - 1) && (current - arr) / N > (N / 2 - 1)) SetConsoleTextAttribute(hConsole, colors[2]);
		else if ((current - arr) % N > (N / 2 - 1) && (current - arr) / N > (N / 2 - 1)) SetConsoleTextAttribute(hConsole, colors[3]);

		cout << *current << '\t';
		if (((current - arr) + 1) % N == 0) {
			cout << '\n';
		}
	}
	SetConsoleTextAttribute(hConsole, 7);
}

void spiralise(int* arr, int N)
{
	srand(time(NULL));
	bool right = true, down = false, left = false, up = false;
	int i = 1;
	for (int* current = arr; i <= N * N; i++)
	{
		if (right) {
			if ((current - arr) % (N - 1) != 0 || (current - arr) == 0) {
				*current = getNumber(N);
				current++;
			}
			else {
				right = false;
				down = true;
				i--;
			}
		}

		else if (down) {
			if ((current - arr) % N != (current - arr) / N) {
				*current = getNumber(N);
				current += N;
			}
			else {
				down = false;
				left = true;
				i--;
			}
		}

		else if (left) {
			if (((current - arr) / N + ((current - arr) % N)) != (N - 1)) {
				*current = getNumber(N);
				current--;
			}
			else {
				left = false;
				up = true;
				i--;
			}
		}

		else if (up) {
			if (((current - arr) / N - (current - arr) % N) != 1) {
				*current = getNumber(N);
				current -= N;
			}
			else {
				up = false;
				right = true;
				i--;
			}
		}

		system("cls");
		showFilling(arr, N);
		Sleep(25);
	}

}

void snake(int* arr, int N) {
	srand(time(NULL));
	bool down = true, up = false;
	int i = 1;
	for (int* current = arr; i <= N * N; i++)
	{
		if (down) {
			if ((current - arr) / N < (N - 1)) {
				*current = getNumber(N);
				current += N;
			}
			else {
				*current = getNumber(N);
				current++;
				down = false;
				up = true;
			}
		}

		else if (up) {
			if ((current - arr) / N > 0) {
				*current = getNumber(N);
				current -= N;
			}
			else {
				*current = getNumber(N);
				current++;
				up = false;
				down = true;
			}
		}

		system("cls");
		showFilling(arr, N);
		Sleep(25);

	}
}

void permuteA(int* arr, int* newArr, int N)
{
	showPermutations(arr, N, 'h');
	cout << '\n';
	Sleep(1000);

	for (int* current = arr, *currentNew = newArr; current <= arr + N * N - 1; current++, currentNew++) {
		if ((current - arr) % N <= (N / 2 - 1) && (current - arr) / N <= (N / 2 - 1)) *currentNew = *(current + (N / 2) * N);
		else if ((current - arr) % N > (N / 2 - 1) && (current - arr) / N <= (N / 2 - 1)) *currentNew = *(current - N / 2);
		else if ((current - arr) % N <= (N / 2 - 1) && (current - arr) / N > (N / 2 - 1)) *currentNew = *(current + N / 2);
		else if ((current - arr) % N > (N / 2 - 1) && (current - arr) / N > (N / 2 - 1)) *currentNew = *(current - (N / 2) * N);
	}

	showPermutations(newArr, N, 'a');

}

void permuteB(int* arr, int* newArr, int N)
{
	showPermutations(arr, N, 'h');
	cout << '\n';
	Sleep(1000);

	for (int* current = arr, *currentNew = newArr; current <= arr + N * N - 1; current++, currentNew++) {
		if ((currentNew - newArr) % N <= (N / 2 - 1) && (currentNew - newArr) / N <= (N / 2 - 1)) *currentNew = *(current + (N + 1) * (N / 2));
		else if ((currentNew - newArr) % N > (N / 2 - 1) && (currentNew - newArr) / N <= (N / 2 - 1)) *currentNew = *(current + (N - 1) * (N / 2));
		else if ((currentNew - newArr) % N <= (N / 2 - 1) && (currentNew - newArr) / N > (N / 2 - 1)) *currentNew = *(current - (N - 1) * (N / 2));
		else if ((current - arr) % N > (N / 2 - 1) && (current - arr) / N > (N / 2 - 1)) *currentNew = *(current - (N + 1) * (N / 2));
	}

	showPermutations(newArr, N, 'b');

}

void permuteC(int* arr, int* newArr, int N)
{
	showPermutations(arr, N, 'h');
	cout << '\n';
	Sleep(1000);

	for (int* current = arr, *currentNew = newArr; current <= arr + N * N - 1; current++, currentNew++) {
		if ((currentNew - newArr) % N <= (N / 2 - 1) && (currentNew - newArr) / N <= (N / 2 - 1)) *currentNew = *(current + N * (N / 2));
		else if ((currentNew - newArr) % N > (N / 2 - 1) && (currentNew - newArr) / N <= (N / 2 - 1)) *currentNew = *(current + N * (N / 2));
		else if ((currentNew - newArr) % N <= (N / 2 - 1) && (currentNew - newArr) / N > (N / 2 - 1)) *currentNew = *(current - N * (N / 2));
		else if ((current - arr) % N > (N / 2 - 1) && (current - arr) / N > (N / 2 - 1)) *currentNew = *(current - N * (N / 2));
	}

	showPermutations(newArr, N, 'c');

}

void permuteD(int* arr, int* newArr, int N)
{
	showPermutations(arr, N, 'h');
	cout << '\n';
	Sleep(1000);

	for (int* current = arr, *currentNew = newArr; current <= arr + N * N - 1; current++, currentNew++) {
		if ((currentNew - newArr) % N <= (N / 2 - 1) && (currentNew - newArr) / N <= (N / 2 - 1)) *currentNew = *(current + N / 2);
		else if ((currentNew - newArr) % N > (N / 2 - 1) && (currentNew - newArr) / N <= (N / 2 - 1)) *currentNew = *(current - N / 2);
		else if ((currentNew - newArr) % N <= (N / 2 - 1) && (currentNew - newArr) / N > (N / 2 - 1)) *currentNew = *(current + N / 2);
		else if ((current - arr) % N > (N / 2 - 1) && (current - arr) / N > (N / 2 - 1)) *currentNew = *(current - N / 2);
	}

	showPermutations(newArr, N, 'd');

}

int* partition(int* array, int* start, int* end, int N)
{
	int* pivot = end;
	int* pIndex = start;

	for (int* i = start; i < end; i++)
	{
		if (*i <= *pivot)
		{
			system("cls");
			swap(*i, *pIndex);
			showFilling(array, N);
			Sleep(50);
			pIndex++;
		}
	}

	system("cls");
	swap(*pIndex, *end);
	showFilling(array, N);
	Sleep(50);

	return pIndex;
}

void quickSort(int* array, int* start, int* end, int N)
{
	if (start >= end) {
		return;
	}
	int* pivot = partition(array, start, end, N);

	quickSort(array, start, pivot - 1, N);
	quickSort(array, pivot + 1, end, N);
}

void IDZ(int N)
{
	int arr6[6][6] = {};
	int arr8[8][8] = {};
	int arr10[10][10] = {};

	int* ptr = nullptr;


	if (N == 6) {
		ptr = *arr6;
	}
	else if (N == 8) {
		ptr = *arr8;
	}
	else if (N == 10) {
		ptr = *arr10;
	}
	int* mx = ptr;

	if (ptr != nullptr) {
		srand(time(NULL));
		for (int* current = ptr; current <= ptr + N * N - 1; current++) {
			*current = rand() % 100 + 1;
			if (*current > *mx) {
				mx = current;
			}
		}

		system("cls");
		showFilling(ptr, N);
		cout << "Maximum: " << *mx << " (" << (mx - ptr) / N << ", " << (mx - ptr) % N << ")\n";

		int i;
		for (i = 0; i < (mx - ptr) / N; i++) {
			int* start = mx - (mx - ptr) % N - i * N;
			for (int* current = start; current <= start + N - 1; current++) {
				swap(*current, *(current - N));
			}
			Sleep(5000);
			system("cls");
			showFilling(ptr, N);
			cout << "Maximum: " << *(mx - (i + 1) * N) << " (" << (mx - (i + 1) * N - ptr) / N << ", " << (mx - (i + 1) * N - ptr) % N << ")\n";
		}

		for (int j = 0; j < (mx - ptr) % N; j++) {
			int* start = ptr + (mx - ptr) % N - j;
			for (int* current = start; current <= start + N * (N - 1); current += N) {
				swap(*current, *(current - 1));
			}
			Sleep(5000);
			system("cls");
			showFilling(ptr, N);
			cout << "Maximum: " << *(mx - j - 1 - i * N) << " (" << (mx - j - 1 - i * N - ptr) / N << ", " << (mx - j - 1 - i * N - ptr) % N << ")\n";
		}

	}
}

void output3()
{
	cout << "e) Введите e чтобы выйти.\n"
		<< "c) Введите c чтобы очистить последнюю использованную матрицу.\n"
		<< "h) Введите h чтобы увидеть комманды.\n"
		<< "0) Выбрать порядок матрицы(6, 8, 10).\n"
		<< "1) Заполнить квадратичную целочисленную матрицу порядка N(6, 8, 10) случайными числами от 1 до  N * N согласно схемам, приведенным на рисунках. (Введите 1a, 1b). Схемы: a) Спиралью; b) Змейкой.\n"
		<< "2) Получить новую матрицу, из матрицы п. 1, переставляя ее блоки в соответствии со схемами(Введите 2a, 2b, 2c, 2d). Схемы: a) по часовой; b) по диагонали; c) относительно горизонтали; d) относительно вертикали.\n"
		<< "3) Отсортировать элементы при помощи quicksort.\n"
		<< "4) Уменьшить, увеличить, умножить или делить все элементы матрицы на введенное число(+, -, *, /). (Введите операцию и число в одной строке).\n"
		<< "i) Введите i чтобы выполнить ИДЗ номер 2\n";
}

void launch3()
{
	int N = 0;

	int arr6[6][6] = {};
	int arr8[8][8] = {};
	int arr10[10][10] = {};

	int transposedArr6[6][6] = {};
	int transposedArr8[8][8] = {};
	int transposedArr10[10][10] = {};

	int* ptr = nullptr;

	char task = ' ';
	bool isClear = true;

	output3();
	do {
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
		cout << "Введите задачу(h - комманды): ";
		cin >> task;

		if (task == '0') {
			cout << "Введите порядок матрицы(6, 8, 10): ";
			cin >> N;
			if (N == 0) cout << '\n';
		}

		else if (task == '1') {
			cin >> task;
			if (task == 'a') {
				if (N == 6) {
					spiralise(*arr6, 6);
					ptr = *arr6;
				}
				else if (N == 8) {
					spiralise(*arr8, 8);
					ptr = *arr8;
				}
				else if (N == 10) {
					spiralise(*arr10, 10);
					ptr = *arr10;
				}
				isClear = false;
			}
			else if (task == 'b') {
				if (N == 6) {
					snake(*arr6, 6);
					ptr = *arr6;
				}
				else if (N == 8) {
					snake(*arr8, 8);
					ptr = *arr8;
				}
				else if (N == 10) {
					snake(*arr10, 10);
					ptr = *arr10;
				}
				isClear = false;
			}
		}

		else if (task == '2') {
			cin >> task;
			if (ptr != nullptr) {
				if (task == 'a') {
					if (N == 6) {
						permuteA(ptr, *transposedArr6, N);
					}
					else if (N == 8) {
						permuteA(ptr, *transposedArr8, N);
					}
					else if (N == 10) {
						permuteA(ptr, *transposedArr10, N);
					}
				}
				else if (task == 'b') {
					if (N == 6) {
						permuteB(ptr, *transposedArr6, N);
					}
					else if (N == 8) {
						permuteB(ptr, *transposedArr8, N);
					}
					else if (N == 10) {
						permuteB(ptr, *transposedArr10, N);
					}
				}
				else if (task == 'c') {
					if (N == 6) {
						permuteC(ptr, *transposedArr6, N);
					}
					else if (N == 8) {
						permuteC(ptr, *transposedArr8, N);
					}
					else if (N == 10) {
						permuteC(ptr, *transposedArr10, N);
					}
				}
				else if (task == 'd') {
					if (N == 6) {
						permuteD(ptr, *transposedArr6, N);
					}
					else if (N == 8) {
						permuteD(ptr, *transposedArr8, N);
					}
					else if (N == 10) {
						permuteD(ptr, *transposedArr10, N);
					}
				}
			}
		}

		else if (task == '3') {
			if (!isClear) {
				system("cls");
				showFilling(ptr, N);
				quickSort(ptr, ptr, ptr + N * N - 1, N);
			}
		}

		else if (task == '+' || task == '-' || task == '*' || task == '/') {
			int k = 0;
			cin >> k;
			if (ptr != nullptr) {
				showFilling(ptr, N);
				cout << "\n";
				if (task == '+') {
					for (int* current = ptr; current <= ptr + N * N - 1; current++) {
						*current = *current + k;
					}
				}
				else if (task == '-') {
					for (int* current = ptr; current <= ptr + N * N - 1; current++) {
						*current = *current - k;
					}
				}
				else if (task == '*') {
					for (int* current = ptr; current <= ptr + N * N - 1; current++) {
						*current = *current * k;
					}
				}
				else if (task == '/') {
					if (k != 0) {
						for (int* current = ptr; current <= ptr + N * N - 1; current++) {
							*current = *current / k;
						}
					}
					else {
						cout << "Делить на 0 нельзя!!! Запомни!!!\n";
					}
				}
				showFilling(ptr, N);
			}
			else {
				cout << "Сначала создайте матрицу!!!\n";
			}
		}

		else if (task == 'i') {
			IDZ(N);
		}

		else if (task == 'c') {
			if (N == 6) {
				clearArray(*arr6, 6);
				cout << "Матрица 6 порядка была обнулена\n";
			}
			else if (N == 8) {
				clearArray(*arr8, 8);
				cout << "Матрица 8 порядка была обнулена\n";
			}
			else if (N == 10) {
				clearArray(*arr10, 10);
				cout << "Матрица 10 порядка была обнулена\n";
			}
			else {
				cout << "Последняя использованная матрица уже пустая\n";
			}
			isClear = true;
		}
		else if (task == 'h') {
			output3();
		}

		cin.clear();
		cin.ignore(10000, '\n');

	} while (task != 'e');
}

void laba3() {
	setlocale(LC_ALL, "Russian");

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


	launch3();
}