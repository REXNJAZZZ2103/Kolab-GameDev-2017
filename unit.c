#include "unit.h"
#include <stdio.h>

void PrintUnitRekrut(Unit U){
	PrintKata(U.type);
	printf(" | Health %d | ATK %d | %dG", U.maxhealth, U.atkdmg,U.cost);
}


void PrintMove(Unit U){
	PrintKata(U.type);
	TulisPOINT(U.pos);
	printf(" | Movement Point : %d | Can Attack : ", U.currmove);
	if(U.canatk)
		printf("YES");
	else
		printf("NO");
}

void PrintUnit(Unit U){
	PrintKata(U.type);
	printf(" ");
	TulisPOINT(U.pos);
	printf(" | Health %d", U.currhealth);
}

boolean IsUnitSama(Unit a, Unit b){
	if(NEQ(position(a), position(b)))
	   return false;
	if(!IsKataSama(a.type, b.type))
	   	return false;
	return true;
}
