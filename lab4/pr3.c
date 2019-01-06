#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>
void sigHandler(int sig)
{	
	sleep(1);
	if(sig==SIGINT)
		printf("\n\nCHILD ::SIGINT %d---- signal caught\n",SIGINT);
	if(sig==SIGHUP)
		printf("\n\nCHILD ::SIGHUP %d---- signal caught\n",SIGHUP);
	if(sig==SIGTERM)
		printf("\n\nCHILD ::SIGTERM %d---- signal caught\n",SIGTERM);
	if(sig==SIGQUIT)
	{
		printf("\n\nCHILD ::SIGQUIT %d---- signal caught\n",SIGQUIT);
		exit(0);
	}
	

}
int main()
{
	signal(SIGINT,sigHandler);
	signal(SIGTERM,sigHandler);
	signal(SIGHUP,sigHandler);
	signal(SIGQUIT,sigHandler);
	pid_t pid ;
	int ch;
	pid = fork();
	if(pid==0)
	{
		while(1);
		
	}
	else	
	{
		while(ch!=4)
		{	
			printf("\n\n\n1::to send SIGINT\n\n2::to send SIGHUP\n\n3::to send SIGTERM\n\n4::to send SIGQUIT\n\nenter your choice::");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					kill(pid,SIGINT);
					break;
				case 2:
					kill(pid,SIGHUP);
					break;
				case 3:
					kill(pid,SIGTERM);
					break;
				case 4:	
					kill(pid,SIGQUIT);
					break;
				default:
  					printf("enter correct choice!!");
			}
			sleep(2);	
		}
	}
	return 0;
}

