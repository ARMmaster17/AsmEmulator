DIR = AsmEmulator
_OBJS = AsmEmulator.cpp GEN_Register.cpp Opcodes.cpp RAM.cpp SFLAG_Register.cpp StringHelpers.cpp
OBJS = $(patsubst %,$(DIR)/%,$(_OBJS))
_DEPS = GEN_Register.h Opcodes.h RAM.h SFLAG_Register.h stdafx.h StringHelpers.h targetver.h
DEPS = $(patsubst %,$(DIR)/%,$(_DEPS))
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

AsmEmulator :
	$(CC) $(LFLAGS) $(OBJS) -o AsmEmulator.o
