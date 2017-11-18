#include "map.h"
#include <stdio.h>

void CreateMap(int m, int n, MATRIKS* M) {
  NBrsEff(*M) = m;
  NKolEff(*M) = n;
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      if (i%4==0) {
          Elmt(*M,i,j).CC='*';
      Elmt(*M,i,j).kepemilikan=3;
      }
      else {
        if (j%4==0) {
          Elmt(*M,i,j).CC='*';
      Elmt(*M,i,j).kepemilikan=3;
        }
        else {
          Elmt(*M,i,j).CC=' ';
      Elmt(*M,i,j).kepemilikan=3;
        }
      }
    }
  }

  Elmt(*M, m-4, 6).CC = 'C';
  Elmt(*M, m-4, 6).kepemilikan = 1;
  Elmt(*M, m-8, 6).CC = 'T';
  Elmt(*M, m-8, 6).kepemilikan = 1;
  Elmt(*M, m-7, 6).CC = 'K';
  Elmt(*M, m-7, 6).kepemilikan = 1;
  Elmt(*M, m-12, 6).CC = 'C';
  Elmt(*M, m-12, 6).kepemilikan = 1;
  Elmt(*M, m-8, 2).CC = 'C';
  Elmt(*M, m-8, 2).kepemilikan = 1;
  Elmt(*M, m-8, 10).CC = 'C';
  Elmt(*M, m-8, 10).kepemilikan = 1;

  Elmt(*M, 1, n-7).CC = 'C';
  Elmt(*M, 1, n-7).kepemilikan = 2;
  Elmt(*M, 5, n-7).CC = 'T';
  Elmt(*M, 5, n-7).kepemilikan = 2;
  Elmt(*M, 6, n-7).CC = 'K';
  Elmt(*M, 6, n-7).kepemilikan = 2;
  Elmt(*M, 5, n-3).CC = 'C';
  Elmt(*M, 5, n-3).kepemilikan = 2;
  Elmt(*M, 5, n-11).CC = 'C';
  Elmt(*M, 5, n-11).kepemilikan = 2;
  Elmt(*M, 9, n-7).CC = 'C';
  Elmt(*M, 9, n-7).kepemilikan = 2;
}

void RecruitMap(int m, int n, MATRIKS *M, int x) {  
	if (x == 1) {
		if (Elmt(*M, m-3, 6).CC == ' ') {
			Elmt(*M, m-3, 6).CC = '#';
			Elmt(*M, m-3, 6).kepemilikan = 3;
		}
		if (Elmt(*M, m-11, 6).CC == ' ') {
			Elmt(*M, m-11, 6).CC = '#';
			Elmt(*M, m-11, 6).kepemilikan = 3;
		} 
		if (Elmt(*M, m-7, 2).CC == ' ') {
			Elmt(*M, m-7, 2).CC = '#';
			Elmt(*M, m-7, 2).kepemilikan = 3;
		} 
		if (Elmt(*M, m-7, 10).CC == ' ') {
			Elmt(*M, m-7, 10).CC = '#';
			Elmt(*M, m-7, 10).kepemilikan = 3;
		} 	
	} else {
		if (Elmt(*M, 6, n-3).CC == ' ') {
			Elmt(*M, 6, n-3).CC = '#';
			Elmt(*M, 6, n-3).kepemilikan = 3;
		}
		if (Elmt(*M, 6, n-11).CC == ' ') {
			Elmt(*M, 6, n-11).CC = '#';
			Elmt(*M, 6, n-11).kepemilikan = 3;
		} 
		if (Elmt(*M, 10, n-7).CC == ' ') {
			Elmt(*M, 10, n-7).CC = '#';
			Elmt(*M, 10, n-7).kepemilikan = 3;
		} 
  	if (Elmt(*M, 2, n-7).CC == ' ') {
			Elmt(*M, 2, n-7).CC = '#';
			Elmt(*M, 2, n-7).kepemilikan = 3;
		}		
	}
}

void PrintMap(int m, int n, MATRIKS M) {
  for (int k=0; k<(n-1)/4; k++) {
    if (k==0) {
        printf("   ");
    }
    printf("  ");
    printf("%d", k);
    if (k==((n-1)/4)-1) {
      printf("\n");
    }
    else {
      if (k<10) {
        printf(" ");
      }
    }
  }

  int l = 0;

  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      if (j==0) {
        if ((i-2)%4==0) {
          if (l<10) {
            printf(" %d ", l);
          }
          else {
            printf("%d ", l);
          }
          l++;
        }
        else {
          printf("   ");
        }
      }

      print_char(Elmt(M, i, j)); //printf("%c", Elmt(M, i, j));
      if (j==(n-1)) {
        printf("\n");
      }
    }
  }
}

void convertIndex (int *m, int *n) {
    *m = ((*m)*4)+1;
    *n = ((*n)*4)+1;
}
