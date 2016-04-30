SRCS = delay.c


###################################################

CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

#CFLAGS  = -g -O0 -Wall --specs=nosys.specs
CFLAGS  = -g -O0 -Wall 
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m0 -mthumb-interwork
CFLAGS += -mfloat-abi=soft
CFLAGS += -ffreestanding -nostdlib

###################################################

vpath %.c src

ROOT=$(shell pwd)

CFLAGS += -Iinc -I../libs -I../libs/inc
CFLAGS += -I../libs/inc/core -I../libs/inc/peripherals

#SRCS += ../libs/startup_stm32f030xc.s
#SRCS += ../libs/system_stm32f0xx.c

OBJS = $(SRCS:.c=.o)

###################################################

.PHONY: libtiming.a

all: libtiming.a

%.o : %.c
	#$(CC) $(CFLAGS) -c $^ -o $@ -L../libs -lstm32f0
	$(CC) $(CFLAGS) -c -o $@ $^

libtiming.a: $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) libtiming.a
