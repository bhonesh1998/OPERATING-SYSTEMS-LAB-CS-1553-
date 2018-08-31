/*
NAME - BHONESH CHAWLA
REGNO - 20164017
BATCH - CSA(2020)
CONTACT - 8619127663
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#define pf printf
#define sf scanf


int main()
{
		int d[2];
		pipe(d);
		int rv;
		int pid = fork();
		char s[100];
		if(pid < 0)
		pf("error\n");
		else if(pid==0)
		{
		//close(d[1]);
		read(d[0],s,100);
		
		pf("%s",s);
		pf("(message from child)");
		//sf("%d",&rv);
		//exit(rv);		
		}
		else
		{
			pf("i am in parent\n");
			pf("please ,write something on screen  \n");
			//wait(&rv);
			char st[100];
			sf("%s",st);
			//close(d[0]);	
			write(d[1],st,strlen(st)+1);
		}			
			
			
}
