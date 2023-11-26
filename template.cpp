#include <iostream>
#include <cmath>
#include <vector>
#include <string>

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
	tabOfPoints = new points[n / 3];
	for (int i = 0; i < n / 2; i++)
	{
		cin >> tabOfPoints[i].x >> tabOfPoints[i].y;
	}
}

// funkcja zwracajaca pozycje ktore zawieraja najmniejsze wartosci w ciagu
// f0(int n - wielkosc tablicy, int i - index od ktorego zaczynam przeszukiwanie tablicy)
int f0(int n, int i)
{
	int minIndex = i - 1;
	for (i; i < n; i++)
	{
		if (tabOfNumbers[i] <= tabOfNumbers[minIndex])
		{
			minIndex = i;
		}
	}
	return minIndex + 1;
}

// funkcja sortujaca wejsciowy ciag liczb
// sortowanie przez wybór
void f1(int n)
{
	for (int i = 0; i < n; i++)
	{
		swap(tabOfNumbers[i], tabOfNumbers[f0(n, i + 1) - 1]);
	}
	int start = 0;
	int end = n - 1;
	// odwracam tablice, ponieważ sortuje się ona rosnąco jeśli wybieramy najmniejszy element
	while (start < end)
	{
		swap(tabOfNumbers[start], tabOfNumbers[end]);
		start++;
		end--;
	}
	cout << endl;
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
		norm += tabOfNumbers[i] * tabOfNumbers[i];
	}
	norm = sqrt(norm);
	return norm;
}

// funkcja obliczajaca i zwracajaca wartosc odchylenia standardowego
int f3(int n)
{
	int standardDeviation = 0;
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
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		swap(tabOfNumbers[start], tabOfNumbers[end]);
		start++;
		end--;
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

int f6(int n)
{
	vector<vector<points>> triangles{0};
	int a, b, c;
	int s = 0;
	int areaOfFigure = 0;
	// podział wielokąta na trojkaty zaczynajac od jednego wierzcholka
	// działamy tylko dla połowy zakresu n, ponieważ wtedy tablica nie wypełni się nie prawdziwymi punktami
	for (int i = 1; i < (n / 2) - 1; i++)
	{
		triangles.push_back({tabOfPoints[0], tabOfPoints[i], tabOfPoints[i + 1]});
	}
	// obliczanie dlugosci bokow trojkatow i ich pol
	for (int i = 0; i < triangles.size(); i++)
	{
		a = sqrt(pow(triangles[i][1].x - triangles[i][0].x, 2) + pow(triangles[i][1].y - triangles[i][0].y, 2));
		b = sqrt(pow(triangles[i][2].x - triangles[i][1].x, 2) + pow(triangles[i][2].y - triangles[i][1].y, 2));
		c = sqrt(pow(triangles[i][0].x - triangles[i][2].x, 2) + pow(triangles[i][0].y - triangles[i][2].y, 2));
		s = (a + b + c) / 2;
		// pierwiastek musi byc zaokraglany w gore, poniewaz zwraca mniejsza wartosc niz jest rzeczywiscie
		areaOfFigure += ceil(sqrt(s * (s - a) * (s - b) * (s - c)));
	}
	return areaOfFigure;
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
		delta = pow(c, 2) - 4 * b * d; // obliczam delte
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

long long f8(int n)
{
	long long result = 0;
	long long maxVal = tabOfNumbers[n - 1];
	result = maxVal * (maxVal + 1) * (3 * maxVal * (maxVal + 1) + 8 * maxVal + 10) / 12;
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
			f0(n, 1);
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
			cout << f6(n) << endl;
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
	free(tabOfNumbers);
	free(tabOfPoints);
	return 0;
}
