#include<stdio.h>
#include<unistd.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(int argc, char **argv){

	int num1 = atoi (argv[0]);
	int num2 = atoi (argv[1]);
	
	int ans = 0;

	if(strcmp(argv[2], "+") == 0)
		ans = num1 + num2;
	else
		ans = num1 - num2;

	return ans;
}