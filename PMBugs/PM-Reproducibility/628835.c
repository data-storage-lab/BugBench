#include <stdio.h>
#include <linux/mman.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#define DATA_SZ 2097152

void rand_str(char *dest, size_t length) {
    char charset[] = "0123456789"
                     "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (length-- > 0) {
        size_t index = (double) rand() / RAND_MAX * (sizeof charset - 1);
        *dest++ = charset[index];
    }
    *dest = '\0';
}


int main(int argc, char *argv[]) {

	if(argc < 2) {
		printf("Usage: ./628835 <path-to-pmem-file>");
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
	// Step 1: Open an mmap over a 2MiB hole
	char *buf = mmap(NULL, DATA_SZ, PROT_READ | PROT_WRITE,
				MAP_SHARED, fd, 0);

	if(buf == MAP_FAILED) {
		perror("MMAP Failed:");
		exit(1);
	}
	// Step 2: Read from a 2MiB hole, faulting in a 2MiB zero page
	printf("Buffer contents before WRITE: test1.txt\n ");
	int fd1 = open("test1.txt", O_CREAT | O_RDWR, 0666);
	write(fd1, buf, DATA_SZ);
	fsync(fd1);
	close(fd1);

	// Step 3: Write to a the hole with write
	char *temp_str = malloc(DATA_SZ * sizeof(char));

	rand_str(temp_str, DATA_SZ);
	int sz = write(fd, temp_str, DATA_SZ);

	if(sz < DATA_SZ) {
		perror("Write failed: ");
		printf("Size written: %d/%d\n", sz, DATA_SZ);
	}

	//Step 4: Read data written
	printf("Buffer contents after WRITE: test2.txt\n");
	fd1 = open("test2.txt", O_CREAT | O_RDWR, 0666);
        write(fd1, buf, DATA_SZ);
        fsync(fd1);
        close(fd1);

	munmap(buf, DATA_SZ);
	close(fd);
	printf("--- Done ---\n");
	return 0;
	
}
