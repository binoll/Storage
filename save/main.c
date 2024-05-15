#include "../libs.h"

int main(int argc, const char* argv[]) {
	char path_to_file[MAX_PATH_SIZE];
	char path_to_storage[MAX_PATH_SIZE];
	char path_to_secret[MAX_PATH_SIZE];
	off_t storage_size;
	off_t file_size;
	off_t offset;
	int file_fd, storage_fd;
	FILE *secret_file;

	if (argc != 5) {
		fprintf(stderr, "Usage: %s (file_as_storage) (file_for_save) (offset) (secret_file)\n", argv[0]);
		return EXIT_FAILURE;
	}

	if (strlen(argv[2]) > MAX_PATH_SIZE || strlen(argv[1]) > MAX_PATH_SIZE) {
		fprintf(stderr, "[-] Error: Your path must be less than 255 characters!\n");
		return EXIT_FAILURE;
	}

	offset = atoi(argv[3]);
	if (offset < 0) {
		fprintf(stderr, "[-] Error: Offset must be a non-negative integer!\n");
		return EXIT_FAILURE;
	}

	strcpy(path_to_file, argv[2]);
	strcpy(path_to_storage, argv[1]);
	strcpy(path_to_secret, argv[4]);

	file_fd = open(path_to_file, O_RDONLY);
	if (file_fd == -1) {
		fprintf(stderr, "[-] Error: Failed to open the file_for_save!\n");
		return EXIT_FAILURE;
	}

	storage_fd = open(path_to_storage, O_RDWR);
	if (storage_fd == -1) {
		fprintf(stderr, "[-] Error: Failed to open the file_as_storage!\n");
		close(file_fd);
		return EXIT_FAILURE;
	}

	storage_size = lseek(storage_fd, 0, SEEK_END);
	if (storage_size < 0) {
		fprintf(stderr, "[-] Error: Failed to get size of file_as_storage\n");
		close(file_fd);
		close(storage_fd);
		return EXIT_FAILURE;
	}

	file_size = lseek(file_fd, 0, SEEK_END);
	if (file_size < 0) {
		fprintf(stderr, "[-] Error: Failed to get size of file_as_storage\n");
		close(file_fd);
		close(storage_fd);
		return EXIT_FAILURE;
	}

	if (save_file(file_fd, storage_fd, file_size, storage_size, offset) == -1) {
		fprintf(stderr, "[-] Error: Failed to save file\n");
		close(file_fd);
		close(storage_fd);
		return EXIT_FAILURE;
	}

	secret_file = fopen(path_to_secret, "a");
	if (secret_file == NULL) {
		fprintf(stderr, "[-] Error: Failed to open secret file for writing\n");
		close(file_fd);
		close(storage_fd);
		return EXIT_FAILURE;
	}

	fprintf(secret_file, "%ld:%ld:%ld", storage_size, file_size, offset);

	close(file_fd);
	close(storage_fd);
	fclose(secret_file);
	return EXIT_SUCCESS;
}
