TARGET=datacollector
SRCS=main.c serial.c bytesfactory.c chanel.c wdt.c fileoperator.c yadaoperator.c taiguoperator.c
OBJS=$(SRCS:.c=.o)

CROSS=arm-none-linux-gnueabi-
CC=$(CROSS)gcc
STRIP=$(CROSS)strip
GFLAGS=-g -O2 -lm

$(TARGET):$(OBJS)
	$(CC) -lpthread $(GFLAGS) -o $@ $(OBJS)
	$(STRIP) $@

clean:
	rm -rf $(TARGET) $(OBJS)

