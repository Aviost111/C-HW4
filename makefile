CC =gcc
FLAGS = -Wall -g
GRAPH_H = graph.h
MAIN_O = main.o
EDGES_O = edges.o
EDGES_H = edges.h
NODES_O = nodes.o
NODES_H = nodes.h
ALGO_O = algo.o
ALGO_H = algo.h

all: graph

.PHONY: all clean

graph: $(MAIN_O) $(ALGO_O) $(NODES_O) $(EDGES_O) $(GRAPH_H)
	$(CC) $(FLAGS) -o graph $(MAIN_O) $(ALGO_O) $(NODES_O) $(EDGES_O)

#Create o files

$(ALGO_O): algo.c $(ALGO_H)
	$(CC) $(FLAGS) -c algo.c

$(NODES_O): nodes.c $(NODES_H)
	$(CC) $(FLAGS) -c nodes.c

$(EDGES_O): edges.c $(EDGES_H)
	$(CC) $(FLAGS) -c edges.c

$(MAIN_O): main.c $(GRAPH_H)
	$(CC) $(FLAGS) -c main.c

clean:
	rm -f *.o *.a graph