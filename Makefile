SRCS = delay.c


###################################################

CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

CFLAGS  = -g -O0 -Wall 
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m0 -mthumb-interwork
CFLAGS += -mfloat-abi=soft
CFLAGS += -ffreestanding -nostdlib

###################################################

vpath %.c src

ROOT=$(shell pwd)

CFLAGS += -Iinc -Iinc/core

OBJS = $(SRCS:.c=.o)

###################################################

.PHONY: libtiming.a

all: libtiming.a

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

libtiming.a: $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) libtiming.a
