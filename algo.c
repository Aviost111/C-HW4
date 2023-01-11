#include "graph.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void build_graph_cmd(pnode *head)
{
    int numberOfNodes = 0;
    pnode pNode = NULL;
    char newNode = NULL;

    // scanf("%d", &numberOfNodes);
    // pNode = (pnode)malloc(numberOfNodes * sizeof(node));
    // if (pNode == NULL)
    // { // allocation failed
    //     exit(0);
    // }
    // for(int i = 0; i < numberOfNodes ;i++){
    //       if (newNode == 'n')
    //     {
    //         int nodeNum = 0;
    //         scanf("%d", &newNode);
    //         pNode -> node_num = newNode;


    //     }


    // }
    
      
    
}

void delete_node_cmd(pnode *head)
{
}

void deleteGraph_cmd(pnode *head)
{
    if (head == NULL)
    {
        return;
    }
    pnode currNode = head;
    pnode nextNode;

    while (currNode != NULL)
    {
        pedge currEdge = currNode->edges;
        pedge nextEdge = NULL;
        while (currEdge != NULL)
        {
            nextEdge = currEdge->next;
            free(currEdge);
            currEdge = nextEdge;
        }
        nextNode = currNode->next;
        free(currNode);
        currNode = nextNode;
    }
}