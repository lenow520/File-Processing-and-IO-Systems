#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/dir.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int flag=0;
void search(char *dirname, char *filename){
	DIR* pDir = NULL;
	pDir = opendir(dirname);
	if (pDir == NULL){
        return;
	}
	struct dirent* entry = NULL;
	char path[1024];
	memset(path,0,sizeof(path));
	while((entry= readdir(pDir))!=NULL){
		strcpy(path, dirname);
            	strcat(path, "/");
            	strcat(path, entry->d_name);
		if (entry->d_type == DT_DIR) {
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){continue;}
		search(path,filename);
		}
	 	else if(entry->d_type == DT_REG){
		if(strcmp(entry->d_name, filename) == 0){
		flag=1;	
    		printf ("%s\n", path);
		}
		}
		}
	closedir(pDir);
}
int main(int argc, char *argv[]){
	if(argc==2){search(".",argv[1]);}
	else{search(argv[1], argv[2]);}

	if(flag==0){printf("cannot find the corresponding file.\n");}
	return 0;
}
