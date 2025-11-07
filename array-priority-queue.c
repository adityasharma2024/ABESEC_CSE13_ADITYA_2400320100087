#include <stdio.h>
#define MAX 100

struct PriorityQueue {
    int data[MAX];
    int priority[MAX];
    int size;
};

void enqueue(struct PriorityQueue *pq, int value, int p) {
    int i = pq->size++;
    while (i > 0 && p > pq->priority[i - 1]) {
        pq->data[i] = pq->data[i - 1];
        pq->priority[i] = pq->priority[i - 1];
        i--;
    }
    pq->data[i] = value;
    pq->priority[i] = p;
}

int dequeue(struct PriorityQueue *pq) {
    if (pq->size == 0) return -1;
    int val = pq->data[0];
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }
    pq->size--;
    return val;
}

void display(struct PriorityQueue pq) {
    for (int i = 0; i < pq.size; i++)
        printf("%d(%d) ", pq.data[i], pq.priority[i]);
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    pq.size = 0;
    enqueue(&pq, 10, 2);
    enqueue(&pq, 30, 3);
    enqueue(&pq, 20, 1);
    display(pq);
    printf("Dequeued: %d\n", dequeue(&pq));
    display(pq);
    return 0;
}
