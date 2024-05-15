#include "../libs.h"

int main(int argc, const char* argv[]) {
	char path_to_storage[MAX_PATH_SIZE];
	char path_to_secret[MAX_PATH_SIZE];
	int storage_fd;
	off_t storage_size;
	off_t file_size;
	off_t offset;
	FILE *secret_file;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s (file_as_storage) (secret_file)\n", argv[0]);
		return EXIT_FAILURE;
	}

	if (strlen(argv[2]) > MAX_PATH_SIZE || strlen(argv[1]) > MAX_PATH_SIZE) {
		fprintf(stderr, "[-] Error: Your path must be less than 255 characters!\n");
		return EXIT_FAILURE;
	}

	strcpy(path_to_storage, argv[1]);
	strcpy(path_to_secret, argv[2]);

	storage_fd = open(path_to_storage, O_RDWR);
	if (storage_fd == -1) {
		fprintf(stderr, "[-] Error: Failed to open the file_as_storage!\n");
		return EXIT_FAILURE;
	}

	secret_file = fopen(path_to_secret, "r");
	if (secret_file == NULL) {
		fprintf(stderr, "[-] Error: Failed to open secret file for reading!\n");
		close(storage_fd);
		return EXIT_FAILURE;
	}

	if (fscanf(secret_file, "%ld:%ld:%ld", &storage_size, &file_size, &offset) != 3) {
		fprintf(stderr, "[-] Error: Failed to read storage_size, file_size, and offset from secret file!\n");
		fclose(secret_file);
		close(storage_fd);
		return EXIT_FAILURE;
	}

	if (get_file(storage_fd, file_size, offset) == -1) {
		fprintf(stderr, "[-] Error: Failed to read file\n");
		fclose(secret_file);
		close(storage_fd);
		return EXIT_FAILURE;
	}

	fclose(secret_file);
	close(storage_fd);
	return EXIT_SUCCESS;
}
