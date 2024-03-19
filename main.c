#include <stdint.h>
#include <stdio.h>
#include "checkfile.h"
#include "my_htonl.h"

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
