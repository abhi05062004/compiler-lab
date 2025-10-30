#include <stdio.h>
#include <stdlib.h>

struct node {
    int st;
    struct node *link;
};

void findclosure(int, int);
void insert_trantbl(int, char, int);
int findalpha(char);
void print_e_closure(int);

int nostate, noalpha, notransition;
char alphabet[20];
int e_closure[20][20] = {0};
int buffer[20];
struct node *transition[20][20] = {NULL};
int c_index;

int main() {
    int i, r, s;
    char c;
    
    printf("Enter the number of alphabets: \n");
    scanf("%d", &noalpha);
    getchar();
    
    printf("NOTE: [USE LETTER e AS EPSILON]\n");
    printf("NOTE: [e MUST BE LAST CHARACTER, IF IT IS PRESENT]\n");
    printf("Enter alphabets: \n");
    
    for (i = 0; i < noalpha; i++) {
        alphabet[i] = getchar();
        getchar();
    }
    
    printf("Enter the number of states: \n");
    scanf("%d", &nostate);
    
    printf("Enter the number of transitions: \n");
    scanf("%d", &notransition);
    
    printf("NOTE: [TRANSITION IS IN THE FORM -> qno alphabet qno]\n");
    printf("NOTE: [STATE NUMBERS MUST BE GREATER THAN ZERO]\n");
    printf("Enter Transitions: \n");
    
    for (i = 0; i < notransition; i++) {
        scanf("%d %c %d", &r, &c, &s);
        insert_trantbl(r, c, s);
    }
    
    printf("\ne-closure of states...\n");
    for (i = 1; i <= nostate; i++) {
        // Reset buffer and e_closure for each state
        for (int j = 0; j < 20; j++) {
            buffer[j] = 0;
            e_closure[i][j] = 0;
        }
        c_index = 0; // Reset the index for each state
        findclosure(i, i);
        printf("e-closure(q%d): ", i);
        print_e_closure(i);
    }
    
    return 0;
}

void findclosure(int x, int sta) {
    struct node *temp;
    if (buffer[x])
        return;
    
    e_closure[sta][c_index++] = x;
    buffer[x] = 1;
    
    // Check if epsilon exists and there are epsilon transitions from state x
    if (alphabet[noalpha - 1] == 'e' && transition[x][noalpha - 1] != NULL) {
        temp = transition[x][noalpha - 1];
        while (temp != NULL) {
            findclosure(temp->st, sta);
            temp = temp->link;
        }
    }
}

void insert_trantbl(int r, char c, int s) {
    int j = findalpha(c);
    if (j == 999) {
        printf("Error: Invalid alphabet '%c'\n", c);
        exit(1);
    }
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->st = s;
    temp->link = transition[r][j];
    transition[r][j] = temp;
}

int findalpha(char c) {
    for (int i = 0; i < noalpha; i++) {
        if (alphabet[i] == c)
            return i;
    }
    return 999;
}

void print_e_closure(int i) {
    printf("{");
    for (int j = 0; j < c_index && e_closure[i][j] != 0; j++) {
        if (j > 0)
            printf(", ");
        printf("q%d", e_closure[i][j]);
    }
    printf("}\n");
}

