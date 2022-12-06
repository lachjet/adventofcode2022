.DEFAULT_GOAL := all

CC=gcc

all:
	make rps
	make rpsd

rps: rps.o
	$(CC) -o rps rps.c


rpsd: rpsd.o
	$(CC) -o rpsd rpsd.c

clean:
	rm rps.o rps rpsd.o rpsd
