#include <stdio.h>
#include <stdlib.h>
struct tree
{
int info;
struct tree *leftchild; struct tree *rightchild;
};
typedef struct tree *NODE; NODE root = NULL;
int count=0;
/* Insert the elements into BST ... BST construction */ void insert()
{
NODE temp; NODE current; NODE parent; int ele;
temp=(NODE)malloc(sizeof(struct tree)); if(temp==NULL)
{
printf("\n Unable to allocate memory...\n"); return;
}
printf("\nEnter an element to be inserted: "); scanf("%d", &ele);
temp->info = ele;
temp->leftchild = NULL; temp->rightchild = NULL; if(root == NULL)
{
root = temp;
}
else
{
current = root; parent = NULL;
// traverse until insert position is found... while(current != NULL)
{
parent = current;

if(ele < parent->info) current = current->leftchild; else
current = current->rightchild;
}
if(ele < parent->info) parent->leftchild = temp; else
parent->rightchild = temp;
}
}
// Preorder tree travsersal - [NLR]
void preorder(NODE root)
{
if (root!=NULL)
{
printf(" %d ", root->info); preorder(root->leftchild); preorder(root->rightchild);
}
}
// Inorder tree travsersal - [LNR]
void inorder(NODE root)
{
if(root!= NULL)
{
inorder(root->leftchild); printf("%d ", root-> info); inorder(root->rightchild);
}
}
// Postorder tree travsersal - [LRN]
void postorder(NODE root)
{
if (root!=NULL)
{
postorder(root->leftchild); postorder(root->rightchild); printf(" %d ", root->info);
}
}
/* Search key in the tree ...*/ void searchKey()
{
NODE current; int key;
if(root == NULL)
{
printf("\n Tree doesnt exist, create the tree prior to search...\n"); return;
}
printf("\nEnter the key to be searched: "); scanf("%d",&key);
current = root;
//search in the tree
while(current != NULL)
{
if(key == current->info)
{
printf("\nSucessful search , Key found...\n");
 break;
}
else if(key<current->info) current = current->leftchild; else
current = current->rightchild;
}
// key not found if(current == NULL)
printf("\n Unsuccessful search , key not found...\n");
}
// To find highest element in the tree
void maximum()
{
NODE current; if(root == NULL)
{
printf("\nTree doesnt exist...\n");
}
else
{
current = root;
while(current->rightchild != NULL) current = current->rightchild;
printf("\nHighest element in the tree is %d", current->info);
}
}
// To find least element in the tree
void minimum()
{
NODE current; if(root == NULL)
{
printf("\nTree doesnt exist...\n");
}
else
{
current = root;
while(current->leftchild != NULL) current = current->leftchild;
printf("\nLeast element in the tree is %d", current->info);
}
}
int max(int a, int b)
{
return (a>b)?a:b;
}
// To find height of the tree
int height(NODE root)
{
if(root == NULL) return -1;
else
return 1+max(height(root->leftchild),height(root->rightchild));
}
// To count nodes in the tree
int countnode(NODE root)
{
return (root == NULL) ? 0 : 1 + countnode(root->leftchild) + countnode(root->rightchild);
}
// To count leaves in a tree
int countleaf(NODE root)
{
if (root == NULL) return 0;
if (root->leftchild == NULL && root->rightchild == NULL)
return 1;
return (countleaf(root->leftchild) + countleaf(root->rightchild));
}
// Delete the key element
void deleteKey()
{
int key;
NODE current, parent, suc, q; if(root == NULL)
{
printf("\nTree doesnt exist..."); return;
}
printf("\nEnter the key to be deleted: "); scanf("%d", &key);
parent = NULL; current = root;
//obtain node to be deleted and its parent
while(current != NULL)
{
if(key == current->info) break;
parent = current; if(key< current->info)
current = current->leftchild; else
current = current->rightchild;
}
if(current == NULL)
{
printf("\nKey not found..\n"); return;
}
// Delete Key : case 1 : Node to be deleted is a leaf node if(current->leftchild == NULL && current->rightchild == NULL)
{
if(parent != NULL)
{
if(current == parent->leftchild) parent->leftchild = NULL;
else
parent->rightchild = NULL;
}
printf("\n Key = %d will be deleted now...\n", current->info); free(current);
return;
}
//delete the key : case 2 : either left or right subtree of key node is empty
if(current->leftchild == NULL)
q = current->rightchild;
else if(current->rightchild == NULL) q = current->leftchild;
//delete the key case 3: Both subtrees exist, so find inorder successor and attach the nodes properly else
{
suc = current->rightchild;
// inorder successor search while(suc->leftchild != NULL) suc = suc->leftchild;
//attach left of node to be deleted to left of successor node to be deleted suc->leftchild = current->leftchild;
//Obtain right subtree of node to be deleted q = current->rightchild;
}
//attaching to parent node : case 1: if parent doesnt exist if(parent == NULL)
{
root = q; return;
}
//attaching to parent node : case 2: if parent exist
//connect parent of node to be deleted to q
if(current == parent->leftchild)
parent->leftchild = q; else
parent->rightchild = q;
printf("\n Key = %d will be deleted now...\n", current->info); free(current);
}
// To display the tree contents in the tree format - side wise
void display(NODE root, int level)
{
int i;
if(root == NULL) return;
display(root->rightchild, level+1); for(i=0;i<level;i++)
printf(" "); printf("%d\n",root->info);
display(root->leftchild, level+1);
}
void levelorder()
{
NODE q[10], current; int front = 0, rear=-1; q[++rear] = root; while(front<=rear)
{
current = q[front++]; printf("%d ", current->info); if(current->leftchild != NULL) q[++rear] = current->leftchild; if(current->rightchild != NULL) q[++rear] = current->rightchild;
}
printf("\n");
}
void main()
{
int choice, h; while(1)
{
printf("\n********** Binary Search Tree Implementation ************\n");
printf("\n1. Insert \n2. Preorder \n3. Inorder \n4. Postorder \n5. Search for a key\n");
printf("6. Maximum element\n7. Minimum element\n8. Tree Height\n9. Count Node\n10. Count Leaf"); printf("\n11. Delete a node\n12. Display - side wise\n13. Display - level order\n14. Exit"); printf("\n*****************************************\n");
printf("\nEnter your choice: ");
scanf("%d",&choice); switch(choice)
{
case 1: insert(); break;
case 2: if(root == NULL) printf("\nTree doesnt exist..\n"); else
{
printf("\nPreorder traversal : "); preorder(root);
}
break;
case 3: if(root == NULL) printf("\nTree doesnt exist..\n"); else
{
printf("\nInorder traversal : "); inorder(root);
}
break;
case 4: if(root == NULL) printf("\nTree doesnt exist..\n"); else
{
printf("\nPostorder traversal : "); postorder(root);
}
break;
case 5: searchKey(); break;
case 6: maximum(); break;
case 7: minimum(); break;
case 8: h = height(root); if(h == -1)
printf("\nHeight = 0"); else
printf("\nHeight = %d\n",h+1); break;
case 9: count=0; count=countnode(root); if(count == 0)
printf("\n Tree doesnt exist..."); else
printf("\ncount of nodes : %d",count); break;
case 10:count=0; count=countleaf(root); if(count == 0)
printf("\n Tree doesnt exist..."); else
printf("\ncount of leaves : %d",count); break;
case 11:deleteKey(); break;
case 12:h = height(root); if(h == -1)
printf("\nTree doesnt exist, create 1 to display"); else
display(root,h); break;
case 13:levelorder(); break;
case 14: printf("\n BST program terminates now... Thank you...\n"); exit(0);
default: printf("\nInvalid choice... please enter valid choice	\n");
}
}
}
