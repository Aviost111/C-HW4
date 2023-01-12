#include <stdio.h>
#include "nodes.h"
#include "graph.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool findNode(pnode *head, int find_num)
{
    pnode curr = *head;
    pnode prev=NULL;
    while (curr != NULL)
    {

        if (curr->node_num == find_num)
        {
            **head = *curr;
            return true;
        }
        *prev=*curr;
        curr = curr->next;
    }
    **head= *prev;
    return false;
}
bool create_node(pnode *newNode)
{
    pnode new_node;
    new_node = (pnode)malloc(sizeof(node));
    if (new_node == NULL)
    {
        // allocation failed
        return false;
    }
    // TODO is good to leave as 0?
    new_node->node_num = 0;
    new_node->edges = NULL;
    new_node->next = NULL;
    *newNode = new_node;
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