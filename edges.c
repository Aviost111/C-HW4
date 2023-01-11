#include "graph.h"
#include "nodes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool create_edge(pedge *head,int weight, int endpoint){
    pedge new_edge = (pedge)malloc(sizeof(edge));
    pnode pNode=NULL;
    if(new_edge ==NULL){
        //allocation failed
        return false;
    }
    new_edge->weight = weight;
    if(!findNode(&pNode,endpoint)){
        printf("error finding node in create edge");
        return false;
        exit(0);
    }
    new_edge->endpoint = pNode;
    new_edge->next = NULL;
    *head=new_edge;
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


