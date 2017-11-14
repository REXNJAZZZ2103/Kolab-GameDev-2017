#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "player.h"

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return ((Head(Q) == 0) && (Tail(Q) == 0));
}
boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return ((Head(Q) == 1) && (Tail(Q) == MaxEl(Q)));
}
int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmpty(Q)) {
        return 0;
    } else if (Head(Q)>Tail(Q)) {
        return ((MaxEl(Q)-Head(Q)) + 1 + Tail(Q));
    } else {
        return (Tail(Q) - Head(Q) + 1);
    }
}
/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (int *) malloc ((Max+1) * sizeof(int));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else /* alokasi gagal */ {
        MaxEl(*Q) = 0;
    }
}
/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = 0;
    free((*Q).T);
}
/* *** Primitif Add/Delete *** */
void Add (Queue * Q, int X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (IsEmpty(*Q)) {
        Head(*Q) = 1;
    }
    else if (Tail(*Q) == MaxEl(*Q)) {
        Tail(*Q) = Nil;
    }
    Tail(*Q)++;
    InfoTail(*Q) = X
}
void Del (Queue * Q, int * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    *X = InfoHead(*Q);
    if (Head(*Q)==Tail(*Q)) {
        Head(*Q)=Nil;
        Tail(*Q)=Nil;
    } else {
        Head(*Q)++;
    }
}

void Turn(Queue *Q)
{
    infotype X;
    Del(Q, &X);
    Add(Q, X);
}