# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lkarel -lcurses
OUTPUT=$@

# targets
%: %.c
	$(CC) $(CFLAGS) $@.c $(LDLIBS) -o $(OUTPUT)
