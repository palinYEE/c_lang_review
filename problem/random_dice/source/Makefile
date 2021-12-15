CC = gcc
CFLAGS = -I../include
CFLAGS += -Wall -O2
OBJS = problem.o main.o
TARGET = random_dice_exe

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm $(TARGET)

