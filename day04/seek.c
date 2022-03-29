#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){


	int fd=open("seek.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
	if(fd==-1){
	perror("open");
	return -1;
	}
	const char *text="hello world!";
	if(write(fd,text,strlen(text)*sizeof(text[0]))==-1){
	perror("write");
	return -1;
	}

	if(lseek(fd,-6,SEEK_CUR)==-1){
	perror("lseek");
	return -1;
	}

	off_t pos=lseek(fd,0,SEEK_CUR);





}
