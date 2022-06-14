#include "matriks.h"
#include <stdio.h>


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
    for (int i=0;i<=GetLastIdxBrs(*M);i++){
        for (int j=0;j<=GetLastIdxKol(*M);j++){
            Elmt(*M,i,j) = ' ';
        }
    }
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
    return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
    return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
    return NBrsEff(M)-1;
}
indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
    return NKolEff(M)-1;
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void TulisMATRIKS (MATRIKS M){
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
int n,i,j;
char star='*';
    for (n=0;n<=GetLastIdxKol(M)+2;n++){
        printf("%c", star);
    }
    printf("\n");
    for (i=0;i<=GetLastIdxBrs(M);i++){
        printf("%c", star);
        for (j=0;j<=GetLastIdxKol(M);j++){
            printf("%c",Elmt(M,i,j));
        }
        printf("%c", star);
        printf("\n");
    }
    for (n=0;n<=GetLastIdxKol(M)+2;n++){
        printf("%c", star);
    }
    printf("\n");
}