#include<fcntl.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *increment();                 //for increment with thread1
void *read1();                  //for read data of incremented in thread2
void *store();                 // for stores all the data in test.txt file
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
char buffer[30];                //for storing data
int  bytes,c1=7;

int main()
{
	int a1,a2,a3;
	pthread_t thread1, thread2,thread3;            //thread ini

	if((a1 = pthread_create(&thread1, NULL, &increment, NULL)))      //thread1 create
	{
		printf("thread failed:\n",a1);
	}
	if((a2 = pthread_create(&thread2, NULL, &read1, NULL)))     //thread2 create
	{
		printf("thread failed:\n",a2);
	}
	if((a3 = pthread_create(&thread3, NULL, &store, NULL)))     //thread3 create
	{
		printf("thread3 failed:\n",a3);
	}
		
	pthread_join(thread1, NULL);      //thread1 join 
	pthread_join(thread2, NULL);      //thread2 join
	pthread_join(thread3, NULL);      //thread3 join
	return 0;
}

void *increment()
{
	pthread_mutex_lock(&lock);                             //mutext lock starts
//	int c1=4;                                              //var c1=1;
	printf("value of variable is %d",c1);                   //print c1 real value as c1=1
	c1++;
	printf("\nafter increment %d\n",c1);                    //incremented value of c1
	sprintf(buffer, "%d\n",c1);                        //take one char buffer and stores the value of c1 and storing that string into int bytes
	pthread_mutex_unlock(&lock);
}

void *read1() {
	pthread_mutex_lock(&lock);
	printf("value is: %s",buffer);                             //stored data will print
	pthread_mutex_unlock(&lock);                             //mutex unlocking
}

void *store(){
	pthread_mutex_lock(&lock);
	bytes = sprintf(buffer, "%d\n", c1);
	int fd = open("test.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);  //take one file descriptor for storing the data
    if (fd != -1) {
        if (bytes > 0)
            write(fd, buffer, bytes);                                            //write stored data into file
        close(fd);
    }
    pthread_mutex_unlock(&lock);
		
}
