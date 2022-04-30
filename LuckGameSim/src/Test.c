#include "Dosya.h"
#include "Kisi.h"
#include "Oyun.h"
#include <stdio.h>

static Kisi kisi[1000];
static int numbers[278];

int main(){
	
	// Dosyalarý ac
	File kisiler = new_File("Kisiler.txt");
	File sayilar = new_File("Sayilar.txt");
	// Dosyalarý oku
	FILE *file = kisiler->openFile(kisiler);
	FILE *numfile = sayilar->openFile(sayilar);
	
	kisiler->toArray(file, kisi, kisiler); // Kisileri diziye ata
	sayilar->numstoArray(numfile, numbers); // Sayilari diziye ata
	
	Oyun game = new_Oyun(0); // Oyunu olustur
	game->start(game, numbers, kisi); // Oyunu baslat
	
	return 0;
}
