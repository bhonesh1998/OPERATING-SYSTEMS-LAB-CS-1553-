#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
int main(int argc, char const *argv[])
{
	//remember SIGKILL and SIGSTOP can't be block
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	while(1)
	{
		printf("Signal blocked\n");
		printf("try ctrl+c \n");
		sigprocmask(SIG_BLOCK,&set,NULL);
		sleep(2);
		printf("Signal unblocked\n");
		sigprocmask(SIG_UNBLOCK,&set,NULL);
		sleep(2);

	}
	return 0;
}
