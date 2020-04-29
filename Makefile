CFLAGS=-std=c11 -g -static
SRCS=main.c parse.c codegen.c container.c
OBJS=$(SRCS:.c=.o)

9cc: $(OBJS)
	$(CC) -o 9cc $(OBJS) $(LDFLAGS)

$(OBJS): 9cc.h

test: 9cc
	./test.sh
test2: 9cc
	./test2.sh

clean:
	rm -f 9cc *.o *~ tmp*

.PHONY: test clean

