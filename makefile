CC =gcc
FLAGS = -Wall -g
GRAPH_H = graph.h
MAIN_O = main.o

all: graph

.PHONY: all clean

#Create o files

$(MAIN_O): main.c $(GRAPH_H)
	$(CC) $(FLAGS) -c main.c

clean:
	rm -f *.o *.a graph