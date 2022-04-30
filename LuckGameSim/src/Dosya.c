#include "Dosya.h"
#include "Kisi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replace_char(char*, char, char);

File new_File(char* path){
	File this;
	this = (File)malloc(sizeof(struct DOSYA));
	this->path = path;
	
	this->openFile = &openFile;
	this->getLine = &getLine;
	this->toArray = &toArray;
	this->numstoArray = &numstoArray;
	
	return this;
}

FILE* openFile(const File this){
	FILE *file = fopen(this->path,"r");
	if (file == NULL){
    	printf("Dosya acilamiyor! \n");
    }
	return file;
}

// Satir dondur
char* getLine(FILE* file, char* arr){
	fgets(arr, 45, file);
	replace_char(arr, '#', ' '); // Satirlari sadece bosluklar ile ayrilmis hale getir ('#' sil)
	return arr;
}

Kisi* toArray(FILE* file, Kisi* kisi, const File this){
	char line[45];
	char ad[10];
	char soyad[15];
	double para;
	float yatirilan;
	int sayi;
	
	// Kisi dizisi icin bellek ayirma	
	for (int j = 0; j < 1000; j++) {
		kisi[j] = malloc(20000);
	}
	
	//Kisileri diziye atama
	for (int i = 0; i <1000; i++){
		this->getLine(file,line);
		sscanf(line, "%s %s %lf %f %d",ad, soyad, &para, &yatirilan, &sayi); // Satiri oku
		kisi[i] = new_Kisi(ad,soyad,para,yatirilan,sayi); // Kisi olusturup diziye koy
	}
	return kisi;
}

int* numstoArray(FILE* file, int* arr){
	*arr = (int)malloc(278 * sizeof(int));
	for (int i = 0; i < 278; i++){
		fscanf(file, "%d", &arr[i]);
	}
}

// String icindeki bir karakteri verilen yeni karakterle degistiren fonksiyon
char* replace_char(char* str, char find, char replace){
    char *current_pos = strchr(str,find);
    while (current_pos){
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
    return str;
}
