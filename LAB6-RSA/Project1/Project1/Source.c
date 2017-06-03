#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int tablica1[1000];
int tablica2[1000];
int licznik = 0;
int en;
int ee;


long long int funkcja_modulo(long long int podstawa, long long int potega, long long int modulo)
{
	long long int wynik1 = 0;
	long long int a = 1;
	long long int b = podstawa;
	do
	{
		if (potega % 2 == 1) a = (a * b) % modulo;
		b = (b * b) % modulo;
		potega = potega / 2;
	} while (potega > 0);

	wynik1 = a % modulo;
	return wynik1;
}

int euklides(int e, int fi)
{
	int liczba = fi;
	int r, nwd, a, q, b;
	int x, x1, x2;
	int y, y1, y2;

	if (fi > e)
	{
		nwd = fi;
		fi = e;
		e = nwd;
	}
	a = e;
	b = fi;

	q = a / b;
	r = a - q*b;
	nwd = b;

	x2 = 1;
	x1 = 0;
	y2 = 0;
	y1 = 1;
	x = 1;
	y = y2 - (q - 1)*y1;

	while (r != 0)
	{
		a = b;
		b = r;

		x = x2 - q*x1;
		x2 = x1;
		x1 = x;

		y = y2 - q*y1;
		y2 = y1;
		y1 = y;

		nwd = r;
		q = a / b;
		r = a - q*b;
	}
	if (x < 0)
		x = x + liczba;


	printf("NWD(%i, %i = %i = %i * %i + %i * %i\n\n", e, fi, nwd, x, e, y, fi);

	if (nwd == 1)
		printf("%i * %i mod %i = 1\n\n", fi, y, e);

	printf("Twoim kluczem prywatnym jest(%i,%i)\nTwoim kluczem publicznym jest(%i,%i)\n", en, x, en, ee);

	return x;

}

int nwd(int e, int fi)
{
	while (e != fi)
	{
		if (e > fi)
		{
			e -= fi;
		}
		else
		{
			fi -= e;
		}
	}
	return e;

}

int sitko(int liczba, int dzielnik, int j)
{
	int maksymalna = 0;
	for (int i = j; i < liczba - 1; i++)
	{
		if (tablica1[i] % dzielnik == 0 && tablica1[i] != 0)
		{
			tablica1[i] = 0;
		}
		else if (tablica1[i] != 0)
			maksymalna = tablica1[i];
	}
	if (maksymalna > pow(dzielnik, 2.0))
	{
		return sito(liczba, dzielnik);
	}
	else
		return 0;

}

int sito(int liczba, int dzielnik)
{
	int j = 0;
	int maksymalna = 0;
	for (int i = 0; i < liczba - 1; i++)
	{
		if (tablica1[i] != 0 && dzielnik != tablica1[i])
		{
			dzielnik = tablica1[i];
			j = j + 1;
			tablica2[licznik] = dzielnik;
			licznik++;
			sitko(liczba, dzielnik, j);
		}
	}
	return 0;
}

int main()
{
	int p, q, liczba, dzielnik = 0, n, fi = 0, e = 0, wyniknwd, wynik, m;

	srand(time(NULL));
	liczba = 500;

	for (int i = 0; i < liczba - 1; i++)
		tablica1[i] = i + 2;

	sito(liczba, dzielnik);
	p = tablica2[rand() % licznik];
	q = tablica2[rand() % licznik];
	n = p*q;
	en = n;
	fi = ((p - 1)*(q - 1));

	do
	{
		e = (rand() % fi) + 1;
		wyniknwd = nwd(e, fi);
	} while (wyniknwd != 1);
	ee = e;
	printf("P:%i Q:%i N:%i fi(N):%i E:%i NWD(E,FI):%i\n\n", p, q, n, fi, e, wyniknwd);
	wyniknwd = 0;
	wynik = euklides(e, fi);

	printf("Podaj m:");
	scanf_s("%i", &m);

	int modulo = funkcja_modulo(m, ee, en);
	printf("C:%i^%i mod %i=%i\n", m, ee, en, modulo);

	int modulo2 = funkcja_modulo(modulo, wynik, en);
	printf("M:%i^%i mod %i=%i\n", modulo, wynik, en, modulo2);


	system("PAUSE");
	return 0;
}