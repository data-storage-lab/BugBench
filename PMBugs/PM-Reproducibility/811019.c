#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
        if(argc < 3) {
                printf("Usage: ./811019 <path-to-devdax> <offset>");
                exit(1);
        }

	// Step 1: mmap with MAP_PRIVATE
        printf("Step 1: open & mmap devdax\n");
	int fd = open(argv[1], O_RDONLY);
        if(fd < 0) {
                perror("Unable to open file:");
                exit(1);
        }
        char *buf = mmap(NULL, 0, PROT_READ, MAP_PRIVATE, fd, 0);
	printf("mmaped address 1: %p\n", buf);
	char *tmp = mmap(NULL, 0, PROT_READ, MAP_PRIVATE, fd, 0);
        printf("mmaped address 1: %p\n", tmp);


	int offset = atoi(argv[2]);
	printf("Step 2: Read from offset: %d\n", offset);
	sleep(1);

	printf("Value at given offset: %s\n", tmp + offset);
	//char *tmp2 = malloc(10*sizeof(char));
	//memcpy
	munmap(buf,0);
	munmap(tmp,0);
	close(fd);
	printf("--- Done ---\n");
	return 0;

}
