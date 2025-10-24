BIN=euklides prime
CC=gcc
CFLAGS=-g -Wall -Werror -pedantic -fsanitize=bounds -fsanitize=address -O2 -std=c23

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) -o $@ $^ -lm

.PHONY: clean

clean: 
	rm -rf $(BIN)
