CC=arm-cortexm0-eabi-gcc
AR=arm-cortexm0-eabi-ar

###########################################
PATHLIBCORE  = ../lib-core/CMSIS
INCLLIBCORE  = -I$(PATHLIBCORE)/Include -I$(PATHLIBCORE)/Device/ST/STM32F0xx/Include

PATHLIBPERIPH  = ../lib-mcu
INCLLIBPERIPH  = -I$(PATHLIBPERIPH) -I$(PATHLIBPERIPH)/STM32F0xx_StdPeriph_Driver/inc
INCLLIBPERIPH += -include $(PATHLIBPERIPH)/stm32f0xx_conf.h

vpath %.c ./Utilities
#vpath %.a $(PATHLIBPERIPH)

CFLAGS  = -g -O2 -Wall
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m0 -march=armv6s-m
CFLAGS += -ffreestanding -nostdlib
CFLAGS += -I. -I inc 
CFLAGS += $(INCLLIBCORE) $(INCLLIBPERIPH)

SRCS = stm32f072b_discovery.c stm32f072b_discovery_l3gd20.c stm32f072b_discovery_i2c_ee.c
 
OBJS = $(SRCS:.c=.o)

#.PHONY: lib_Utilities.a

all: libstm32f072b.a

lib:
	$(MAKE) -C $(STD_PERIPH_LIB)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

libstm32f072b.a: $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) libstm32f072b.a
