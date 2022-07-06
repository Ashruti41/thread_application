CC=gcc
INCLUDES= -I "/home/ashruti/thread_application/m"
DEPS= th1.h th2.h th3.h
OBJ= th1.o th2.o th3.o main.o
CFLAG=-pthread

%.o: %.c $(DEPS)
	$(CC) $(CFLAG) -o $@ $<
Thread:
	$(CC) main.c $(CFLAG) $(INCLUDES) -o $@ $^

.PHONY: clean
clean:
	-rm Thread
