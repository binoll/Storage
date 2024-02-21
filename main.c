#include "libs.h"

int32_t main(int argc, const char* argv[]) {
	const uint16_t MAX_PATH_SIZE = 255;
	char* path_file = NULL;
	char* path_fs = NULL;
	int64_t fd = 0, cd = 0;
	uint8_t ch = 0;

	if(argc != 4) {
		printf("Error! You must use 3 args!\n");
		return EXIT_FAILURE;
	}

	if(strlen(path_file = argv[2]) > MAX_PATH_SIZE || strlen(path_fs = argv[3]) > MAX_PATH_SIZE) {
		printf("Error! Your path must be less than 255 characters!\n");
		return EXIT_FAILURE;
	}

	if((fd = open(path_file, O_RDONLY)) == -1 && (cd = open(path_fs, O_RDWR) == -1)) {
		printf("Error! Can not open the file!\n");
		return EXIT_FAILURE;
	}

	do {
		printf("Choices:\n0 - exit\n1 - get file\nYour choice: ");
		ch = getchar() - '0';

		switch(ch) {
			case 0:
			case 1: {
				for(uint8_t i = 0; i < 4 * 2; ++i) {
					printf("Getting file: %c\r", saving[i % 4]);
					sleep(1000);
				}
				get_file(fd, cd);
				break;
			}
			case 2: {
				for(uint8_t i = 0; i < 4 * 2; ++i) {
					printf("Saving file: %c\r", saving[i % 4]);
					sleep(1000);
				}
				save_file(fd, cd);
				break;
			}
			default: {
				printf("Wrong number! Try again!\n");
			}
		}
	} while(ch != 0);

	return EXIT_SUCCESS;
}
