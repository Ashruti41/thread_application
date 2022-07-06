pthread_mutex_t lock =PTHREAD_MUTEX_INITIALIZER;

extern int c1;
 char buffer[30];

void *increment()
{
   		 pthread_mutex_lock(&lock);                             //mutext lock starts                                            
		printf("number is :%d",c1);
		c1++;                                                 //increment value
		printf("\t after increment number is :%d\n",c1);
    	sprintf(buffer, "%d\n",c1);                           //stores all the data in char buffer
		pthread_mutex_unlock(&lock);
}

