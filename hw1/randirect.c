#include <sys/time.h> //gettimeoftheday
#include <sys/types.h> //open
#include <sys/stat.h> //open
#include <unistd.h> //read
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#define __USE_GNU 1
#include <sys/fcntl.h> //open
#define size 104857600

int main(){
	struct timeval start;
	struct timeval end;
	int8_t *buffer = valloc(size);
	int32_t fd = open("newf.txt",O_WRONLY | O_DIRECT);
	int32_t wr2,curr;
	int64_t diff;
	int a;
	srand(time(NULL));

	gettimeofday(&start,NULL);
	for(int i=0;i<25600;i++){
	a=(rand()%25600);
	curr = lseek(fd,a*4096,SEEK_SET);
	wr2 = write(fd, buffer,4096);
	}
	gettimeofday(&end,NULL);
	if(curr==-1){
	printf("seek file error.\n");
	return 0;			
	}
	if(wr2==-1){
	printf("write file error.\n");
	return 0;			
	}
	free(buffer);
	close(fd);
	diff = 1000000*(end.tv_sec-start.tv_sec)+ (end.tv_usec-start.tv_usec);
	printf("Time: %ld us \n",diff);
	return 0;
}


