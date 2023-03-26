#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 5
//Check if Queue is empty
int isQEmpty(int rear, int front)
{
if(rear<front) return 1;
else return 0;
}
// Check if queue is full int
isQFull(int rear)
{
if(rear == QUEUE_SIZE-1)
    return 1;
else
    return 0;
}
// Insert to the queue
void insertQ(int q[], int *rear, int item)
{
q[++(*rear)]=item;
}
//Delete from the queue
int deleteQ(int q[], int rear, int *front)
{
int item; if(isQEmpty(rear, *front)) return -1;
item = q[(*front)++]; return item;
}
//Display the elements in the queue
void displayQ(int q[], int rear, int front)
{
int i;
if(isQEmpty(rear, front))
printf("\nQueue Underflow... No elements to display"); else
{
printf("\n Queue Elements: "); for(i=front;i<=rear;i++) printf("%d\t",q[i]);

}
}
//Main function
void main()
{
int q[QUEUE_SIZE], front =0, rear =-1, item; int choice;
while(1)
{
printf("\nLinear Queue Implementation\n"); printf("\n****************************\n"); printf("1. Insert\n2. Delete\n3.Display\n4. Exit"); printf("\n****************************\n"); printf("\nEnter your choice: "); scanf("%d",&choice);
switch(choice)
{
case 1: if(isQFull(rear))

printf("\nQueue Overflow"); else
{
printf("\nEnter the element : "); scanf("%d", &item);
insertQ(q, &rear, item);
}
break;
case 2: item = deleteQ(q, rear, &front); if(item ==-1)
printf("\nQueue Underflow..."); else
printf("\nElement deleted is %d", item); break;
case 3: displayQ(q, rear, front); break;
case 4: printf("\nThank you!!! Queue Program will end now..."); exit(0);
default: printf("\nInvalid choice .... Please enter valid choice...");
}
}
}
