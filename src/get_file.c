// Copyright 2024 binoll
#include "../libs.h"

int get_file(int file_fd, int storage_fd, off_t file_size, off_t storage_size) {
	char buffer[BUFFER_SIZE];
	struct flock perms;

	perms.l_type = F_UNLCK;
	perms.l_whence = SEEK_END;
	perms.l_start = 0;
	perms.l_len = 0;

	if (fcntl(storage_fd, F_SETLK, &perms) == -1) {
		fprintf(stdout, "[-] Error: Failed to unlock the file storage.\n");
		return -1;
	}
	fprintf(stdout, "[+] Success: The file is unlocked.");

	if (lseek(file_fd, 0, SEEK_SET) == -1) {
		perror("[-] Error: Failed to seek input file to the beginning.\n");
		return -1;
	}

	if (lseek(storage_fd, 10, SEEK_END) == -1) {
		fprintf(stdout, "[-] Error: Failed to seek storage file to the end.");
		return -1;
	}
	fprintf(stdout, "[-] Success: The file has been read: \n");

	while (read(file_fd, buffer, BUFFER_SIZE) > 0) {
		fprintf(stdout, "%s", buffer);
	}
	return EXIT_SUCCESS;
}
