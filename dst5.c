#include<stdio.h>
#include<stdlib.h>
// Node creation
struct node
{
int info;
struct node *llink; struct node *rlink;
};
typedef struct node *NODE;
// Insert node at the front end
NODE insertFront(NODE first)
{
NODE temp; int item;
temp = (NODE)malloc(sizeof(struct node)); if(temp==NULL)
{
printf("\n Unable to allocate memory...\n"); return first;
}
printf("\nEnter an element to be inserted: "); scanf("%d", &item);
temp->info = item; temp->llink = NULL; temp->rlink = NULL; if(first == NULL) first=temp;
else
{
temp->rlink = first; first->llink=temp; first=temp;
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
temp->info = item; temp->llink = NULL; temp->rlink = NULL; if(first == NULL) first=temp;
else
{
cur=first;
while(cur->rlink!=NULL) cur=cur->rlink;
cur->rlink=temp; temp->llink = cur;
}
return first;
}
// Insert at position
NODE insertPos(NODE first)
{
NODE temp,cur; int item, pos, k;
printf("\nEnter a position: "); scanf("%d",&pos);  if(pos==1)
{
first = insertFront(first); return first;
}
cur=first; k=1;
while(cur!=NULL && k<pos-1)
{
cur=cur->rlink; k++;
}
if(cur == NULL)
{
printf("\nPosition doesnt exist... \n"); return first;
}
temp = (NODE)malloc(sizeof(struct node)); if(temp==NULL)
{
printf("\n Unable to allocate memory...\n"); return first;
}
printf("\nEnter an element to be inserted: "); scanf("%d", &item);
temp->info = item; temp->llink = NULL; temp->rlink = NULL;
temp->rlink = cur->rlink; temp->llink = cur;
cur->rlink->llink = temp; cur->rlink = temp; return first;
}
// insert before element
NODE insertBeforeEle(NODE first)
{
NODE temp,cur; int item, ele;
printf("\nEnter an element: "); scanf("%d",&ele);
cur=first;
while(cur!=NULL && cur->info!=ele)
{
cur=cur->rlink;
}
if(cur == NULL)
{
printf("\nGiven element doesnt exist in the list... \n"); return first;
}
if(cur == first)
{
first = insertFront(first); return first;
}
temp = (NODE)malloc(sizeof(struct node)); if(temp==NULL)
{
printf("\n Unable to allocate memory...\n"); return first;
}
printf("\nEnter an element to be inserted: "); scanf("%d", &item);
temp->info = item; temp->llink = NULL; temp->rlink = NULL; temp->rlink = cur;
temp->llink = cur->llink; cur->llink->rlink = temp; cur->llink = temp; return first;
}
//insert after element
NODE insertAfterEle(NODE first)
{
NODE temp,cur; int item, ele;
printf("\nEnter an element: "); scanf("%d",&ele);
cur=first;
while(cur!=NULL && cur->info!=ele)
{
cur=cur->rlink;
}
if(cur == NULL)
{
printf("\nGiven element doesnt exist in the list... \n"); return first;
}
temp = (NODE)malloc(sizeof(struct node)); if(temp==NULL)
{
printf("\n Unable to allocate memory...\n"); return first;
}
printf("\nEnter an element to be inserted: "); scanf("%d", &item);
temp->info = item; temp->llink = NULL; temp->rlink = NULL;
temp->rlink = cur->rlink; temp->llink = cur;
if(cur->rlink != NULL) cur->rlink->llink = temp; cur->rlink = temp; return first;
}
// Delete node from the front end
NODE deleteFront(NODE first)
{
NODE temp; if(first==NULL)
{
printf("\nThe list is empty.. no elements to delete...\n"); return first;
}
temp=first;
first = first->rlink; first->llink = NULL;
printf("\nElement being deleted is : %d\n", temp->info); free(temp);
return first;
}
// Delete node from the rear end
NODE deleteRear(NODE first)
{
NODE cur; if(first==NULL)
{
printf("\nThe list is empty.. no elements to delete...\n"); return first;
}
if(first->llink == NULL && first->rlink == NULL)
{
printf("\nElement being popped is : %d\n", first->info); free(first);
first = NULL; return first;
}
cur=first;
while(cur->rlink != NULL)
{
cur=cur->rlink;
}
cur->llink->rlink = NULL;
printf("\nElement being deleted is : %d\n", cur->info); free(cur);
return first;
}
// Delete the element given from the linked list
NODE deleteElement(NODE first)
{
NODE cur = NULL;
int item; if(first==NULL)
{
printf("\nThe list is empty.. no elements to delete...\n"); return first;
}
printf("\nEnter the element to be deleted :"); scanf("%d",&item);
cur=first;
while(cur!=NULL && cur->info!=item)
{
cur=cur->rlink;
}
if(cur==NULL)
{
return first;
}
if(cur == first)
{
first = deleteFront(first); return first;
}
if(cur->rlink == NULL)
{
first = deleteRear(first); return first;
}
cur->llink->rlink = cur->rlink; cur->rlink->llink = cur->llink;
printf("\nElement being deleted is : %d\n", cur->info); free(cur);
return first;
}
// Delete element at the given position
NODE deletePos(NODE first)
{
NODE cur = NULL;
int pos, k; if(first==NULL)
{
printf("\nThe list is empty.. no elements to delete...\n"); return first;
}
printf("\nEnter the position of element to be deleted :"); scanf("%d",&pos);
if(pos==1)
{
first = deleteFront(first); return first;
}
cur=first; k=1;
while(cur!=NULL && k<pos)
{
cur=cur->rlink; k++;
}
if(cur==NULL)
{
printf("\nPosition doesnt exist in the list\n"); return first;
}
cur->llink->rlink = cur->rlink; cur->rlink->llink = cur->llink;
printf("\nElement being deleted is : %d\n", cur->info); free(cur);
return first;
}
// Delete element which is present before the given element
NODE deleteBeforeEle(NODE first)
{
    int ele;
NODE cur = NULL, prev = NULL; //SLL had pprev pointer , which is not required here int ele;
if(first==NULL)
{
printf("\nThe list is empty.. no elements to delete...\n"); return first;
}
printf("\nEnter an element whose left element to be deleted :"); scanf("%d",&ele);
cur=first;
while(cur!=NULL && cur->info!=ele)
{
cur=cur->rlink;
}
if(cur==NULL)
{
printf("\nElement doesnt exist in the list\n"); return first;
}
if(cur->llink == first)
{
first = deleteFront(first); return first;
}
prev = cur->llink;
prev->llink->rlink = cur; cur->llink = prev->llink;
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
while(cur!=NULL && cur->info!=ele)
{
cur=cur->rlink;
}
if(cur==NULL)
{
printf("\nElement doesnt exist in the list\n"); return first;
}
if(cur->rlink == NULL)
{
printf("\nNo elements to delete after the given element..."); return first;
}
next = cur->rlink; if(next->rlink == NULL)
{
first = deleteRear(first); return first;
}
cur->rlink = next->rlink; next->rlink->llink = cur;
printf("\nElement being deleted is : %d\n", next->info); free(next);
return first;
}
// Compute length of the Singly Linked List
NODE findLength(NODE first)
{
NODE cur=NULL;
int length=0; cur=first; while(cur!=NULL)
{
length++; cur=cur->rlink;
}
printf("\nLength of the linked list is : %d",length); return first;
}
// Search the given element in the linked list
NODE searchKey(NODE first)
{
int key;
NODE cur;
int pos=0;
if(first==NULL)
{
printf("\n List is empty.. no elements to search...\n"); return first;
}
printf("\nEnter the key to be searched: "); scanf("%d",&key);
cur=first;
while(cur!=NULL && cur->info!=key)
{
cur=cur->rlink; pos++;
}
if(cur==NULL)
{
printf("\nKey doesnt exist in the given linked list...\n"); return first;
}
printf("\nKey is found successfully in the linked list at pos = %d\n",pos); return first;
}
// Display the contents of the linked list
void display(NODE first)
{
NODE cur; if(first == NULL)
printf("\nList is empty, no elements to display\n"); else
{
cur=first;
printf("\nElements in the linked list are : "); while(cur!=NULL)
{
printf("%d\t",cur->info); cur=cur->rlink;
}
}
}
void main()
{
NODE first = NULL; int choice; while(1)
{
printf("\n********** Doubly Linked List ************\n");
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
case 15: printf("\n DLL program terminates now... Thank you...\n"); exit(0);
default: printf("\nInvalid choice... please enter valid choice	\n");
}
}
}
