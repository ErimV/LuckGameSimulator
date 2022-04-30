#ifndef KISI_H
#define KISI_H

#include <stdio.h>
#include "Kisi.h"

struct KISI{
	char ad[20];
	char soyad[20];
	double para;
	float yatirilan;
	int sayi;
	
	
	void (*paraGuncelle)(const struct KISI*, double);
	
};
typedef struct KISI* Kisi;

Kisi new_Kisi(char*, char*, double, float, int);
void paraGuncelle(const Kisi, double);


#endif

