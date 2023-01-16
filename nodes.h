#include <stdbool.h>
#include "graph.h"

#ifndef NODES_
#define NODES_

bool create_node(pnode *new_node);

bool findNode(pnode *head, int find_num);

pnode get_node(pnode *head, int node_num);

pnode get_last_node(pnode *head);

pnode get_prev_node(pnode *head, int node_num);

#endif