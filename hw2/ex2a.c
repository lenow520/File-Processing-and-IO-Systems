#include <sys/time.h> //gettimeoftheday
#include <sys/types.h> //open
#include <sys/stat.h> //open
#include <sys/fcntl.h> //open
#include <unistd.h> //read
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define size 4096000

int main(){
	struct timeval start;
	struct timeval end;
	char *buffer = valloc(size);
	int32_t fd = open("2a.txt",O_WRONLY | O_CREAT);
	int32_t wr1;
	int64_t diff;

	gettimeofday(&start,NULL);
	for(int i=0;i<1000;i++){
	wr1 = write(fd, buffer,4096);
	}
	gettimeofday(&end,NULL);

	if(wr1==-1){
	printf("write file error.\n");
	return 0;			
	}
	free(buffer);
	close(fd);
	diff = 1000000*(end.tv_sec-start.tv_sec)+ (end.tv_usec-start.tv_usec);
	printf("Time: %ld us \n",diff);
	return 0;
}
