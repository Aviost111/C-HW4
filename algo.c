#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"
#include "nodes.h"
#include "edges.h"

//TODO  the function does not read the last n.
void build_graph_cmd(pnode *head) {
    int numberOfNodes = 0;
    pnode pNode = NULL, realHead = NULL, temp = NULL;
    pedge pEdge = NULL;
    char input;
    int inputNum, inputNum2;

    scanf("%d", &numberOfNodes);
    if (numberOfNodes == 0) {
        return;
    }
    //create the head node
    if (!create_node(head)) {
        printf("error");
        exit(0);
    }
    //pnode points to first node
//    pNode = *head;
    realHead = *head;
//    pEdge=&(pNode->edges);
    scanf(" %c", &input);
    for (int i = 1; i < numberOfNodes; i++) {
        //get and update node_num
        temp = realHead;
        scanf("%d", &inputNum);
        if ((!findNode(&temp, inputNum)) && (i != 1)) {
            //make it
            if (!create_node(&(temp->next))) {
                printf("error");
                exit(0);
            }
            temp = temp->next;
            pNode = temp;
            pNode->node_num = inputNum;
        }
        pNode = temp;
        if (pNode->node_num == 0) {
            pNode->node_num = inputNum;
        }
        pEdge = pNode->edges;
        //create all edges;
        while (scanf("%d%d", &inputNum, &inputNum2) == 2) {
            temp = realHead;
            //if it cant find the node ,create it.
            if (!findNode(&temp, inputNum)) {
                if (!create_node(&(temp->next))) {
                    printf("error");
                    exit(0);
                }
                temp = temp->next;
                temp->node_num = inputNum;
            }
            if (pNode->edges == NULL) {
                if (!create_edge(&(pNode->edges), inputNum2, inputNum, realHead)) {
                    printf("problem creating edge");
                    exit(0);
                }
                pEdge = pNode->edges;
            } else {
                if (!create_edge(&(pEdge->next), inputNum2, inputNum, realHead)) {
                    printf("problem creating edge");
                    exit(0);
                }
                pEdge = pEdge->next;
            }
        }

        if (i != numberOfNodes - 1) {
            scanf(" %c", &input);
        }
    }
}

/**
 * delete a node from the graph
 *
 * @param head pointer to the head of the linked list of nodes
 *
 * It first reads a node number from the user input. Then it uses the get_node function to find the node with the matching number in the linked list.
 * if it finds the node, it gets the previous node and updates the next pointer to skip the node that is going to be deleted.
 * Then it calls delete_outgoing_edges function to delete all the edges that go out of that node.
 * It also calls delete_ingoing_edges function to delete all the edges that go into that node.
 * Finally, it frees the memory allocated for the deleted node.
 *
 */
void delete_node_cmd(pnode *head) {
    int node_num;
    if (head == NULL) {
        return;
    }
    scanf("%d", &node_num);
    pnode delete_node = get_node(head, node_num);
    if (delete_node != NULL) {
        pnode prevNode = get_prev_node(head, node_num);
        if (prevNode != NULL) {
            prevNode->next = delete_node->next;
        } else {
            *head = delete_node->next;
        }
    }
    delete_outgoing_edges(delete_node);
    delete_ingoing_edges(*head, delete_node);
    free(delete_node);
}

void deleteGraph_cmd(pnode *head) {
    if (head == NULL) {
        return;
    }
    pnode currNode = *head;
    pnode nextNode;
    while (currNode != NULL) {
        pedge currEdge = currNode->edges;
        pedge nextEdge = NULL;
        while (currEdge != NULL) {
            nextEdge = currEdge->next;
            free(currEdge);
            currEdge = nextEdge;
        }
        nextNode = currNode->next;
        free(currNode);
        currNode = nextNode;
    }
}


/**
 * Insert a node into a linked list of nodes, and add edges to the node.
 *
 * @param head pointer to pointer to the head of the linked list
 *
 * It first reads an integer value as the node number.
 * Then it calls the get_node function to check if the node with the given number already exists in the list.
 * If the node already exists, it calls the delete_outgoing_edges function to remove any existing edges from the node,
 * and then it reads edge information (endpoint node number and weight) in a while loop.
 * For each edge, it calls the get_node function to get the endpoint node,
 * and the createEdge function to create an edge between the current node and the endpoint node with the given weight.
 *
 * If the node does not exist, it calls the get_last_node function to get the last node in the list,
 * creates a new node using create_node function, sets the node number for the new node,
 * and reads edge information in a similar way as above and creates edges for the new node.
 *
 */
void insert_node_cmd(pnode *head) {
    int node_num, end_point_node_num, node_weight;
    scanf("%d", &node_num);
    pnode currNode = get_node(head, node_num);

    if (currNode != NULL) { // node exist
        delete_outgoing_edges(currNode);
        while (scanf(" %d %d", &end_point_node_num, &node_weight) == 2) {
            pnode end_point = get_node(head, end_point_node_num);
            createEdge(currNode, end_point, node_weight);
        }
    } else { // node doesn't exist
        currNode = get_last_node(head);
        create_node(&currNode->next);
        currNode = currNode->next;
        currNode->node_num = node_num;
        while (scanf(" %d %d", &end_point_node_num, &node_weight) == 2) {
            pnode end_point = get_node(head, end_point_node_num);
            createEdge(currNode, end_point, node_weight);
        }
    }
}
