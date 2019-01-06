#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>
#include<semaphore.h>
#define pf printf
#define sf scanf

pthread_t t1,t2;
sem_t pr,cu;
int num;

int cata(int n)
{		
	if(n<=1) return 1;
	int res=0,i;
	for(i=0;i<n;i++)
	{res+=cata(i)*cata(n-i-1);
	}
	return res;
		
}

void *producer(void *p)
{
	int i;
	int *t = (void *)p;
	int n=*t;
	for(i=1;i<=n;i++)
	{
		sem_wait(&pr);
		num=cata(i);
		sleep(2);
		sem_post(&cu);
	}
}


void *consumer(void *p)
{
	int i;
	int *t = (void *)p;
	int n=*t;
	for(i=1;i<=n;i++)
	{
		sem_wait(&cu);
		pf("catalan of %d is %d \n",i,num);		
		//num=cata(i);
		sem_post(&pr);
	}
}

int main(int argc,char *argv[])
{
	int xx = atoi(argv[1]);
	sem_init(&pr,0,1);
	sem_init(&cu,0,0);
	
	pthread_create(&t1,NULL,producer,(void *)&xx);
	pthread_create(&t1,NULL,consumer,(void *)&xx);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}
