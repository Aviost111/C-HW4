#include "graph.h"
#include <stdio.h>

int main() {
    char option = 0;
    pnode head = NULL;

    while (scanf(" %c", &option) != EOF) {
        switch (option) {
            case 'A':
                deleteGraph_cmd(&head);
                head = NULL;
                build_graph_cmd(&head);
                break;
            case 'B':
                insert_node_cmd(&head);
                break;

            case 'D':
                delete_node_cmd(&head);
                break;

            case 'S':
                shortsPath_cmd(head);
                break;

            case 'T':
                TSP_cmd(head);
                break;

            default:
                break;
        }

    }
    deleteGraph_cmd(&head);
    return 0;
}