#ifndef C_HW4_QUEUE_H
#define C_HW4_QUEUE_H
#include <stdbool.h>
#include "graph.h"

typedef struct QUEUE_TUPLE {
    node Node;
    int priority;
} tuple, *ptuple;

typedef struct QUEUE_ {
    int rear;
    int front;
    int size;
    int origional_size;
    ptuple Queue;
} queue, *pqueue;

ptuple create_tuple(node Node,int priority);
pqueue create_queue(int size);
void add(pqueue myQueue,tuple myTuple);
pnode poll(pqueue myQueue);
void adjust(pqueue myQueue);
bool isEmpty(pqueue myQueue);
#endif //C_HW4_QUEUE_H
