/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */

#include "queue.h"
#include "arraydin.h"
#include <stdlib.h>
#include <stdio.h>

/* Prototype manajemen memori */
void Alokasi (address *P, int no_ord, int no_pel, char* komp1, char* komp2, char* komp3, char* komp4, char* komp5, char* komp6, char* komp7, char* komp8, int invoice)
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
    *P = (address) malloc(sizeof(ElmtQueue));
    if (*P!=Nil){
        NoOrder(*P) = no_ord;
        NoPel(*P) = no_pel;
        (*P)->T[0].komponen = komp1;
        (*P)->T[1].komponen  = komp2;
        (*P)->T[2].komponen  = komp3;
        (*P)->T[3].komponen = komp4;
        (*P)->T[4].komponen  = komp5;
        (*P)->T[5].komponen  = komp6;
        (*P)->T[6].komponen = komp7;
        (*P)->T[7].komponen  = komp8;
        Invoice(*P) = invoice;
        Status(*P) = false;
        Next(*P) = Nil;
    }
}

void Dealokasi (address  P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free(P);
}

boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
    return(Head(Q)==Nil && Tail(Q)==Nil);
}

int NbElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
    int count = 0;
    if (!IsEmpty(Q)){
        address P = Head(Q);
        while(P!=Nil){
            count++;
            P = Next(P);
        }
    }
    return count;
}

/*** Kreator ***/
void CreateEmpty(Queue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/*** Primitif Enqueue/Dequeue ***/
void Enqueue (Queue * Q, int no_ord, int no_pel,  char* komp1, char* komp2, char* komp3, char* komp4, char* komp5, char* komp6, char* komp7, char* komp8, int invoice)
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
    address P;
    Alokasi(&P, no_ord, no_pel, komp1, komp2, komp3, komp4, komp5, komp6, komp7, komp8, invoice);
    if (P!=Nil){
        if (IsEmpty(*Q)){
            Head(*Q) = P;
            Tail(*Q) = P;
        } else {
            Next(Tail(*Q)) = P;
            Tail(*Q) = P;
        }
    }
}

void Dequeue(Queue * Q)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    address P = Head(*Q);
    if (NbElmt(*Q)==1){
        Tail(*Q) = Nil;
    }
    Head(*Q) = Next(Head(*Q));
    Dealokasi(P);
}

void STARTBUILD(Queue Q, boolean *build) //inputnya data orderan
//asumsi semua posisi di map nya valid
{
    address current_order;
    current_order = Head(Q);
    if ((Head(Q) != Nil) && (Status(current_order)==false))
        {
            printf("Kamu telah memulai pesanan %d untuk pelanggan %d.\n", NoOrder(current_order), NoPel(current_order));
        }
    *build = true;
}

void FINISHBUILD(Queue *Q, boolean *build, Stack S, List *inventory)
{
    int i=0;
    boolean sama = true;
    while (i<=7 && sama){
        if (S.T[i] != Head(*Q)->T[i].komponen){
            sama = false;
        }
        i++;
    }
	if (sama) //proses add component telah berhasil dan selesai
    {
        Status(Head(*Q)) = true;
        *build = false;
		printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d!\n", NoOrder(Head(*Q)), NoPel(Head(*Q)));
        char * noord;
        sprintf(noord, "%d", NoOrder(Head(*Q)));
        char* order = "Build untuk pesanan #";
        char* baru = strcat(order, noord);
        InsertLast(inventory, baru, 1);
	}
	else
	{
		printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
	}
}

void CheckOrder(Queue Q){
    printf("Nomor Order: %d\n", NoOrder(Head(Q)));
    printf("Pemesan: Pelanggan %d\n", NoPel(Head(Q)));
    printf("Invoice: $%d\n", Invoice(Head(Q)));
    printf("Komponen:\n");
    for (int i = 0; i<=7; i++){
        printf("%d. ", i+1);
        printf("%s\n", Head(Q)->T[i].komponen);
    }
}