#include<stdio.h> #include<math.h> #include<string.h>
/* Function is to evaluate based on the operator and operands */
double compute(char symbol, double op1, double op2)
{
switch(symbol)
{
case '+': return op1+op2; break;
case '-': return op1-op2; break;
case '*': return op1*op2; break;
case '/': return op1/op2; break;
case '^':
case '$': return pow(op1,op2); break;
}
}
void main()
{
double s[20], res, op1, op2; int top=-1, i;
char postfix[20], symbol;
printf("\nEnter a valid postfix expression: "); scanf("%s",postfix);
//start of evaluation
for(i=0;i<strlen(postfix);i++)
{
symbol = postfix[i]; if(isdigit(symbol)) s[++top] = symbol -'0'; else
{
op2 = s[top--];
op1 = s[top--];
//perform the operation based on operator being processed res = compute(symbol, op1, op2);
s[++top] = res;
}
}
res = s[top--];
printf("\nThe postifx evaluation result: %f ",res);
}
