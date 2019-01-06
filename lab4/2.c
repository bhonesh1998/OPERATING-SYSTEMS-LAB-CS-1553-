#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<string.h>
#include<sys/wait.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define pf printf
#define sf scanf

int main()
{


	FILE *fp;
	int i;
	fp=fopen("pro.txt","w");
	for(i=1;i<=10;i++)
	{
		fork();
		pf("process id : %d",getpid());
	}
	
	fprintf(fp,"%d\n",getpid());
	
	


}



