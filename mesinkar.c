/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void STARTFILE() {
	pita = fopen("Unit.txt","r");
	ADVFILE();
}

void ADVFILE() {
	retval = fscanf(pita,"%c",&CC);
	EOP = (CC == MARK);
	if (EOP) {
       fclose(pita);
 	}
}

void STARTCLI(){
	ADVCLI();
}

void ADVCLI(){
	scanf("%c", &CC);
	EOP = (CC == MARK);
}