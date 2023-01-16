#include "graph.h"
#include "nodes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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
void delete_outgoing_edges(pnode current_node) {
    pedge edge_head = current_node->edges;
    while (edge_head != NULL) {
        pedge temp = edge_head->next;
        free(edge_head);
        edge_head = temp;
    }
    current_node->edges = NULL;
}


/**
 * delete all the ingoing edges of a node.
 *
 * @param head pointer to the head of the linked list of nodes
 * @param current_node pointer to the node whose ingoing edges will be deleted
 *
 * This function takes a pointer to the head of the linked list of nodes, and a pointer to a node,
 * and deletes all the edges that go into that node.
 * It starts at the head of the linked list of nodes and uses a while loop to iterate through the list,
 * for each node it checks the edges, it compares the endpoint of the edge with the current_node.
 * If they are the same, it removes the edge by updating the pointers and freeing the memory allocated for the edge.
 *
 */
void delete_ingoing_edges(pnode head, pnode current_node) {
    pnode temp = head;
    while (temp != NULL) {
        pedge prev = NULL;
        pedge current = temp->edges;
        while (current != NULL) {
            if (current->endpoint == current_node) {
                if (prev == NULL) {
                    temp->edges = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                break;
            }
            prev = current;
            current = current->next;
        }
        temp = temp->next;
    }
}