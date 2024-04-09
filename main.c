// Copyright 2024 binoll
#include "libs.h"

int32_t main(int argc, const char* argv[]) {
	const uint32_t MAX_PATH_SIZE = 255;
	char path_to_file[MAX_PATH_SIZE];
	char path_to_storage[MAX_PATH_SIZE];
	char choice;
	FILE* file_ptr;
	FILE* storage_ptr;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <file_as_storage> <file_for_save>\n", argv[0]);
		return EXIT_FAILURE;
	}
	if (strlen(argv[2]) > MAX_PATH_SIZE || strlen(argv[1]) > MAX_PATH_SIZE) {
		fprintf(stderr, "[-] Error: Your path must be less than 255 characters!\n");
		return EXIT_FAILURE;
	}
	strcpy(path_to_file, argv[2]);
	strcpy(path_to_storage, argv[1]);

	do {
		fprintf(stdout, "Menu:\n\t0 - exit\n\t1 - get your file from the storage\n"
		                "\t2 - write file to the storage\nYour choice: ");

		file_ptr = fopen(path_to_file, "rb");
		storage_ptr = fopen(path_to_storage, "r+b");
		if (!file_ptr || !storage_ptr) {
			fprintf(stderr, "[-] Error: Failed to open the file(s)!\n");
			if (file_ptr) fclose(file_ptr);
			if (storage_ptr) fclose(storage_ptr);
			return EXIT_FAILURE;
		}

		if (scanf(" %c", &choice) == 0) {
			fprintf(stderr, "[-] \n");
			return -1;
		}

		switch (choice - '0') {
			case 0: {
				break;
			}
			case 1: {
				if (get_file(fileno(file_ptr), fileno(storage_ptr)) == 0) {
					fprintf(stdout, "[+] Success: Getting path_to_file.\n");
				}
				break;
			}
			case 2: {
				int32_t file_fd = fileno(file_ptr);
				int32_t storage_fd = fileno(storage_ptr);
				save_file(file_fd, storage_fd);
				break;
			}
			default: {
				fprintf(stderr, "[-] Error: Wrong number! Try again!\n");
				break;
			}
		}

		fclose(file_ptr);
		fclose(storage_ptr);

	} while (choice != '0');

	return EXIT_SUCCESS;
}
