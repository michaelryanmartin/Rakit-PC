#include "mesinkata.h"
#include "map.h"
#include "queue.h"
#include "arraydin.h"
#include "status.h"
#include "drivergraph.h"
#include "point.h"
#include "stack.h"
#include <stdio.h>

int main(){
    // Kamus Lokal
    POINT Position = MakePOINT(-1,-1);
    int uang = 100000;
    char replaced;
    Queue order;
    CreateEmpty(&order);
    List inventory = MakeList();
    boolean build;
    MATRIKS M;
    Graph G;
    int NbBuilding;

    Config(&M, &G, &NbBuilding, &Position, &replaced);
    Enqueue(&order, 1, 1, "Motherboard A", "CPU B", "Memory B", "CPU Cooler C", "Case A", "GPU A", "Storage C", "PSU B", 2000);

    BacaCmd();
    while (!IsKataEXIT(CKata)){
        if (IsKataMOVE(CKata)){
            printf("run MOVE\n");
            Move(&Position, M, G);
        } else if (IsKataSTATUS(CKata)){
            printf("run STATUS\n");
            Stat(order, uang, inventory);
        } else if (IsKataCHECKORDER(CKata)){
            printf("run checkorder\n");
            CheckOrder(order);
        } else if (IsKataSTARTBUILD(CKata)){
            printf("run STARTBUILD\n");
            STARTBUILD(order, &build);
            int i =0;
            while (i<=7){
                printf("%s", order.HEAD->T[i].komponen);
                if (i == 7){
                    printf("\n");
                } else {
                    printf(", ");
                }
                i++;
            }
        } else if (IsKataFINISHBUILD(CKata)){
            printf("run FINISHBUILD\n");
        } else if (IsKataADDCOMPONENT(CKata)){
            printf("run ADDCOMPONENT\n");
            // if (build) {
                // ADDCOMPONENT;
            // } else {
                // printf("belum start build\n");
            // }
        } else if (IsKataREMOVECOMPONENT(CKata)){
            printf("run REMOVECOMPONENT\n");
        } else if (IsKataSHOP(CKata)){
            printf("run SHOP\n");
        } else if (IsKataDELIVER(CKata)){
            printf("run DELIVER\n");
        } else if (IsKataEND_DAY(CKata)){
            printf("run END_DAY\n");
        } else if (IsKataSAVE(CKata)){
            printf("run SAVE\n");
        } else if (IsKataMAP(CKata)){
            TulisMATRIKS(M);
        } else {
            printf("Command wrong\n");
        }
        BacaCmd();
    }
    printf("Exit success\n");
    return 0;
}