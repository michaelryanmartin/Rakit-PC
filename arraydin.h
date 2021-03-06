#ifndef __DYNAMIC_LIST__
#define __DYNAMIC_LIST__
#include "boolean.h"

#define InitialSize 10

typedef int IdxType;
typedef struct {
    char* nama;
    int banyak;
} ElmtArr;
typedef struct {
    ElmtArr *A;
    int Capacity;
    int Neff;
} List;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk List kosong dengan ukuran InitialSize
 */
List MakeList();

/**
 * Destruktor
 * I.S. List terdefinisi
 * F.S. list->A terdealokasi
 */
void DeallocateList(List *list);

/**
 * Fungsi untuk mengetahui apakah suatu list kosong.
 * Prekondisi: list terdefinisi
 */
boolean IsArrEmpty(List list);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
 * Prekondisi: list terdefinisi
 */
int Length(List list);

/**
 * Mengembalikan elemen list L yang ke-I (indeks lojik).
 * Prekondisi: list tidak kosong, i di antara 0..Length(list).
 */
ElmtArr Get(List list, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: list terdefinisi
 */
int GetCapacity(List list);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: list terdefinisi, i di antara 0..Length(list).
 */
void InsertAt(List *list, char* el, int nb, IdxType i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir list.
 * Prekondisi: list terdefinisi
 */
void InsertLast(List *list, char* el, int nb);

/**
 * Fungsi untuk menambahkan elemen baru di awal list.
 * Prekondisi: list terdefinisi
 */
void InsertFirst(List *list, char* el, int nb);

void PrintArrDin(List list);
/*
    Fungsi ini akan membaca elemen-elemen pada array dinamis
    dan akan mencetak elemen-elemen tersebut kelayar
*/

#endif