CC=gcc
CFLAGS = -I ../include
CFLAGS += -Wall -O2
OBJS = int_set.o yyj.o main.o

main_exe : $(OBJS)
	$(CC) $(CFLAGS) -o main_exe $(OBJS)

int_set.o : int_set.c
	$(CC) $(CFLAGS) -c int_set.c

yyj.o : yyj.c
	$(CC) $(CFLAGS) -c yyj.c

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm *.o 
	rm ../main_exe