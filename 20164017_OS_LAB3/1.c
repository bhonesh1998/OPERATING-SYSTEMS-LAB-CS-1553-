/*
NAME - BHONESH CHAWLA
REGNO - 20164017
BATCH - CSA(2020)
CONTACT - 8619127663
*/



#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#define pf printf
#define sf scanf
int main()
{
    pid_t pid;
    int rv;
    switch(pid = fork()) {
    case -1:
        perror("fork");  
        exit(1);  

    case 0:
        pf(" CHILD: This is the child process!\n");
        pf(" CHILD: My PID is %d\n", getpid());
        pf(" CHILD: My parent's PID is %d\n", getppid());
        pf(" CHILD: Enter my exit status (make it small): ");
        sf(" %d", &rv);
        pf(" CHILD: I'm outta here!\n");
        exit(rv);

    default:
        pf("PARENT: This is the parent process!\n");
        pf("PARENT: My PID is %d\n", getpid());
        pf("PARENT: My child's PID is %d\n", pid);
        pf("PARENT: I'm now waiting for my child to exit()...\n");
        wait(&rv);
        pf("PARENT: My child's exit status is (in decimal) : %d\n)", WEXITSTATUS(rv));
        pf("PARENT: My child's exit status is (in hexadecimal ): %x\n", WEXITSTATUS(rv));
        pf("PARENT: I'm outta here!\n");
    }

    return 0;
}
