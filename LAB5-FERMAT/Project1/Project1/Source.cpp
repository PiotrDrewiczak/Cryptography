#include <iostream>
#include <cmath>

using namespace std;
int tablica1[100];
int licznik = 0;

unsigned int funkcja_modulo(unsigned int podstawa, unsigned int potega, unsigned int modulo)
{

	unsigned int  wynik = 0;
	unsigned int a = 1;
	unsigned int c = podstawa;
	do
	{
		if (potega % 2 == 1) a = (a * c) % modulo;
		c = (c * c) % modulo;
		potega = potega / 2;
	} while (potega > 0);

	wynik = a % modulo;
	return wynik;


}

void testfermata(unsigned int liczba)
{
	unsigned long long pierwiastek, y, z, m, n;
	pierwiastek = (unsigned long long)floor(sqrt(liczba));
	if (sqrt(liczba) != floor(sqrt(liczba)))
	{
		pierwiastek = pierwiastek + 1;
		do
		{
			z = pierwiastek * pierwiastek - liczba;
			y = (unsigned long long)floor(sqrt(z));
			if (y*y>0 && z == y * y)
			{
				m = pierwiastek + y;
				n = pierwiastek - y;
				if (n == 1) break;
				testfermata(m);
				testfermata(n);
				return;
			}
			pierwiastek++;
		} while (pierwiastek  < ((liczba + 1) / 2));

		cout << liczba << " ";
		tablica1[licznik] = liczba;
		licznik++;
	}
	else
	{
		liczba = sqrt(liczba);
		cout << liczba << "^2  ";
	}
}


int main()
{
	int licznik2 = 0;
	unsigned int liczba;
	unsigned int b;
	unsigned int c;
	unsigned int podstawa;
	cout << "PODAJ LICZBE" << endl;
	cin >> liczba;
	cout << "ROZKLAD LICZBY-1" << endl;
	podstawa = liczba;
	liczba = liczba - 1;
	while (liczba % 2 == 0)
	{
		liczba = liczba / 2;
		tablica1[licznik] = 2;
		cout << "2 ";
		licznik++;
	}
	if (liczba > 1)
		testfermata(liczba);
	cout << endl;
	cout << "PODAJ PODSTAWE" << endl;
	cin >> c;



	b = funkcja_modulo(c, podstawa - 1, podstawa);
	if (b == 1)
	{
		cout << "WYNIK PRZYSTAJE DO:" << b << endl;
		for (int i = 0; i < licznik; i++)
		{
			b = 0;
			b = funkcja_modulo(c, ((podstawa - 1) / tablica1[i]), podstawa);
			if (b == 1)
			{
				cout << c << " DO POTEGI " << ((podstawa - 1) / tablica1[i]) << " MODULO " << podstawa << " PRZYSTAJE DO 1 " << endl;
				licznik2++;
				break;
			}
			else
			{
				cout << c << " DO POTEGI " << ((podstawa - 1) / tablica1[i]) << " MODULO " << podstawa << " NIE PRZYSTAJE DO 1 " << endl;
			}
		}
	}
	else
		cout << "WYNIKIEM NIE PRZYSTAJE DO:1,KONIEC PROGRAMU" << endl;

	if (licznik2 > 0)
	{
		cout << "NIE MOZNA OKRESLIC CZY " << podstawa << " JEST PIERWSZA" << endl;
	}

	else
	{
		cout << podstawa << " JEST PIERWSZA" << endl;

	}



	system("PAUSE");
	return 0;
}