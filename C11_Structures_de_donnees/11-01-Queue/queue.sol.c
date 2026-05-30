#include "queue.sol.h"
#include <assert.h>
#include <stdlib.h>

struct node {
    struct node *nxt;
    int val;
};

struct queue {
    struct node *front;
    struct node *back;
    int size;
};

void *new_queue() {
    struct queue *q = malloc(sizeof(struct queue));
    q->front = q->back = NULL;
    q->size = 0;
    return q;
}

void free_queue(void *_q) {
    while (size_of_queue(_q))
        pop_from_queue(_q);
    free(_q);
}

void push_in_queue(void *_q, int i) {
    // push_back()
    struct queue *q = (struct queue *) _q;
    struct node *n = malloc(sizeof(struct node));
    n->nxt = NULL;
    n->val = i;
    if (q->front == NULL)
        q->front = n;
    if (q->back != NULL)
        q->back->nxt = n;
    q->back = n;
    q->size++;
}

void pop_from_queue(void *_q) {
    // pop_front()
    assert(size_of_queue(_q));
    struct queue *q = (struct queue *) _q;
    struct node *n = q->front;
    q->front = q->front->nxt;
    q->size--;
    if (q->size == 0)
        q->back = NULL;
    free(n);
}

int front_of_queue(void *_q) {
    assert(size_of_queue(_q));
    struct queue *q = (struct queue *) _q;
    return q->front->val;
}

int back_of_queue(void *_q) {
    assert(size_of_queue(_q));
    struct queue *q = (struct queue *) _q;
    return q->back->val;
}

int size_of_queue(void *_q) {
    struct queue *q = (struct queue *) _q;
    return q ? q->size : 0;
}
