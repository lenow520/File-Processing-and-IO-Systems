#include <sys/mman.h>
#include <string.h>
#include <sys/time.h> //gettimeoftheday
#include <sys/types.h> //open
#include <sys/stat.h> //open
#include <sys/fcntl.h> //open
#include <unistd.h> //read
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#define size 104857600

int main(){
	struct timeval start;
	struct timeval end;
	int count = 25*pow(2,10);
	int32_t source = open("s.txt",O_RDWR | O_CREAT,0644);
	int32_t target = open("t.txt",O_RDWR  | O_CREAT,0644);
	if(source<0){printf("Failed to open source file.\n"); 
	exit(1);
	}
	if(target<0){printf("Failed to open target file.\n"); 
	exit(1);
	}
	ftruncate(target,size);

	char *map_f1 =(char*) mmap(NULL,size,PROT_READ | PROT_WRITE,MAP_SHARED,source,0);
	char *map_f2 = (char*)mmap(NULL,size,PROT_READ | PROT_WRITE,MAP_SHARED,target,0);
	close(source);
	close(target);
	if (map_f1 == MAP_FAILED){printf("Failed to mmap source file.\n"); 
	exit(1);}
	if (map_f2 == MAP_FAILED){printf("Failed to mmap target file.\n"); 
	exit(1);}
	

	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){memcpy(map_f2+4096*count,map_f1+4096*count,4096);}
	gettimeofday(&end,NULL);

	munmap(map_f1,size);
	munmap(map_f2,size);
	int64_t diff = 1000000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec);
	printf("Time: %ld us \n",diff);
	return 0;			
	}
