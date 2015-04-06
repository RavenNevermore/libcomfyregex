CFLAGS+=-g -std=c11
CFLAGS+=-I../build/headers

LDFLAGS+=-L../build/lib
LDLIBS+=-lcomfyregex

test_c=$(wildcard *.c)
test_o=$(patsubst %.c, %.o, $(test_c))
tests=$(patsubst %.c, %.test, $(test_c))
run_tests=$(patsubst %.c, %.run, $(test_c))

test: $(run_tests)


%.run: %.test
	./$?

%.test: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@ $?

clean:
	$(RM) $(tests)

.PHONY: test clean
