#include<fcntl.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#include "th1.h"
#include "th2.h"
#include "th3.h"

pthread_mutex_t lock;
pthread_cond_t condR;
pthread_cond_t condW;
 
extern int c1=0,done=0;
extern int c2=0;

int main()
{
	int a1,a2,a3;
	pthread_t thread1, thread2,thread3;            //thread 

	pthread_mutex_init(&lock, 0);
    pthread_cond_init(&condR, NULL);
    pthread_cond_init(&condW, NULL);

	if((a1 = pthread_create(&thread1, 0, increment, 0)))      //thread1 create
	{
		printf("thread failed:\n");
	}

	if((a2 = pthread_create(&thread2, 0, read1, 0)))     //thread2 create
	{
		printf("thread failed:\n");
	}
	if((a3 = pthread_create(&thread3, 0,store, 0)))     //thread3 create
	{
		printf("thread3 failed:\n");
	}
	pthread_join(thread1, 0);		                        //used to wait for the termination of a thread
	pthread_join(thread2, 0);
	pthread_join(thread3, 0);      
	
	
	return 0;
}


