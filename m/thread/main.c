#include<fcntl.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

//#include "th1.h"
//#include "th2.h"
//#include "th3.h"

int i = 0,i2;
sem_t sR;
sem_t sW; 
void* writer()
{
    printf("In Writer\n");
    while(i!= 100)
    {
        i= i+1;
//        printf("Writer: %d\n",i);
        sem_post(&sW);
        sem_wait(&sR);
    }
 
}
 
void* reader()
{
    printf("In Reader\n");
    while(i!= 100)
    {
		i2=i;
        sem_wait(&sW);
        printf("Reader: %d\n",i2);
        sem_post(&sR);
    }
 
}
void *store(){
        FILE *fp;
        fp = fopen("app.txt","a+");
        if(fp == NULL){
            printf("filed can't be open");
        }
        fprintf(fp, "value is:%d\n", i2);
        fclose(fp);
}
int main()
{
	int a1,a2,a3;
	pthread_t thread1, thread2,thread3;            //thread 

	sem_init(&sR, 0, 0);
    sem_init(&sW, 0, 0);
	if((a1 = pthread_create(&thread1, 0, writer, 0)))      //thread1 create
	{
		printf("thread failed:\n");
	}

	if((a2 = pthread_create(&thread2, 0,reader, 0)))     //thread2 create
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
	
	sem_destroy(&sW);
    sem_destroy(&sR);
	
	return 0;
}

