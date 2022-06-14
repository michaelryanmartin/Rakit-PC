/*  NIM : 18219071
    Nama : Nadya Laurentia
    Tanggal : Senin, 26 Oktober 2020
    Topik praktikum : List linear dengan representasi pointer
    Deskripsi : Implementasi ADT list berkait dengan representasi pointer
*/

/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addrLL dengan pointer */
/* infoganteng adalah integer */

#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLL (ListL L)
/* Mengirim true jika list kosong */
{
    return(First(L)==Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (ListL *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L)=Nil;
}

/****************** Manajemen Memori ******************/
addrLL AlokasiLL (infoganteng X)
/* Mengirimkan addrLL hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrLL tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addrLL P = (addrLL) malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void DealokasiLL (addrLL *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrLL P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addrLL Search (ListL L, infoganteng X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan addrLL elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    addrLL result = Nil;
    addrLL P = First(L);
    boolean found = false;
    if (!IsEmptyLL(L)) {
        do {
            if (Info(P)==X){
                result = P;
                found = true;
            } else {
                P = Next(P);
            }
        } while (P!=Nil && !found);
    }
    return result;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
// void InsVFirst (ListL *L, infoganteng X)
// /* I.S. L mungkin kosong */
// /* F.S. Melakukan alokasi sebuah elemen dan */
// /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
// {
//     addrLL P = Alokasi(X);
//     if (P != Nil) {
//         InsertFirst(L,P);
//     } 
// }

void InsVLast (ListL *L, infoganteng X)
// /* I.S. L mungkin kosong */
// /* F.S. Melakukan alokasi sebuah elemen dan */
// /* menambahkan elemen list di akhir: elemen terakhir yang baru */
// /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addrLL P = AlokasiLL(X);
    if (P != Nil) {
        InsertLastLL(L,P);
    } 
}

// /*** PENGHAPUSAN ELEMEN ***/
// void DelVFirst (ListL *L, infoganteng *X)
// /* I.S. List L tidak kosong  */
// /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
// /*      dan alamat elemen pertama di-dealokasi */
// {
//     addrLL P;
//     DelFirst(L,&P);
//     *X = Info(P);
//     Dealokasi(&P);
// }

// void DelVLast (ListL *L, infoganteng *X)
// /* I.S. list tidak kosong */
// /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
// /*      dan alamat elemen terakhir di-dealokasi */
// {
//     addrLL P;
//     DelLast(L,&P);
//     *X = Info(P);
//     Dealokasi(&P);
// }

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstLL (ListL *L, addrLL P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addrLL P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;   
}

void InsertAfterLL (ListL *L, addrLL P, addrLL Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLastLL (ListL *L, addrLL P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmptyLL(*L)) {
        InsertFirstLL(L,P);
    } else {
        addrLL Last = First(*L);
        while (Next(Last)!=Nil){
            Last = Next(Last);
        }
        InsertAfterLL(L,P,Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
// void DelFirst (ListL *L, addrLL *P)
// /* I.S. List tidak kosong */
// /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
// /*      Elemen list berkurang satu (mungkin menjadi kosong) */
// /* First element yg baru adalah suksesor elemen pertama yang lama */
// {
//     *P = First(*L);
//     First(*L) = Next(*P);
// }

// void DelP (ListL *L, infoganteng X)
// /* I.S. Sembarang */
// /* F.S. Jika ada elemen list beraddrLL P, dengan Info(P)=X  */
// /* Maka P dihapus dari list dan di-dealokasi */
// /* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
// /* List mungkin menjadi kosong karena penghapusan */
// //Untuk Prosedur DelP, apabila terdapat lebih dari satu elemen yang memiliki Info bernilai X, maka yang dihapus hanyalah elemen pertama dimana Info = X.
// {
//     addrLL P = First(*L);
//     if (Info(P)==X){
//         DelFirst(L,&P);
//     } else {
//         while(Next(P)!=Nil && Info(Next(P))!=X){
//             P = Next(P);
//         }
//         addrLL P1 = Next(P);
//         if (P1 != Nil) {
//             addrLL P2 = Next(P1);
//             Next(P) = P2;
//             Dealokasi(&P1);
//         }
//     }
// }

// void DelLast (ListL *L, addrLL *P)
// /* I.S. List tidak kosong */
// /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
// /*      Elemen list berkurang satu (mungkin menjadi kosong) */
// /* Last element baru adalah predesesor elemen terakhir yg lama, */
// /* jika ada */
// {
//     *P = First(*L);
//     addrLL Prec = Nil;
//     while (Next(*P)!=Nil){
//         Prec = *P;
//         *P = Next(*P);
//     }
//     if (Prec == Nil) {
//         First(*L) = Nil;
//     } else {
//         Next(Prec) = Nil;
//     }
// }

// void DelAfter (ListL *L, addrLL *Pdel, addrLL Prec)
// /* I.S. List tidak kosong. Prec adalah anggota list  */
// /* F.S. Menghapus Next(Prec): */
// /*      Pdel adalah alamat elemen list yang dihapus  */
// {
//     *Pdel = Next(Prec);
//     Next(Prec) = Next(*Pdel);
//     Next(*Pdel) = Nil;
// }

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (ListL L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    if (!IsEmptyLL(L)){
        int i = 1;
        addrLL P = First(L);
        while(P!=Nil){
            printf("%d. ",i);
            if (Info(P) == 'B'){
                printf("Base");
            }
            else if (Info(P) == 'S'){
                printf("Shop");
            }
            else{
                printf("Pelanggan %d",Info(P));
            }
            i++;
            P = Next(P);
        }
    }
    else{
        printf("huhu gabisa ke mana2 :(");
    } 
}

int NbL (ListL L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count=0;
    addrLL P = First(L);
    while (P!=Nil){
        count++;
        P = Next(P);
    }
    return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infoganteng Max (ListL L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    addrLL P = First(L);
    infoganteng Max = Info(P);
    P = Next(P);
    while (P!=Nil){
        if(Info(P)>Max){
            Max = Info(P);
        }
        P = Next(P);
    }
    return Max;
}

addrLL AdrMax (ListL L)
/* Mengirimkan addrLL P, dengan info(P) yang bernilai maksimum */
{
    return (Search(L,Max(L)));
}

infoganteng Min (ListL L)
/* Mengirimkan nilai info(P) yang minimum */
{
    addrLL P = First(L);
    infoganteng Min = Info(P);
    P = Next(P);
    while (P!=Nil){
        if(Info(P)<Min){
            Min = Info(P);
        }
        P = Next(P);
    }
    return Min;
}

addrLL AdrMin (ListL L)
/* Mengirimkan addrLL P, dengan info(P) yang bernilai minimum */
{
    return (Search(L,Min(L)));
}

float Average (ListL L)
/* Mengirimkan nilai rata-rata info(P) */
{
    addrLL P = First(L);
    float avg = 0;
    while (P!=Nil){
        avg += Info(P);
        P = Next(P);
    }
    avg = avg/NbL(L);
    return avg;
}

/****************** PROSES TERHADAP LIST ******************/
void InversList (ListL *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    addrLL P,Q,temp,pertama;
    pertama = First(*L);
    P = First(*L);
    Q = Next(P);
    while (Q!=Nil){
        P = Q;
        Q = Next(Q);
        InsertFirstLL(L,P);
        Next(pertama) = Q;
    }
}


void Konkat1 (ListL *L1, ListL *L2, ListL *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    CreateEmpty(L3);
    if (!IsEmptyLL(*L1)){
        First(*L3) = First(*L1);
        addrLL P = First(*L1);
        while (Next(P)!=Nil){
            P = Next(P);
        }
        Next(P) = First(*L2);
    } else {
        First(*L3) = First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}