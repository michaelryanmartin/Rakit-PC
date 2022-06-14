#include <stdio.h>
#include <string.h>
#include "matriks.h"
#include "point.h"
#include "graph.h"
#include "mesinkata.h"

void Move(POINT *Pos, MATRIKS M, Graph G){
    char* Posisi;
    if (Elmt(M, Ordinat(*Pos), Absis(*Pos)) == 'B'){
        Posisi = "base";
    }
    else if (Elmt(M, Ordinat(*Pos), Absis(*Pos)) == 'S'){
        Posisi = "shop" ;
    }
    else{
        Posisi[0] = Elmt(M, Ordinat(*Pos), Absis(*Pos));
    }
    printf("Kamu berada pada %s. \n", Posisi);

    printf("Daftar lokasi yang dapat dicapai: \n");

    PrintLink(G,Elmt(M, Ordinat(*Pos), Absis(*Pos)));
    
    printf("Nomor tujuan: ");

    BacaCmd();

    addressGraph P;
    ListL L;
    P = FirstGraph(G);
    while (InfoGraph(P) != (Elmt(M, Ordinat(*Pos), Absis(*Pos)))) {
        P = NextGraph(P);
    }
    L = Link(P);
    addrLL AL = First(L);
    int z = ToInt(CKata)-1;
    char *hasil;
    while (z != 0){
        AL = Next(AL);
        z--;
    }
    if (Info(AL) == 'B'){
        hasil = ("Base");
    }
    else if (Info(AL) == 'S'){
        hasil = ("Shop");
    }
    else{
        char gans = Info(AL);
        hasil = strncat("Pelanggan ", &gans, 1);
    }
    printf("Kamu telah mencapai lokasi %s!\n",hasil);

    int a = 0;
    int b = 0;
    boolean found = false;
    while (a < M.NBrsEff && !found){
        while (b < M.NKolEff && !found){
            if (Elmt(M,a,b) == Info(AL)){
                found = true;
            } else {
                b++;
            }
        }
        if (!found) {
            a++;
        }
    }

    *Pos = MakePOINT(b+1,a+1);
}