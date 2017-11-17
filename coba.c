#include "listsirkuler.h"
#include "unit.h"
#include <stdio.h>

int main()
{
	List ListUnit;
	int i;

	CreateEmpty(&ListUnit);

	bacaunit(&ListUnit);

	PrintUnitRekrut(InfoList(FirstList(ListUnit)));
}