#include "graph.h"
#include "nodes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool create_edge(pedge *head, int weight, int endpoint, pnode realHead) {
    pnode pNode = realHead;
    pedge new_edge = (pedge) malloc(sizeof(edge));
    if (new_edge == NULL) {
        // allocation failed
        return false;
    }
    new_edge->weight = weight;
    if (!findNode(&pNode, endpoint)) {
        printf("error finding node in create edge");
        return false;
    }
    new_edge->endpoint = pNode;
    new_edge->next = NULL;
    *head = new_edge;
    return true;
}

bool createEdge(pnode from, pnode to, int weight) {
    pedge new_edge = (pedge) malloc(sizeof(edge));
    if (new_edge == NULL) {
        // allocation failed
        return false;
    }
    new_edge->weight = weight;
    new_edge->endpoint = to;
    new_edge->next = NULL;
    if (from->edges == NULL) {
        // If the from node doesn't have any edges yet
        from->edges = new_edge;
    } else {
        //add the new edge to the end of the list
        pedge current = from->edges;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_edge;
    }
    return true;
}


void print_edge(pedge *head) {
    pedge current = *head;
    while (current != NULL) {
        printf("%d ", current->endpoint->node_num);
        printf("%d", current->weight);
        current = current->next;
    }
}
/**
* delete all the outgoing edges of a node.
*
* @param current_node pointer to the node whose outgoing edges will be deleted
*
* This function takes a pointer to a node, and deletes all the edges that go out of that node.
* It starts at the head of the linked list of edges and uses a while loop to iterate through the list,
* it updates the pointer of current edge and frees the memory allocated for the current edge.
*
*/
void delete_outgoing_edge(pnode current_node) {
    pedge edge_head = current_node->edges;
    while (edge_head->next != NULL) {
        pedge temp = edge_head;
        edge_head = edge_head->next;
        free(temp);
    }
    current_node->edges = NULL;
}
