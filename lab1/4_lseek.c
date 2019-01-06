#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define pf printf
#define sf scanf
int main()
{
	FILE *fp1;
	char fname1[100];
	pf("enter file namae for 1st file \n");
	sf("%s",fname1);
	fp1=fopen(fname1,"r");
	fseek(fp1,0,SEEK_END);
	int pos=ftell(fp1);
	pf("size: %d",pos);



}
