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
	int fd;
	char * myfifo= "/tmp/myfifo";
	mkfifo(myfifo,0666);
	char a1[100],a2[100];
	while(1)
	{
		

		fd =open(myfifo,O_RDONLY);
		read(fd,a1,sizeof(a1));
		pf("message: %s\n",a1);
		close(fd);
		fd=open(myfifo,O_WRONLY);
		pf("write something on console\n");
		fgets(a2,100,stdin);
		write(fd,a2,strlen(a2)+1);
		close(fd);
	}
	return 0;

}



