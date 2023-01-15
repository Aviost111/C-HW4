#ifndef ALGO_
#define ALGO_
#include <stdbool.h>

void swap(int *first, int *second);
int min(int a,int b);
int compare(const void * a, const void * b);
bool next_permutation(int *arr, int size);
void reverse(int *permutation, int start_index, int size);

#endif