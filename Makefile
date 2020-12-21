CC = gcc
CFLAGS = -Wall
ODIR=obj
LIBS=-lm

_OBJ = main.o elimination.o exchange.o gaussElimination.o print.o reverseElimination.o solution.o swapRows.o uniqueSolution.o plot.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)