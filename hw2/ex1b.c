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
	FILE *fp;
	int wr1;
	char *buffer = valloc(sizeof(char));
	int64_t diff;
	fp = fopen("1b.txt","wt+");
	if(fp<0){printf("Failed to open file.\n"); 
	exit(1);
	}

	gettimeofday(&start,NULL);
	for(int i=0;i<size;i++){
	wr1 =fwrite(&buffer, sizeof(char),1,fp);}
	gettimeofday(&end,NULL);

	fclose(fp);
	diff = 1000000*(end.tv_sec-start.tv_sec)+ (end.tv_usec-start.tv_usec);
	printf("Time: %ld us \n",diff);
	return 0;
}
