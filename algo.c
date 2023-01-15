#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.h"
#include "nodes.h"
#include "edges.h"
#include <limits.h>

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
    for (int i = 0; i < numberOfNodes; i++) {
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
    if (*head == NULL) {
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
    *head = NULL;
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


/***
 * Find minimum between two numbers.
 */
int min(int num1, int num2) {
    return (num1 >= num2) ? num2 : num1;
}

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

/***

reverse
@param permutation pointer to an array of integers representing the current permutation
@param start_index starting index of the subarray to be reversed
@param size size of the permutation array
This function takes a permutation array and a starting index, it then starts swapping the elements in the subarray starting from the start_index till the end of the array
thus reversing the subarray.
*/
void reverse(int *permutation, int start_index, int size) {
    int i = start_index;
    int j = size - 1;
    while (i < j) {
        swap(&permutation[i], &permutation[j]);
        i++;
        j--;
    }
}

int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}
/***
* next_permutation - function that generates the next lexicographically greater permutation of a given permutation array
* @permutation: pointer to an integer array that represents the current permutation
* @size: size of the permutation array
*
* The function first finds the rightmost element in the permutation array that is smaller than its successor.
* If it cannot find such element, the permutation is the last permutation (i.e. the array is sorted in descending order)
* and the function returns false indicating that there is no next permutation.
* Otherwise, the function finds the rightmost element in the array that is greater than the previously found element
* and swaps it with the latter.
* Then, the function reverses the order of the elements that come after the previously found element
* to get the lexicographically smallest permutation that is greater than the current one.
* The function returns true to indicate that a next permutation has been generated.
*/

bool next_permutation(int *permutation, int size) {
    int i = size - 2;
    while (i >= 0 && permutation[i] >= permutation[i + 1]) {
        i--;
    }
    if (i == -1) {
        return false;
    }
    int j = size - 1;
    while (permutation[j] <= permutation[i]) {
        j--;
    }
    swap(&permutation[i], &permutation[j]);
    reverse(permutation, i + 1, size);
    return true;
}

// Function to find the node with the smallest distance
// that hasn't been visited yet
pnode poll(pnode head) {
    pnode min_node = NULL;
    int shortest_distance = INT_MAX;
    pnode current = head;
    while (current != NULL) {
        if (!current->visited && current->distance < shortest_distance) {
            shortest_distance = current->distance;
            min_node = current;
        }
        current = current->next;
    }
    return min_node;
}

// Function to initialize the graph for Dijkstra's algorithm
void initialize(pnode head, int start_node) {
    pnode current = head;
    while (current != NULL) {
        current->distance = INT_MAX;
        current->visited = false;
        current = current->next;
    }
    pnode start = get_node(&head, start_node);
    start->distance = 0;
}

// Dijkstra's shortest path algorithm
int dijkstra_algorithm(pnode head, int start, int dest) {
    int distance;
    pnode min_node = NULL, adj = NULL, end = NULL;
    pedge current_edge = NULL;
    initialize(head, start);

    while (true) {
        min_node = poll(head);
        if (min_node == NULL) {
            break;
        }
        min_node->visited = true;
        adj = NULL;
        current_edge = min_node->edges;
        while (current_edge != NULL) {
            adj = current_edge->endpoint;
            if (!adj->visited) {
                distance = current_edge->weight;
                if (min_node->distance + distance < adj->distance) {
                    adj->distance = min_node->distance + distance;
                }
            }
            current_edge = current_edge->next;
        }
    }

    end = get_node(&head, dest);
    return end->distance;
}

void shortsPath_cmd(pnode head) {
    int start, dest, ans;
    if (scanf("%d%d", &start, &dest) != 2) {
        printf("problem with input");
        return;
    }
    ans = dijkstra_algorithm(head, start, dest);
    //TODO if problem check space after ans
    printf("Dijsktra shortest path: %d \n", ans);
}

void TSP_cmd(pnode head) {
    int size,dijkAns;
    scanf("%d", &size);
//    int *permutation=(int*) malloc(sizeof(int)*size);
    int permutation[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &permutation[i]);
    }
    qsort(permutation, size, sizeof(int), compare);
    int min_path = INT_MAX;

    do {
        int current_path_weight = 0;
        for (int i = 0; i < size - 1; i++) {
            dijkAns = dijkstra_algorithm(head, permutation[i], permutation[i + 1]);
            if(dijkAns==INT_MAX){
                current_path_weight=INT_MAX;
                break;
            }
            current_path_weight+=dijkAns;

        }
        min_path = min(min_path, current_path_weight);

    } while (next_permutation(permutation, size));

    if (min_path != INT_MAX) { //TODO change when you know what Dijkstra return.
        printf("TSP shortest path: %d \n", min_path);
    } else printf("TSP shortest path: -1 \n");
}
