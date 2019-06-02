#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <math.h>
#define DOKLADNOSC 0.00001
// prototyp funkcji watku
// uwaga: przed stdcall wystepuja dwa znaki podkreslenia
unsigned __stdcall bisekcja (void * parametry);
double fun(double);
// ----------------------------------------------------------
// deklaracje zmiennych globalnych (uywanych przez wszystkie
// watki)
HANDLE watek[3], wyswietl;
CRITICAL_SECTION sekcja_krytyczna;
// struktura uywana do przekazywania parametrów do obu watków
typedef struct
{
	//char koniec;
	double a;
	double b;
} dane_watku;
//-----------------------------------------------------------
int main(int argc, char * argv[])
{
// to jest watek g³ówny uruchamiany automatycznie
// przez system
	unsigned int i=0,  ida=999, idb=998, idc=997;
	dane_watku dane_watku_A, dane_watku_B, dane_watku_C;
// wype³nianie struktur przekazywanych do watków A i B
	dane_watku_A.a = -10;
	dane_watku_A.b = -5;
	//dane_watku_A.koniec = 0;
	dane_watku_B.a = -2;
	dane_watku_B.b = 2;
	//dane_watku_B.koniec = 0;
	dane_watku_C.a = 2;
	dane_watku_C.b = 7;
	//dane_watku_C.koniec = 0;
// przydzielanie obszaru pamieci do przechowywania
// obliczonych liczb pierwszych - ze wzgledu na prace
// wielowatkowa moe zostac
// wyznaczona dodatkowa liczba poza wymaganymi
	wyswietl = CreateMutex(NULL, FALSE, NULL);
// inicjalizacja zmiennej dla sekcji krytycznej
	InitializeCriticalSection (& sekcja_krytyczna);
// tworzenie watków A i B
// oba watki, w chwili uruchomienia rozpoczynaja wykonywanie
// tej samej funkcji 'liczba_pierwsza ', lecz z rónymi
// parametrami startowymi;
// funkcja do wykonania przekazywana jest przez
// parametr trzeci
// parametry startowe watku przekazywane sa przez
// parametr czwarty
	watek[0] = (HANDLE) _beginthreadex (NULL, 0, &bisekcja, &dane_watku_A, 0, &ida);
	watek[1] = (HANDLE) _beginthreadex (NULL, 0, &bisekcja, &dane_watku_B, 0, &idb);
	watek[2] = (HANDLE) _beginthreadex (NULL, 0, &bisekcja, &dane_watku_C, 0, &idc);
// poniszy kod stanowi dalej watek g³ówny
// sukcesywne wyswietlanie wygenerowanych liczb
	// przygotowanie do zakonczenia watku g³ównego (i ca³ego
	// programu)
	WaitForMultipleObjects(3, watek, TRUE, INFINITE);
	CloseHandle (watek[0]);
	CloseHandle (watek[1]);
	CloseHandle (watek[2]);
	// usuniecie sekcji krytycznej
	DeleteCriticalSection (&sekcja_krytyczna);
	return 0;
}
//-----------------------------------------------------------
// funkcja watku - generowanie liczb pierwszych
double fun(double x){
	return (x*x*x + 4.0*x*x - 25.0 * x - 28);
}
unsigned __stdcall bisekcja (void * parametry)
{
	double a, b,x,fx,fa;
	dane_watku * wsk = (dane_watku*) parametry;
	char koniec=0;
	a = wsk->a;
	b = wsk->b;
	//printf("BISEKCJA: %lf %lf\n", a, b);
	//printf("\n Watek! a: %2.1lf b: %2.1lf", a, b);
	while (!koniec){//BISEKCJA
		
		x=0.5*(a+b);
		fx=fun(x);
		printf("%3.8lf\n", x);

		if (fx<=DOKLADNOSC && fx>=-DOKLADNOSC)
			koniec=1;
		else{
			fa=fun(a);
			if (fa*fx<0)
				b=x;
			else
				a=x;
		}
	}
	//WaitForSingleObject(wyswietl, INFINITE);
	printf("znaleziono miejsce zerowe : %3.8lf\n", x);
	//ReleaseMutex(wyswietl);
	//wsk->koniec=1;
	_endthreadex(0);
	return 0;
}