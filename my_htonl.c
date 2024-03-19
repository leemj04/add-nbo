#include "my_htonl.h"

uint32_t my_htonl(uint32_t a) {
	return (a << 24) | ((a << 8) & 0xFF0000) | ((a >> 8) & 0xFF00) | (a >> 24);
}
