#include <stdio.h>
#include "nodes.h"
#include "graph.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool findNode(pnode *head, int find_num) {
    pnode curr = *head;
    pnode prev = NULL;
    while (curr != NULL) {

        if (curr->node_num == find_num) {
            *head = curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    *head = prev;
    return false;
}

bool create_node(pnode *newNode) {
    pnode new_node = NULL;
    new_node = (pnode) malloc(sizeof(node));
    if (new_node == NULL) {
        // allocation failed
        return false;
    }
    new_node->node_num = 0;
    new_node->edges = NULL;
    new_node->next = NULL;
    new_node->distance=INT_MAX;
    new_node->visited=false;
    *newNode = new_node;
    return true;
}

void print_node(pnode head) {
    printf("node_num: %d\n", head->node_num);
    printf("edges: ");
    while (head->edges != NULL) {
        head->edges = head->edges->next;
    }
    printf("\n");
    while (head->next != NULL) {
        printf("%d ", head->next->node_num);
        head->next = head->next->next;
    }
}

pnode get_node(pnode *head, int node_num) {
    if (head == NULL) {
        return NULL;
    }
    pnode currNode = *head;
    while ((currNode != NULL) && (currNode->node_num != node_num)) {
        currNode = currNode->next;
    }
    return currNode;
}

pnode get_prev_node(pnode *head, int node_num) {
    if (head == NULL) {
        return NULL;
    }
    pnode prevNode = NULL;
    pnode currNode = *head;
    while (currNode != NULL) {
        if (currNode->node_num == node_num) {
            return prevNode;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
    return NULL;
}

/**
 *
 * @param head pointer to the head of the linked list
 * @return pnode pointer to the last node in the list
 *
 * It starts at the head of the list and uses a while loop to iterate through the list until it reaches the last node.
 * It returns a pointer to the last node.
 */
pnode get_last_node(pnode *head) {
    pnode last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    return last;
}

int num_of_nodes(pnode head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

