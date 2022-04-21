CC = gcc -m64
CFLAGS += -Wall -O2
OBJS = yyj_bcrypto.o
TARGET = yyj_bcrypto

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm $(TARGET)