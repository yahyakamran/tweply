CC = clang
LINKERS = -L ./lib/ -lraylib -lm
INCLUDES = -I ./include/
CFLAGS = -ggdb -O1 -Wall -std=c99 -Wno-missing-braces

All:
	$(CC) tweply.c -o tweply -ggdb -O1 -Wall -std=c99 -Wno-missing-braces -I ./include/ -L ./lib/ -lraylib -lm

