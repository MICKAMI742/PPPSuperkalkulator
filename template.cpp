#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
// inicjacja zmiennej pod utworzenie dynamicznej tabliczy intow
int *tabOfNumbers;
vector<string> tabOfPositions;

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

int minimal(int n)
{
	int minVar = tabOfNumbers[0];
	for (int i = 1; i < n; i++)
	{
		if (tabOfNumbers[i] < minVar)
		{
			minVar = tabOfNumbers[i];
		}
	}
	return minVar;
}

// funkcja zwracajaca pozycje ktore zawieraja najmniejsze wartosci w ciagu
// f0(int n - wielkosc tablicy, int i - index od ktorego zaczynam przeszukiwanie tablicy)
int f0(int n, int i, int minimal)
{
	int minIndex = i - 1;
	string resultString = "";
	if (n == 1)
	{
		cout << 1;
	}
	if (tabOfNumbers[0] <= tabOfNumbers[i] && tabOfNumbers[0] == minimal)
	{
		tabOfPositions.push_back(to_string(minIndex + 1) + " ");
	}
	for (i; i < n; i++)
	{
		resultString = "";
		if (tabOfNumbers[i] <= tabOfNumbers[minIndex])
		{
			minIndex = i;
			if (tabOfNumbers[i] == minimal)
			{
				minIndex = i;
				resultString += to_string(minIndex + 1) + " ";
			}
			tabOfPositions.push_back(resultString);
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
		swap(tabOfNumbers[i], tabOfNumbers[f0(n, i + 1, minimal(n)) - 1]);
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
	float standardDeviation = 0;
	for (int i = 0; i < n; i++)
	{
		standardDeviation += tabOfNumbers[i];
	}
	standardDeviation /= n;
	float difference = 0;
	for (int i = 0; i < n; i++)
	{
		difference += (tabOfNumbers[i] - standardDeviation) * (tabOfNumbers[i] - standardDeviation);
	}
	standardDeviation = sqrt(difference / n);
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

bool f5(int number)
{
	std::vector<bool> isPrime(number + 1, true);
	std::vector<int> primes;

	for (int p = 2; p * p <= number; ++p)
	{
		if (isPrime[p])
		{
			for (int i = p * p; i <= number; i += p)
			{
				isPrime[i] = false;
			}
		}
	}

	for (int p = 2; p <= number; ++p)
	{
		if (isPrime[p])
		{
			primes.push_back(p);
		}
	}

	if (number == primes[primes.size() - 1])
	{
		return true;
	}
	else
	{
		return false;
	}
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

unsigned int f9(int n, unsigned int number)
{
	unsigned int i = 31;
	string binaryNumber;
	unsigned int bitsCounter = 0;
	while (i--)
	{
		// zamieniam liczbe int na liczbe w binarnym systemie i zapisuje jako string powstaly ciag
		binaryNumber += to_string((number >> i) & 1);
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
			f0(n, 1, minimal(n));
			for (auto x : tabOfPositions)
			{
				cout << x;
			}
			tabOfPositions.clear();
			cout << endl;
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
				cout << f5(tabOfNumbers[i]) << " ";
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
			string stringResult = "";
			for (int i = 0; i < n; i++)
			{
				stringResult += to_string(f9(n, tabOfNumbers[i])) + " ";
			}
			cout << stringResult << endl;
			break;
		}
	};
	return 0;
}
