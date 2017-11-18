/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */
#include "matriks.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS *M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return(((i>=BrsMin)&&(i<=BrsMax))&&((j>=KolMin)&&(j<=KolMax)));
}
/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    int i,j;
    for (i = 0; i <= MIn.NBrsEff; i++) {
        for (j = 0; j <= MIn.NKolEff; j++) {
            Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
        }
    }

    NBrsEff(*MHsl) = NBrsEff(MIn);
    NKolEff(*MHsl) = NKolEff(MIn);
}

POINT AksesMatriksUnit(int a, int b) {
    POINT P;

    P.X = 2+(a-1)*4;
    P.Y = 2+(b-1)*4;

    return P;
}