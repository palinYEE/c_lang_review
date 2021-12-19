CC = gcc -m64
CFLAGS = -I../include
CFLAGS += -Wall -O2
OBJS = yj_utils.o yj_time.o phone_book.o main.o
TARGET = phone_book_exe

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm $(TARGET)