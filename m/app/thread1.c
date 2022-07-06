//in this file thread one is created and increment the var+1

#include<stdio.h>
#include<pthread.h>

#include "thread1.h"
extern pthread_mutex_t lock;

extern pthread_cond_t cond1, cond2, cond3;
extern int var,count;

void *writer()
{
	pthread_mutex_lock(&lock);                                            //start mutex locking
	while(var!=100){                                
		printf("Var is :%d\n",var);                                       
		var++;                       
		printf("After increment:%d\n",var);                              //var is incremented by 1
		pthread_cond_signal( &cond2);                                    //signal for cond2
    	pthread_cond_wait(&cond1, &lock);                               //wait condition for completed 
	}
	pthread_mutex_unlock(&lock);                                        //mutex unlocking
}
