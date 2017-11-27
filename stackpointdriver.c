#include<stdlib.h>
#include<stdio.h>
#include "boolean.h"
#include "point.h"
#include "stackpoint.h"

POINT P1,P2,P3;
Stack S1;
int pil;

int main(){
	CreateEmptyStack (&S1);
	printf("Input Titik X Pada Point 1: ");
	scanf("%d", &Absis(P1));
	printf("Input Titik Y Pada Point 1: ");
	scanf("%d", &Ordinat(P1));
	printf("Input Titik X Pada Point 2: ");
	scanf("%d", &Absis(P2));
	printf("Input Titik Y Pada Point 2: ");
	scanf("%d", &Ordinat(P2));
	printf("Apakah anda ingin membuat stacknya dengan titik koordinat pertama? (Jawab dengan no pilihan)\n");
	printf("1.Yes\n");
	printf("2.No\n");
	scanf("%d", &pil);
	printf("\n");
	if(pil==1){
		if(!IsFullStack (S1)){
			Push (&S1, P1);
		}
		else{
			printf("Stack sudah penuh\n");
		}
		printf("Apakah anda ingin membuat stacknya dengan titik koordinat kedua? (Jawab dengan no pilihan)\n");
		printf("1.Yes\n");
		printf("2.No\n");
		scanf("%d", &pil);
		printf("\n");
		if(pil==1){
			if(!IsFullStack (S1)){
				Push (&S1, P2);
			}
			else{
				printf("Stack sudah penuh\n");				
			}
		}
	}
	else{
		printf("Apakah anda ingin membuat stacknya dengan titik koordinat kedua? (Jawab dengan no pilihan)\n");
		printf("1.Yes\n");
		printf("2.No\n");
		scanf("%d", &pil);
		printf("\n");
		if(pil==1){
			if(!IsFullStack (S1)){
				Push (&S1, P2);
			}
			else{
				printf("Stack sudah penuh\n");				
			}
		}
		else{
			printf("Anda tidak mengisi stack!!!");
		}
	}
	if(!IsEmptyStack(S1)){
		while(!IsEmptyStack(S1)){
			printf("Apakah anda ingin mencetak nilai dari top of stack? (Jawab dengan no pilihan)\n");
			printf("1.Yes\n");
			printf("2.No\n");
			scanf("%d", &pil);
			printf("\n");
			if(pil==1){
				Pop (&S1, &P3);
				printf("Input Titik X dari Point Top Stack: ");
				printf("%d", Absis(P3));
				printf("\n");
				printf("Input Titik Y dari Point Top Stack: ");
				printf("%d", Ordinat(P3));
				printf("\n");
			}
			else{
				printf("Anda Mager Banget!!!\n");
				printf("\n");
			}
		}
		Push(&S1,P3);
	}
	else{
		printf("Stacknya Full Yahhh\n");
		printf("\n");
	}
	printf("Apakah anda ingin mengecek status stack? (Masukkan no pilihan)\n");
	printf("1.Yes\n");
	printf("2.NO\n");
	scanf("%d", &pil);
	if(pil==1){
		if(IsEmptyStack(S1)){
			printf("Stacknya Kosong Yeayyy\n");
		}
		else{
			printf("Stacknya Tidak Kosong Yahh\n");
			if(IsFullStack(S1)){
				printf("Stacknya Full Yahhh\n");
			}
			else{
				printf("Stacknya Tidak Full Yeayyy\n");
			}
		}
		printf("\n");
	}
	else{
		printf("Yahhh anda mager sekali bahkan tes untuk tes driver :')\n");
		printf("\n");
	}
	if(IsEmptyStack(S1)){
		printf("Stacknya Kosong Yeayyy\n");
	}
	else{
		printf("Stacknya Tidak Kosong Yahh\n");
		printf("Karena udah diakhir driver mari kosongkan stacknya\n");
		CreateEmptyStack (&S1);
		printf("\n");
	}
	printf("\nYahh buat tiap driver susah banget kak \n");
	return 0;
}
