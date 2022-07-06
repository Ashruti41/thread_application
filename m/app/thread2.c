//in this file thread2 is created and store incremented var in unother second name variable

#include<stdio.h>
#include<pthread.h>

#include "thread2.h"
extern pthread_mutex_t lock;
extern pthread_cond_t cond2,cond3;
extern int var,count;
extern int second;


void *reader(){
	pthread_mutex_lock(&lock);                                    //mutex locking
	while(var!=100){
		pthread_cond_wait(&cond2,&lock);
		second = var;                                             //var value store in second
		printf("Incremented value :%d\n",second);
		pthread_cond_signal( &cond3);                             
	}
	pthread_mutex_unlock(&lock);                                  //mutex unlocking
}
