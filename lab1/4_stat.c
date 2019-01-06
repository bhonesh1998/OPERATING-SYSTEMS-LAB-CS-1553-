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

size_t get(const char *filename)
{
	struct stat st;

	if( stat(filename,&st) !=0 ) return 0;
	else
		return st.st_size;

}

int main()
{
	char filename[100];
	pf("enter filename\n");
	sf("%s",filename);
	pf("%d",(int)get(filename));

	struct stat stbuff;
	stat(filename,&stbuff);
	pf("block size : %d",(int)stbuff.st_blksize);


}
