#ifndef OYUN_H
#define OYUN_H

#include "Kisi.h"
#include <stdio.h>

struct OYUN{
	
	double masaBakiye;
	
	void (*start)(const struct OYUN*, int*, Kisi*);
	void (*masayiGuncelle)(const Oyun, double);
	
};
typedef struct OYUN* Oyun;

Oyun new_Oyun(double);
void start(const Oyun, int*, Kisi*);
void masayiGuncelle(const Oyun, double);

#endif
