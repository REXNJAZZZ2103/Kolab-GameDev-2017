#include "mesinkata.h"
#include "queue.h"

#ifndef player_H
#define player_H


typedef struct { Kata name;
                 int gold;
                 int income;
                 int upkeep;

               } Player;

#define Name(P) (P).name
#define Gold(P) (P).gold
#define Income(P) (P).income
#define Upkeep(P) (P).upkeep

void MakeNewGame(int n, Queue *Q);
void Turn(Queue *Q, int *X);
void PrintTurn(Player X);

#endif