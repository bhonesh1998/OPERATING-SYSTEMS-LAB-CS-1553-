#include<stdio.h>
#include<unistd.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){

	int times = 0;
	printf("How many operations :");
	scanf("%d", &times);

	int num1 = 0, num2 = 0;
	char op = '0';

	while(times-- > 0){

		//read num1
		printf("Enter num1 :");
		scanf("%d", &num1);
		char snum1[5];
		sprintf(snum1, "%d", num1);

		//read num2
		printf("Enter num2 : ");
		scanf("%d", &num2);
		char snum2[5];
		sprintf(snum2, "%d", num2);

		//read operation
		printf("Enter operation : ");
		scanf(" %c", &op);
		char sop[5];
		sprintf(sop, "%c", op);

		//fork
		pid_t pid = fork();

		if(pid == 0){//child

			//call server with arguments
			//char *args[] = {"./server",NULL};

        		execl("/home/bhonesh/Desktop/testing/s",snum1, snum2, sop, NULL); 

		} else {//parent

			int status;
			waitpid(pid, &status, 0);//wait for child to finish

			if(WIFEXITED(status)){
				int res = WEXITSTATUS(status);
				printf("RESULT : %d\n", res);
			}
		}
	}

	printf("\n");
	return 0;
}
