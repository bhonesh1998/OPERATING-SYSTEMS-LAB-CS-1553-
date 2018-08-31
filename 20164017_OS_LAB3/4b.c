/*
NAME - BHONESH CHAWLA
REGNO - 20164017
BATCH - CSA(2020)
CONTACT - 8619127663
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main( void)
{
int pid;
int n=0;
pid= fork();
while (n<10)
{
		if (pid == 0)
		{
				printf("%d\n",n);
				n = n + 2;
				sleep(1);
		}
		else
		{
				printf("%d\n",n);
				n = n +3;
				sleep(1);
		}
}
return 0;
}
