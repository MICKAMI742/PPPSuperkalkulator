#include <iostream>
#include <cmath>

using namespace std;
// inicjacja zmiennej pod utworzenie dynamicznej tabliczy intow
int *tabOfNumbers;

// funkcja inicjujaca wielkosc tablicy i wczytujaca do niej dane
void readIntSequence(int n)
{
	tabOfNumbers = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> tabOfNumbers[i];
	}
}

// funkcja zwracajaca pozycje ktore zawieraja najmniejsze wartosci w ciagu
// f0(int n - wielkosc tablicy, int i - index od ktorego zaczynam przeszukiwanie tablicy)
int f0(int n, int i)
{
	int minIndex = i - 1;
	for (i; i < n; i++)
	{
		if (tabOfNumbers[i] < tabOfNumbers[minIndex])
		{
			minIndex = i;
		}
	}

	return minIndex;
}

// funkcja sortujaca wejsciowy ciag liczb
// sortowanie przez wybór
void f1(int n)
{
	int minIndex;
	int pom;
	for (int i = 0; i < n; i++)
	{
		minIndex = f0(n, i + 1);
		pom = tabOfNumbers[i];
		tabOfNumbers[i] = tabOfNumbers[minIndex];
		tabOfNumbers[minIndex] = pom;
	}
	for (int i = 0; i < n; i++)
	{
		cout << tabOfNumbers[i] << " ";
	}
	cout << endl;
}

// funkcja znajdujaca wartosc normy euklidesowej
int f2(int n)
{
	// int norm = sqrt(pow(x1, 2) + pow(x2, 2));
	int norm = 0;
	for (int i = 0; i < n; i++)
	{
		norm += pow(tabOfNumbers[i], 2);
	}
	norm = sqrt(norm);
	return norm;
}

// funkcja obliczajaca i zwracajaca wartosc odchylenia standardowego
int f3(int n)
{
	int avg = 0;
	int standardDeviation = 0;
	for (int i = 0; i < n; i++)
	{
		avg += tabOfNumbers[i];
	}
	avg /= n;
	for (int i = 0; i < n; i++)
	{
		standardDeviation += f2(n);
	}
	standardDeviation /= n;
	standardDeviation = sqrt(standardDeviation) - 1;
	return standardDeviation;
}

// funkcja odwracajaca tablice
void f4(int n)
{
	int pom;
	for (int i = 0; i < n / 2; i++)
	{
		pom = tabOfNumbers[i];
		tabOfNumbers[i] = tabOfNumbers[n - i - 1];
		tabOfNumbers[n - i - 1] = pom;
	}
	for (int i = 0; i < n; i++)
	{
		cout << tabOfNumbers[i] << " ";
	}
	cout << endl;
}

string f5(int n)
{
	int j = 2;
	string returningString;
	int m = 0;
	int L = 4;
	for (int i = 0; i < n; i++)
	{
		for (int j = 2; j < sqrt(tabOfNumbers[i]); i++)
		{
			m = pow(2, tabOfNumbers[i]) - 1;
		}
	}
	return returningString;
}

int main()
{
	int subprogram, n;

	while (cin >> subprogram >> n)
	{
		switch (subprogram)
		{
		case 0:
			readIntSequence(n);
			cout << f0(n, 1) << endl;
			break;
		case 1:
			readIntSequence(n);
			f1(n);
			break;
		case 2:
			readIntSequence(n);
			cout << f2(n);
			break;
		case 3:
			readIntSequence(n);
			cout << f3(n);
			break;
		case 4:
			readIntSequence(n);
			f4(n);
			break;
		case 5:
			readIntSequence(n);
			cout << f5(n);
			break;
		}
	};
	return 0;
}
