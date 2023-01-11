#include "graph.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool craete_edge(int weight, pnode endpoint){
    pedge new_edge = (pedge)malloc(sizeof(edge));
    if(new_edge ==NULL){
        //allocation failed
        return 0;
    }
    new_edge->weight = weight;
    new_edge->next = endpoint;
    new_edge->next = NULL;
    return 1;
}

void print_egde(pedge head){
    pedge current = head;
    while(current != NULL){
        printf("%d" , current->endpoint->node_num);
        printf("%d", current->weight);
        current = current->next;
    }
}


