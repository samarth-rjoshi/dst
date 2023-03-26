#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int isFull(int top)
{
if(top==MAX_SIZE-1) return 1;
else return 0;
}
int isEmpty(int top)
{
if(top==-1) return 1; else
return 0;
}
void push(int s[],int *top, int item)
{
if(isFull(*top)==1)
printf("\n stack overflow... no space to push new element"); else
{
s[++(*top)]=item;
}
}
int pop(int s[], int *top)
{
int item=-1; if(isEmpty(*top)==1)
printf("\n stack underflow... no elements to pop"); else
{
item = s[(*top)--];
}
return item;
}
void display(int s[], int top)
{
int i; if(isEmpty(top)==1)
printf("\nStack empty... no elements to display"); else
{
printf("\n Elements of the stack :\t"); for(i=0;i<=top;i++) printf("%d\t",s[i]);

}
}
void main()
{
int s[MAX_SIZE]; int top=-1;
int choice, item;
while(1)
{
printf("\nSTACK IMPLEMENTATION");
printf("\n******************\n"); printf("\n1.Push\n2.Pop\n3.Display\n4.Exit"); printf("\n******************\n"); printf("\nEnter your choice"); scanf("%d",&choice);
switch(choice)
{
case 1: printf("\nEnter an element:"); scanf("%d",&item); push(s,&top,item);
break;
case 2: item = pop(s,&top); if(item!=-1)
printf("\n Element popped is : %d",item); break;
case 3: display(s,top); break;
case 4: printf("\nThank you... Stack Program will exit now"); exit(0);
default: printf("\nInvalid choice... Please enter a valid choice");
}
}
}
