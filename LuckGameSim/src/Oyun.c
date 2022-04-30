#include "Oyun.h"
#include "Kisi.h"
#include "Dosya.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void kisiDongusu(const Oyun, Kisi*, int);
void paraYatir(const Oyun, Kisi , double);
void tutturmaDurumu(const Oyun, Kisi, int, double);
Kisi enZengin(Kisi*);
void ekran(int, int, const Oyun, Kisi);
void delay(int);

Oyun new_Oyun(double masaBakiye){
	Oyun this;
	this = (Oyun)malloc(sizeof(struct OYUN));
	this->masaBakiye = masaBakiye;
	
	this->start = &start;
	this->masayiGuncelle = &masayiGuncelle;
	
	return this;
}

// Ana oyun dongusu
void start(const Oyun this, int* numbers, Kisi* kisi){
	int i = 0;
	int turn, lucky_number;
	
	//Her tur için
	while (i < 278){
		turn = i + 1;
		lucky_number = numbers[i];
		kisiDongusu(this, kisi, lucky_number); // Her bir kisi icin kontrol dongusu
		Kisi en_zengin = enZengin(kisi); // En zengini bul
		system ("cls"); // cmd temizle
		ekran(lucky_number, turn, this, en_zengin); // Ekraný yazdir
		delay(100); // Gecikme
		i++;
	}
}

void masayiGuncelle(const Oyun this, double yatirilan){
	this->masaBakiye = this->masaBakiye + yatirilan;
}

void kisiDongusu(const Oyun this, Kisi* kisi, int lucky_number){
	double kisininYatirdigi;
	for (int i=0; i<1000; i++){
		if (kisi[i]->para >= 1000) { // Parasi 1000 altina duseni ele
			
			kisininYatirdigi = kisi[i]->para * kisi[i]->yatirilan;

			paraYatir(this, kisi[i], kisininYatirdigi); // Para yatirma durumu
			
			tutturmaDurumu(this, kisi[i], lucky_number, kisininYatirdigi); // Sayi tutturma durumu
			
		}	
	}
}

void paraYatir(const Oyun this, Kisi kisi, double kisininYatirdigi){

	kisi->paraGuncelle(kisi, -kisininYatirdigi);
	this->masayiGuncelle(this, kisininYatirdigi);
}

void tutturmaDurumu(const Oyun this, Kisi kisi, int lucky_number, double kisininYatirdigi){
	double odul = 0;
	if (lucky_number == kisi->sayi){
		odul = 10 * kisininYatirdigi;
		kisi->paraGuncelle(kisi, odul);
		this->masayiGuncelle(this, -odul);	
	}
}

Kisi enZengin(Kisi* kisi){
	Kisi en_zengin = new_Kisi("dummy","dummy",0,0,0); // Ýlk kýyaslama için
	for (int i=0; i<1000; i++){
		if(kisi[i]->para > en_zengin->para) {
			en_zengin = kisi[i];
		}
	}
	return en_zengin;
}

void ekran(int lucky_number, int turn, const Oyun this, Kisi enZengin){
	// Ad soyad ayrý ayrý dizayný bozuyordu, tek string haline getirildi
	char isim[100];
	strcat(isim,enZengin->ad);
	strcat(isim," ");
	strcat(isim,enZengin->soyad);
	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                     #########################################\n");
	printf("                     ##          SANSLI SAYI: %-4d          ##\n",lucky_number);
	printf("                     #########################################\n");
	printf("                     #########################################\n");
	printf("                     ##          TUR: %-4d                  ##\n",turn);
	printf("                     ##  MASA BAKIYE: %-12.2lf TL       ##\n",this->masaBakiye);
	printf("                     ##                                     ##\n");
	printf("                     ##-------------------------------------##\n");
	printf("                     ##          EN ZENGIN KISI             ##\n");
	printf("                     ##          %-20s       ##\n",isim);
	printf("                     ##  BAKIYESI: %-10.2lf TL            ##\n",enZengin->para);
	printf("                     ##                                     ##\n");
	printf("                     #########################################\n");
	printf("\n");

	// OYUN BITTI ekraný
	if (turn == 278) {
		system ("cls");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("                     #########################################\n");
		printf("                     ##          TUR: %-4d                  ##\n",turn);
		printf("                     ##  MASA BAKIYE: %-10.2lf TL        ##\n",this->masaBakiye);
		printf("                     ##                                     ##\n");
		printf("                     ##-------------------------------------##\n");
		printf("                     ##             OYUN BITTI              ##\n");
		printf("                     ##                                     ##\n");
		printf("                     ##                                     ##\n");
		printf("                     #########################################\n");
		printf("\n");
	}
}

void delay(int mili_seconds){
  
    // Sureyi ayarla
    clock_t start_time = clock();
  
    // Istenen sureye gelene kadar don
    while (clock() < start_time + mili_seconds);
}

