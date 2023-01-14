#include <stdbool.h>
#include "graph.h"
#ifndef EDGES_
#define EDGES_

bool create_edge(pedge *head,int weight,int endpoint,pnode realHead);
void print_edge(pedge head);
void delete_outgoing_edges(pnode current_node);
bool createEdge(pnode from, pnode to, int weight);
void delete_ingoing_edges(pnode head,pnode current_node);

#endif