#include <stdio.h>
#include "funkcje.h"
int main()
{
	int a;
	int a1, b1, h1;
	int a2, b2, h2;
	printf("\nPodaj dlugosc boku kwadratu:");
	scanf_s("%d", &a);
	printf("\nPole kwadratu wynosi: %d \n",
		PolePowierzchni(a));

	printf("\nPodaj wymiary prostopadloscianu.\n Podstawa: ");
	scanf_s("%d", &a1);
	scanf_s("%d", &b1);
	printf("\nWysokosc: ");
	scanf_s("%d", &h1);
	printf("\nPole powierzchni bocznej wynosi: %d \n",
		PolePowierzchniBocznej(a1, b1, h1));

	printf("\nPodaj wymiary prostopadloscianu.\n Podstawa: ");
	scanf_s("%d", &a2);
	scanf_s("%d", &b2);
	printf("\nWysokosc: ");
	scanf_s("%d", &h2);
	printf("\nObjetosc wynosi: %d \n",
		Objetosc(a2, b2, h2));

	return 0;
}