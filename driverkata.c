#include <stdio.h>
#include "mesinkata.h"

const Kata filetes = {" teskata.txt",11};
const Kata satu = {" katasama",8};
const Kata beda = {" katabeda",8};
const Kata sama = {" katasama",8};
const Kata bilangan = {" 123456",6};
const Kata nonbilangan = {" 1as23a",6};
const Kata katanull ={" ",0};

int main(){
	printf("nama file : ");
	PrintKata(filetes);
	puts("\ntes baca file!");
	STARTKATA(true, filetes);
	while(!EndKata){
		PrintKata(CKata);
		puts("");
		ADVKATA(true);
	}
	puts("tes baca file selesai");
	puts("tes baca input dari terminal");
	puts("masukkan input dalam satu line");
	CKata.Length = 0;
	STARTKATA(false, katanull);
	while(CKata.Length>0){
		printf("hasi> ");
		PrintKata(CKata);
		puts("");
		if(CC!='\n')
			ADVKATA(false);
		else
			CKata.Length = 0;
	}
	printf("isi kata1 : ");
	PrintKata(satu);
	printf("\nisi kata2 : ");
	PrintKata(sama);
	printf("\nisi kata3 : ");
	PrintKata(beda);
	printf("\nhasi dari fungsi IsKataSama dari kata1 dan kata2 : %d", IsKataSama(satu, sama));
	printf("\nhasi dari fungsi IsKataSama dari kata1 dan kata3 : %d\n", IsKataSama(satu, beda));
	printf("isi kata4 : ");
	PrintKata(bilangan);
	printf("\nisi kata5 : ");
	PrintKata(nonbilangan);
	printf("\nhasi dari fungsi IsBilangan dari kata4 : %d", IsBilangan(bilangan));
	printf("\nhasi dari fungsi IsBilangan dari kata5 : %d\n", IsBilangan(nonbilangan));
	printf("\nhasi dari fungsi KatatoBilangan + 1 dari kata4 : %d\n", KatatoBilangan(bilangan)+1);
	return 0;
}
