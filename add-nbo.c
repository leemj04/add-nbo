#include <stdint.h>
#include <stdio.h>

uint32_t my_htonl(uint32_t a) {
	return (a << 24) | ((a << 8) & 0xFF0000) | ((a >> 8) & 0xFF00) | (a >> 24);
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("syntax : ./add-nbo <file1> <file2>\n");
		printf("sample : ./add-nbo a.bin b.bin\n");
		
		return 0;
	}

	FILE* f1,* f2;
	f1 = fopen(argv[1], "rb");
	f2 = fopen(argv[2], "rb");
	
	if (f1 == NULL) {
		printf("cannot open %s file\n", argv[1]);
		
		return 0;
	}
	if (f2 == NULL) {
		printf("cannot open %s file\n", argv[2]);
		
		return 0;
	}
	
	fseek(f1, 0, SEEK_END);
	fseek(f2, 0, SEEK_END);
	
	int s1 = ftell(f1);
	int s2 = ftell(f2);
	
	fseek(f1, 0, SEEK_SET);
	fseek(f2, 0, SEEK_SET);
	
	if (s1 != 4) {
		printf("%s file is not 4-byte\n", argv[1]);
		
		return 0;
	}
	if (s2 != 4) {
		printf("%s file is not 4-byte\n", argv[2]);
		
		return 0;
	}
	
	uint32_t num1, num2;
	
	fread(&num1, sizeof(uint32_t), 1, f1);
	fread(&num2, sizeof(uint32_t), 1, f2);
	
	num1 = my_htonl(num1);
	num2 = my_htonl(num2);
	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1+num2, num1+num2);
}
