#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "map.h"

int pilihanawal;

int main()
{
	puts("BATTLE OF OLYMPIA");
	puts("1. New Game");
	puts("2. Load Game");
	printf("Masukkan pilihan : ");
	scanf("%d", &pilihanawal);
	if (pilihanawal == 1) {
		//Persiapan baca file (ADT UNIT, PLAYER)
		//Bikin Queue buat turn Player (ADT QUEUE)
		int Baris, Kolom;
		MATRIKS MAP;
		printf("Masukkan Baris dan Kolom pada MAP : ");
		scanf("%d %d", &Baris, &Kolom);
		convertIndex(&Baris, &Kolom);
		CreateMap(Baris, Kolom, &MAP);
		PrintMap(Baris, Kolom, MAP);

		//Create Player	(ADT PLAYER)	
	} else if (pilihanawal == 2) {
		
	} else {

	}

	boolean Main = true;
	boolean EndTurn = false;
	while(Main) {
		EndTurn = false;
		//Bikin Turn Siapa masukkan dalam integer X (ADT QUEUE)
		while(!EndTurn) {
			// char *pilihan;
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