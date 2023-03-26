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
char prefix[20], symbol;
printf("\nEnter a valid prefix expression: "); scanf("%s",prefix);
strrev(prefix);
//start of evaluation
 for(i=0;i<strlen(prefix);i++)
{
symbol = prefix[i]; if(isdigit(symbol)) s[++top] = symbol -'0'; else
{
op1 = s[top--];
op2 = s[top--];
//perform the operation based on operator being processed
res = compute(symbol, op1, op2);
s[++top] = res;
}
res = s[top--];
printf("\nThe prefix evaluation result: %f ",res);
}
}
