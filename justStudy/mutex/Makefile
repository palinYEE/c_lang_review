CC = gcc -m64
CFLAGS += -Wall -O2 -lpthread
OBJS = yyj_mutex.o
TARGET = yyj_mutex

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm $(TARGET)