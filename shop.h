/* File : shop.h */
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
#ifndef _SHOP_H
#define _SHOP_H

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef int infotype;

/* Queue dengan representasi berkait dengan pointer */
typedef struct {
	char* nama; 
	int harga;
} Elmt;

extern Elmt array[24];

void Shop(/*inventory*/, int uang);

#endif