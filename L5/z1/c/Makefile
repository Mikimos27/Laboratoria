all: listtest.c list.c list.h
	gcc -Wall -Werror -pedantic -O2 -o out listtest.c list.c -fsanitize=address -fsanitize=bounds
