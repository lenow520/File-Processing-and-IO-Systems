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
	int32_t source = open("s.txt",O_RDONLY | O_CREAT);
	int32_t target = open("t.txt",O_WRONLY | O_CREAT);
	int32_t wr1,rd1;
	int count = 25*pow(2,10);
	char *buffer = valloc(4096*sizeof(char));
	int64_t diff;
	if(source<0){printf("Failed to open source file.\n"); 
	exit(1);
	}
	if(target<0){printf("Failed to open target file.\n"); 
	exit(1);
	}

	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
	rd1=read(source,buffer, 4096);
	wr1 = write(target, buffer,4096);}
	gettimeofday(&end,NULL);
	if(rd1==-1){
	printf("read file error.\n");
	return 0;			
	}
	if(wr1==-1){
	printf("write file error.\n");
	return 0;			
	}
	free(buffer);
	close(source);
	close(target);
	diff = 1000000*(end.tv_sec-start.tv_sec)+ (end.tv_usec-start.tv_usec);
	printf("Time: %ld us \n",diff);
	return 0;
}
