#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "map.h"
#include "player.h"
#include "listsirkuler.h"
#include "stackpoint.h"

int Baris, Kolom, BarisR, KolomR;
Queue TurnPlayer;
int pilihanawal;
Queue PlayerTurn;
Player SelectedPlayer;
Unit SelectedUnit[3];
int PlayerKe = 1;
List ListUnitAwal;
List ListUnitPlayer[3];
Stack MoveUndo;

const Kata Recruit = {" RECRUIT", 7};
const Kata Change_Unit = {" CHANGE_UNIT", 11};
const Kata Info = {" INF0", 4};
const Kata Attack = {" ATTACK", 6};
const Kata Map = {" MAP", 3};
const Kata Next_Unit = {" NEXT_UNIT", 9};
const Kata Kosong = {" ", 0};
const Kata Move = {" MOVE", 4};
const Kata Undo = {" UNDO", 4};
const Kata EndT = {" ENDTURN", 7};
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
		for(int i = 1; i <= 2; i++) {
			CreateEmptyList(&ListUnitPlayer[i]);
			InsVFirstList(&ListUnitPlayer[i], InfoList(FirstList(ListUnitAwal)));
		}

		InfoList(FirstList(ListUnitPlayer[1])).pos.X = BarisR-1;
		InfoList(FirstList(ListUnitPlayer[1])).pos.Y = 2;

		InfoList(FirstList(ListUnitPlayer[2])).pos.X = 2;
		InfoList(FirstList(ListUnitPlayer[2])).pos.Y = KolomR - 1;

		CreateEmptyStack(&MoveUndo);
		BacaPlayer(&PlayerTurn);


	} else if (pilihanawal == 2) {
		
	} else {

	}

	boolean Main = true;
	boolean EndTurn = false;
	while(Main) {
		EndTurn = false;
		Del(&PlayerTurn, &SelectedPlayer);
		for(int i = 1; i <= 2; i++) {
			SelectedUnit[i] = InfoList(FirstList(ListUnitPlayer[i]));
		}
		
		while(!EndTurn) {
			PrintPlayer(SelectedPlayer);
			
			POINT PSelected;
			
			PrintMove(SelectedUnit[PlayerKe]);
			PSelected = AksesMatriksUnit(SelectedUnit[PlayerKe].pos.X, SelectedUnit[PlayerKe].pos.Y);

			Elmt(MAPASLI, PSelected.X, PSelected.Y).kepemilikan = 4;
			printf("\n");

			Kata pilihan;
			printf("Your Input : ");
			STARTKATA(false, Kosong);
			pilihan = CKata;

			if (!IsKataSama(pilihan, EndT)) {
				if (IsKataSama(pilihan, Move)) {
					CopyMap(MAPASLI, &MAPCOPY);
					UpdateMoveMAP(&MAPCOPY, SelectedUnit[PlayerKe], PlayerKe);
					
					int TujuanX, TujuanY;
					POINT PTujuan, PAsal;
					
					PrintMap(Baris, Kolom, MAPCOPY);
					printf("Please enter cell's coordinate x y :");
					scanf("%d %d", &TujuanX, &TujuanY);
					PTujuan = AksesMatriksUnit(TujuanX, TujuanY);
					PAsal = AksesMatriksUnit(SelectedUnit[PlayerKe].pos.X, SelectedUnit[PlayerKe].pos.Y);
					
					while(Elmt(MAPCOPY, PTujuan.X, PTujuan.Y).CC != '?') {
						printf("You can't move there\n");
						printf("Please enter cell's coordinate x y :");
						scanf("%d %d", &TujuanX, &TujuanY);
						PTujuan = AksesMatriksUnit(TujuanX, TujuanY);
					}
						
					Elmt(MAPASLI, PTujuan.X, PTujuan.Y).CC = SelectedUnit[PlayerKe].simbol;
					Elmt(MAPASLI, PTujuan.X, PTujuan.Y).kepemilikan = PlayerKe;
					Elmt(MAPASLI, PAsal.X, PAsal.Y).CC = ' ';
					Elmt(MAPASLI, PAsal.X, PAsal.Y).kepemilikan = 3;
				
					PTujuan.X = TujuanX;
					PTujuan.Y = TujuanY;
				
					Push(&MoveUndo, PAsal);
					UpdateListMove(&ListUnitPlayer[PlayerKe], &SelectedUnit[PlayerKe], PTujuan);	
				} else if (IsKataSama(pilihan, Map)) {
					PrintMap(Baris, Kolom, MAPASLI);
				} else if (IsKataSama(pilihan, Change_Unit)) {
					int SelectChange;

					if (PlayerKe == 1) {
						Elmt(MAPASLI, PSelected.X, PSelected.Y).kepemilikan = 1;
					} else {
						Elmt(MAPASLI, PSelected.X, PSelected.Y).kepemilikan = 2;
					}

					printf("== List of Units ==\n");
					TulisListChangeUnit(ListUnitPlayer[PlayerKe]);
					printf("Please enter the no. of unit you want to select : ");
					scanf("%d", &SelectChange);
					UpdateSelectedUnit(ListUnitPlayer[PlayerKe], SelectChange, &SelectedUnit[PlayerKe]);

					printf("You are now selected ");
					PrintKata(SelectedUnit[PlayerKe].type);
					printf("\n");
				} else if (IsKataSama(pilihan, Recruit)) {
					POINT SelectRecruit;
					POINT SelectRecruitMAP;
					Unit SelectedUnitRecruit;
					int SelectRecruitX;
					int SelectRecruitY;
					int NoRecruit;

					printf("Enter coordinate of empty castle : ");
					scanf("%d %d", &SelectRecruitX, &SelectRecruitY);

					SelectRecruit = MakePOINT(SelectRecruitX, SelectRecruitY);
					SelectRecruitMAP = AksesMatriksUnit(SelectRecruit.X, SelectRecruit.Y);
					while(Elmt(MAPASLI, SelectRecruitMAP.X, SelectRecruitMAP.Y).CC != ' ' || Elmt(MAPASLI, SelectRecruitMAP.X-1, SelectRecruitMAP.Y).CC != 'C' || Elmt(MAPASLI, SelectRecruitMAP.X - 1, SelectRecruitMAP.Y).kepemilikan != PlayerKe) {
						printf("WRONG INPUT MAP\n");

						printf("Enter coordinate of empty castle : ");
						scanf("%d %d", &SelectRecruitX, &SelectRecruitY);

						SelectRecruit = MakePOINT(SelectRecruitX, SelectRecruitY);
						SelectRecruitMAP = AksesMatriksUnit(SelectRecruit.X, SelectRecruit.Y);
					}

					printf("== List of Recruits ==\n");
					TulisRecruitUnit(ListUnitAwal);

					printf("Enter no. of unit you want recruit: ");
					scanf("%d", &NoRecruit);

					UpdateRecruit(ListUnitAwal, NoRecruit, &SelectedUnitRecruit);
					SelectedUnitRecruit.pos.X = SelectRecruit.X;
					SelectedUnitRecruit.pos.Y = SelectRecruit.Y;

					InsVLastList(&ListUnitPlayer[PlayerKe], SelectedUnitRecruit);
					SelectedPlayer.gold -= SelectedUnitRecruit.cost;

					Elmt(MAPASLI, SelectRecruitMAP.X, SelectRecruitMAP.Y).CC = SelectedUnitRecruit.simbol;
					Elmt(MAPASLI, SelectRecruitMAP.X, SelectRecruitMAP.Y).kepemilikan = PlayerKe;
				} else if(IsKataSama(pilihan, Attack)) {

				} else if (IsKataSama(pilihan, Info)) {
					POINT SelectedInfo;

					printf("Enter the coordinate of the cell : ");
					scanf("%d %d", &SelectedInfo.X, &)
				}
			} else {
				Add(&PlayerTurn, SelectedPlayer);
				if (PlayerKe == 1) {
					Elmt(MAPASLI, PSelected.X, PSelected.Y).kepemilikan = 1;
					PlayerKe = 2;
				} else {
					Elmt(MAPASLI, PSelected.X, PSelected.Y).kepemilikan = 2;
					PlayerKe = 1;
				}
				EndTurn = true;
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