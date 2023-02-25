VERSION = 1.0

CC = cc
AR = ar

CPPFLAGS = -D_DEFAULT_SOURCE
CFLAGS   = -std=c17 -pedantic -Wall -Wextra -Werror -Os
LDGLAGS  = -s

FUN =\
		 manage\
		 rectangle\
		 circle\
		 triangle

VPATH = src
HDR = rysik.h src/internals.h
OBJ = $(FUN:=.o)

all: librysik.a

.o: .c $(HDR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

librysik.a: $(OBJ) $(HDR)
	$(AR) -rcs $@ $?

test: test.c librysik.a
	$(CC) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS) -o $@ test.c librysik.a

check: test
	./test

clean:
	rm -f *.o *.a test

.PHONY: all check clean
