#include <stdio.h>
#include "nodes.h"
#include "graph.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 32767

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
    new_node->index = -1;
    new_node->edges = NULL;
    new_node->next = NULL;
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

int *all_nodes(pnode head, int start) {
    int n = num_of_nodes(head);
    int *arr = (int *) malloc(sizeof(int) * n);
    arr[0] = start;
    for (int i = 1; i < n; ++i) {
        if (head->node_num == start) {
            head->index = 0;
            head = head->next;
        }
        arr[i] = head->node_num;
        head->index = i;
        head = head->next;
    }
    return arr;
}

int **make_int_dijk_mat(pnode head, int start) {
    int *nodes = all_nodes(head, start);
    int rows = num_of_nodes(head), cols = 4;
    int **mat = (int **) malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; ++i) {
        mat[i] = (int *) malloc(sizeof(int) * cols);
        if (i == 0) {
            mat[0][0] = start;
            mat[0][1] = 0;
            mat[0][2] = -1;
            mat[0][3] = 0;

        } else {
            //node name
            mat[i][0] = nodes[i];
            //dist
            mat[i][1] = INF;
            //previous node for dist
            mat[i][2] = -1;
            //visited
            mat[i][3] = 0;
        }
    }
    free(nodes);
    return mat;
}
