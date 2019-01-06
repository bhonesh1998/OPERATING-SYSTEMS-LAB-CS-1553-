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
int main(int argc , char *argv[])
{
	FILE *fp1,*fp2;	
	char fname1[4],fname2[4];
	pf("enter file namae for 1st file \n");
	sf("%s",fname1);
	fp1=fopen(fname1,"r");
	pf("enter file namae for 2nd file \n");
        sf("%s",fname2);
	fp2=fopen(fname2,"w");

	fseek(fp1,0,SEEK_END);
	int pos=ftell(fp1);
	fseek(fp1,0,SEEK_SET);
	char ch ;
	while(pos--)
	{
		ch = fgetc(fp1);
		fputc(ch,fp2);
	} 


//	fcloseall();

}

