#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tempCount = 1;

// Generate temporary variable
void getTemp(char temp[]) {
    sprintf(temp, "T%d", tempCount++);
}

// Print intermediate code
void genCode(char left[], char op, char right[], char result[]) {
    printf("%s = %s %c %s\n", result, left, op, right);
}

// Remove spaces from expression
void removeSpaces(char* expr) {
    int i = 0, j = 0;
    while (expr[i]) {
        if (!isspace(expr[i])) {
            expr[j] = expr[i];
            j++;
        }
        i++;
    }
    expr[j] = '\0';
}

// Find main operator outside parentheses for given precedence
int findOperator(char expr[], const char ops[]) {
    int paren = 0;
    for (int i = strlen(expr) - 1; i >= 0; i--) {
        if (expr[i] == ')') paren++;
        else if (expr[i] == '(') paren--;
        else if (paren == 0 && strchr(ops, expr[i]))
            return i;
    }
    return -1;
}

// Recursive expression processor
void processExpr(char expr[], char result[]) {
    int len = strlen(expr);

    // 1. Remove outer parentheses if fully enclosed
    if (expr[0] == '(' && expr[len - 1] == ')')
    {
        int paren = 0, fullyWrapped = 1;
        for (int i = 0; i < len; i++)
        {
            if (expr[i] == '(') paren++;
            else if (expr[i] == ')') paren--;
            if (paren == 0 && i < len - 1) 
            {
                fullyWrapped = 0;
                break;
            }
        }

        if (fullyWrapped) {
            char temp[100];
            // Copy inner expression safely
            memcpy(temp, expr + 1, len - 2);
            temp[len - 2] = '\0';
            processExpr(temp, result);
            return;
        }
    }
    // 2. Find main operator (+- first, then */)
    int opIndex = findOperator(expr, "+-");
    if (opIndex == -1)
        opIndex = findOperator(expr, "*/");

    // 3. If operator found, split and process recursively
    if (opIndex != -1) {
        char left[100], right[100], tLeft[100], tRight[100];

        // Copy left and right parts safely
        memcpy(left, expr, opIndex);
        left[opIndex] = '\0';
        strcpy(right, expr + opIndex + 1);

        // Process sub-expressions
        processExpr(left, tLeft);
        processExpr(right, tRight);

        // Generate temporary variable and intermediate code
        getTemp(result);
        genCode(tLeft, expr[opIndex], tRight, result);
        return;
    }

    // 4. Base case: single variable or number
    strcpy(result, expr);
}

int main() {
    char expr[100], result[50];
    printf("Enter arithmetic expression: ");
    scanf(" %[^\n]", expr);   // Read full line including spaces
    removeSpaces(expr);       // Remove spaces
    printf("\nIntermediate Code:\n");
    processExpr(expr, result);
    printf("\nFinal Result: %s\n", result);
    return 0;
}

