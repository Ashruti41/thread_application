/*in this program Thread1 is for increment var till 100 and Thread2 is for storing that incremented data in unother variable and thread3 is for store that all data in unother app.txt name file*/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>

#include "thread1.h"
#include "thread2.h"
#include "thread3.h"

int var,second;
pthread_mutex_t lock;                           //mutex lock initializer
pthread_cond_t cond1, cond2, cond3;            //sync conditions

int main(){
	pthread_t thread1, thread2, thread3;
	
	pthread_create(&thread1, NULL, &writer, NULL);            //thread creation
	pthread_create(&thread2, NULL, &reader, NULL);
	pthread_create(&thread3, NULL, &store, NULL);

	pthread_join(thread1, 0);                            //thread wait till termination
	pthread_join(thread2, 0);
	pthread_join(thread3, 0);

	return 0;
}

