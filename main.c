#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "map.h"
#include "player.h"
#include "listsirkuler.h"

int Baris, Kolom;
Queue TurnPlayer;
int pilihanawal;
Queue PlayerTurn;
Player SelectedPlayer;
Unit SelectedUnit1;
Unit SelectedUnit2;
int x = 1;
List ListUnitAwal;
List ListUnitPlayer1;
List ListUnitPlayer2;

const Kata Recruit = {" RECRUIT", 7};
const Kata Change_Unit = {" CHANGE_UNIT", 12};
const Kata Info = {" INF0", 4};
const Kata Attack = {" ATTACK", 6};
const Kata Map = {" MAP", 3};
const Kata Next_Unit = {" NEXT_UNIT", 9};
const Kata Kosong = {" ", 0};
const Kata Move = {" Move", 4};
const Kata Undo = {" Undo", 4};
const Kata EndT = {" EndTurn", 7};

int main()
{
	puts("BATTLE OF OLYMPIA");
	puts("1. New Game");
	puts("2. Load Game");
	printf("Masukkan pilihan : ");
	scanf("%d", &pilihanawal);
	if (pilihanawal == 1) {
		bacaunit(&ListUnitAwal);
		MATRIKS MAP;
		printf("Masukkan Baris dan Kolom pada MAP : ");
		scanf("%d %d", &Baris, &Kolom);
		convertIndex(&Baris, &Kolom);
		CreateMap(Baris, Kolom, &MAP);
		PrintMap(Baris, Kolom, MAP);
		RecruitMap(Baris, Kolom, &MAP, 1);
		PrintMap(Baris, Kolom, MAP);
	} else if (pilihanawal == 2) {

	} else {

	}

	boolean Main = true;
	boolean EndTurn = false;
	while(Main) {
		EndTurn = false;
		while(!EndTurn) {
			PrintPlayer(x, SelectedPlayer);
			printf("\n");
			if (x == 1) {
				PrintMove(SelectedUnit1);
			} else {
				PrintMove(SelectedUnit2);
			}
			printf("\n");
			Kata pilihan;
			STARTKATA(false, Kosong);
			pilihan = CKata;
			if (!IsKataSama(pilihan, EndT)) {
				if (IsKataSama(pilihan, Move)) {
				//Update Map (Map.h)
				//Update Unit yang digerakkan (Unit.h)
				//Update stack buat di Undo(Undo.h)
				//Update Map (Map.h)
				} else if (IsKataSama(pilihan, Undo)) {
				//Update Stack(Stack.h)
				} else if (IsKataSama(pilihan, Change_Unit)) {
		 		//Print List Unit (list.h)
		 	 	//Ganti Selected Unit
				} else if (IsKataSama(pilihan, Recruit)) {
			 	//Check posisi King
			 	//Print List Semua Unit (list.h)
			 	//Update status Player
			 	//Update King movement Point
			 	//Update Selected Unit
				} else if (IsKataSama(pilihan, Attack)) {
			 	//Print Unit yang bisa di attack (list.h)
			 	//Update Darah Unit yang di attack dan nge-attack (list.h)
			 	//Update Status Unit yang nge-attack
				} else if (IsKataSama(pilihan, Map)) {
			 	//Print Map (Map.h)
				} else if (IsKataSama(pilihan, Info)) {
			 	//Print Status setiap variabel pada matriks sesuai dengan perhitungan
				} else if (IsKataSama(pilihan, EndT)) {
			 		EndTurn = true;
			 	} else {
			 		puts("Masukan Salah");
			 	}
		  } else if (IsKataSama(pilihan, EndT)) {
		  	EndTurn = true;
		 	}
		}
	}
}
