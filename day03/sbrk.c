#include<stdio.h>
#include<unistd.h>

int main(){

	int i=2;

	int *phead;
	int *pnow;

	pnow=sbrk(0);
	phead=pnow;

      for(i=2; i<50; i++)
    {
        if(i%2==1) // 该函数用于判断是否是素数
        {
           brk(pnow+1);// 分配4个字节
            *pnow = i; // 存入数据
            pnow = sbrk(0); // 指向系统指针上次移动到的那个位置
        printf("%d\n",pnow);
	}
    }


	int *p=sbrk(0);
	int *p1=sbrk(1);
	int *p2=sbrk(2);

	*p=1;
	*p1=2;
	*p2=3;

	printf("%d\n",*p);
	printf("%d\n",*p1);
	printf("%d\n",*p2);



}
