CC = gcc
CFLAGS = -I../include
CFLAGS += -Wall -O2
OBJS = dvd_init.o dvd_user.o main.o
TARGET = dvd_management_program

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm $(TARGET)