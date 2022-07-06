CC=gcc
TARGET_PATH= -I "/home/ashruti/thread_application/m/app"
DEPS= thread1.h thread2.h thread3.h
OBJ= thread1.o thread2.o thread3.o main.o
CFLAG= -pthread

%.o: %.c $(DEPS)
	$(CC) $(CFLAG) -o $@ $<
Thread:
	$(CC) thread1.c thread2.c thread3.c main.c $(CFLAG) $(TARGET_PATH) -o $@ $^

.PHONY: clean
clean:
	-rm Thread

