#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"arraydin.h"

/*** Konstruktor/Kreator ***/
void CreateStackEmpty(Stack *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0..MaxEl-1 */
/* Ciri stack kosong: TOP bernilai Nil */
{
    Top(*S) = Nill;
}
/********** Predikat Untuk test keadaan KOLEKSI **********/
boolean IsStackEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S) == Nill);
}
boolean IsFull(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S) == MaxEl-1);
}
/*********** Menambahkan sebuah elemen ke Stack **********/
void Push(Stack *S, type X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S)++;
    InfoTop(*S) = X;
}
/*********** Menghapus sebuah elemen Stack **********/
void Pop(Stack *S, type *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S)--;
}

void PrintStack(Stack S)
/* Mencetak ke layar stack yang sudah dibuat*/
{
    
    int num = 1;

    for (int i = 0; S.T[i]; i++){
        printf("%d. %s\n", num, S.T[i]);
        num++;
    }
}

void ADDCOMPONENT(Stack currentBuild)
/* Menambahkan part-part komputer untuk membuat PC*/
/* Sesuai urutannya*/
{
    
    type T;
    List inventory;

    printf("Komponen yang telah terpasang: ");
    PrintStack(currentBuild);


    printf("Komponen yang tersedia: ");
    PrintArrDin(inventory);
    
    int N = scanf("Komponen yang ingin dipasang: ");   //USER AKAN DIMINTA INPUT, UNTUK MEMILIH KOMPONEN MANA YANG INGIN DIPASANG DI PC
    
    printf("Komponen berhasil dipasang!");
}

void REMOVECOMPONENT(Stack currentBuild, type X)
/*Stack tidak kosong, sudah ada isinya*/
/* Mencopot suatu komponen dari PC yang sedang/sudah dibuat*/
{
    type temp;
    if (!IsStackEmpty(currentBuild)){
        temp = InfoTop(currentBuild);
        Pop(&currentBuild, &temp);
        printf("Komponen %s berhasil dicopot", temp);
    }

}