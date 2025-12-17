CC = gcc

INCLUDES = -I./include
WARNINGS = -Wall -Wextra
OUT = focaccia

# Default to debug build
DEBUG ?= 1

ifeq ($(DEBUG), 1)
	CFLAGS = $(INCLUDES) $(WARNINGS) -g -Og
else
	CFLAGS = $(INCLUDES) $(WARNINGS) -O2 -DNDEBUG
endif

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)


$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean debug release

debug:
	$(MAKE) DEBUG=1

release:
	$(MAKE) DEBUG=0

clean:
	rm -f $(OBJ) $(OUT)
