#include <stdio.h>
#include "queue.h"
#include <stdlib.h>


ptuple create_tuple(node Node, int priority) {
    ptuple Tuple = (ptuple) malloc(sizeof(tuple));
    if (Tuple == NULL) {
        printf("error no room");
        return NULL;
    }
    Tuple->Node = Node;
    Tuple->priority = priority;
    return Tuple;
}

pqueue create_queue(int size) {
    pqueue myQueue = (pqueue) malloc(sizeof(queue));
    if (myQueue == NULL) {
        printf("error no room");
        return NULL;
    }
    myQueue->front = -1;
    myQueue->rear = -1;
    myQueue->origional_size = size;
    myQueue->size = 0;
    myQueue->Queue = (ptuple*) malloc(sizeof(tuple*) * size);
    if (myQueue->Queue == NULL) {
        printf("error no room");
        free(myQueue);
        return NULL;
    }
    return myQueue;
}

//void adjust(pqueue myQueue) {
//    pnode dest = (pnode) malloc(sizeof(node) * myQueue->origional_size);
//    for (int i = 0; i < myQueue->size; ++i) {
//        dest[i] = myQueue->Queue[myQueue->front + i];
//    }
//    free(myQueue->Queue);
//    myQueue->Queue = dest;
//    myQueue->front = 0;
//    myQueue->rear = myQueue->size - 1;
//}

void add(pqueue myQueue, tuple myTuple) {
    int index;
    if (myQueue->front == -1) {
        myQueue->front = 0;
        myQueue->rear = 0;
        myQueue->Queue[0] = myTuple;
        myQueue->size = 1;
    } else if (myQueue->size < myQueue->origional_size) {
        for (int i = 0; i <myQueue->size; ++i) {
            if(myQueue->Queue[i].priority>=myTuple.priority){
                index=i;
                break;
            }
        }
        ptuple newQueue=(ptuple) malloc(sizeof(tuple)*myQueue->origional_size);int k=0;
        for (int i = 0; i < myQueue->size; ++i) {
            if(k==index){
                newQueue[k]=myTuple;
                k++;
            }
            //do we have to make sure to free every instance in old arr?
            newQueue[k] = myQueue->Queue[myQueue->front + i];
            k++;
        }
        for (int i = 0; i <myQueue->front ; ++i) {
            free(&(myQueue->Queue[i]));

        }
        free(myQueue->Queue);
        myQueue->size++;
        myQueue->Queue = newQueue;
        myQueue->front = 0;
        myQueue->rear = myQueue->size - 1;
    } else {
        printf("queue is full");
    }
}

pnode poll(pqueue myQueue) {
    if (myQueue->front == -1) {
        printf("queue is empty already");
        return NULL;
    }
    node ans = myQueue->Queue[0].Node;
    pnode fullAns = &ans;
    ptuple myTuple;
    myQueue->front++;
    myQueue->size--;
    if (myQueue->front > myQueue->rear) {
        myQueue->rear = -1;
        myQueue->front = -1;
    }
    return fullAns;
}

bool isEmpty(pqueue myQueue) {
    if (myQueue->size == 0) {
        return true;
    }
    return false;
}

