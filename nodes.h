#include <stdbool.h>
#include "graph.h"
#ifndef NODES_
#define NODES_


bool create_node(pnode *new_node);
void print_node(pnode head);
bool findNode(pnode* head,int find_num);
pnode get_node(pnode *head, int node_num);
pnode get_last_node(pnode *head);
pnode get_prev_node(pnode *head, int node_num);
int num_of_nodes(pnode head);
int* all_nodes(pnode head,int start);
int** make_int_dijk_mat(pnode head,int start);

#endif