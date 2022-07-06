int bytes;

void *store(){
	pthread_mutex_lock(&lock);

	bytes = sprintf(buffer, "value:%d\n", c1);
	int fd = open("test.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);  //take one file descriptor for storing the data
    if (fd != -1) {
        if (bytes > 0)
            write(fd, buffer, bytes);                                            //write stored data into file
        close(fd);
    }

    pthread_mutex_unlock(&lock);		
}
