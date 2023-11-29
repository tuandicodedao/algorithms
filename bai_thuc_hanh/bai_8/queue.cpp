#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    char name[100];
    char ip[20];
    char content[200];
    time_t timestamp;
} Request;

typedef struct {
    Request data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isQueueFull(Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(Queue* queue, Request request) {
    if (isQueueFull(queue)) {
        printf("Hang doi da day!\n");
        return;
    }

    if (isQueueEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->data[queue->rear] = request;
}

Request dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Hang doi rong!\n");
        exit(1);
    }

    Request request = queue->data[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return request;
}

void processRequest(Request request) {
    printf("Yeu cau: %s\n", request.name);
    printf("Tu dia chi IP: %s\n", request.ip);
    printf("Noi dung: %s\n", request.content);
    printf("Thoi gian thuc hien: %s\n", ctime(&request.timestamp));
    printf("----------------------------\n");
}

int main() {
    Queue requestQueue;
    initializeQueue(&requestQueue);

    char choice;
    do {
        printf("\n===== MO PHONG HANG DOI SERVER =====\n");
        printf("1. Them yeu cau moi\n");
        printf("2. Xu ly yeu cau\n");
        printf("3. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': {
                Request newRequest;
                printf("Nhap ten yeu cau: ");
                scanf("%s", newRequest.name);
                printf("Nhap dia chi IP: ");
                scanf("%s", newRequest.ip);
                printf("Nhap noi dung: ");
                scanf("%s", newRequest.content);
                newRequest.timestamp = time(NULL);

                enqueue(&requestQueue, newRequest);
                printf("Them yeu cau vao hang doi thanh cong!\n");
                break;
            }
            case '2': {
                if (!isQueueEmpty(&requestQueue)) {
                    Request processedRequest = dequeue(&requestQueue);
                    processRequest(processedRequest);
                } else {
                    printf("Hang doi rong, khong co yeu cau nao de xu ly!\n");
                }
                break;
            }
            case '3':
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
                break;
        }
    } while (choice != '3');

    return 0;
}

