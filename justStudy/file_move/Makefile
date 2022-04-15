CC = gcc -m64
CFLAGS += -Wall -O2
OBJS = file_move.o
TARGET = file_move 

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm $(TARGET)
