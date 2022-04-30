#include "Kisi.h"
#include <stdio.h>
#include <stdlib.h>

Kisi new_Kisi(char* ad, char* soyad, double para, float yatirilan, int sayi){
	Kisi this;
	this = (Kisi)malloc(sizeof(struct KISI));
	for (int i=0;i<20;i++){
		this->ad[i] = ad[i];
		this->soyad[i] = soyad[i];
	}
	this->para = para;
	this->yatirilan = yatirilan;
	this->sayi = sayi;
	
	this->paraGuncelle = &paraGuncelle;
	
	return this;
}


void paraGuncelle(const Kisi this, double miktar) {
	this->para += miktar;
}
