#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "map.h"
#include "player.h"
#include "listsirkuler.h"

int Baris, Kolom, BarisR, KolomR;
Queue TurnPlayer;
int pilihanawal;
Queue PlayerTurn;
Player SelectedPlayer;
Unit SelectedUnit1;
Unit SelectedUnit2;
int PlayerKe = 1;
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
MATRIKS MAPASLI;
MATRIKS MAPCOPY;

int main()
{
	puts("BATTLE OF OLYMPIA");
	puts("1. New Game");
	puts("2. Load Game");
	printf("Masukkan pilihan : ");
	scanf("%d", &pilihanawal);
	if (pilihanawal == 1) {
		printf("Masukkan Baris dan Kolom pada MAP : ");
		scanf("%d %d", &Baris, &Kolom);
		BarisR = Baris, KolomR = Kolom;
		MAPASLI.NBrsEff = BarisR;
		MAPASLI.NKolEff = KolomR;
		convertIndex(&Baris, &Kolom);
		CreateMap(Baris, Kolom, &MAPASLI);
		PrintMap(Baris, Kolom, MAPASLI);

		bacaunit(&ListUnitAwal);
		CreateEmptyList(&ListUnitPlayer1);
		InsertFirstList(&ListUnitPlayer1, FirstList(ListUnitAwal));
		InfoList(FirstList(ListUnitPlayer1)).pos.X = 2;
		InfoList(FirstList(ListUnitPlayer1)).pos.Y = KolomR-1;
		CreateEmptyList(&ListUnitPlayer2);
		InsertFirstList(&ListUnitPlayer2, FirstList(ListUnitAwal));
		InfoList(FirstList(ListUnitPlayer2)).pos.X = BarisR-1;
		InfoList(FirstList(ListUnitPlayer2)).pos.Y = 2;

	} else if (pilihanawal == 2) {
		
	} else {

	}

	boolean Main = true;
	boolean EndTurn = false;
	while(Main) {
		SelectedUnit1 = InfoList(FirstList(ListUnitPlayer1));
		SelectedUnit2 = InfoList(FirstList(ListUnitPlayer2));
		EndTurn = false;
		BacaPlayer(&PlayerTurn);
		Del(&PlayerTurn, &SelectedPlayer);
		while(!EndTurn) {
			PrintPlayer(PlayerKe, SelectedPlayer);
			if (PlayerKe == 1) {
				PrintMove(SelectedUnit1);
			} else {
				PrintMove(SelectedUnit2);
			}
			printf("\n");
			Kata pilihan;
			printf("Your Input : ");
			STARTKATA(false, Kosong);
			pilihan = CKata;
			if (!IsKataSama(pilihan, EndT)) {
				if (IsKataSama(pilihan, Move)) {
					if (PlayerKe == 1) {
						CopyMap(MAPASLI, &MAPCOPY);
						UpdateMoveMAP(&MAPCOPY, SelectedUnit1, 1);
						int TujuanX, TujuanY;
						POINT PTujuan, PAsal;
						PrintMap(Baris, Kolom, MAPCOPY);
						printf("Please enter cell's coordinate x y :");
						scanf("%d %d", &TujuanX, &TujuanY);
						PTujuan = AksesMatriksUnit(TujuanX, TujuanY);
						PAsal = AksesMatriksUnit(SelectedUnit1.pos.X, SelectedUnit1.pos.Y);
						while(Elmt(MAPCOPY, PTujuan.X, PTujuan.Y).CC != '?') {
							printf("You can't move there\n");
							printf("Please enter cell's coordinate x y :");
							scanf("%d %d", &TujuanX, &TujuanY);
							PTujuan = AksesMatriksUnit(TujuanX, TujuanY);
						}
						Elmt(MAPASLI, PTujuan.X, PTujuan.Y).CC = SelectedUnit1.simbol;
						Elmt(MAPASLI, PTujuan.X, PTujuan.Y).kepemilikan = PlayerKe;
						Elmt(MAPASLI, PAsal.X, PAsal.Y).CC = ' ';
						Elmt(MAPASLI, PAsal.X, PAsal.Y).kepemilikan = 3;
						PTujuan.X = TujuanX;
						PTujuan.Y = TujuanY;
						UpdateListMove(&ListUnitPlayer1, &SelectedUnit1, PTujuan);						
					}

				}
				int ss;
				scanf("%d", &ss);
			} else {

			}
			// if (!IsKataSama(pilihan, EndT)) {
			// 	if (IsKataSama(pilihan, Move)) {
			// 		//Update Map (Map.h)
			// 		//Update Unit yang digerakkan (Unit.h)
			// 		//Update stack buat di Undo(Undo.h)
			// 		//Update Map (Map.h)
			// 	} else if (IsKataSama(pilihan, Undo)) {
			// 		//Update Stack(Stack.h)
			// 	// } else if (pilihan == "Change Unit") {
			// 	// 	//Print List Unit (list.h)
			// 	// 	//Ganti Selected Unit
			// 	// } else if (pilihan == "Recruit") {
			// 	// 	//Check posisi King
			// 	// 	//Print List Semua Unit (list.h)
			// 	// 	//Update status Player
			// 	// 	//Update King movement Point
			// 	// 	//Update Selected Unit
			// 	// } else if (pilihan == "Attack") {
			// 	// 	//Print Unit yang bisa di attack (list.h)
			// 	// 	//Update Darah Unit yang di attack dan nge-attack (list.h)
			// 	// 	//Update Status Unit yang nge-attack
			// 	// } else if (pilihan == "Map") {
			// 	// 	//Print Map (Map.h)
			// 	// } else if (pilihan == "Info") {
			// 	// 	//Print Status setiap variabel pada matriks sesuai dengan perhitungan
			// 	// } else if (pilihan == "End Turn") {
			// 	// 	EndTurn = true;
			// 	// } else {
			// 	// 	puts("Masukan Salah");
			// 	// }
			// // } else if (pilihan == "EndTurn"){
			// // 	EndTurn = true;
			// 	}
			// }
		}
	}
}