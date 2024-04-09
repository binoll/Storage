// Copyright 2024 binoll
#include "libs.h"

int main(int argc, const char* argv[]) {
	char path_to_file[MAX_PATH_SIZE];
	char path_to_storage[MAX_PATH_SIZE];
	char choice = '0';
	FILE* file_ptr = NULL;
	FILE* storage_ptr = NULL;
	off_t storage_size = 0;
	off_t file_size = 0;
	bool is_saved = false;

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
		                "\t2 - write file to the storage");

		file_ptr = fopen(path_to_file, "rb");
		storage_ptr = fopen(path_to_storage, "r+b");
		if (!file_ptr || !storage_ptr) {
			fprintf(stdout, "\n[-] Error: Failed to open the file(s)!\n");
			if (file_ptr) fclose(file_ptr);
			if (storage_ptr) fclose(storage_ptr);
			return EXIT_FAILURE;
		}

		fprintf(stdout, "\nYour choice: ");

		if (scanf(" %c", &choice) == 0) {
			fprintf(stdout, "[-] \n");
			return -1;
		}

		switch (choice - '0') {
			case 0: {
				break;
			}
			case 1: {
				if (!is_saved) {
					fprintf(stdout, "[-] Error: The file was not saved! Save the file first!\n");
					continue;
				}
				int file_fd = fileno(file_ptr);
				int storage_fd = fileno(storage_ptr);
				get_file(file_fd, storage_fd, file_size, storage_size);
				break;
			}
			case 2: {
				int file_fd = fileno(file_ptr);
				int storage_fd = fileno(storage_ptr);
				save_file(file_fd, storage_fd, file_size, storage_size);
				is_saved = true;
				break;
			}
			default: {
				fprintf(stdout, "[-] Error: Wrong number! Try again!\n");
				break;
			}
		}
		fclose(file_ptr);
		fclose(storage_ptr);
	} while (choice != '0');
	return EXIT_SUCCESS;
}
