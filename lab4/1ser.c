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

int main(int argc,char **argv)
{

	int p=atoi(argv[0]);
	int q =atoi(argv[1]);
	int ans =0;
	if(strcmp(argv[2],"+")==0)
	{
		ans=p+q;
	}
	else
		ans=p-q;
	return ans;

}



