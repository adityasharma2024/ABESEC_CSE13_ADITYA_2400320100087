#include <stdio.h>
#include <stdlib.h>

#define SIZE 5   // Maximum size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert an element (Enqueue)
void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) {
            front = rear = 0; // First insertion
        } else {
            rear = (rear + 1) % SIZE;
        }
        queue[rear] = value;
        printf("%d inserted into the circular queue.\n", value);
    }
}

// Function to delete an element (Dequeue)
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! No elements to delete.\n");
    } else {
        printf("%d deleted from the circular queue.\n", queue[front]);
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

// Function to view the front element (Peek)
void peek() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

// Function to display the queue
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Circular Queue elements are: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
