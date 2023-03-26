#include<stdio.h>
#include<string.h>

// stack precedence table
int F(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 3;
        case '^':
        case '$':
            return 6;
        case ')':
            return 0;
        case '#':
            return -1;
        default:
            return 7;
    }
}

// input precedence table
int G(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '^':
        case '$':
            return 5;
        case '(':
            return 0;
        case ')':
            return 9;
        default:
            return 8;
    }
}

void infix_prefix(char infix[], char prefix[]) {
    int top, i, j;
    char s[30], symbol;
    top = -1;
    s[++top] = '#';
    j = 0;
    strrev(infix);
    for(i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        // second condition while(F(s[top]) > G(symbol))
        {
            prefix[j++] = s[top--];
        }
        // first condition
        if(F(s[top]) != G(symbol)) {
            s[++top] = symbol;
        }
        else {
            top--;
        }
    }
    // when input is completely processed, pop everything and put it into prefix expression
    while(s[top] != '#') {
        prefix[j++] = s[top--];
    }
    prefix[j] = '\0';
    strrev(prefix);
}

int main() {
    char infix[20], prefix[20];
    printf("\nEnter a valid infix expression: ");
    scanf("%s", infix);
    infix_prefix(infix, prefix);
    printf("The prefix expression is: %s", prefix);
    return 0;
}
