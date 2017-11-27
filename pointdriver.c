//point drive
#include <stdio.h>
#include "point.h"

int main(){
	int x, y;
	POINT P1, P2;
	x = 2;
	y = 3;
	printf("Nilai yang akan dimasukkan ke titik 1 x = %d, y = %d\n", x, y);
	P1 = MakePOINT(x,y);
	printf("Nilai titik 1 x = %d, y = %d\n", Absis(P1), Ordinat(P1));
	printf("Hasil fungsi TulisPOINT untuk titik 1 : ");
	TulisPOINT(P1);
	puts("");
	x = 1;
	y = 4;
	printf("Nilai yang akan dimasukkan ke titik 1 x = %d, y = %d\n", x, y);
	P2 = MakePOINT(x,y);
	puts("Tes  fungsi EQ dan NEQ (0 = false, 1 = true)");
	printf("EQ titik 1 dan 2 adalah %d\n", EQ(P1,P2));
	printf("NEQ titik 1 dan 2 adalah %d\n", NEQ(P1,P2));
	x = 2;
	y = 3;
	printf("Nilai yang akan dimasukkan ke titik 1 x = %d, y = %d\n", x, y);
	P2 = MakePOINT(x,y);
	puts("Tes  fungsi EQ dan NEQ (0 = false, 1 = true)");
	printf("EQ titik 1 dan 2 adalah %d\n", EQ(P1,P2));
	printf("NEQ titik 1 dan 2 adalah %d\n", NEQ(P1,P2));
	return 0;
}
