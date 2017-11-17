#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "map.h"
#include "player.h"

int Baris, Kolom;
Queue TurnPlayer;
int pilihanawal;
int PlayerTurn;

const Kata recruit = {" RECRUIT", 7};
const Kata change_unit = {" CHANGE_UNIT", 12};
const Kata info = {" INF0", 4};
const Kata attack = {" ATTACK", 6};
const Kata map = {" MAP", 3};
const Kata next_unit = {" NEXT_UNIT", 9};

int main()
{
	puts("BATTLE OF OLYMPIA");
	puts("1. New Game");
	puts("2. Load Game");
	printf("Masukkan pilihan : ");
	scanf("%d", &pilihanawal);
	if (pilihanawal == 1) {
		//Persiapan baca file (ADT UNIT, PLAYER)

		MATRIKS MAP;
		printf("Masukkan Baris dan Kolom pada MAP : ");
		scanf("%d %d", &Baris, &Kolom);
		convertIndex(&Baris, &Kolom);
		CreateMap(Baris, Kolom, &MAP);
		PrintMap(Baris, Kolom, MAP);

		MakeNewGame(2, &TurnPlayer);
	} else if (pilihanawal == 2) {
		
	} else {

	}

	boolean Main = true;
	boolean EndTurn = false;
	while(Main) {
		Turn(&TurnPlayer, &PlayerTurn);
		printf("%d\n", PlayerTurn);
		EndTurn = false;
		while(!EndTurn) {
			Kata pilihan;
			getchar();
			InputString(&pilihan);
			PrintKata(pilihan);
			//PrintPlayer(X) (ADT PLAYER)
			//PrintSelectedUnit
			// if (pilihan != "EndTurn") {
			// 	if (pilihan == "Move") {
			// 		//Update Map (Map.h)
			// 		//Update Unit yang digerakkan (Unit.h)
			// 		//Update stack buat di Undo(Undo.h)
			// 		//Update Map (Map.h)
			// 	} else if (pilihan == "Undo") {
			// 		//Update Stack(Stack.h)
			// 	} else if (pilihan == "Change Unit") {
			// 		//Print List Unit (list.h)
			// 		//Ganti Selected Unit
			// 	} else if (pilihan == "Recruit") {
			// 		//Check posisi King
			// 		//Print List Semua Unit (list.h)
			// 		//Update status Player
			// 		//Update King movement Point
			// 		//Update Selected Unit
			// 	} else if (pilihan == "Attack") {
			// 		//Print Unit yang bisa di attack (list.h)
			// 		//Update Darah Unit yang di attack dan nge-attack (list.h)
			// 		//Update Status Unit yang nge-attack
			// 	} else if (pilihan == "Map") {
			// 		//Print Map (Map.h)
			// 	} else if (pilihan == "Info") {
			// 		//Print Status setiap variabel pada matriks sesuai dengan perhitungan
			// 	} else if (pilihan == "End Turn") {
			// 		EndTurn = true;
			// 	} else {
			// 		puts("Masukan Salah");
			// 	}
			// } else if (pilihan == "EndTurn"){
			// 	EndTurn = true;
			// }
		}
	}
}