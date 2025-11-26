BIN=primetest dwumian nta
CC=gcc
CFLAGS=-g -Wall -Werror -pedantic -fsanitize=bounds -fsanitize=address -O2 -std=c23

all: $(BIN)

primetest: primetest.c prime.c prime.h
	$(CC) $(CFLAGS) -o $@ primetest.c prime.c -lm

dwumian: dwumian.c
	$(CC) $(CFLAGS) -o $@ dwumian.c

nta: nta.c
	$(CC) $(CFLAGS) -o $@ nta.c -lm
.PHONY: clean

clean: 
	rm -rf $(BIN)
