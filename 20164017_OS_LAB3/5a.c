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

// in this program both processes are related so that they can communicate with each other using pipe 

int main()
{
		int d[2];
		pipe(d);
		int rv;
		int n;
		int pid = fork();
		char s[100];
		char st[100];
		while(1)
		{
				if(pid < 0)
				pf("error\n");
				else if(pid==0)
				{
				close(d[1]);
				read(d[0],s,100);
				pf("%s",s);
				pf("(message from child)");	
				}
				else
				{
				close(d[0]);
					pf("i am in parent\n");
					pf("please ,write something on screen  \n");
					
			
					sf("%s",st);	
					write(d[1],st,strlen(st)+1);
				}		
				
				pf("( -1 to stop )\n");
				sf("%d",&n);
				if(n==-1) break;
		}	
			
			
}
