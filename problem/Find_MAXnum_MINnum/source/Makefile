CC = gcc
CFLAGS = -I ../include
CFLAGS += -Wall -O2
OBJS = problem.o main.o

problem_exe : $(OBJS)
	$(CC) $(CFLAGS) -o problem_exe $(OBJS) 

problem.o : problem.c
	$(CC) $(CFLAGS) -c problem.c

main.o : main.c 
	$(CC) $(CFLAGS) -c main.c

clean :
	rm -rf *.o problem_exe