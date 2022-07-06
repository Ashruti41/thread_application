#include<stdio.h>
#include<pthread.h>

#include "th3.h"
extern int c1,c2,done;
pthread_mutex_t lock;
pthread_cond_t condR;
pthread_cond_t condW;

void *store(){
	
	pthread_mutex_lock(&lock);
	for(int i=0; i<10; i++){
		if(done!=2){
			pthread_cond_wait(&condR,&lock);
		}
		FILE *fp;
		fp = fopen("app.txt","a+");
		if(fp == NULL){
			printf("filed can't be open");
		}
		fprintf(fp, "value is:%d\n", c2);
		fclose(fp);
		pthread_cond_signal( & condW);
	}
		pthread_mutex_unlock(&lock);
} 
