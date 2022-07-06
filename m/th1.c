#include<stdio.h>
#include<pthread.h>

#include "th1.h"
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condR;
pthread_cond_t condW;
 
extern int c1,c2, done;

void *increment()
{
	for(int i=0; i<10; i++){	
	    pthread_mutex_lock(&lock);                             //mutext lock starts                                          
        printf("number is :%d",c1);
		if(done!=0){
			pthread_cond_signal( & condR);
			pthread_cond_wait(&condW, &lock);
		}
		done=1;
        c1++;                                                 //increment value
        printf("\t after increment number is :%d\n",c1);
    }
    pthread_mutex_unlock(&lock);
}

