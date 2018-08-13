#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main(int argc, char* argv[])
{
    DIR *mydir;
    struct dirent *myfile;
    mydir = opendir(argv[1]);
    while((myfile = readdir(mydir)) != NULL)
        printf(" %s\n", myfile->d_name);
    closedir(mydir);
}
