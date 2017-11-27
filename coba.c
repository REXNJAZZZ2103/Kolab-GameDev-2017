#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x;

	for(int i = 1; i <= 1000; i++) {
		x = rand()%100;

		printf("%d\n", x);		
	}
	
}