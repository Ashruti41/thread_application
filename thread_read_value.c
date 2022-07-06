//thread 2 for stored inceremented data
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *read1();                  //for read data of incremented in thread2

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int bytes;
int main()
{
	int a2;
	pthread_t thread2;
	if((a2 = pthread_create(&thread2, NULL, &read1, NULL)))     //thread2 create
	{
		printf("thread failed:\n",a2);
	}
	pthread_join(thread2, NULL);      //thread2 join

	return 0;
}

void *read1() {
	pthread_mutex_lock(&lock);
	printf("value is: %d",bytes);                             //stored data will print
	pthread_mutex_unlock(&lock);                             //mutex unlocking
}
