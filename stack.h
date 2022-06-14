/* File: stackt.h */
/* Implementasi Stack dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H
#include "boolean.h"

#define Nill -1 /* Nil adalah stack dengan elemen kosong */
#define MaxEl 10

typedef char* type;
typedef int addrS; /* indeks tabel */
/* Versi I: dengan menyimpan tabel dan alamat top secara
eksplisit */
typedef struct {
    type T[MaxEl]; /* tabel penyimpan elemen */
    addrS TOP; /* alamat TOP: elemen puncak */
} Stack;
/* Definisi akses dengan Selektor: */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/*** Konstruktor/Kreator ***/
void CreateStackEmpty(Stack *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0..MaxEl-1 */
/* Ciri stack kosong: TOP bernilai Nil */

/********** Predikat Untuk test keadaan KOLEKSI **********/
boolean IsStackEmpty(Stack S);

/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/*********** Menambahkan sebuah elemen ke Stack **********/
void Push(Stack *S, type X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
/*********** Menghapus sebuah elemen Stack **********/
void Pop(Stack *S, type *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void PrintStack(Stack S);
/* Mencetak ke layar stack yang sudah dibuat*/
#endif