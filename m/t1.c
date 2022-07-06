#include<fcntl.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#include "t2.h"
#include "t3.h"
#include "t4.h"

 extern int c1=0,c2;

int main()
{
	int a1,a2,a3;
	pthread_t thread1, thread2,thread3;            //thread 

	if((a1 = pthread_create(&thread1, NULL, &increment, NULL)))      //thread1 create
	{
		printf("thread failed:\n");
	}

	if((a2 = pthread_create(&thread2, NULL, &read1, NULL)))     //thread2 create
	{
		printf("thread failed:\n");
	}
	if((a3 = pthread_create(&thread3, NULL, &store, NULL)))     //thread3 create
	{
		printf("thread3 failed:\n");
	}
	pthread_join(thread1, NULL);		                        //used to wait for the termination of a thread
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);      
	
	
	return 0;
}

