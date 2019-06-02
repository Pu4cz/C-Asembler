#include <stdio.h>
int suma_liczb(int p, int q, int r);
int main()
{
	int wynik;
	wynik = suma_liczb(3, 5, 7);
	printf("\nSuma = %d\n", wynik);
	return 0;
}