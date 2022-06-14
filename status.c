/*status*/
#include"status.h"

void Stat(Queue Q, int uang, /*lokasi*/ List invent){
    printf("Uang tersisa: $%d\n", uang);
    printf("Build yang sedang dikerjakan: pesanan %d untuk pelanggan %d\n", NoOrder(Head(Q)), NoPel(Head(Q)));
    printf("Lokasi: pemain sedang berada di ....\n"); ///BELUM
    printf("Inventory anda:\n");
    /*printarraydinamis*/
    for (int i = 0; i < invent.Neff; i++){
        printf("%d. ", i+1);
        printf("%s ", invent.A[i].nama);
        printf("(%d)\n", invent.A[i].banyak);
    }
}
