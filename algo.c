#include "graph.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void build_graph_cmd(pnode *head) {
    int numberOfNodes = 0;
    pnode pNode = NULL;
    pedge pEdge=NULL;
    char input;
    int inputNum,inputNum2;
//    char newNode = NULL;

    scanf("%d", &numberOfNodes);
    if(numberOfNodes==0){
        return;
    }
    *head = (pnode) malloc(sizeof(node));
    if (pNode == NULL) { // allocation failed
        printf("error");
        exit(0);
    }
    input = getchar();
    pNode=*head;
    for (int i = 0; i < numberOfNodes; i++) {
        scanf("%d", &inputNum);
        pNode->node_num=inputNum;
        if(scanf("%d%d", &inputNum,&inputNum2) == 2){
            pNode->edges= (pedge)malloc(sizeof (edge));
            pEdge=pNode->edges;
            pEdge->weight=inputNum2;

        }
        while (scanf("%d%d", &inputNum,&inputNum2) == 2) {

        }
        head = (pnode * )malloc(sizeof(node));



}

void delete_node_cmd(pnode *head) {
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