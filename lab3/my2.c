#include <stdio.h>
#include<stdlib.h>

#define pf printf
#define sf scanf

int main()
{
		int fd ;
		char *myfifo = "/tmp/myfifo";
		mkfifo(myfifo,0666);
		char a1[100],a2[100];
		while(1)
		{
				fd = open(myfifo,O_RDONLY);
				read(fd,a2,sizeof(a2));
				pf("message : %s",a2);
				close(fd);
				fd = open(myfifo,O_WRONLY);
				fgets(a1,100,stdin);
				write(fd,a1,sizeof(a1));
				close(fd);
				
		}	
}
