CC=gcc
tag= -pthread

file: thread_increment_value.o thread_read_value.o thread_store_value.o
	$(CC) -o file thread_increment_value.o thread_read_value.o thread_store_value.o $(tag)

thread_increment_value.o: thread_increment_value.c
	$(CC) thread_increment_value.c -pthread 

thread_read_value.o: thread_read_value.c
	$(CC) thread_read_value.c $(tag) 

thread_store_value.o: thread_store_value.c
	$(CC) thread_store_value.c $(tag) 
	
