#include <stdbool.h>
#include "graph.h"
#ifndef EDGES_
#define EDGES_

bool create_edge(pedge *head,int weight,int endpoint,pnode realHead);
void print_edge(pedge head);
void delete_outgoing_edge(pnode current_node);
bool createEdge(pnode from, pnode to, int weight);

#endif