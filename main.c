#include <stdint.h>
#include <stdio.h>
#include "checkfile.h"

uint32_t my_htonl(uint32_t a) {
	return (a << 24) | ((a << 8) & 0xFF0000) | ((a >> 8) & 0xFF00) | (a >> 24);
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("syntax : ./add-nbo <file1> <file2>\n");
		printf("sample : ./add-nbo a.bin b.bin\n");
		
		return 0;
	}
	
	int num1, num2;
	
	if (checkFile(argv[1], &num1)) num1 = my_htonl(num1);
	else return 0;
	
	if (checkFile(argv[2], &num2)) num2 = my_htonl(num2);
	else return 0;
	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1+num2, num1+num2);
	
	return 0;
}
