# First time doing a Makefile #

OBJS = tokens.o uimain.o history.o

CFLAGS = -g -O3

all: shellmimic

shellmimic: $(OBJS)
	cc -o shellmimic $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o shellmimic

run:
	./shellmimic
