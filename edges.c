#include "graph.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool create_edge(int weight, pnode endpoint){
    pedge new_edge = (pedge)malloc(sizeof(edge));
    if(new_edge ==NULL){
        //allocation failed
        return false;
    }
    new_edge->weight = weight;
    new_edge->endpoint = endpoint;
    new_edge->next = NULL;
    return true;
}

void print_edge(pedge head){
    pedge current = head;
    while(current != NULL){
        printf("%d" , current->endpoint->node_num);
        printf("%d", current->weight);
        current = current->next;
    }
}


