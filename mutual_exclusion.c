
/*

In computer programming, a mutex (mutual exclusion object) is a program object that is created so that multiple program thread can take turns sharing the same resource, such as access to a file. Typically, when a program is started, it creates a mutex for a given resource at the beginning by requesting it from the system and the system returns a unique name or ID for it. After that, any thread needing the resource must use the mutex to lock the resource from other threads while it is using the resource. If the mutex is already locked, a thread needing the resource is typically queued by the system and then given control when the mutex becomes unlocked (when once more, the mutex is locked during the new thread's use of the resource

For more information visit: https://linux.die.net/man/3/pthread_mutex_init

Try the program: https://onlinegdb.com/SkW2o8O5Q

*/
// File: mutex.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
//#include <conio.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// try uncommenting and commenting the mutext below
// and look at the output

void print(char* a, char* b) {
  //pthread_mutex_lock(&mutex1); // comment out
  printf("\t\t Thread active:%d\n", pthread_self()); //The pthread_self() function 
                                                    //returns the Pthread handle
                                                    //of the calling thread.
  printf("\n%s\n", a);
  
  printf("\t\t Thread sleeping:%d\n", pthread_self());
  sleep(5);
  
  printf("\t\t Thread awake:%d\n", pthread_self());
  printf("\n%s\n", b);
  //pthread_mutex_unlock(&mutex1); // comment out
}


// These two functions will run concurrently.
void* print_csa(void *ptr) {
  print("CSA-A1", "CSA-A2");
}

void* print_csb(void *ptr) {
  print("CSB-B1", "CSB-B2");
}

int main() {
  pthread_t t1, t2;
  int iret1 = pthread_create(&t1, NULL, print_csa, NULL);
  int iret2 = pthread_create(&t2, NULL, print_csb, NULL);

  //while(1){}
 // getch();
  exit(0); //never reached.
}
