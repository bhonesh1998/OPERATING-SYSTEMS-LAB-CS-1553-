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
#include<pthread.h>
#include<semaphore.h>
#define pf printf
#define sf scanf

sem_t mutex ; // for readers 
sem_t wrt ;// for reader and writer 

int readcount=0;

pthread_t reader1,reader2,writer1,writer2;

void *reader( void *);
void *writer( void *);




int main()
{

	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	int t=10;
	while(t--)
	{
		pthread_create(&reader1,NULL,reader,(void *)1 );
		pthread_create(&reader2,NULL,reader,(void *)2 );
		pthread_create(&writer1,NULL,writer,(void *)1 );
		pthread_create(&writer2,NULL,writer,(void *)2 );

		pthread_join(reader1,NULL);
		pthread_join(reader2,NULL);
		pthread_join(writer1,NULL);
		pthread_join(writer2,NULL);
	}


}


void *reader(void *p)
{
	pf("previous value of mutex %d\n",mutex);
	int px =((int) p);
	sem_wait(&mutex);
	pf("mutex acquired by reader %d\n",mutex);
	readcount++;
	if(readcount==1)
		sem_wait(&wrt);

	sem_post(&mutex);
	pf("mutex returned by reader %d\n",mutex);

	pf("reader %d is reading\n", px );
	sleep(5);	
	sem_wait(&mutex);
	pf("reading is completed by %d \n",px);
	readcount--;
	if(readcount==0)
		sem_post(&wrt);
	sem_post(&mutex);

}

void *writer(void *p)
{
	int px = (int)(p);
	pf("writer %d is waiting \n", px);
	sem_wait(&wrt);
	pf("writer %d is writing \n", px );
	sleep(10);
	pf("writer %d has written \n", px );
	sem_post(&wrt);
}


