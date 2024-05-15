// Copyright 2024 binoll
#include "../libs.h"

int get_file(int storage_fd, off_t file_size, off_t offset) {
	char buffer[BUFFER_SIZE];

	if (lseek(storage_fd, 0, SEEK_END) == -1) {
		fprintf(stdout, "[-] Error: Failed to seek file_as_storage to the end\n");
		return -1;
	}

	if (lseek(storage_fd, offset, SEEK_CUR) == -1) {
		fprintf(stdout, "[-] Error: Failed to seek file_as_storage to the end\n");
		return -1;
	}

	fprintf(stdout, "[+] Success: The file has been read: \n");

	while (read(storage_fd, buffer, file_size) > 0) {
		fprintf(stdout, "%s", buffer);
	}

	fprintf(stdout, "\n");

	return EXIT_SUCCESS;
}
