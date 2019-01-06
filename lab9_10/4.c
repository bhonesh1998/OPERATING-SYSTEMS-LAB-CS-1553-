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

pthread_t t1,t2;
sem_t pr,cu;
int num;

int cat(int n)
{
	if(n<=1) return 1;
	int res=0;
	int i;
	for(i=0;i<n;i++)
	{
		res+=(cat(i)*cat(n-i-1));
	}
	return res;
}

void producer( void *arg)
{
	int *t = (void *)arg;
	int n =*t;
	int i;

	for(i=1;i<=n;i++)
	{
		sem_wait(&pr);
		num=cat(i);
		sleep(1);
		sem_post(&cu);
	}

}

void consumer(void *arg)
{
	int *t = (void *)arg;
	int n =*t;
	int i;

	for(i=1;i<=n;i++)
	{
		sem_wait(&cu);
		pf("cat%d is %d\n",i,num);
		sem_post(&pr);
	}

}

int main(int argc , char *argv[])
{
	int xx = atoi(argv[1]); 

	sem_init(&pr,0,1);
	sem_init(&cu,0,0);

	pthread_create( &t1, NULL, producer, (void *) &xx);
	pthread_create( &t2, NULL, consumer, (void *) &xx);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

}



