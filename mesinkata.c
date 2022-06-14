#include "mesinkata.h"
#include<stdio.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
I.S.: CC sembarang
F.S.: CC ≠ BLANK */
{
/* Kamus Lokal */
/* Algoritma */
    while (CC == BLANK || CC == ENTER) {
        ADV();
    } /* CC != BLANK */
}

void STARTKATA()
/* I.S.: CC sembarang
F.S.: EndKata = true, dan CC = Mark;
atau EndKata = false, CKata adalah kata yang sudah
diakuisisi,
CC karakter pertama sesudah karakter terakhir kata */
{
/* Kamus Lokal */
/* Algoritma*/
    START();
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else /* CC != MARK */ {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA()
/* I.S.: CC adalah karakter pertama kata yang akan diakuisisi
F.S.: CKata adalah kata terakhir yang sudah diakuisisi,
CC adalah karakter pertama dari kata berikutnya,
mungkin MARK
Proses: Akuisisi kata menggunakan procedure SalinKata */
{
/* Kamus Lokal */
/* Algoritma*/
    IgnoreBlank(); 
    if (CC == MARK) {
        EndKata = true;
    } else /* CC != MARK */ {
        SalinKata();
    }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
I.S.: CC adalah karakter pertama dari kata
F.S.: CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang
diakuisisi */
{
/* Kamus Lokal */
    int i; 
/* Algoritma*/
    i = 0; /* inisialisasi */
    while ((CC != MARK) && (CC != BLANK) && (CC != ENTER)) {
        CKata.TabKata[i] = CC;
        ADV();
        if (CC != ENTER) {
            i++;
        }
    } /* CC = MARK or CC = BLANK */
    CKata.Length = i;
}

int ToInt(Kata word)
/* Mengubah Kata berupa angka ke dalam bentuk integer */
{
    /*Kamus Lokal*/
    int result = 0;

    /*Algoritma*/
    if(word.Length == 1){
        result = (int)(word.TabKata[0]) - 48;
    } else {
        int pengali = 1;
        for(int i = (word.Length-1); i>=0; i--){
            result += ((int)(word.TabKata[i]) - 48) * pengali;
            pengali *= 10;
        }
    }
    return result;
}

void BacaCmd()
/* Membaca command dari terminal
I.S. : CC adalah karakter pertama kata yang akan diakuisisi dari terminal
F.S. : CKata adalah hasil akuisisi command;
CC = ENTER; CC adalah karakter sesudah karakter terakhir yang diakuisisi*/
{
    /*Kamus Lokal*/
	int i = 0;

    /*Algoritma*/
	do {
		ADVCmd();
		CKata.TabKata[i] = CC;
		i++;
	} while((CC != ENTER) && (i < NMax));
	CKata.Length = i-1;
}

boolean IsKataSama(Kata K1, Kata K2)
{
    /*Kamus Lokal*/
    boolean sama = true;
    int i = 0;

    /*Algoritma*/
    if(K1.Length != K2.Length) {
        sama = false;
    } else {
        while (i<=(K1.Length-1) && sama){
            if (K1.TabKata[i] != K2.TabKata[i]){
                sama = false;
            }
            i++;
        }
    }
    
    return sama;
}

boolean IsKataMOVE(Kata K)
{
    /*Kamus Lokal*/
    Kata MOVE;

    /*Algoritma*/
    MOVE.TabKata[0] = 'M';
    MOVE.TabKata[1] = 'O';
    MOVE.TabKata[2] = 'V';
    MOVE.TabKata[3] = 'E';
    MOVE.Length = 4;

    return(IsKataSama(K, MOVE));
}

boolean IsKataSTATUS(Kata K)
{
    /*Kamus Lokal*/
    Kata STATUS;

    /*Algoritma*/
    STATUS.TabKata[0] = 'S';
    STATUS.TabKata[1] = 'T';
    STATUS.TabKata[2] = 'A';
    STATUS.TabKata[3] = 'T';
    STATUS.TabKata[4] = 'U';
    STATUS.TabKata[5] = 'S';
    STATUS.Length = 6;

    return(IsKataSama(K, STATUS));
}

boolean IsKataCHECKORDER(Kata K)
{
    /*Kamus Lokal*/
    Kata CHECKORDER;

    /*Algoritma*/
    CHECKORDER.TabKata[0] = 'C';
    CHECKORDER.TabKata[1] = 'H';
    CHECKORDER.TabKata[2] = 'E';
    CHECKORDER.TabKata[3] = 'C';
    CHECKORDER.TabKata[4] = 'K';
    CHECKORDER.TabKata[5] = 'O';
    CHECKORDER.TabKata[6] = 'R';
    CHECKORDER.TabKata[7] = 'D';
    CHECKORDER.TabKata[8] = 'E';
    CHECKORDER.TabKata[9] = 'R';
    CHECKORDER.Length = 10;

    return(IsKataSama(K, CHECKORDER));
}

boolean IsKataSTARTBUILD(Kata K)
{
    /*Kamus Lokal*/
    Kata STARTBUILD;

    /*Algoritma*/
    STARTBUILD.TabKata[0] = 'S';
    STARTBUILD.TabKata[1] = 'T';
    STARTBUILD.TabKata[2] = 'A';
    STARTBUILD.TabKata[3] = 'R';
    STARTBUILD.TabKata[4] = 'T';
    STARTBUILD.TabKata[5] = 'B';
    STARTBUILD.TabKata[6] = 'U';
    STARTBUILD.TabKata[7] = 'I';
    STARTBUILD.TabKata[8] = 'L';
    STARTBUILD.TabKata[9] = 'D';
    STARTBUILD.Length = 10;

    return(IsKataSama(K, STARTBUILD));
}

boolean IsKataFINISHBUILD(Kata K)
{
    /*Kamus Lokal*/
    Kata FINISHBUILD;

    /*Algoritma*/
    FINISHBUILD.TabKata[0] = 'F';
    FINISHBUILD.TabKata[1] = 'I';
    FINISHBUILD.TabKata[2] = 'N';
    FINISHBUILD.TabKata[3] = 'I';
    FINISHBUILD.TabKata[4] = 'S';
    FINISHBUILD.TabKata[5] = 'H';
    FINISHBUILD.TabKata[6] = 'B';
    FINISHBUILD.TabKata[7] = 'U';
    FINISHBUILD.TabKata[8] = 'I';
    FINISHBUILD.TabKata[9] = 'L';
    FINISHBUILD.TabKata[10] = 'D';
    FINISHBUILD.Length = 11;

    return(IsKataSama(K, FINISHBUILD));
}

boolean IsKataADDCOMPONENT(Kata K)
{
    /*Kamus Lokal*/
    Kata ADDCOMPONENT;

    /*Algoritma*/
    ADDCOMPONENT.TabKata[0] = 'A';
    ADDCOMPONENT.TabKata[1] = 'D';
    ADDCOMPONENT.TabKata[2] = 'D';
    ADDCOMPONENT.TabKata[3] = 'C';
    ADDCOMPONENT.TabKata[4] = 'O';
    ADDCOMPONENT.TabKata[5] = 'M';
    ADDCOMPONENT.TabKata[6] = 'P';
    ADDCOMPONENT.TabKata[7] = 'O';
    ADDCOMPONENT.TabKata[8] = 'N';
    ADDCOMPONENT.TabKata[9] = 'E';
    ADDCOMPONENT.TabKata[10] = 'N';
    ADDCOMPONENT.TabKata[11] = 'T';
    ADDCOMPONENT.Length = 12;

    return(IsKataSama(K, ADDCOMPONENT));
}

boolean IsKataREMOVECOMPONENT(Kata K)
{
    /*Kamus Lokal*/
    Kata REMOVECOMPONENT;

    /*Algoritma*/
    REMOVECOMPONENT.TabKata[0] = 'R';
    REMOVECOMPONENT.TabKata[1] = 'E';
    REMOVECOMPONENT.TabKata[2] = 'M';
    REMOVECOMPONENT.TabKata[3] = 'O';
    REMOVECOMPONENT.TabKata[4] = 'V';
    REMOVECOMPONENT.TabKata[5] = 'E';
    REMOVECOMPONENT.TabKata[6] = 'C';
    REMOVECOMPONENT.TabKata[7] = 'O';
    REMOVECOMPONENT.TabKata[8] = 'M';
    REMOVECOMPONENT.TabKata[9] = 'P';
    REMOVECOMPONENT.TabKata[10] = 'O';
    REMOVECOMPONENT.TabKata[11] = 'N';
    REMOVECOMPONENT.TabKata[12] = 'E';
    REMOVECOMPONENT.TabKata[13] = 'N';
    REMOVECOMPONENT.TabKata[14] = 'T';
    REMOVECOMPONENT.Length = 15;

    return(IsKataSama(K, REMOVECOMPONENT));
}

boolean IsKataSHOP(Kata K)
{
    /*Kamus Lokal*/
    Kata SHOP;

    /*Algoritma*/
    SHOP.TabKata[0] = 'S';
    SHOP.TabKata[1] = 'H';
    SHOP.TabKata[2] = 'O';
    SHOP.TabKata[3] = 'P';
    SHOP.Length = 4;

    return(IsKataSama(K, SHOP));
}

boolean IsKataDELIVER(Kata K)
{
    /*Kamus Lokal*/
    Kata DELIVER;

    /*Algoritma*/
    DELIVER.TabKata[0] = 'D';
    DELIVER.TabKata[1] = 'E';
    DELIVER.TabKata[2] = 'L';
    DELIVER.TabKata[3] = 'I';
    DELIVER.TabKata[4] = 'V';
    DELIVER.TabKata[5] = 'E';
    DELIVER.TabKata[6] = 'R';
    DELIVER.Length = 7;

    return(IsKataSama(K, DELIVER));
}

boolean IsKataEND_DAY(Kata K)
{
    /*Kamus Lokal*/
    Kata END_DAY;

    /*Algoritma*/
    END_DAY.TabKata[0] = 'E';
    END_DAY.TabKata[1] = 'N';
    END_DAY.TabKata[2] = 'D';
    END_DAY.TabKata[3] = '_';
    END_DAY.TabKata[4] = 'D';
    END_DAY.TabKata[5] = 'A';
    END_DAY.TabKata[6] = 'Y';
    END_DAY.Length = 7;

    return(IsKataSama(K, END_DAY));
}

boolean IsKataSAVE(Kata K)
{
    /*Kamus Lokal*/
    Kata SAVE;

    /*Algoritma*/
    SAVE.TabKata[0] = 'S';
    SAVE.TabKata[1] = 'A';
    SAVE.TabKata[2] = 'V';
    SAVE.TabKata[3] = 'E';
    SAVE.Length = 4;

    return(IsKataSama(K, SAVE));
}

boolean IsKataMAP(Kata K)
{
    /*Kamus Lokal*/
    Kata MAP;

    /*Algoritma*/
    MAP.TabKata[0] = 'M';
    MAP.TabKata[1] = 'A';
    MAP.TabKata[2] = 'P';
    MAP.Length = 3;

    return(IsKataSama(K, MAP));
}

boolean IsKataEXIT(Kata K)
{
    /*Kamus Lokal*/
    Kata EXIT;

    /*Algoritma*/
    EXIT.TabKata[0] = 'E';
    EXIT.TabKata[1] = 'X';
    EXIT.TabKata[2] = 'I';
    EXIT.TabKata[3] = 'T';
    EXIT.Length = 4;

    return(IsKataSama(K, EXIT));
}