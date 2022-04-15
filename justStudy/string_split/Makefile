CC = gcc -m64
CFLAGS += -Wall -O2
OBJS = string_split.o
TARGET = string_split

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm $(TARGET)
