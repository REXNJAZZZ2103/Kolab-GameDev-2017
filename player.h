#include "mesinkata.h"
#include "listsirkuler.h"
#include "queue.h"
#include "listvillage.h"

#ifndef player_H
#define player_H


typedef struct { Kata name;
                 int gold;
                 int income;
                 ListV village;
                 int upkeep;
               } Player;

#define Name(P) (P).name
#define Gold(P) (P).gold
#define Income(P) (P).income
#define Upkeep(P) (P).upkeep

void PrintPlayer(int x, Player Selected);

#endif