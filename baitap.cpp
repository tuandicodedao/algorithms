#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};


struct Node* createNode(float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertNode(struct Node** head, float value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;

        
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }
}


void printList(struct Node* head) {
    struct Node* current = head;

    printf("Danh sach: ");

    while (current != NULL) {
        printf("%.2f ", current->data);
        current = current->next;
    }

    printf("\n");
}


float calculateAverage(struct Node* head) {
    struct Node* current = head;
    float sum = 0;
    int count = 0;

    while (current != NULL) {
        sum += current->data;
        count++;
        current = current->next;
    }

    if (count == 0) {
        return 0;
    }

    return sum / count;
}

float findMax(struct Node* head) {
    struct Node* current = head;
    float max = current->data;

    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }

    return max;
}


void deleteNode(struct Node** head, float value) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    if (current != NULL && current->data == value) {
        *head = current->next;
        free(current);
        return;
    }

    
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    
    if (current == NULL) {
        printf("Khong tim thay phan tu co gia tri %.2f\n", value);
        return;
    }

    prev->next = current->next;
    free(current);
}

void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main() {
    struct Node* head = NULL;

    
    insertNode(&head, 5.2);
    insertNode(&head, 3.7);
    insertNode(&head, 7.1);
    insertNode(&head, 2.4);

    
    printList(head);

    float average = calculateAverage(head);
    printf("Trung binh cac phan tu: %.2f\n", average);

    
    float max = findMax(head);
    printf("Phan tu co gia tri lon nhat: %.2f\n", max);

    
    deleteNode(&head, 7.1);
    printf("Danh sach sau khi xoa: ");
    printList(head);

    
    deleteList(&head);

    return 0;
}

