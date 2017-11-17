#include "map.h"
#include <stdio.h>

int main()
{
	int n, m;
	MATRIKS MAP;

	scanf("%d %d", &n, &m);
	
	convertIndex(&n, &m);

	CreateMap(n, m, &MAP);
	PrintMap(n, m, MAP);
}