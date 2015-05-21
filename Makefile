CC=gcc
CFLAGS=-03 -Wall
LD=gcc
LDFLAGS=

EXEC=chess

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)


.PHONY: clean all distclean


all: $(EXEC)

$(EXEC): $(OBJ)
	$(LD) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CLFAGS) -c $< -o $@


clean:
	rm -f $(OBJ)

distclean: clean
	rm -f $(EXEC)

