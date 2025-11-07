#include <stdio.h>
#define MAX 10

int deque[MAX];
int front = -1, rear = -1;

void insert_front(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) return;
    if (front == -1) front = rear = 0;
    else if (front == 0) front = MAX - 1;
    else front--;
    deque[front] = x;
}

void insert_rear(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) return;
    if (front == -1) front = rear = 0;
    else if (rear == MAX - 1) rear = 0;
    else rear++;
    deque[rear] = x;
}

void delete_front() {
    if (front == -1) return;
    if (front == rear) front = rear = -1;
    else if (front == MAX - 1) front = 0;
    else front++;
}

void delete_rear() {
    if (front == -1) return;
    if (front == rear) front = rear = -1;
    else if (rear == 0) rear = MAX - 1;
    else rear--;
}

void display() {
    if (front == -1) return;
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    insert_rear(10);
    insert_rear(20);
    insert_front(5);
    display();
    delete_rear();
    display();
    delete_front();
    display();
    return 0;
}
