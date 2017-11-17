#include "queue.h"
#include "player.h"
#include <stdio.h>

void MakeNewGame(int n, Queue *Q) {
	CreateEmpty(Q, 100);
	for(int i = 1; i <= n; i++) {
		Add(Q, i);
	}
}

void Turn(Queue *Q, int *X)
{
    Del(Q, X);
    Add(Q, *X);
}

void PrintTurn(Player X) {
	printf("Player %d's Turn\n", 1);
	printf("Cash : %dG | ", X.gold);
	printf("Income : %dG : ", X.income);
	printf("Upkeep : %dG\n", X.upkeep);
}