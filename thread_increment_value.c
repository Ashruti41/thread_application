#include<stdio.h>
#include<pthread.h>

void *increment();                 //for increment with thread1

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

char buffer[30];
int bytes;

int main(){
	int a1;
	pthread_t thread1;
	
	if((a1 = pthread_create(&thread1, NULL, &increment, NULL)))      //thread1 create
	{
		printf("thread failed:\n",a1);
	}

	pthread_join(thread1, NULL);      //thread1 join

	return 0;
}

void *increment()
{
	pthread_mutex_lock(&lock);                             //mutext lock starts
	int c1=1;                                              //var c1=1;
	printf("value of variable is %d",c1);                   //print c1 real value as c1=1
	c1++;
	printf("\nafter increment %d\n",c1);                    //incremented value of c1
	bytes = sprintf(buffer, "%d\n",c1);                        //take one char buffer and stores the value of c1 and storing that string into int bytes
	pthread_mutex_unlock(&lock);
}
	
