CC = clang
LINKERS = -L ./lib/ -lraylib -lm -lncurses
INCLUDES = -I ./include/
CFLAGS = -g -O1 -Wall -std=c99 -Wno-missing-braces

All:
	$(CC) tweply.c -o tweply -O1 -Wall -std=c99 -Wno-missing-braces -I ./include/ -L ./lib/ -lraylib -lm -lncurses

