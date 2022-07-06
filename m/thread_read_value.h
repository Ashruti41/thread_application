void *read1() {
		pthread_mutex_lock(&lock);
		printf("value is: %s",buffer);                             //stored data will print
		pthread_mutex_unlock(&lock); 
}

