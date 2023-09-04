#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DATA_SZ 4096 // Page size

void rand_str(char *dest, size_t length) {
    char charset[] = "0123456789"
                     "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (length-- > 0) {
        size_t index = (double) rand() / RAND_MAX * (sizeof charset - 1);
        *dest++ = charset[index];
    }
    //*dest = '\0';
}

int main(int argc, char *argv[]) {
        if(argc < 2) {
                printf("Usage: ./796808 <path-to-pmem-file>");
                exit(1);
        }

	int fd = open(argv[1], O_CREAT | O_RDWR, 0666);
        if(fd < 0) {
                perror("Unable to open file:");
                exit(1);
        }

	int ret = fallocate(fd, 0, 0, DATA_SZ); // Create a 2MB file
        if(ret < 0) {
                perror("Unable to fallocate:");
                exit(1);
        }
	// Step 1: mmap with MAP_PRIVATE
	printf("Step 1: Create and mmap file\n");
	char *buf = mmap(NULL, DATA_SZ, PROT_READ | PROT_WRITE,
                                MAP_PRIVATE, fd, 0);

        if(buf == MAP_FAILED) {
                perror("MMAP Failed:");
                exit(1);
        }
	sleep(1);

	// Step 2: Write contents
	printf("Step 2: Write contents to file\n");
	rand_str(buf, DATA_SZ);
	sleep(1);

	// Step 3: fallocate to same offset (used same size)
	printf("Step 3: fallocate to same offset (used same size)\n");
	ret = fallocate(fd, 0, 0, DATA_SZ);
        if(ret < 0) {
                perror("Unable to fallocate:");
                exit(1);
        }

	char *tmp = mmap(NULL, DATA_SZ, PROT_READ | PROT_WRITE,
                                MAP_PRIVATE, fd, 0);
	printf("Step 4: Compare data\n");
	int cmp = strcmp(buf, tmp);
	if(cmp) {
		printf("Contents are different\n");
		printf("Contents before fallocate:\n%s\n\n",buf);
                printf("Contents after fallocate:\n%s\n\n", tmp);
	}
	else {
		printf("Contents are same\n");
		printf("Contents before fallocate:\n%s\n\n",buf);
		printf("Contents after fallocate:\n%s\n\n", tmp);
	}

	munmap(buf, DATA_SZ);
        close(fd);
        printf("--- Done ---\n");
        return 0;
}
