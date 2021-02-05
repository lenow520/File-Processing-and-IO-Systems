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
	FILE *source = fopen("s.txt","r");
	FILE *target= fopen("t.txt","w");
	int wr1,rd1;
	int count = 25*pow(2,10);
	char *buffer = valloc(4096*sizeof(char));
	int64_t diff;
	if(source==NULL){printf("Failed to open source file.\n"); 
	freopen("s.txt", "a+", source);
	}
	if(target==NULL){printf("Failed to open target file.\n"); 
	exit(1);
	}
	gettimeofday(&start,NULL);
	for(int i=0;i<count;i++){
	rd1=fread(buffer, sizeof(char),4096,source);
	wr1 =fwrite(buffer, sizeof(char),4096,target);
	}
	gettimeofday(&end,NULL);

	fclose(source);
	fclose(target);
	diff = 1000000*(end.tv_sec-start.tv_sec)+ (end.tv_usec-start.tv_usec);
	printf("Time: %ld us \n",diff);
	return 0;
}
