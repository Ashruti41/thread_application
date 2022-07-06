#include<stdio.h>
#include<pthread.h>

#include "th2.h"
extern int c1,done;
extern int c2;

pthread_mutex_t lock;
pthread_cond_t condR;
pthread_cond_t condW;
void *read1()
{
	pthread_mutex_lock(&lock);
	for(int i=0; i<10; i++){
		if(done!=1){
			pthread_cond_wait( & condR, &lock );
		}
		done=2;
		c2 = c1;
		printf("value is %d\n",c2);	
        pthread_cond_signal( & condW);
	}
	pthread_mutex_unlock(&lock);
}

