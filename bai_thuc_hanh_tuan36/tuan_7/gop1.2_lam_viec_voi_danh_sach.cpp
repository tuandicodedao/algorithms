#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai bao cau truc du lieu cho danh sach lien ket don
struct SinhVien {
    int MSSV;
    char hoTen[100];
    char hocPhan[100];
    float diem;
    struct SinhVien* next;
};

// Toa mot nut sinh vien moi
struct SinhVien* createNode(int MSSV, const char* hoTen, const char* hocPhan, float diem) {
    struct SinhVien* newNode = (struct SinhVien*)malloc(sizeof(struct SinhVien));
    newNode->MSSV = MSSV;
    strcpy(newNode->hoTen, hoTen);
    strcpy(newNode->hocPhan, hocPhan);
    newNode->diem = diem;
    newNode->next = NULL;
    return newNode;
}

// ham them mot sinh vien vao danh sach
void addNode(struct SinhVien** head, int MSSV, const char* hoTen, const char* hocPhan, float diem) {
    struct SinhVien* newNode = createNode(MSSV, hoTen, hocPhan, diem);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct SinhVien* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Da them sinh vien vao danh sach.\n");
}

// Ham sua thong tin cua mot sinh vien trong danh sach
void updateNode(struct SinhVien* head, int MSSV, const char* hoTen, const char* hocPhan, float diem) {
    struct SinhVien* temp = head;
    while (temp != NULL) {
        if (temp->MSSV == MSSV) {
            strcpy(temp->hoTen, hoTen);
            strcpy(temp->hocPhan, hocPhan);
            temp->diem = diem;
            printf("Da sua thong tin sinh vien co MSSV %d.\n", MSSV);
            return;
        }
        temp = temp->next;
    }
    printf("Khong tim thay sinh vien co MSSV %d.\n", MSSV);
}

// ham xoa mot sinh vien ra khoi danh sach
void deleteNode(struct SinhVien** head, int MSSV) {
    struct SinhVien* temp = *head;
    struct SinhVien* prev = NULL;
    if (temp != NULL && temp->MSSV == MSSV) {
        *head = temp->next;
        free(temp);
        printf("Da xoa sinh vien co MSSV %d.\n", MSSV);
        return;
    }
    while (temp != NULL && temp->MSSV != MSSV) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim thay sinh vien co MSSV %d.\n", MSSV);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Da xoa sinh vien co MSSV %d.\n", MSSV);
}

// Ham tim kiem 1 sinh vien trong danh sach
void searchNode(struct SinhVien* head, int MSSV) {
    struct SinhVien* temp = head;
    while (temp != NULL) {
        if (temp->MSSV == MSSV) {
            printf("Thong tin sinh vien co MSSV %d:\n", MSSV);
            printf("Ho ten: %s\n", temp->hoTen);
            printf("Hoc phan: %s\n", temp->hocPhan);
            printf("Diem: %.2f\n", temp->diem);
            return;
        }
        temp = temp->next;
    }
    printf("Khong tim thay sinh vien co MSSV %d.\n", MSSV);
}

// Ham hien thi danh sach sinh vien
void displayList(struct SinhVien* head) {
    if (head == NULL) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        printf("Danh sach sinh vien:\n");
        struct SinhVien* temp = head;
        while (temp != NULL) {
            printf("MSSV: %d\n", temp->MSSV);
            printf("Ho ten: %s\n", temp->hoTen);
            printf("Hoc phan: %s\n", temp->hocPhan);
            printf("Diem: %.2f\n", temp->diem);
            printf("------------------------\n");
            temp = temp->next;
        }
    }
}

// Ham giai phong bo nho cap phat
void freeList(struct SinhVien** head) {
    struct SinhVien* temp = *head;
    while (temp != NULL) {
        struct SinhVien* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    printf("Da giai phong bo nho.\n");
}

int main() {
    struct SinhVien* head = NULL;

    int choice, MSSV;
    char hoTen[50], hocPhan[50];
    float diem;

    while (1) {
        printf("\n---- MENU ----\n");
        printf("1. Them sinh vien\n");
        printf("2. Sua thong tin sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Tim kiem sinh vien\n");
        printf("5. Hien thi danh sach sinh vien\n");
        printf("6. Giai phong bo nho\n");
        printf("0. Thoat chuong trinh\n");
        printf("---------------\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap MSSV: ");
                scanf("%d", &MSSV);
                printf("Nhap ho ten: ");
                scanf(" %[^\n]s", hoTen);
                printf("Nhap hoc phan: ");
                scanf(" %[^\n]s", hocPhan);
                printf("Nhap diem: ");
                scanf("%f", &diem);
                addNode(&head, MSSV, hoTen, hocPhan, diem);
                break;
            case 2:
                printf("Nhap MSSV can sua: ");
                scanf("%d", &MSSV);
                printf("Nhap ho ten moi: ");
                scanf(" %[^\n]s", hoTen);
                printf("Nhap hoc phan moi: ");
                scanf(" %[^\n]s", hocPhan);
                printf("Nhap diem moi: ");
                scanf("%f", &diem);
                updateNode(head, MSSV, hoTen, hocPhan, diem);
                break;
            case 3:
                printf("Nhap MSSV can xoa: ");
                scanf("%d", &MSSV);
                deleteNode(&head, MSSV);
                break;
            case 4:
                printf("Nhap MSSV can tim kiem: ");
                scanf("%d", &MSSV);
                searchNode(head, MSSV);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                freeList(&head);
                break;
            case 0:
                freeList(&head);
                printf("Chuong trinh da ket thuc.\n");
                return 0;
            default:
                printf("Lua chon khong hop le.\n");
        }
    }

    return 0;
}

