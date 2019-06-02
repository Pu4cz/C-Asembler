#include <windows.h>
#include <stdlib.h>
// bibliotek do liczenia pola kwadratu, pola powierzchni bocznej i objetosci prostopadloscianu
unsigned int __declspec(dllexport) _stdcall
PolePowierzchni(int bok)
{
	int bok1 = bok;
	int wynik;
	wynik = bok1*bok1;
	return (int) wynik;
}

unsigned int __declspec(dllexport) _stdcall
PolePowierzchniBocznej(int podstawa1, int podstawa2, int wysokosc)
{
	int a = podstawa1;
	int b = podstawa2;
	int h = wysokosc;
	int wynik;
	wynik = 2 * a*b + 2 * b*h + 2 * a*h;
	return (int) wynik;
}

unsigned int __declspec(dllexport) _stdcall
Objetosc(int podstawa1, int podstawa2, int wysokosc)
{
	int a = podstawa1;
	int b = podstawa2;
	int h = wysokosc;
	int wynik;
	wynik = a*b*h;
	return (int) wynik;
}