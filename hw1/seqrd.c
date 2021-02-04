#include <sys/time.h> //gettimeoftheday
#include <sys/types.h> //open
#include <sys/stat.h> //open
#include <sys/fcntl.h> //open
#include <unistd.h> //read
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define size 104857600

int main(){
	struct timeval start;
	struct timeval end;
	int8_t *buffer = valloc(size);
	int32_t fd = open("newf.txt",O_RDONLY);
	int32_t rd;
	int64_t diff;

	gettimeofday(&start,NULL);
	rd = read(fd, buffer,size);
	gettimeofday(&end,NULL);

	if(rd==-1){
	printf("read file error.\n");
	return 0;			
	}
	free(buffer);
	close(fd);
	diff = 1000000*(end.tv_sec-start.tv_sec)+ (end.tv_usec-start.tv_usec);
	printf("Time: %ld us \n",diff);
	return 0;
}


