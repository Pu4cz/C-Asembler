#include <stdio.h>
__int64 suma_liczb64(__int64 p, __int64 q, __int64 r, __int64 s, __int64 t, __int64 u, __int64 w );
int main()
{
	__int64 wynik;
	wynik = suma_liczb64(3, -1, 7, 1, 2, 3, 5 );
	
	printf("\nSuma = %I64d\n", wynik);
	return 0;
}