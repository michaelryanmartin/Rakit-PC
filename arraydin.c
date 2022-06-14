#include<stdio.h>
#include<stdlib.h>
#include "arraydin.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk List kosong dengan ukuran InitialSize
 */
List MakeList(){
    List L;
    L.A = (ElmtArr *)malloc(InitialSize * sizeof(ElmtArr));
    L.Capacity = InitialSize;
    L.Neff = 0;
    return L;
}

/**
 * Destruktor
 * I.S. List terdefinisi
 * F.S. list->A terdealokasi
 */
void DeallocateList(List *list){
    free((*list).A);
    (*list).Capacity = 0;
    (*list).Neff = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu list kosong.
 * Prekondisi: list terdefinisi
 */
boolean IsArrEmpty(List list){
    return (list.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
 * Prekondisi: list terdefinisi
 */
int Length(List list){
    return(list.Neff);
}

/**
 * Mengembalikan elemen list L yang ke-I (indeks lojik).
 * Prekondisi: list tidak kosong, i di antara 0..Length(list).
 */
ElmtArr Get(List list, IdxType i){
    return(list.A[i]);
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: list terdefinisi
 */
int GetCapacity(List list){
    return(list.Capacity);
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: list terdefinisi, i di antara 0..Length(list).
 */
void InsertAt(List *list, char* el, int nb, IdxType i){
    if((*list).Neff==(*list).Capacity) {
        int desired = (*list).Capacity * 2;
        ElmtArr *temp=(ElmtArr*)malloc(desired * sizeof(ElmtArr));
        for(IdxType z=0; z<(*list).Neff;z++){
            temp[z] = (*list).A[z];
        }
        free((*list).A); 
        (*list).A = temp;
        (*list).Capacity = desired;

    }
    for(IdxType j=(*list).Neff; j>i; j--){
        (*list).A[j] = (*list).A[j-1] ;
    }
    (*list).A[i].nama = el;
    (*list).A[i].banyak = nb;
    (*list).Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir list.
 * Prekondisi: list terdefinisi
 */
void InsertLast(List *list, char* el, int nb){
    InsertAt(list, el, nb, (*list).Neff);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal list.
 * Prekondisi: list terdefinisi
 */
void InsertFirst(List *list, char* el, int nb){
    InsertAt(list, el, nb, 0);
}


void PrintArrDin(List list)
/*
    Fungsi ini akan membaca elemen-elemen pada array dinamis
    dan akan mencetak elemen-elemen tersebut kelayar
*/
{
    
    ElmtArr A;
    int c = 1;

    for(int i = 0; i<=list.Neff;i++){
        printf("%d. %s\n", c, list.A[i].nama);
        c++;
    }
}