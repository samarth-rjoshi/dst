#include<stdio.h>
#include<stdlib.h>
// Node creation
struct node
{
int info;
struct node *link;
};
typedef struct node *NODE;
// Insert node at the front end
NODE insertFront(NODE first)
{
NODE temp,cur; int item;
temp = (NODE)malloc(sizeof(struct node)); if(temp==NULL)
{
printf("\n Unable to allocate memory...\n"); return first;
}
printf("\nEnter an element to be inserted: "); scanf("%d", &item);
temp->info = item; temp->link = temp; if(first == NULL) first=temp;
else
{
temp->link = first; cur=first;
while(cur->link!=first) cur=cur->link;
cur->link=temp; first=temp;
}
return first;
}
// Insert node at the rear end
NODE insertRear(NODE first)
{
NODE temp,cur; int item;
temp = (NODE)malloc(sizeof(struct node)); if(temp==NULL)
{
printf("\n Unable to allocate memory...\n"); return first;
}
printf("\nEnter an element to be inserted: "); scanf("%d", &item);
temp->info = item; temp->link = temp; if(first == NULL) first=temp;
else
{
cur=first;
while(cur->link!=first) cur=cur->link;
cur->link=temp; temp->link=first;
}
return first;
}
// Insert at position
NODE insertPos(NODE first)
{
NODE temp,cur; int item, pos, k;
printf("\nEnter a position: ");
scanf("%d",&pos); if(pos==1)
{
first = insertFront(first); return first;
}
cur=first; k=1;
while(k<pos-1)
{
cur=cur->link; k++;
printf("\n loop execution..\n"); if(cur==first)
break;
}
if(cur == first && k!=pos-1)
{
printf("\nPosition doesnt exist... \n"); return first;
}
if(cur->link == first)
{
first = insertRear(first); return first;
}
temp = (NODE)malloc(sizeof(struct node)); if(temp==NULL)
{
printf("\n Unable to allocate memory...\n"); return first;
}
printf("\nEnter an element to be inserted: "); scanf("%d", &item);
temp->info = item; temp->link = NULL; temp->link = cur->link; cur->link = temp; return first;
}
// insert before element
NODE insertBeforeEle(NODE first)
{
NODE temp,cur, prev; int item, ele;
printf("\nEnter an element: "); scanf("%d",&ele);
cur=first; prev=NULL; while(cur->info!=ele)
{
prev=cur; cur=cur->link; if(cur==first) break;
}
if(cur == first && cur->info!=ele)
{
printf("\nGiven element doesnt exist in the list... \n");
return first;
}
temp = (NODE)malloc(sizeof(struct node)); if(temp==NULL)
{
printf("\n Unable to allocate memory...\n"); return first;
}
printf("\nEnter an element to be inserted: "); scanf("%d", &item);
temp->info = item; temp->link = NULL; temp->link = cur; if(prev!=NULL) prev->link = temp; else
{
cur=first;
while(cur->link!=first) cur=cur->link;
cur->link=temp; first=temp;
}
return first;
}
//insert after element
NODE insertAfterEle(NODE first)
{
NODE temp,cur; int item, ele;
printf("\nEnter an element: "); scanf("%d",&ele);
if(first == NULL)
{
printf("\n No elements in the CSLL...\n"); return first;
}
cur=first;
while(cur->info!=ele)
{
cur=cur->link; if(cur==first) break;
}
if(cur == first && cur->info!=ele)
{
printf("\nGiven element doesnt exist in the list... \n"); return first;
}
temp = (NODE)malloc(sizeof(struct node)); if(temp==NULL)
{
printf("\n Unable to allocate memory...\n"); return first;
}
printf("\nEnter an element to be inserted: "); scanf("%d", &item);
temp->info = item; temp->link = NULL;
temp->link = cur->link; cur->link=temp;  return first;
}
// Delete node from the front end
NODE deleteFront(NODE first)
{
NODE temp,cur; if(first==NULL)
{
printf("\nThe list is empty.. no elements to delete...\n"); return first;
}
temp=first;
if(first->link == first) first = NULL;
else
{
cur = first;
while(cur->link!=first) cur= cur->link;
/*
cur->link=first->link; first = first->link;
*/
first = first->link; cur->link = first;
}
printf("\nElement being deleted is : %d\n", temp->info); free(temp);
return first;
}
// Delete node from the rear end
NODE deleteRear(NODE first)
{
NODE cur,prev; if(first==NULL)
{
printf("\nThe list is empty.. no elements to delete...\n"); return first;
}
if(first->link == first)
{
printf("\nElement being deleted is : %d\n", first->info); free(first);
first = NULL; return first;
}
cur=first;
while(cur->link!=first)
{
prev=cur; cur=cur->link;
}
prev->link=first;
printf("\nElement being deleted is : %d\n", cur->info); free(cur);
return first;
}
// Delete the element given from the linked list
NODE deleteElement(NODE first)
{
NODE cur = NULL, prev = NULL; int item;
if(first==NULL)
{
printf("\nThe list is empty.. no elements to delete...\n"); return first;
}
printf("\nEnter the element to be deleted :"); scanf("%d",&item);
if(first->info == item)
{
first = deleteFront(first); return first;
}
cur=first;
while(cur->info!=item)
{
prev=cur; cur=cur->link; if(cur==first) break;
}
if(cur==first && cur->info != item)
{
printf("\nElement to be deleted doesnt exist in the list\n"); return first;
}
prev->link = cur->link;
printf("\nElement being deleted is : %d\n", cur->info); free(cur);
return first;
}
// Delete element at the given position
NODE deletePos(NODE first)
{
NODE cur = NULL, prev = NULL; int pos, k;
if(first==NULL)
{
printf("\nThe list is empty.. no elements to delete...\n"); return first;
}
printf("\nEnter the position of element to be deleted :"); scanf("%d",&pos);
if(pos==1)
{
first = deleteFront(first); return first;
}
cur=first; k=1;
while(k<pos)
{
prev=cur; cur=cur->link;
k++;
if(cur == first) break;
}
if(cur==first && k!=pos)
{
printf("\nPosition doesnt exist in the list\n"); return first;
}
prev->link = cur->link;
printf("\nElement being deleted is : %d\n", cur->info); free(cur);
return first;
}
// Delete element which is present before the given element
 NODE deleteBeforeEle(NODE first)
{
NODE cur = NULL, prev = NULL, pprev = NULL; int ele;
if(first==NULL)
{
printf("\nThe list is empty.. no elements to delete...\n"); return first;
}
printf("\nEnter an element whose left element to be deleted :"); scanf("%d",&ele);
cur=first;
while(cur->info!=ele)
{
pprev = prev; prev=cur; cur=cur->link; if(cur== first) break;
}
if(cur==first && cur->info!=ele)
{
printf("\nElement doesnt exist in the list\n"); return first;
}
if(cur==first && cur->info == ele)
{
printf("\n There are no elements before the given element - to delete	\n");
return first;
}
if(pprev==NULL && prev!=NULL)
{
first = deleteFront(first); return first;
}
pprev->link = prev->link;
printf("\nElement being deleted is : %d\n", prev->info); free(prev);
return first;
}
// Delete the element which is present afer the given element
NODE deleteAfterEle(NODE first)
{
NODE cur = NULL, next = NULL; int ele;
if(first==NULL)
{
printf("\nThe list is empty.. no elements to delete...\n"); return first;
}
printf("\nEnter an element whose right element to be deleted :"); scanf("%d",&ele);
cur=first;
while(cur->info!=ele)
{
cur=cur->link; if(cur == first) break;
}
if(cur==first && cur->info!=ele)
{
printf("\nElement doesnt exist in the list\n"); return first;
}
if(cur->link == first)
{
printf("\nNo elements to delete after the given element..."); return first;
}
next = cur->link;
cur->link = next->link;
printf("\nElement being deleted is : %d\n", next->info); free(next);
return first;
}
// Compute length of the Cirular Singly Linked List
NODE findLength(NODE first)
{
NODE cur=NULL;
int length=0; if(first==NULL)
{
printf("\n CSLL is empty.. length = 0 ...\n"); return first;
}
cur=first;
while(cur->link!=first)
{
length++; cur=cur->link;
}
length++;
printf("\nLength of the linked list is : %d",length); return first;
}
// Search the given element in the linked list
NODE searchKey(NODE first)
{
NODE cur;
int key, pos = 1; if(first==NULL)
{
printf("\n List is empty.. no elements to search...\n"); return first;
}
printf("\nEnter the key to be searched: "); scanf("%d",&key);
cur=first;
while(cur->info!=key)
{
cur=cur->link; pos++;
if(cur == first) break;
}
if(cur == first && cur->info != key)
{
printf("\nKey doesnt exist in the given linked list...\n"); return first;
}
else
printf("\nKey is found successfully in the linked list at pos = %d\n",pos); return first;
}
// Display the contents of the linked list
void display(NODE first)
{
NODE cur; if(first == NULL)
printf("\nList is empty, no elements to display\n"); else
{
cur=first;
printf("\nElements in the linked list are : "); do
{
printf("%d\t",cur->info); cur=cur->link;
}while(cur!=first);
}
}
void main()
{
NODE first = NULL; int choice; while(1)
{
printf("\n**********Circular Singly Linked List ************\n");
printf("\n1. Insert Front\n2. Insert Rear\n3. Insert at given position\n4. Insert before element\n5. Insert afer element\n");
printf("6. Delete Front\n7. Delete Rear\n8. Delete the given element\n9. Delete element at the given position\n10. Delete before the given element");
printf("\n11. Delete after the given element\n12. Compute length of linked list\n13. Search for the given key\n14. Display\n15. Exit");
printf("\n*****************************************\n"); printf("\nEnter your choice: ");
scanf("%d",&choice); switch(choice)
{
case 1: first = insertFront(first); break;
case 2: first = insertRear(first); break;
case 3: first = insertPos(first); break;
case 4: first = insertBeforeEle(first); break;
case 5: first = insertAfterEle(first); break;
case 6: first = deleteFront(first); break;
case 7: first = deleteRear(first); break;
case 8: first = deleteElement(first); break;
case 9: first = deletePos(first); break;
case 10: first = deleteBeforeEle(first); break;
case 11: first = deleteAfterEle(first); break;
case 12: first = findLength(first); break;
case 13: first = searchKey(first); break;
case 14: display(first); break;
case 15: printf("\n CSLL program terminates now... Thank you...\n"); exit(0);
default: printf("\nInvalid choice... please enter valid choice	\n");
}
}
}


