// Copyright 2024 binoll
#include "../libs.h"

int8_t save_file(int32_t file_fd, int32_t storage_fd) {
	struct statvfs fs_info;
	struct flock perms;
	const size_t BUFFER_SIZE = 128;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;
	off_t storage_size, file_size;
	uint64_t block_size;

	if (fstatvfs(storage_fd, &fs_info) == -1) {
		fprintf(stderr, "[-] Error: Failed to get filesystem information.");
		return -1;
	}
	block_size = fs_info.f_frsize;

	storage_size = lseek(storage_fd, 0, SEEK_END);
	if (storage_size == -1) {
		fprintf(stderr, "[-] Error: Failed to get size of storage file.");
		return -1;
	}
	file_size = lseek(file_fd, 0, SEEK_END);
	if (file_size == -1) {
		fprintf(stderr, "[-] Error: Failed to get size of input file.");
		return -1;
	}

	if (block_size - storage_size < file_size) {
		fprintf(stderr, "[-] Error: The size of your file(%lu bytes) "
		                "is larger than the available space in the storage(%lu bytes)!\n",
		        file_size, block_size - storage_size);
		return -1;
	}

	if (lseek(file_fd, 0, SEEK_SET) == -1) {
		perror("[-] Error: Failed to seek input file to the beginning.");
		return -1;
	}

	if (lseek(storage_fd, 0, SEEK_END) == -1) {
		fprintf(stderr, "[-] Error: Failed to seek storage file to the end.");
		return -1;
	}

	while ((bytes_read = read(file_fd, buffer, BUFFER_SIZE)) > 0) {
		bytes_written = write(storage_fd, buffer, bytes_read);
		if (bytes_written == -1) {
			fprintf(stderr, "[-] Error: Failed to write data to storage file.");
			return -1;
		}
		if (bytes_written != bytes_read) {
			fprintf(stderr, "[-] Error: Incomplete write to storage file.\n");
			return -1;
		}
	}

	perms.l_type = F_WRLCK;
	perms.l_whence = SEEK_END;
	perms.l_start = 0;
	perms.l_len = 0;

	if (fcntl(storage_fd, F_SETLK, &perms) == -1) {
		fprintf(stderr, "[-] Error: Failed to lock the file storage.");
		return -1;
	}

	fprintf(stdout, "[+] Success: The file has been saved! Free space in the block: %lu bytes.\n",
	        block_size - storage_size);
	return 0;
}
