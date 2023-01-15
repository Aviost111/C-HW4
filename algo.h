#ifndef ALGO_
#define ALGO_
#include <stdbool.h>
#include "graph.h"

pnode poll(pnode head);
void initialize(node *head, int start_node);
int dijkstra_algorithm(pnode head, int start, int dest);
void swap(int *first, int *second);
int min(int a,int b);
int compare(const void * a, const void * b);
bool next_permutation(int *arr, int size);
void reverse(int *permutation, int start_index, int size);

#endif