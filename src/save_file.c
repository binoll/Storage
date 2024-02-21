#include "../libs.h"

int8_t save_file(int64_t fd, int64_t cd) {
	char buf[1024];
	uint8_t ch = 0;

	do {
		printf("Choices:\n0 - exit\n1 - get file\nYour choice: ");
		ch = getchar() - '0';


	} while(ch != 0);

	return EXIT_SUCCESS;
}