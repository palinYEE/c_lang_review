CC = gcc -m64
CFLAGS += -Wall -O2
OBJS = serialize.o
TARGET = serialize

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm $(TARGET)
