// Copyright 2024 binoll
#include "libs.h"

int main(int argc, const char* argv[]) {
	char path_to_file[MAX_PATH_SIZE];
	char path_to_storage[MAX_PATH_SIZE];
	char choice = '0';
	FILE* file_ptr = NULL;
	FILE* storage_ptr = NULL;
	off_t storage_size;
	off_t file_size;
	off_t offset = 100;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s (file_as_storage) (file_for_save)\n", argv[0]);
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

		int file_fd = fileno(file_ptr);
		int storage_fd = fileno(storage_ptr);

		storage_size = lseek(storage_fd, 0, SEEK_END);
		if (storage_size < 0) {
			fprintf(stdout, "[-] Error: Failed to get size of storage file\n");
			return -1;
		}

		file_size = lseek(file_fd, 0, SEEK_END);
		if (file_size < 0) {
			fprintf(stdout, "[-] Error: Failed to get size of input file\n");
			return -1;
		}

		if (lseek(storage_fd, 0, SEEK_SET) < 0 || lseek(file_fd, 0, SEEK_SET) < 0) {
			fprintf(stdout, "[-] Error: Failed to seek a ptr of the file\n");
			return -1;
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
				get_file(file_fd, storage_fd, file_size, offset);
				break;
			}
			case 2: {
				save_file(file_fd, storage_fd, file_size, storage_size, offset);
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
