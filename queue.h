/* File : queuelist.h */
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
#ifndef _QUEUELIST_H
#define _QUEUELIST_H
#include "boolean.h"
#include "stack.h"
#include "arraydin.h"
#include <string.h>
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef int infotype;

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue * address;
typedef struct {
	char* komponen;
} komp;
typedef struct tElmtQueue {
	int no_order;
	int no_pelanggan;
	komp T[8]; //8 baris/komponen;tiap komponen max 30 char
	int invoice;
	boolean status;
	address Next;
} ElmtQueue;

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct {
	address HEAD;  /* alamat penghapusan */
	address TAIL;  /* alamat penambahan */
} Queue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
// #define InfoHead(Q) (Q).HEAD->Info
// #define InfoTail(Q) (Q).TAIL->Info
#define NoOrder(P) (P)->no_order
#define NoPel(P) (P)->no_pelanggan
#define T(P) (P)->T
#define Invoice(P) (P)->invoice
#define Status(P) (P)->status
#define Next(P) (P)->Next
// #define Info(P) (P)->Info


/* Prototype manajemen memori */
void Alokasi (address *P, int no_ord, int no_pel,  char* komp1, char* komp2, char* komp3, char* komp4, char* komp5, char* komp6, char* komp7, char* komp8, int invoice);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi (address  P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmpty (Queue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(Queue * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Enqueue/Dequeue ***/
void Enqueue (Queue * Q, int no_ord, int no_pel,  char* komp1, char* komp2, char* komp3, char* komp4, char* komp5, char* komp6, char* komp7, char* komp8, int invoice);
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void Dequeue(Queue * Q);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
void STARTBUILD(Queue Q, boolean *build);
void FINISHBUILD(Queue *Q, boolean *build, Stack S, List *inventory);
void CheckOrder(Queue Q);

#endif
