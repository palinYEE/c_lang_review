CC=gcc
CFLAGS = -I ../include
CFLAGS += -Wall -O2
OBJS = int_set.o main.o

main_exe : $(OBJS)
	$(CC) $(CFLAGS) -o main_exe $(OBJS)

int_set.o : int_set.c
	$(CC) $(CFLAGS) -c int_set.c

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm *.o main_exe