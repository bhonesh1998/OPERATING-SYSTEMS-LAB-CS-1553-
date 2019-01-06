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


int main(int argc , char *argv[])
{
	
	int pid;
	int rv ;
	pid = fork();

	if(pid<0)
		pf("error");
	else if(pid==0)
	{
		pf("this is child\n");
		pf("id of child is %d\n",getpid());
		pf("id of it's parent is %d\n",getppid());
		pf("enter my exit state\n");
		sf("%d",&rv);
		exit(rv);
	}
	else
	{
		pf("this is parent\n");
		pf("id of parent is %d\n",getpid());
		pf("waiting for child to get exit\n");
		wait(&rv);
		pf("exit status of child is %d",WEXITSTATUS(rv));

	}


}



