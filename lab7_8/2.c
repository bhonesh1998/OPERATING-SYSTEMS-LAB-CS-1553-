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
#include<sys/sem.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<pthread.h>
#include<ctype.h>
#include<semaphore.h>
#define pf printf
#define sf scanf

sem_t chop[5]; // it is semaphore array 
int n=5;

void *thread(int no)
{
int i;
	for(i=0;i<5;i++)
	{
		sem_wait(&chop[no]);
		sem_wait(&chop[(no+1)%n]);
		pf("p%d is eating\n",no);
		sleep(3);
		pf("p%d has completed\n",no);
		sem_post(&chop[no]);
		sem_post(&chop[(no+1)%n]);
	}

	pthread_exit(NULL);

}




int main()
{

	int i,res;
	pthread_t th[5];
	for(i=0;i<5;i++)
		sem_init(&chop[i],0,0);
	for(i=0;i<5;i++)
		{pthread_create(&th[i],NULL,thread,(int*)i);
		 sem_post(&chop[i]);}

	for(i=0;i<n;i++)
	{
		pthread_join(th[i],NULL);
	}

	for(i=0;i<n;i++)
	{
		sem_destroy(&chop[i]);
	}


	return 0;


}




