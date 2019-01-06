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
	
	char a[10],b[10],c[10];
	int n1=0,n2=0;char ch='0';

	pf("enter 1st\n");
	sf("%d",&n1);
	sprintf(a,"%d",n1);
		
	pf("enter 2nd\n");
	sf("%d",&n2);
	sprintf(b,"%d",n2);

	pf("enter operator\n");
	sf(" %c",&ch);
	sprintf(c,"%c",ch);
	

	
	int pid = fork();
	int st;
	if(pid==0)
	{
			execl("/media/bhonesh/06FE52A2FE528A37/study/3rd year/oslab/mycodes/lab4/s",&a,&b,&c,NULL);
	}
	else
	{
		waitpid(pid,&st,0);
		int res = WEXITSTATUS(st);
		pf("%d",st);
	}


}



