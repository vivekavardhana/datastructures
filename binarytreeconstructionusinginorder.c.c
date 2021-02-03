#include<stdio.h>
#include<stdlib.h> 

struct Node{
   int data;
   struct Node *left;
   struct Node *right;
};

struct Node *root = NULL;
int count = 0;

struct Node* insert(struct Node*, int);
void inorder(struct Node*);
void preorder(struct Node*);
void postorder(struct Node*);

void main(){
   int choice, value;
    
   printf("\n----- Binary Tree -----\n");
   while(1){
      printf("\n***** MENU *****\n");
      printf("1. Insert\n2. Inorder Traversal\n2. Pre order Traversal\n2. Postorder Traversal\n3. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("\nEnter the value to be insert: ");
		 scanf("%d", &value);
		 root = insert(root,value);
		 break;
	 case 2: printf("\n In order Traversal");
		 inorder(root); 
		 break;
	 case 3: printf("\n Pre order Traversal");
		 preorder(root); 
		 break;
	 case 4: printf("\n Post order Traversal");
		 postorder(root); 
		 break;		      
	 case 5: exit(0);
	 default: printf("\nPlease select correct operations!!!\n");
      }
   }
}

struct Node* insert(struct Node *root,int value){
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(root == NULL){
      newNode->left = newNode->right = NULL;
      root = newNode;
      count++;
   }
   else{
      if(count%2 != 0)
	 root->left = insert(root->left,value);
      else
	 root->right = insert(root->right,value);
   }
   return root;
}
// display is performed by using Inorder Traversal
void inorder(struct Node *root)
{
   if(root != NULL){
      inorder(root->left);
      printf("%d\t",root->data);
      inorder(root->right);
   }
}

// display is performed by using Preorder Traversal
void preorder(struct Node *root)
{
   if(root != NULL){
      printf("%d\t",root->data);	   
      preorder(root->left);
      preorder(root->right);
   }
}

// display is performed by using Postorder Traversal
void postorder(struct Node *root)
{
   if(root != NULL){
      	   
      postorder(root->left);
      postorder(root->right);
      printf("%d\t",root->data);
   }
}
