#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#define pf printf
int main(int argc , char* argv[])
{
	DIR *mydir;
	struct dirent *myfile; 
	mydir=opendir(argv[1]);
	
	while((myfile=readdir(mydir)) != NULL)
		pf("%s\n",myfile->d_name);

	closedir(mydir);

}

