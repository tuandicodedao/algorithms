#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

Node* findMin(Node* node) {
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

int searchNode(Node* root, int key) {
    if (root == NULL) {
        return 0;
    }

    if (key == root->key) {
        return 1;
    }

    if (key < root->key) {
        return searchNode(root->left, key);
    } else {
        return searchNode(root->right, key);
    }
}

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int countLeft = countNodes(root->left);
    int countRight = countNodes(root->right);

    return 1 + countLeft + countRight;
}

void printTreeUtil(Node* root, int space) {
    // Kho?ng cách gi?a các c?p c?a cây
    int COUNT = 5;

    // Tru?ng h?p cây r?ng
    if (root == NULL) {
        return;
    }

    // Tang kho?ng cách gi?a các c?p c?a cây
    space += COUNT;

    // Ð? quy hi?n th? nút con bên ph?i
    printTreeUtil(root->right, space);

    // In ra nút hi?n t?i theo d?ng mô hình
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->key);

    // Ð? quy hi?n th? nút con bên trái
    printTreeUtil(root->left, space);
}

// Hi?n th? cây nh? phân du?i d?ng mô hình
void printTree(Node* root) {
    printTreeUtil(root, 0);
}

int main() {
    Node* root = NULL;
    int choice, key;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Them phan tu vao cay\n");
        printf("2. Xoa phan tu khoi cay\n");
        printf("3. Kiem tra phan tu trong cay\n");
        printf("4. Dem so phan tu cua cay\n");
        printf("5. Hien thi cay nhi phan\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri phan tu muon them: ");
                scanf("%d", &key);
                root = insertNode(root, key);
                printf("Da them phan tu vao cay.\n");
                break;
            case 2:
                printf("Nhap gia tri phan tu muon xoa: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Da xoa phan tu khoi cay.\n");
                break;
            case 3:
                printf("Nhap gia tri phan tu muon kiem tra: ");
                scanf("%d", &key);
                if (searchNode(root, key)) {
                    printf("Phan tu co trong cay.\n");
                } else {
                    printf("Phan tu khong co trong cay.\n");
                }
                break;
            case 4:
                printf("So phan tu cua cay: %d\n", countNodes(root));
                break;
            case 5:
                printf("Cay nhi phan: \n");
                printTree(root);
                printf("\n");
                break;
            case 6:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

