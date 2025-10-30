#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

char str[MAX], stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void pop(int n) {
    top -= n;
    stack[top + 1] = '\0';
}

void check() {
    int reduced;
    do {
        reduced = 0;

        if (top >= 0 && stack[top] == '4') {
            pop(1);
            push('E');
            printf("$%s\t%s$\tReduce by E-->4\n", stack, str);
            reduced = 1;
        } 
        else if (top >= 2 && stack[top] == '2' && stack[top - 1] == 'E' && stack[top - 2] == '2') {
            pop(3);
            push('E');
            printf("$%s\t%s$\tReduce by E-->2E2\n", stack, str);
            reduced = 1;
        } 
        else if (top >= 2 && stack[top] == '3' && stack[top - 1] == 'E' && stack[top - 2] == '3') {
            pop(3);
            push('E');
            printf("$%s\t%s$\tReduce by E-->3E3\n", stack, str);
            reduced = 1;
        }
    } while (reduced);
}

int main() {
    printf("GRAMMAR IS\nE->2E2\nE->3E3\nE->4\n");
    printf("Enter the input string:\t");
    scanf("%s", str);

    printf("\nStack\tInput Buffer\tParsing Action\n");
    printf("$\t%s$\tShift\n", str);

    int len = strlen(str);
    for (int j = 0; j < len; j++) {
        push(str[j]);
        str[j] = ' ';
        printf("$%s\t%s$\tShift\n", stack, str);
        check();
    }

    check();

    if (top == 0 && stack[top] == 'E')
        printf("$%s\t%s$\tAccept\n", stack, str);
    else
        printf("$%s\t%s$\tReject\n", stack, str);

    return 0;
}
