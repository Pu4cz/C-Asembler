#include <stdio.h>
#include "dysk.h"
int main()
{
	printf("\nObszar niezajety = %d [MB]\n",
		PodajRozmiarObszaruNiezajetego('D'));
	printf("\nObszar zajety = %d [MB]\n",
		PodajRozmiarObszaruZajetego('D'));
	return 0;
}