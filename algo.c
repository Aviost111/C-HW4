#include "graph.h"
#include "nodes.h"
#include "edges.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


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
            pNode=temp;
            pNode->node_num = inputNum;
        }
        pNode = temp;
        if(pNode->node_num==0) {
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

void insert_node_cmd(pnode *head) {
    int node_num = getchar();
    pnode pnew_node = *head;
    if (findNode(&pnew_node, node_num)) {
    } else { // node doesn't exsits
        pnew_node = NULL;
        create_node(&pnew_node);
        pnew_node->node_num = node_num;
//        do
//        {
//        } while (/* condition */){
//
//        }

    }
}
