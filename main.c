// Copyright 2024 binoll
#include "libs.h"

int32_t main(int argc, const char* argv[]) {
	struct statvfs* statvfsbuf;
	struct statfs* statfsbuf;
	const uint16_t MAX_PATH_SIZE = 255;
	char* path_file = NULL;
	char* path_fs = NULL;
	int64_t fd = 0, cd = 0;
	uint8_t ch = 0;

	if(argc != 3) {
		fprintf(stderr, "Error! You must use 3 args! "
		                "Usage: prog[0] catalog(file)_for_storage[1] file_for_save[2]\n");
		return EXIT_FAILURE;
	}

	if(strlen(argv[2]) > MAX_PATH_SIZE ||
	   strlen(argv[1]) > MAX_PATH_SIZE) {
		fprintf(stderr, "Error! Your path must be less than 255 characters!\n");
		return EXIT_FAILURE;
	}

	strcpy(path_file, argv[2]);
	strcpy(path_fs, argv[1]);

	if((fd = open(path_file, O_RDONLY)) == -1 &&
	   (cd = open(path_fs, O_RDWR) == -1)) {
		fprintf(stderr, "Error! Can not open the catalog/file!\n");
		return EXIT_FAILURE;
	}

	if(fstatvfs(cd, statvfsbuf) != 0) {
		close(fd);
		fprintf(stderr, "Error! Can work with catalog/file!\n");
		return EXIT_FAILURE;
	}

	if(statfs(path_file, statfsbuf) != 0) {
		switch(statfsbuf->f_type) {
			case EXT4_SUPER_MAGIC: {
				fprintf(stdout, "Your file system - ext [+]\n");
				sleep(2000);
				break;
			}
			default: {
				close(fd);
				close(cd);
				fprintf(stderr, "Error! Catalog/file for storage must be ext2-ext4!\n");
				return EXIT_FAILURE;
			}
		}
	}

	do {
		fprintf(stdout, "Choices:\n0 - exit\n1 - get file\nYour choice: ");
		ch = getchar() - '0';

		switch(ch) {
			case 0:
			case 1: {
				fprintf(stdout, "Getting file [+]\n");
				sleep(2000);
				get_file(fd, cd);
				break;
			}
			case 2: {
				fprintf(stdout, "Saving file [+]\n");
				sleep(2000);
				save_file(fd, cd);
				break;
			}
			default: {
				fprintf(stderr, "Wrong number! Try again!\n");
			}
		}
	} while(ch != 0);

	close(fd);
	close(cd);

	return EXIT_SUCCESS;
}
