CC = gcc -m64
CFLAGS = -I../include
CFLAGS += -Wall -O2
OBJS = problem.o yj_time.o main.o
TARGET = baseball_game_exe

all : $(TARGET)
    
$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm $(TARGET)