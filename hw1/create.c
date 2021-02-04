#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
	char buf[20];
	int size = 1024*1024*100;
	int fd = open("newf.txt",O_WRONLY | O_CREAT, 0755);
	if(fd==-1){
	printf("create file error.\n");
	return 1;			
	}
	int curr = lseek(fd,size,SEEK_SET);
	if(fd==-1){
	printf("offset error.\n");
	close(fd);
	return 1;			
	}
	int f = write(fd,buf,size);
	return 0;
}


