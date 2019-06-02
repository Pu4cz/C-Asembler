#include <windows.h>
#include <stdlib.h>
BOOL WINAPI DllEntryPoint(HINSTANCE hinstDLL,
	DWORD fdwReason, LPVOID lpvReserved)
{
	return(TRUE);
}
//===========================================================
unsigned int __declspec(dllexport) _stdcall
PodajRozmiarObszaruNiezajetego(char symbol_dysku)
{
	unsigned __int64 l_dostepnych;
	BOOL odp;
	unsigned int wynik;
	char dysk[4] = " :\\";
	if (!isalpha(symbol_dysku)) return 0xFFFFFFFF;
	// blad, jesli symbol dysku nie jest litera
	dysk[0] = symbol_dysku;
	odp = GetDiskFreeSpaceEx((LPCSTR)dysk,
		(PULARGE_INTEGER)&l_dostepnych, NULL, NULL);
	if (!odp) return 0xFFFFFFFF;
	// blad, jesli nie mozna ustalic rozmiaru
	// wyznaczenie liczby megabajtów - dzielenie przez 2^20
	wynik = (unsigned int)(l_dostepnych >> 20);
	return (unsigned int)wynik;
}
//===========================================================
unsigned int __declspec(dllexport) _stdcall
PodajRozmiarObszaruZajetego(char symbol_dysku)
{
	unsigned __int64 l_pojemnosc, l_wolnych, l_zajetych;
	unsigned int wynik;
	BOOL odp;
	char dysk[4] = " :\\";
	if (!isalpha(symbol_dysku)) return 0xFFFFFFFF;
	// blad, jesli symbol dysku nie jest litera
	dysk[0] = symbol_dysku;
	odp = GetDiskFreeSpaceEx((LPCTSTR)dysk, NULL,
		(PULARGE_INTEGER)&l_pojemnosc, (PULARGE_INTEGER)&l_wolnych);
	if (!odp) return 0xFFFFFFFF;
	// blad, jesli nie mozna ustalic rozmiaru
	l_zajetych = l_pojemnosc - l_wolnych;
	wynik = (unsigned int)(l_zajetych >> 20);
	// wyznaczenie liczby megabajtów - dzielenie przez 2^20
	return (unsigned int)wynik;
}