#include <stdlib.h>
#include <stdio.h>
#include "shop.h"

void Shop(/*inventory*/, int uang)
{
    /*Declare array (gw bingung napa ga compile di bagian ini)*/
    Elmt array[24] =
    {"Motherboard A","Motherboard B","Motherboard C",
    "CPU A","CPU B","CPU C",
    "Memory A","Memory B","Memory C",
    "CPU Cooler A","CPU Cooler B","CPU Cooler C",
    "Case A","Case B","Case C",
    "GPU A","GPU B","GPU C",
    "Storage A","Storage B","Storage C",
    "PSU A","PSU B","PSU C"};

    /*Kamus*/
    int i;
    int jmlh;
    int harga = 500;

    /*Menu*/
    printf("Komponen yang tersedia:\n");
    for (i = 0,i < 23,i++)
    {
        printf("%s",Elmt array[i]);
    }

    /*Spesifikasi pembelian*/
    printf("Komponen yang ingin dibeli: ");
    scanf("%d",i);
    printf("Masukkan jumlah yang ingin dibeli: ");
    scanf("%d",jmlh);

    /*Pengecekan uangnya dan nambah barang ke inventory*/
    if (uang - jmlh*harga < 0)
    {
        printf("Uang tidak cukup!");
    }
    else
    {
        uang - jmlh*harga;
        /*masukin ke inventory*/
        printf("Komponen berhasil dibeli");
    }
    return 0;
}
