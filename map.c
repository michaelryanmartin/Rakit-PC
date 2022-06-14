/*File : MAP*/

#include"map.h"
#include<stdio.h>

void Config(MATRIKS *M, Graph *G, int *n, POINT *p, char *r){
    int brs, kol;
    int BaseB, BaseK;

    STARTKATA();
    brs = ToInt(CKata);
    ADVKATA();
    kol = ToInt(CKata);
    MakeMATRIKS(brs, kol, M);
    
    ADVKATA();
    *n = ToInt(CKata);

    int i = 1;
    while (i<=(*n)){
        char dot;
        ADVKATA();
        if (i<=2){
            dot = CKata.TabKata[0];
        } else {
            dot = (i-2) + '0';
        }
        ADVKATA();
        brs = ToInt(CKata)-1;
        ADVKATA();
        kol = ToInt(CKata)-1;
        Elmt(*M,brs,kol) = dot;
        if (i==1) {
            BaseB = brs;
            BaseK = kol;
        }
        i++;
    }

    //BACA GRAPH
    i = 1;
    int j = 1;
    while (i<=(*n)){
        while (j<=(*n)){
            ADVKATA();
            if (ToInt(CKata) == 1) {
                if (i == 1){
                    if (j == 1){
                        AddLink(G, 'B', 'B');
                    } else if (j == 2){
                        AddLink(G, 'B', 'S');
                    } else {
                        AddLink(G, 'B', (j-2)+'0');
                    }
                } else if (i == 2) {
                    if (j == 1){
                        AddLink(G, 'S', 'B');
                    } else if (j == 2){
                        AddLink(G, 'S', 'S');
                    } else {
                        AddLink(G, 'S', (j-2)+'0');
                    }
                } else {
                    AddLink(G, (i-2)+'0', (j-2)+'0');
                }
            }
            j++;
        }
        j = 1;
        i++;
    }

    //Tempatin P
    *p = MakePOINT(BaseK, BaseB);
    Elmt(*M,BaseB,BaseK) = 'P';
    *r = 'B';

    //Buat di deliver/move
    // *r = Elmt(*M,Ordinat(*p),Absis(*p));
    // Elmt(*M,Ordinat(*p),Absis(*p)) = 'P';
}