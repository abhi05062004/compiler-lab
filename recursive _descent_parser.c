#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int flag, i;
char buffer[100];  // I made it longer

void advance() {
    i++;
}

void error() {
    flag = 0;
}

// Forward prototypes
void E();
void E_dash();
void T();
void T_dash();
void F();

void E() {
    T();
    E_dash();
}

void E_dash() {
    if (buffer[i] == '+') {
        advance();
        T();
        E_dash();
    } 
    else {
        // epsilon case: do nothing
        return;
    }
}

void T() {
    F();
    T_dash();
}

void T_dash() {
    if (buffer[i] == '*') {
        advance();
        F();
        T_dash();
    }
    else {
        return;
    }
}

void F() {
    if (buffer[i] == '(') {
        advance();
        E();
        if (buffer[i] == ')') {
            advance();
        }
        else {
            error();
        }
    }
    else if (buffer[i] == 'i') {
        advance();
    }
    else {
        error();
    }
}

int main() {
    printf("Enter the input: ");
    scanf("%s", buffer);
    i = 0;
    flag = 1;
    E();
    if (flag == 1 && buffer[i] == '\0') {
        printf("\nValid expression\n");
    }
    else {
        printf("\nInvalid expression\n");
    }
    return 0;
}

