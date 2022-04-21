CC = gcc -m64
CFLAGS += -Wall -O2
OBJS = yyj_dev_random.o
TARGET = yyj_dev_random

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm $(TARGET)