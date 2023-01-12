#ifndef EDGES_
#define EDGES_
#include <stdbool.h>
#include "graph.h"

bool create_edge(pedge *head,int weight,int endpoint,pnode realHead);
void print_edge(pedge head);

#endif