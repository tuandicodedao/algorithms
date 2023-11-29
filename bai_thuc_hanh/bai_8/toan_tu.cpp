#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    double data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, double value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("Ngan xep day!\n");
        exit(1);
    }
}

double pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    } else {
        printf("Ngan xep rong!\n");
        exit(1);
    }
}

double evaluatePostfixExpression(const char* expression) {
    Stack stack;
    initializeStack(&stack);

    int i = 0;
    while (expression[i] != '\0') {
        if (isdigit(expression[i])) {
            double operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            push(&stack, operand);
        } else if (expression[i] == ' ') {
            i++;
        } else {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            double result;
            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Phuong thuc toan khong hop le!\n");
                    exit(1);
            }
            push(&stack, result);
            i++;
        }
    }

    return pop(&stack);
}

int main() {
    char expression[MAX_SIZE];

    printf("Nhap bieu thuc hau to: ");
    scanf("%[^\n]%*c", expression);

    double result = evaluatePostfixExpression(expression);

    printf("Bieu thuc hau to: %s\n", expression);
    printf("Gia tri cua bieu thuc: %.2f\n", result);

    return 0;
}

