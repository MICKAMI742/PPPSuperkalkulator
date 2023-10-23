#include <iostream>
#include <cmath>

using namespace std;
// inicjacja zmiennej pod utworzenie dynamicznej tabliczy intow
int *tabOfNumbers;

// inicjacja struktury służącej do zadania 6
struct points
{
	int x, y;
};

points *tabOfPoints;

// funkcja inicjujaca wielkosc tablicy i wczytujaca do niej dane
void readIntSequence(int n)
{
	tabOfNumbers = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> tabOfNumbers[i];
	}
}

// funkcja wczytujaca punkty do struktury
void setPointsToStruct(int n)
{
	tabOfPoints = new points[n];
	for (int i = 0; i < n; i++)
	{
		cin >> tabOfPoints[i].x;
		cin >> tabOfPoints[i].y;
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

bool *f5(int n)
{
	bool *tabOfBool = new bool(n);
	// wypelnia pusta tablice wartosciami boolowymi, zeby zapobiec przed artefaktami w pamieci
	for (int i = 0; i < n; i++)
	{
		tabOfBool[i] = 0;
	}
	// petla sprawdzajaca czy liczba jest pierwsza
	for (int i = 0; i < n; i++)
	{
		if (tabOfNumbers[i] == 2)
		{
			tabOfBool[i] = 1;
			continue;
		}

		for (int j = 2; j <= sqrt(tabOfNumbers[i]); j++)
		{
			if (tabOfNumbers[i] % j == 0)
			{
				tabOfBool[i] = 0;
			}
			tabOfBool[i] = 1;
		}
	}
	return tabOfBool;
}

void f6(int n)
{
	points triangles[n][3];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			triangles[i][j].x = 0;
			triangles[i][j].y = 0;
		}
	}
	int k = 0;
	for (int i = 1; i < n - 1; i++)
	{
		triangles[k][0] = tabOfPoints[0];
		triangles[k][1] = tabOfPoints[i];
		triangles[k][2] = tabOfPoints[i + 1];
		k++;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << triangles[i][j].x << " " << triangles[i][j].y << endl;
		}
		cout << endl;
	}
}

void f7(int n)
{
	int a = tabOfNumbers[0];
	int b = tabOfNumbers[1];
	int c = tabOfNumbers[2];
	int d = tabOfNumbers[3];
	int firstX = 0;
	int secondX = 0;
	int delta = 0;
	if (a == 0)
	{
		delta = pow(c, 2) - 4 * b * d; // obli5czam delte
		if (delta > 0)
		{
			firstX = (-c + sqrt(delta)) / (2 * b);
			secondX = (-c - sqrt(delta)) / (2 * b);
			cout << firstX << endl;
			cout << secondX << endl;
		}
		if (delta == 0)
		{
			firstX = -c / (2 * b);
			cout << firstX << endl;
		}
	}
	else
	{
	}
}

int f8(int n)
{
	int result = 0;
	for (int i = 1; i <= tabOfNumbers[n - 1]; i++)
	{
		result += i * pow(i + 1, 2);
	}
	return result;
}

int f9(int n)
{
	int i = 31;
	string binaryNumber;
	int bitsCounter = 0;
	while (i--)
	{
		// zamieniam liczbe int na liczbe w binarnym systemie i zapisuje jako string powstaly ciag
		binaryNumber += to_string((tabOfNumbers[0] >> i) & 1);
	}
	for (int i = 0; i < binaryNumber.size(); i++)
	{
		// zliczam chary ktore sa jedynka
		if (binaryNumber[i] == '1')
			bitsCounter++;
	}
	return bitsCounter;
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
			cout << f2(n) << endl;
			break;
		case 3:
			readIntSequence(n);
			cout << f3(n) << endl;
			break;
		case 4:
			readIntSequence(n);
			f4(n);
			break;
		case 5:
			readIntSequence(n);
			for (int i = 0; i < n; i++)
			{
				bool *array = f5(n);
				cout << array[i] << " ";
			}
			cout << endl;
			break;
		case 6:
			setPointsToStruct(n);
			f6(n);
			break;
		case 7:
			readIntSequence(n);
			f7(n);
			break;
		case 8:
			readIntSequence(n);
			cout << f8(n) << endl;
			break;
		case 9:
			readIntSequence(n);
			cout << f9(n) << endl;
			break;
		}
	};
	return 0;
}
