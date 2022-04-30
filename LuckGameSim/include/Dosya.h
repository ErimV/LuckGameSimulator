#ifndef DOSYA_H
#define DOSYA_H

#include <stdio.h>
#include <stdlib.h>
#include "Kisi.h"

struct DOSYA{
	char* path;
	
	FILE* (*openFile)(struct DOSYA*);
	char* (*getLine)(FILE*, char*);
	Kisi* (*toArray)(FILE*, Kisi*,struct DOSYA*);
	int* (*numstoArray)(FILE*, int*);
	
};
typedef struct DOSYA* File;

File new_File(char*);
FILE* openFile(const File);
char* getLine(FILE*, char*);
Kisi* toArray(FILE*, Kisi*,struct DOSYA*);
int* numstoArray(FILE*, int*);

#endif
