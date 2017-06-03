#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

int tablica1[100];
int tablica2[100];
int licznik = 0;

long long int B = 54;

long long int funkcja_modulo(long long int podstawa, long long int potega, long long int modulo, long long int B)
{
	long long int wynik = 0;
	long long int a = 1;
	long long int b = podstawa;
	do
	{
		if (potega % 2 == 1) a = (a * b) % modulo;
		b = (b * b) % modulo;
		potega = potega / 2;
	} while (potega > 0);

	wynik = (B*a) % modulo;
	return wynik;
}


void testfermata(long long int liczba)
{
	long long int pierwiastek, y, z, m, n;
	pierwiastek = (long long int)floor(sqrt(liczba));
	if (sqrt(liczba) != floor(sqrt(liczba)))
	{
		pierwiastek = pierwiastek + 1;
		do
		{
			z = pierwiastek * pierwiastek - liczba;
			y = (long long int)floor(sqrt(z));
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

		printf("%lld ", liczba);
		tablica1[licznik] = liczba;
		licznik++;
	}
	else
	{
		liczba = sqrt(liczba);
		printf("%lld^2 ", liczba);
	}
}


int main()
{
	srand(time(NULL));
	long long int liczba;
	long long int r;
	long long int k;
	long long int podstawa;
	long long int a;
	long long int C1;
	long long int t;
	long long int P;

	long long int C2;
	long long int j = 34310;
	printf("PODAJ LICZBE PIERWSZA:");
	scanf_s("%lld", &liczba);
	printf("P:%lld\nROZKLAD P-1:%lld:", liczba, liczba - 1);
	podstawa = liczba;
	liczba = liczba - 1;
	while (liczba % 2 == 0)
	{
		liczba = liczba / 2;
		tablica1[licznik] = 2;
		printf("2 ");
		licznik++;
	}
	if (liczba > 1)
		testfermata(liczba);
	k = 2 + rand() % (podstawa - 1);
	int licznik2 = 0;

	while (licznik != licznik2)
	{
		r = 2 + rand() % (podstawa - 1);
		for (int i = 0; i < licznik; i++)
			tablica2[i] = funkcja_modulo(r, (podstawa - 1) / tablica1[i], podstawa, 1);

		for (int i = 0; i < licznik; i++)
		{
			if (tablica2[i] != 1)
			{
				licznik2++;
			}
			else
				licznik2 = 0;
		}
	}
	printf("\nR:%lld\nK:%lld\n", r, k);
	a = funkcja_modulo(r, k, podstawa, 1);
	C1 = funkcja_modulo(r, j, podstawa, 1);
	C2 = funkcja_modulo(a, j, podstawa, B);
	printf("A:%lld\n", a);
	printf("KLUCZ PUBLICZNY:(%lld,%lld,%lld)\n", podstawa, r, a);
	printf("J:%lld\n", j);
	printf("C1:%lld\nC2:%lld\n", C1, C2);
	t = funkcja_modulo(C1, podstawa - 1 - k, podstawa, 1);
	P = funkcja_modulo(C2, 1, podstawa, t);
	printf("T:%lld\nTWOJA WIADOMOSC TO:%lld\n", t, P);
	printf("\n");
	system("PAUSE");
	return 0;
}