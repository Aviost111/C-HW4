//
// Created by noa on 1/15/23.
//

/***
 * Find minimum between two numbers.
 */
int min(int num1, int num2) {
    return (num1 > num2) ? num2 : num1;
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

void TSP_cmd(pnode head) {
    int size;
    int count = 0;
    scanf("%d", &size);
    int permutation[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &permutation[i]);
    }
    qsort(permutation, size, sizeof(int), compare);
    int min_path = INT_MAX;

    do {
        int current_path_weight = 0;
        for (int i = 0; i < size - 1; i++) {
            pnode from = get_node(&head, permutation[i]);
            pnode to = get_node(&head, permutation[i + 1]);
            current_path_weight += get_edge_weight(from, to); //TODO Dijkstra
            count++;
        }
        pnode from = get_node(&head, permutation[size - 1]);
        pnode to = get_node(&head, permutation[0]);
        current_path_weight += get_edge_weight(from, to); //TODO Dijkstra
        min_path = min(min_path, current_path_weight);

    } while (next_permutation(permutation, size));

    if (min_path != INT_MAX) { //TODO change when you know what Dijkstra return.
        printf("TSP shortest path: %d", min_path);
    } else printf("TSP shortest path: -1 ");
    printf("%d",count);
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 1000

// Node structure for a graph
typedef struct node {
    int node_num;
    int distance;
    bool visited;
    struct edge *edges;
    struct node *next;
} node;

// Edge structure for a graph
typedef struct edge {
    int weight;
    struct node *endpoint;
    struct edge *next;
} edge;

// Function to find the node with the smallest distance
// that hasn't been visited yet
node* find_smallest_distance_node(node *head) {
    node *smallest_node = NULL;
    int smallest_distance = INT_MAX;
    node *current = head;
    while (current != NULL) {
        if (!current->visited && current->distance < smallest_distance) {
            smallest_distance = current->distance;
            smallest_node = current;
        }
        current = current->next;
    }
    return smallest_node;
}

// Function to initialize the graph for Dijkstra's algorithm
void initialize_graph(node *head, int start_node) {
    node *current = head;
    while (current != NULL) {
        current->distance = INT_MAX;
        current->visited = false;
        current = current->next;
    }
    node *start = get_node(head, start_node);
    start->distance = 0;
}

// Dijkstra's shortest path algorithm
void dijkstra(node *head, int start_node, int end_node) {
    initialize_graph(head, start_node);

    while (true) {
        node *smallest_node = find_smallest_distance_node(head);
        if (smallest_node == NULL) {
            break;
        }
        smallest_node->visited = true;
        node *neighbor = head;
        edge *current_edge = smallest_node->edges;
        while (current_edge != NULL) {
            neighbor = current_edge->endpoint;
            if (!neighbor->visited) {
                int distance = current_edge->weight;
                if (smallest_node->distance + distance < neighbor->distance) {
                    neighbor->distance = smallest_node->distance + distance;
                }
            }
            current_edge = current_edge->next;
        }
    }

    node *end = get_node(head, end_node);
    printf("Shortest distance from node %d to node %d is %d", start_node, end_node, end->distance);
}
