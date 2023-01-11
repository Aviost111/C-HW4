#include <stdio.h>
#include "nodes.h"
#include "graph.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool findNode(pnode head){

}
bool create_node(int node_num)
{
    pnode new_node = (pnode)malloc(sizeof(node));
    if (new_node == NULL)
    {
        // allocation failed
        return false;
    }
    new_node->node_num = node_num;
    new_node->edges = NULL;
    new_node->next = NULL;
    return true;
}

void print_node(pnode head)
{
    printf("node_num: %d\n", head->node_num);
    printf("edges: ");
    while (head->edges != NULL)
    {
        
        head->edges = head->edges->next;
    }
    printf("\n");
    while (head->next != NULL)
    {
        printf("%d ", head->next->node_num);
        head->next = head->next->next;
    }
}