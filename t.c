#include<fcntl.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


void *func1();
void *func2();
void *func3();
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
char buf[25];
int bytes=0;

int main()
{
	int a1,a2,a3;
	pthread_t thread1, thread2,thread3;

	if((a1 = pthread_create(&thread1, NULL, &func1, NULL)))
	{
		printf("thread failed:\n",a1);
	}
	if((a2 = pthread_create(&thread2, NULL, &func2, NULL)))
	{
		printf("thread failed:\n",a2);
	}
	if((a3 = pthread_create(&thread3, NULL, &func3, NULL)))
	{
		printf("thread3 failed:\n",a3);
	}
		
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	return 0;
}

void *func1()
{
	pthread_mutex_lock(&lock);
	int i,c1=2;
	printf("value of variable is %d",c1);
	c1++;
	printf("\nafter increment %d\n",c1);
	bytes = sprintf(buf, "%d\n", c1);
//	printf("buffer: %d", bytes);
	pthread_mutex_unlock(&lock);
}

void *func2() {
	pthread_mutex_lock(&lock);
	if(bytes > 2){
		printf("value is: %d",bytes+1);
	}
	else{
		printf("values : %d",bytes);
	}
	pthread_mutex_unlock(&lock);
}

void *func3(){
	pthread_mutex_lock(&lock);
	int fd = open("test.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd != -1) {
        if (bytes > 0)
            write(fd, buf, bytes);
        close(fd);
    }
	pthread_mutex_unlock(&lock);
}	
