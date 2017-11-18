#include <stdio.h>
#include "player.h"

void PrintPlayer(int x, Player Selected)
{
	printf("Player %d's Turn\n", x);
	printf("Cash: %dG | Income : %dG | Upkeep: %dG\n", Selected.gold, Selected.income, Selected.upkeep);
}