CC = gcc
CFLAGS = -Wall -Wextra -pthread
SRCS = $(wildcard *.c)
PROGS = a.out

# make 30.1 && ./a.out | grep thr
30.1:
	$(CC) $(CFLAGS) -o $(PROGS) 30.1.c

clean:
	rm -f $(PROGS)

.PHONY: clean
