// Copyright 2024 binoll
#include "../libs.h"

int8_t save_file(int64_t fd, int64_t cd) {
	const uint8_t SIZE_BUF = 128;
	char buf[SIZE_BUF];
	struct stat* statfbuf = NULL;
	struct stat* statfsbuf = NULL;
	struct virtio_blk_config* blk;

	fstat(fd, statfbuf);
	fstat(cd, statfsbuf);

	if(statfsbuf->st_blocks * statfsbuf->st_blksize < statfbuf->st_size) {
		fprintf(stderr, "Size of the file too much!\n");
		return EXIT_FAILURE;
	}

	if(read(fd, buf, SIZE_BUF) == 0) {
		fprintf(stderr, "Can not read file error!\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}