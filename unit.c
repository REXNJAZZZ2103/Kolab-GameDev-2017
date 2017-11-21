#include "unit.h"
#include <stdio.h>

void PrintUnitRekrut(Unit U){
	PrintKata(U.type);
	printf(" | Health %d | ATK %d | %dG", U.maxhealth, U.atkdmg,U.cost);
}

void PrintMove(Unit U){
	printf("Unit : ");
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

void PrintNamaUnit(char X) {
	if (X == 'A') {
		printf("Archer\n");
	} else if (X == 'K') {
		printf("King\n");
	} else if (X == 'S') {
		printf("Swordsman\n");
	} else if (X == 'W') {
		printf("White Mage\n");
	}
}

void PrintUnitAttack(Unit a, Unit b) {
	const Kata Range = {" Range", 5};
	
	PrintKata(a.type);
	printf(" ");
	TulisPOINT(a.pos);
	printf(" | Health ");
	printf("%d/%d", a.currhealth, a.maxhealth);

	if (IsKataSama(b.atktype, Range)) {
		printf(" (Retaliates)");
	} else {
		if (IsKataSama(a.atktype, b.atktype)) {
			printf(" (Retaliates)");
		}
	}
}
