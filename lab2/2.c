#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define pf printf
#define sf scanf


int main(int argc , char *argv[])
{
	
	char str[]="find ";
	strcat(str,argv[1]);
	strcat(str," -iname ");
	strcat(str,argv[2]);
	execl("/bin/bash","bash","-c",str,(char *)NULL);


}



