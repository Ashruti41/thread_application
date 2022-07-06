//in this file all the data store in app.txt file

#include<stdio.h>
#include<pthread.h>

#include "thread3.h"
extern pthread_mutex_t lock;
extern pthread_cond_t cond1, cond3;
extern int second,var;

void *store(){
	pthread_mutex_lock(&lock);                     //mutex locking
	while(var!=100){
		pthread_cond_wait(&cond3,&lock);
    	FILE *fp;
    	fp = fopen("app.txt","a+");                //file open in append mode
   		 if(fp == NULL){
       		printf("filed can't be open");
     	}
    	fprintf(fp, "value is:%d\n", second);     //file data store in file 
    	fclose(fp);                              //file close
    	pthread_cond_signal(&cond1);
    }	
	pthread_mutex_unlock(&lock);                 //mutex unlocking
}
