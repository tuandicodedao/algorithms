#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char buffer[MAX_SIZE];
    int cursor;
} Editor;

typedef struct {
    char action;
    char data;
} Operation;

typedef struct {
    Operation operations[MAX_SIZE];
    int count;
} UndoRedoStack;

Editor editor;
UndoRedoStack undoStack;
UndoRedoStack redoStack;

void initializeEditor() {
    memset(editor.buffer, 0, sizeof(editor.buffer));
    editor.cursor = 0;
}

void initializeUndoRedoStack(UndoRedoStack* stack) {
    stack->count = 0;
}

void pushOperation(UndoRedoStack* stack, char action, char data) {
    if (stack->count < MAX_SIZE) {
        stack->operations[stack->count].action = action;
        stack->operations[stack->count].data = data;
        stack->count++;
    }
}

Operation popOperation(UndoRedoStack* stack) {
    Operation operation;
    if (stack->count > 0) {
        operation = stack->operations[stack->count - 1];
        stack->count--;
    }
    return operation;
}

void performUndo() {
    Operation operation = popOperation(&undoStack);
    if (operation.action == 'I') {
        memmove(editor.buffer + editor.cursor - 1, editor.buffer + editor.cursor, strlen(editor.buffer + editor.cursor) + 1);
        editor.cursor--;
    } else if (operation.action == 'D') {
        memmove(editor.buffer + editor.cursor, editor.buffer + editor.cursor - 1, strlen(editor.buffer + editor.cursor - 1) + 1);
    }
    pushOperation(&redoStack, operation.action, operation.data);
}

void performRedo() {
    Operation operation = popOperation(&redoStack);
    if (operation.action == 'I') {
        memmove(editor.buffer + editor.cursor + 1, editor.buffer + editor.cursor, strlen(editor.buffer + editor.cursor) + 1);
        editor.buffer[editor.cursor] = operation.data;
        editor.cursor++;
    } else if (operation.action == 'D') {
        memmove(editor.buffer + editor.cursor - 1, editor.buffer + editor.cursor, strlen(editor.buffer + editor.cursor) + 1);
    }
    pushOperation(&undoStack, operation.action, operation.data);
}

void performInsert(char ch) {
    if (editor.cursor < MAX_SIZE - 1 && strlen(editor.buffer) < MAX_SIZE - 1) {
        memmove(editor.buffer + editor.cursor + 1, editor.buffer + editor.cursor, strlen(editor.buffer + editor.cursor) + 1);
        editor.buffer[editor.cursor] = ch;
        editor.cursor++;
        pushOperation(&undoStack, 'I', ch);
        initializeUndoRedoStack(&redoStack);
    } else {
        printf("Khong the chen them ky tu!\n");
    }
}

void performDelete() {
    if (editor.cursor > 0) {
        char deletedChar = editor.buffer[editor.cursor - 1];
        memmove(editor.buffer + editor.cursor - 1, editor.buffer + editor.cursor, strlen(editor.buffer + editor.cursor) + 1);
        editor.cursor--;
        pushOperation(&undoStack, 'D', deletedChar);
        initializeUndoRedoStack(&redoStack);
    } else {
        printf("Khong co ky tu nao de xoa!\n");
    }
}

void printEditor() {
    printf("Noi dung: %s\n", editor.buffer);
    printf("Con tro: %d\n", editor.cursor);
}

int main() {
    char choice;
    char ch;
    
    initializeEditor();
    initializeUndoRedoStack(&undoStack);
    initializeUndoRedoStack(&redoStack);
    
    do {
        printf("\n===== CHUONG TRINH SOAN THAO VAN BAN =====\n");
        printf("1. Chen ky tu\n");
        printf("2. Xoa ky tu\n");
        printf("3. Undo\n");
        printf("4. Redo\n");
        printf("5. In noi dung\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                printf("Nhap ky tu can chen: ");
                scanf(" %c", &ch);
                performInsert(ch);
                break;
            case '2':
                performDelete();
                break;
            case '3':
                performUndo();
                break;
            case '4':
                performRedo();
                break;
            case '5':
                printEditor();
                break;
            case '6':
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != '6');
    
    return 0;
}

