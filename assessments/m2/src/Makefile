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
ifeq (&(PLATFORM),HOST)
	# Architectures Specific Flags
	LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs

	# Compiler Flags and Defines
	CC = arm-none-eabl-gcc
	LD = arm-none-eabl-ld 
	LDFLAGS = -wl,-Map=demo.map
	CFLAGS =-Wall -Wextra
	TARGET = out.a

else
	
	# Architectures Specific Flags
	LINKER_FILE=msp432p401r.lds
	CPU = 
	ARCH = 
	SPECS = 

	# Compiler Flags and Defines
	CC=gcc
	LD=gcc
	LDFLAGS=Wl,-wl,-Map=demo.map
	CFLAGS=-Wall -Wextra -O0 -g -std=c99 $(INCLUDES)
	TARGET = out.a

endif

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) 

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -rf *.o *.i *.map *.a



