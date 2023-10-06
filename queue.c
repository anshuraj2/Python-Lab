#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

struct CircularQueue {
    int data[MAX_SIZE];
    int front, rear;
};

void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

void initializeCircularQueue(struct CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

int isFullCircular(struct CircularQueue *queue) {
    return ((queue->rear + 1) == queue->front);
}

int isEmpty(struct Queue *queue) {
    return (queue->front == -1);
}

int isEmptyCircular(struct CircularQueue *queue) {
    return (queue->front == -1);
}

void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->data[queue->rear] = value;
}

void enqueueCircular(struct CircularQueue *queue, int value) {
    if (isFullCircular(queue)) {
        printf("Circular Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmptyCircular(queue)) {
        queue->front = queue->rear = 0;
    } else if(queue->rear == MAX_SIZE)
    {
        queue->rear = 1;
    }
    else
        queue->rear++;
    queue->data[queue->rear] = value;
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return value;
}

int dequeueCircular(struct CircularQueue *queue) {
    if (isEmptyCircular(queue)) {
        printf("Circular Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return value;
}

void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

void displayCircular(struct CircularQueue *queue) {
    if (isEmptyCircular(queue)) {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = queue->front;
    do {
        printf("%d ", queue->data[i]);
        i++;
    } while (i != (queue->rear + 1));
    printf("\n");
}

int main() {
    struct Queue queue;
    struct CircularQueue cqueue;
    initializeQueue(&queue);
    initializeCircularQueue(&cqueue);

    int choice, value, position;

    do{
        printf("\n1. Enqueue in Queue\n");
        printf("2. Dequeue from Queue\n");
        printf("3. Enqueue in Circular Queue\n");
        printf("4. Dequeue from Circular Queue\n");
        printf("5. Display Queue\n");
        printf("6. Display Circular Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue(&queue));
                break;
            case 3:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueueCircular(&cqueue, value);
                break;
            case 4:
                printf("Dequeued element: %d\n", dequeueCircular(&cqueue));
                break;
            case 5:
                display(&queue);
                break;
            case 6:
                displayCircular(&cqueue);
                break;
            case 7:
                printf("Exited!!!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 7);

    return 0;
}