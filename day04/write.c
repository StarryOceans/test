#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){

	int fd=open("write.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd==-1){
	perror("open");
	return -1;
	}

	const char *text ="Hello,World";

	printf("write content: %s\n",text);

	size_t towrite=strlen(text)*sizeof(text[0]);

	size_t written=write(fd,text,towrite);
	if(written==-1){
	perror("write");
	return -1;
	}

	printf("want write %u words,actual write %d Byte\n",towrite,written);

	close(fd);
	return 0;




}
