#include <iostream>
#include <chrono>
#include <time.h>
#include "course.h"

using namespace std;
using namespace chrono;

int getNumber() {
	return rand() % 200 - 100;
}

void fillArray(int array[], int N) {
	srand(time(NULL));

	for (int i = 0; i < N; i++) {
		array[i] = getNumber();
	}

}

void bubbleSort(int array[], int N) {
	for (int i = 0; i < N; i++) {
		bool notSwap = true;
		for (int j = 0; j < N - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
				notSwap = false;
			}
		}
		if (notSwap) {
			break;
		}
	}
}

void shakerSort(int array[], int N)
{
	for (int k = 0; k < N; k++) {
		bool notSwap = true;
		for (int i = k; i < N - 1 - k; i++) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
				notSwap = false;
			}
		}
		for (int j = N - 1 - k; j > k; j--) {
			if (array[j] < array[j - 1]) {
				swap(array[j], array[j - 1]);
				notSwap = false;
			}
		}
		if (notSwap) {
			break;
		}
	}
}

int getNextGap(int gap)
{
	gap = (gap * 10) / 13;

	if (gap < 1)
		return 1;
	return gap;
}

void combSort(int array[], int N)
{
	int gap = N;
	bool swapped = true;

	while (gap != 1 || swapped == true)
	{
		gap = getNextGap(gap);
		swapped = false;

		for (int i = 0; i < N - gap; i++)
		{
			if (array[i] > array[i + gap])
			{
				swap(array[i], array[i + gap]);
				swapped = true;
			}
		}
	}
}

void insertSort(int array[], int N)
{
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (array[j] < array[j - 1]) {
				swap(array[j], array[j - 1]);
			}
			else break;
		}
	}
}

int partition(int array[], int start, int end)
{
	int pivot = array[end];
	int pIndex = start;

	for (int i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(array[i], array[pIndex]);
			pIndex++;
		}
	}

	swap(array[pIndex], array[end]);

	return pIndex;
}

void quickSort(int array[], int start, int end)
{
	if (start >= end) {
		return;
	}
	int pivot = partition(array, start, end);

	quickSort(array, start, pivot - 1);
	quickSort(array, pivot + 1, end);
}

int binarySearch(int arr[], int left, int right, int x)
{
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == x) {
			return mid;
		}
		if (arr[mid] < x) {
			return binarySearch(arr, mid + 1, right, x);
		}
		else {
			return binarySearch(arr, left, mid - 1, x);
		}
	}
	return -1;
}

void timeForQuickSort()
{
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;
	const int N = 100;
	int array[N]{};

	fillArray(array, N);
	cout << "Unsorted Array: ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << "\n\n";

	start = steady_clock::now();
	quickSort(array, 0, N - 1);
	end = steady_clock::now();

	cout << "Sorted Array: ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << "\n\n";

	result = duration_cast<nanoseconds>(end - start);
	cout << "Time for Quick Sort: " << result.count() << " ns (" << (result.count() / 1000000.0) << " ms)" << "\n";

}

void searchMinMax()
{
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;

	const int N = 100;
	int unsortedArray[N]{};
	fillArray(unsortedArray, N);

	start = steady_clock::now();
	int mn = unsortedArray[0];
	int mx = unsortedArray[0];

	for (int i = 1; i < N; i++) {
		mn = min(mn, unsortedArray[i]);
		mx = max(mx, unsortedArray[i]);
	}
	end = steady_clock::now();

	cout << "Minimum: " << mn << "\t" << "Maximum: " << mx << "\n";

	result = duration_cast<nanoseconds>(end - start);
	cout << "Time for searching the Minimum and Maximum in the Unsorted Array: "
		<< result.count() << " ns (" << (result.count() / 1000000.0) << " ms)" << "\n";

	int sortedArray[N]{};
	fillArray(sortedArray, N);
	bubbleSort(sortedArray, N);

	start = steady_clock::now();

	mn = sortedArray[0];
	mx = sortedArray[N - 1];

	end = steady_clock::now();

	cout << "Minimum: " << mn << "\t" << "Maximum: " << mx << "\n";

	result = duration_cast<nanoseconds>(end - start);
	cout << "Time for searching the Minimum and Maximum in the Sorted Array: "
		<< result.count() << " ns (" << (result.count() / 1000000.0) << " ms)" << "\n";
}

void averageValue()
{
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;

	const int N = 100;
	int unsortedArray[N]{};
	fillArray(unsortedArray, N);

	int sortedArray[N]{};
	fillArray(sortedArray, N);
	quickSort(sortedArray, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << sortedArray[i] << " ";
	}
	cout << "\n";

	int mn = sortedArray[0];
	int mx = sortedArray[N - 1];
	int averageValue = round((mx + mn) / 2.0);

	cout << "Average Value: " << averageValue << "\n";

	int count = 0;
	cout << "Indexes in unsorted array: ";
	start = steady_clock::now();
	for (int i = 0; i < N; i++) {
		if (unsortedArray[i] == averageValue) {
			cout << i << " ";
			count++;
		}
	}
	end = steady_clock::now();

	result = duration_cast<nanoseconds>(end - start);
	cout << "\n" << "Time to count in unsorted array: " << result.count() << " ns (" << (result.count() / 1000000.0) << " ms)\n";


	cout << "Indexes in sorted array: ";
	start = steady_clock::now();
	count = 0;
	int index = binarySearch(sortedArray, 0, N - 1, averageValue);
	if (index != -1) {
		cout << index << " ";
		bool isTheFirst = false, isTheLast = false;
		count = 1; int step = 1;
		while ((!isTheFirst || !isTheLast) && step <= N) {
			if ((index - step) < 0) {
				isTheFirst = true;
			}
			else if (!isTheFirst && (index - step) >= 0 && ((index - step) <= (N - 1)) && sortedArray[index - step] == averageValue) {
				cout << (index - step) << " ";
				count++;
			}
			if ((index + step) > (N - 1)) {
				isTheLast = false;
			}
			else if (!isTheLast && (index + step) <= (N - 1) && ((index + step) >= 0) && sortedArray[index + step] == averageValue) {
				cout << (index + step) << " ";
				count++;
			}
			step++;
		}

	}
	end = steady_clock::now();

	result = duration_cast<nanoseconds>(end - start);
	cout << "\n" << "Time to count in sorted array: " << result.count() << " ns (" << (result.count() / 1000000.0) << " ms)\n";
	cout << "Count: " << count << "\n";

}

void lessThanA(int point)
{
	const int N = 100;
	int array[N]{};
	fillArray(array, N);
	quickSort(array, 0, N - 1);

	cout << "Sorted Array: ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << "\n\n";

	int i = binarySearch(array, 0, N - 1, point - 1), elem = point - 1;
	while ((i == -1) && (elem >= -99)) {
		i = binarySearch(array, 0, N - 1, --elem);
	}

	for (i; i < N; i++) {
		if (array[i] >= point) {
			break;
		}
	}
	int res = i;

	cout << "Count of numbers less than A: " << res << "\n";
}

void moreThanB(int point) {
	const int N = 100;
	int array[N]{};
	fillArray(array, N);
	quickSort(array, 0, N - 1);

	cout << "Sorted Array: ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << "\n\n";

	int i = binarySearch(array, 0, N - 1, point + 1), elem = point + 1;
	while ((i == -1) && (elem <= 99)) {
		i = binarySearch(array, 0, N - 1, ++elem);
	}

	for (i; i >= 0; i--) {
		if (array[i] <= point) {
			break;
		}
	}
	int res;
	if (point >= 99) {
		res = 0;
	}
	else if (point <= -101) {
		res = 100;
	}
	else {
		res = 100 - (i + 1);
	}

	cout << "Count of numbers more than B: " << res << "\n";
}

void compareTime(int x) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;

	const int N = 100;
	int array[N] = {};
	fillArray(array, N);
	quickSort(array, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << "\n\n";

	bool isThere;
	start = steady_clock::now();
	binarySearch(array, 0, N - 1, x);
	end = steady_clock::now();
	isThere = binarySearch(array, 0, N - 1, x) != -1;

	cout << "Is there number: " << (isThere ? "true" : "false") << "\n";

	result = duration_cast<nanoseconds>(end - start);
	cout << "Time for Binary Search: " << result.count() << " ns (" << (result.count() / 1000000.0) << " ms)" << "\n";

	int i = 0;
	start = steady_clock::now();
	while (array[i] <= x) {
		if (array[i] == x) {
			break;
		}
		i++;
	}
	end = steady_clock::now();

	result = duration_cast<nanoseconds>(end - start);
	cout << "Time for Brute Force: " << result.count() << " ns (" << (result.count() / 1000000.0) << " ms)" << "\n";

}

void replace(int i, int j)
{
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;

	const int N = 100;
	int array[N] = {};
	fillArray(array, N);

	for (int k = 0; k < N; k++) {
		if (k == i || k == j) {
			cout << '|' << array[k] << "| ";
		}
		else {
			cout << array[k] << ' ';
		}
	}
	cout << "\n\n";


	start = steady_clock::now();
	swap(array[i], array[j]);
	end = steady_clock::now();

	for (int k = 0; k < N; k++) {
		if (k == i || k == j) {
			cout << '|' << array[k] << "| ";
		}
		else {
			cout << array[k] << ' ';
		}
	}
	cout << "\n";

	result = duration_cast<nanoseconds>(end - start);
	cout << "\n" << "Time to swap elements: " << result.count() << " ns (" << (result.count() / 1000000.0) << " ms)\n";

}

void generator() { // IDZ
	const int N = 100;
	int array[N] = {};
	fillArray(array, N);

	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << "\n\n";
	cout << "Comb Sort Перестановки: ";

	int gap = N, count = 0;
	bool swapped = true;

	while (gap != 1 || swapped == true)
	{
		gap = getNextGap(gap);
		swapped = false;

		for (int i = 0; i < N - gap; i++)
		{
			if (array[i] > array[i + gap])
			{
				cout << "swap(" << i << ", " << (i + gap) << ") ";
				swap(array[i], array[i + gap]);
				count++;
				swapped = true;
			}
		}
	}
	cout << "\n\nКоличество перестановок Comb Sort: " << count << "\n";

}

void launch(char task) {
	switch (task) {
	case '1':
		timeForQuickSort();
		break;
	case '2':
		searchMinMax();
		break;
	case '3':
		averageValue();
		break;
	case '4':
		int a;
		cout << "Введите число a: ";
		cin >> a;
		cout << "\n";
		lessThanA(a);
		break;
	case '5':
		int b;
		cout << "Введите число b: ";
		cin >> b;
		cout << "\n";
		moreThanB(b);
		break;
	case '6':
		int n;
		cout << "Введите искомое число: ";
		cin >> n;
		cout << "\n";
		compareTime(n);
		break;
	case '7':
		int i, j;
		cout << "Введите индексы заменяемых элементов(i, j): ";
		cin >> i >> j;
		cout << "\n";
		replace(i, j);
		break;
	case '8':
		cout << "\n";
		generator();
		break;
	}
}

void laba2() {
	setlocale(LC_ALL, "Russian");

	cout << "1) Отсортировать заданный в пункте 1 массив […] сортировкой (от меньшего к большему). Определить время, затраченное на сортировку, используя библиотеку chrono.\n"
		<< "2) Найти максимальный и минимальный элемент массива.Подсчитайте время поиска этих элементов в отсортированном массиве и неотсортированном, используя библиотеку chrono.\n"
		<< "3) Выводит среднее значение (если необходимо, число нужно округлить) максимального и минимального значения в отсортированном и неотсортированном. Выводит индексы всех элементов, которые равны этому значению, и их количество. Подсчитайте время поиска.\n"
		<< "4) Выводит количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем.\n"
		<< "5) Выводит количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем.\n"
		<< "6) Выводит информацию о том, есть ли введенное пользователем число в отсортированном массиве. Реализуйте алгоритм бинарного поиска. Сравните скорость его работы с обычным перебором. (*)\n"
		<< "7) Меняет местами элементы массива, индексы которых вводит пользователь. Выведите скорость обмена, используя библиотеку chrono.\n"
		<< "8) ИДЗ: Генератор проверочных работ(сортировка, итерации и их количество).\n"
		<< "0) Чтобы выйти\n";

	char command[1000] = {}; //буфер ввода, чтобы программа не легла
	bool running = true;
	while (running) {

		cout << "---------------------------------------------------------------------------------------------------------------------\n";
		cout << "Enter the Command: ";

		cin >> command;

		if (command[1] == NULL) {
			if (command[0] == '0') {
				break;
			}
			else if ('1' <= command[0] <= '8') {
				launch(command[0]);
			}

		}

	}

}