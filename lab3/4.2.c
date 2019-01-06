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
	
	int pid =fork();
	int n=0;
	while(n<10)
	{
			if(pid==0)
			{
				n+=2;
				pf("%d\n",n);
				sleep(1);
			}
			else
			{
				n+=3;
				pf("%d\n",n);
				sleep(1);
			}
	}

}



