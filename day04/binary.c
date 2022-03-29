#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){

	int fd=open("binary.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd==-1){
	perror("open");
	return -1;
	}
	char name[256]="zhangfei";
	if(write(fd,name,sizeof(name))==1){
	perror("write");
	return -1;
	}

	unsigned int age=38;
	if(write(fd,&age,sizeof(age))==-1){
	perror("write");
	return -1;
	}

	double salary=20000;
	if(write(fd,&salary,sizeof(salary))==-1){
	perror("write");
	return -1;
	}

	struct Emplyee{
	char name[256];
	unsigned int age;
	double salary;
	}employee={"zhaoyun",25,10000};

	if(write(fd,&employee,sizeof(employee))==-1){
	
	perror("write");
	return -1;
	}

	close(fd);





}
