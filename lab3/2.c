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
	
	int f[2];
	pipe(f);
	int pid =fork();
	char s[100];
if(pid<0) pf("error");
else if(pid==0)
{
	pf("i am in child\n");
	read(f[0],s,100);
	pf("message: %s",s);
}
else
{
	pf("i am parent\n");
	pf("enter something");
	
	char st[100];
	sf("%s",st);
	
	write(f[1],st,strlen(st)+1);

}


}



