#include "checkfile.h"

int checkFile(char filename[], int* num) {
	FILE* fp = fopen(filename, "rb");
	
	if (fp == NULL) {
		printf("cannot open %s file\n", filename);
		return 0;
	}
	
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	
	if (size != 4) {
		printf("%s file is not 4-byte\n", filename);
		return 0;
	}
	
	fseek(fp, 0, SEEK_SET);
	fread(num, sizeof(uint32_t), 1, fp);
	
	return 1;
}
