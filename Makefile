CC = gcc
CFLAGS = -g -Wall

BINDIR = bin
SRCDIR = src
OBJDIR = $(BINDIR)/obj

EXEC := $(BINDIR)/pid.out

SRC := $(shell find $(SRCDIR) -name "*.c")
OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ $(LDFLAGS) -o $(EXEC)

$(OBJDIR)/%.o: %.c
	mkdir -p '$(@D)'
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(BINDIR)
