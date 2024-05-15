// Copyright 2024 binoll
#include "../libs.h"

int save_file(int file_fd, int storage_fd, off_t file_size, off_t storage_size, off_t offset) {
	struct statvfs fs_info;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;
	uint64_t block_size;

	if (fstatvfs(storage_fd, &fs_info) == -1) {
		fprintf(stdout, "[-] Error: Failed to get filesystem information\n");
		return -1;
	}

	block_size = fs_info.f_frsize;

	if (block_size - storage_size < file_size) {
		fprintf(stdout, "[-] Error: The size of your file(%lu bytes) "
		                "is larger than the available space in the storage(%lu bytes)!\n",
		        file_size, block_size - storage_size);
		return -1;
	}

	if (lseek(storage_fd, 0, SEEK_END) < 0) {
		fprintf(stdout, "[-] Error: Failed to seek file_as_storage to the end\n");
		return -1;
	}

	if (lseek(storage_fd, offset, SEEK_CUR) < 0) {
		fprintf(stdout, "[-] Error: Failed to seek file_as_storage to the offset\n");
		return -1;
	}

	if (lseek(file_fd, 0, SEEK_SET) < 0) {
		fprintf(stdout, "[-] Error: Failed to seek file_for_save to the offset\n");
		return -1;
	}

	while ((bytes_read = read(file_fd, buffer, BUFFER_SIZE)) > 0) {
		bytes_written = write(storage_fd, buffer, bytes_read);

		if (bytes_written == -1) {
			fprintf(stdout, "[-] Error: Failed to write data to file_as_storage\n");
			return -1;
		}

		if (bytes_written != bytes_read) {
			fprintf(stdout, "[-] Error: Incomplete write to storage file\n");
			return -1;
		}
	}

	fprintf(stdout, "[+] Success: The file has been saved! Free space in the block: %lu bytes\n",
	        block_size - storage_size);

	return 0;
}
