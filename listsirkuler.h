/* File : listsirkuler.h */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan address adalah pointer */

#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"
#include "unit.h"
#include "mesinkata.h"

#define Nil NULL

typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	Unit info;
	address next;
} ElmtList;
typedef struct {
	address First;
} List;
const Kata EndUnit("ENDUNIT" , 7);

/* Definisi list : */
/* List kosong : FirstList(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list: jika addressnya Last, maka Next(Last)=FirstList(L) */

/* Notasi Akses */
#define InfoList(P) (P)->info
#define NextList(P) (P)->next
#define FirstList(L) (L).First

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L);
/* I.S. L sembarang             */
/* F.S. Terbentuk List kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (Unit X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN List ******************/
address SearchPoint (List L, POINT X);
/* Mencari apakah ada elemen List dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstList (List *L, Unit X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, Unit X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen List di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstList (List *L, Unit * X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama List dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, Unit * X);
/* I.S. List tidak kosong */
/* F.S. Elemen terakhir List dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (List *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec);
/* I.S. Prec pastilah elemen List dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstList (List *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama List sebelum penghapusan */
/*      Elemen List berkurang satu (mungkin menjadi kosong) */
/* FirstList element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir List sebelum penghapusan  */
/*      Elemen List berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec);
/* I.S. List tidak kosong. Prec adalah anggota List  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen List yang dihapus  */
void DelP (List *L, Unit X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen List beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari List dan di-dealokasi */
/* Jika tidak ada elemen List dengan Info(P)=X, maka List tetap */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN List ******************/
// void PrintInfo (List L);
// /* I.S. List mungkin kosong */
// /* F.S. Jika List tidak kosong, iai List dicetak ke kanan: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika List kosong : menulis [] */
// /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

void bacaunit(List *stdunit);

#endif
