CONFIG = config.mk
include $(CONFIG)

FUN =\
		 rinit\
		 rdestroy\
		 rsave_to_ppm\
		 rfill\
		 rrectangle

VPATH = src
HDR = rysik.h src/internals.h
OBJ = $(FUN:=.o)

all: check

.o: .c $(HDR) $(CONFIG)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

librysik.a: $(OBJ)
	$(AR) -rcs $@ $?

test: test.c librysik.a
	$(CC) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS) -o $@ test.c librysik.a

check: test
	./test

clean:
	rm -f *.o *.a test

.PHONY: all check clean