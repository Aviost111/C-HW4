#include <stdbool.h>
#include "graph.h"
#ifndef NODES_
#define NODES_

bool create_node(pnode *new_node);
void print_node(pnode head);
bool findNode(pnode* head,int find_num);

#endif