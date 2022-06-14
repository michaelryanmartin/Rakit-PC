#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include"mesinkar.h"

#define NMax 50
#define BLANK ' '
#define ENTER '\n'

typedef struct {
    char TabKata[NMax];
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
I.S.: CC sembarang
F.S.: CC ≠ BLANK atau CC = MARK */

void STARTKATA();
/* I.S.: CC sembarang
F.S.: EndKata = true, dan CC = Mark;
atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S.: CC adalah karakter pertama kata yang akan diakuisisi
F.S.: CKata adalah kata terakhir yang sudah diakuisisi,
CC adalah karakter pertama dari kata berikutnya, mungkin MARK
Proses: Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
I.S.: CC adalah karakter pertama dari kata
F.S.: CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang diakuisisi */

int ToInt(Kata word);
/* Mengubah Kata berupa angka ke dalam bentuk integer */

void BacaCmd();
/* Membaca command dari terminal
I.S. : CC adalah karakter pertama kata yang akan diakuisisi dari terminal
F.S. : CKata adalah hasil akuisisi command;
CC = ENTER; CC adalah karakter sesudah karakter terakhir yang diakuisisi*/

boolean IsKataSama (Kata K1, Kata K2);

boolean IsKataMOVE(Kata K);

boolean IsKataSTATUS(Kata K);

boolean IsKataCHECKORDER(Kata K);

boolean IsKataSTARTBUILD(Kata K);

boolean IsKataFINISHBUILD(Kata K);

boolean IsKataADDCOMPONENT(Kata K);

boolean IsKataREMOVECOMPONENT(Kata K);

boolean IsKataSHOP(Kata K);

boolean IsKataDELIVER(Kata K);

boolean IsKataEND_DAY(Kata K);

boolean IsKataSAVE(Kata K);

boolean IsKataMAP(Kata K);

boolean IsKataEXIT(Kata K);

void Tulis();

#endif