#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>

void *store();                 // for stores all the data in test.txt file

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
char buffer[30];
int bytes;

int main()
{
	int a3;
	pthread_t thread3;

	if((a3 = pthread_create(&thread3, NULL, &store, NULL)))     //thread3 create
	{
		printf("thread3 failed:\n",a3);
	}

	pthread_join(thread3, NULL);

	return 0;
}

void *store(){
	pthread_mutex_lock(&lock);
	int fd = open("test.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);  //take one file descriptor for storing the data
    if (fd != -1) {
        if (bytes > 0)
            write(fd, buffer, bytes);                                            //write stored data into file
        close(fd);
    }
    pthread_mutex_unlock(&lock);
		
}
