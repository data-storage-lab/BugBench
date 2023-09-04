#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
        if(argc < 2) {
                printf("Usage: ./628835 <path-to-pmem-file>");
                exit(1);
        }

        int fd = open(argv[1], O_TRUNC, 0666);
        if(fd < 0) {
                perror("Unable to open file:");
                exit(1);
        }

        char *addr =  mmap(NULL, 2*1024*1024, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
        *addr = 'a';

        return 0;
} 
