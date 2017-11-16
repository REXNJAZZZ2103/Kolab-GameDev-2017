#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "listsirkuler.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return FirstList(L) == Nil;
}


/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	FirstList(*L) = Nil;
}


/****************** Manajemen Memori ******************/
address Alokasi (Unit X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, NextList(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address P = (address) malloc(sizeof(ElmtList));
	if(P!=Nil){
		InfoList(P) = X;
		NextList(P) = Nil;
	}
	return P;
}

void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN List ******************/
address SearchPoint (List L, Point X)
/* Mencari apakah ada elemen List dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address P;
	P = FirstList(L);
	while(NextList(P)!=FirstList(L) && !EQ(X,L.Unit.pos)){
		P = NextList(P);
	}
	if(EQ(X,L.Unit.pos))
		return P;
	else
		return Nil;
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstList (List *L, Unit X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P = Alokasi(X);
	if(P!=Nil)
		InsertFirstList(L, P);
}

void InsVLast (List *L, Unit X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen List di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P = Alokasi(X);
	if(P!=Nil)
		InsertLast(L, P);
}


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstList (List *L, Unit * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama List dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address P;
	DelFirstList(L, &P);
	*X = InfoList(P);
}

void DelVLast (List *L, Unit * X)
/* I.S. List tidak kosong */
/* F.S. Elemen terakhir List dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address P;
	DelLast(L, &P);
	*X = InfoList(P);
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	address Q = FirstList(*L);
	if(IsEmpty(*L)){
		FirstList(*L) = P;
		NextList(FirstList(*L)) = FirstList(*L);
	}
	else{
		while(NextList(Q) != FirstList(*L)){
			Q = NextList(Q);
		}
		NextList(P) = FirstList(*L);
		FirstList(*L) = P;
		NextList(Q) = FirstList(*L);
	}
	
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	address Q = FirstList(*L);
	if(IsEmpty(*L)){
		FirstList(*L) = P;
		NextList(FirstList(*L)) = FirstList(*L);
	}
	else{
		while(NextList(Q) != FirstList(*L)){
			Q = NextList(Q);
		}
		NextList(Q) = P;
		NextList(P) = FirstList(*L);
	}
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen List dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	NextList(P) = NextList(Prec);
	NextList(Prec) = P;
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstList (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama List sebelum penghapusan */
/*      Elemen List berkurang satu (mungkin menjadi kosong) */
/* FirstList element yg baru adalah suksesor elemen pertama yang lama */
{
	address Q = FirstList(*L);
	*P = Q;
	if(NextList(Q) == FirstList(*L)){
		CreateEmpty(L);
	}
	else{
		while(NextList(Q) != FirstList(*L)){
			Q = NextList(Q);
		}
		FirstList(*L) = NextList(*P);
		NextList(Q) = FirstList(*L);
	}
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir List sebelum penghapusan  */
/*      Elemen List berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
	address Q = FirstList(*L);
	*P = Q;
	if(NextList(Q) == FirstList(*L)){
		CreateEmpty(L);
	}
	else{
		while(NextList(NextList(Q)) != FirstList(*L)){
			Q = NextList(Q);
		}
		*P = NextList(Q);
		NextList(Q) = FirstList(*L);
	}
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota List  */
/* F.S. Menghapus NextList(Prec): */
/*      Pdel adalah alamat elemen List yang dihapus  */
{
	*Pdel = NextList(Prec);
	if(NextList(Prec) == FirstList(*L)){
		NextList(Prec) = NextList(FirstList(*L));
		FirstList(*L) = NextList(Prec);
	}
	else{
		NextList(Prec) = NextList(*Pdel);
	}
}

void DelP (List *L, Unit X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen List beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari List dan di-dealokasi */
/* Jika tidak ada elemen List dengan Info(P)=X, maka List tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	address P=FirstList(*L);
	if(IsUnitSama(InfoList(P),X)){
		DelFirstList(L, &P);
	}
	else if(NextList(P)!=FirstList(*L)){
		while(IsUnitSama(InfoList(NextList(P)),X) && NextList(P)!=FirstList(*L)){
			P = NextList(P);
		}
		if(IsUnitSama(InfoList(NextList(P)),X))
			NextList(P) = NextList(NextList(P));
	}
}


/****************** PROSES SEMUA ELEMEN List ******************/
// void PrintInfo (List L)
// /* I.S. List mungkin kosong */
// /* F.S. Jika List tidak kosong, iai List dicetak ke kanan: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika List kosong : menulis [] */
// /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
// {
	// address P = FirstList(L);
	// printf("[");
	// if(P!=Nil){
		// while(NextList(P) != FirstList(L)){
			// printf("%d,", Info(P));
			// P = NextList(P);
		// }
		// printf("%d", Info(P));
	// }
	// printf("]");
// }

void bacaunit(List *stdunit){
	int i;
	Unit Utemp;
	STARTKATA(true);
	while(!EOP){
		if(!IsKataSama(CKata, EndUnit)){
			switch(i){
				case 1 : Utemp.type = CKata;
						 break;
				case 2 : Utemp.maxhealth = KatatoBilangan(CKata);
						 Utemp.currhealth = Utemp.maxhealth;
						 break;
				case 3 : Utemp.atkdmg = KatatoBilangan(CKata);
						 break;
				case 4 : Utemp.maxmove = KatatoBilangan(CKata);
						 Utemp.currmove = Utemp.maxmove;
						 break;
				case 5 : Utemp.atktype = CKata;
						 break;
				case 6 : Utemp.cost = KatatoBilangan(CKata);
						 break;
				case 7 : Utemp.heal = KatatoBilangan(CKata);
						 break;
			}
			i++;
		}
		else{
			Utemp.canatk = true;
			if(i<8)
				Utemp.heal = 0;
			i=1;
			Add(stdunit, Utemp);
		}
		ADVKATA(true);
	}
}
