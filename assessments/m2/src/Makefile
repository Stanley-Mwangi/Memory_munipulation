#******************************************************************************
# Copyright (C) 2017 by Stanley mwangi
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
ifeq ($(PLATFORM), HOST)

# Architectures Specific Flags
	CPU = x86_64
	ARCH = $(shell arch)

else
	LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	
endif

ifeq ($(PLATFORM), HOST)
# Compiler Flags and Defines
	CC=gcc
	LDFLAGS=-Wl,-Map=demo.map
	CFLAGS=-Wall -Wextra -O0 -g -std=c99 $(INCLUDES)
	CPPFLAGS = -M -MF test.d
	TARGET = out.a

else
	CC = arm-none-eabl-gcc
	LD = arm-none-eabl-ld 
	LDFLAGS=-Wl,-Map=demo.map, -T$(LINKER_FILE) 
	CFLAGS=-Wall -Wextra -O0 -g -std=c99 $(INCLUDES)
	CPPFLAGS = -M -MF test.d
	TARGET = out.a
	
endif

#declare variables
OBJS:= $(SOURCES:.c=.o)
ASMS:= $(SOURCES:.c=.s)
PPS:= $(SOURCES:.c=.i)
MAPS:= $(SOURCES:.c=.map)
OUTS:= $(SOURCES:.c=.out)


.PHONY: all
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $^

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $^

%.asm: %.c 
	$(CC) $(CFLAGS) -S -o $@ $<

%.i: %.c $(INCLUDES) 
	$(CC) -E $^ -o $@ 
	
.PHONY: compile
compile: $(SOURCES)
%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -rf *.o *.i *.map *.a
 


