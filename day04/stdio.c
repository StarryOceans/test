#include <stdio.h>
int main(void){

	FILE*fp =fopen("sysio.dat","wb");
	if(!fp){
	perror("fopen");
	return -1;
	}
	for(unsigned int i=0;i<10000;++i)
		fwrite(&i,sizeof(i),1,fp);

	fclose(fp);
	return 0;


}
