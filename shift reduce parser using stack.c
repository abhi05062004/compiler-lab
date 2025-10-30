#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50

char str[MAX], stack[MAX];
int top=-1;

void push(char c){
    stack[++top]=c;
    stack[top+1]='\0';
}

void pop(int n){
    top-=n;
    stack[top+1]='\0';
}

void check(){
    char reduce[20];
    int reduced;
    do{
        reduced=0;
        if(top>=0 && stack[top]=='4'){
            strcpy(reduce,"REDUCED TO E->4");
            printf("\n$%s\t%s$\t%s",stack,str,reduce);
            stack[top]='E';
            reduced=1;
        } else if(top>=2 && stack[top]=='3' && stack[top-1]=='E' && stack[top-2]=='3'){
            strcpy(reduce,"REDUCED TO E->3E3");
            printf("\n$%s\t%s$\t%s",stack,str,reduce);
            pop(3);
            push('E');
            reduced=1;
        } else if(top>=2 && stack[top]=='2' && stack[top-1]=='E' && stack[top-2]=='2'){
            strcpy(reduce,"REDUCED TO E->2E2");
            printf("\n$%s\t%s$\t%s",stack,str,reduce);
            pop(3);
            push('E');
            reduced=1;
        }
    } while(reduced);
}

int main(){
    int len;
    printf("GRAMMAR IS \nE->2E2\nE->3E3\nE->4\n");
    printf("Enter the input string:\t");
    scanf("%s",str);
    len=strlen(str);
    printf("\nstack\tinput\tAction\n");
    printf("\n$\t%s$\t",str);
    for(int j=0;j<len;j++){
        printf("SHIFT");
        push(str[j]);
        str[j]=' ';
        printf("\n$%s\t%s$\t",stack,str);
        check();
    }
    check();
    printf("\n$%s\t%s$\t",stack,str);
    if(top==0 && stack[top]=='E') printf("Accepted\n");
    else printf("Rejected\n");
    return 0;
}

