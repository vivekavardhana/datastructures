#include <stdio.h>
   
#include <stdlib.h>
 //structure of Node with prev and next pointers
struct node {
  int data;
  struct node * prev;
  struct node * next;
}* head, * last;

void createList(int n);
void displayList();
void insert_given_pos(int data, int position);

int main() {
  int n, data, pos;
  head = NULL;
  last = NULL;
  printf("\nEnter the total number of nodes in list : "); // Input the number of nodes
  scanf("%d", & n);
  createList(n);
  displayList();
  printf("\n\nEnter data of Last node : ");
  scanf("%d", & data);
  printf("\nEnter the position : ");
  scanf("%d", & pos);
  insert_given_pos(data, pos);
  displayList();
  return 0;
}

void createList(int n) {
  int i, data;
  struct node * newNode;
  if (n >= 1) {
    head = (struct node * ) malloc(sizeof(struct node));
    printf("\nEnter data of node 1 : ");
    scanf("%d", & data);
    head -> data = data;
    head -> prev = NULL; // HEAD nodes's prev is set to NULL
    head -> next = NULL; // HEAD nodes's next is set to NULL
    last = head;
    for (i = 2; i <= n; i++) {
      newNode = (struct node * ) malloc(sizeof(struct node));
      printf("\nEnter data of node %d : ", i);
      scanf("%d", & data);
      newNode -> data = data;
      newNode -> prev = last; // Link new node with the previous node
      newNode -> next = NULL;
      last -> next = newNode; // Link previous node with the new node
      last = newNode; // Make new node as last node
    }
  }
}

void displayList() {
  struct node * temp;
  int n = 1;
  if (head == NULL) {
    printf("\nList is empty.\n");
  } else {
    temp = head;
    printf("\nTHE DOUBLY LINKED LIST IS :\n\n");
    while (temp != NULL) {
      printf("%d\t", temp -> data);
      n++;
      /* Move the current pointer to next node */
      temp = temp -> next;
    }
  }
}

void insert_given_pos(int data, int position) {
  int i;
  struct node * newNode, * temp; 
  if (head == NULL) {
    printf("Error, List is empty!\n");
  } else {
    temp = head;
    i = 0;
    while (i < position - 1 && temp != NULL) {
      temp = temp -> next;
      i++; 
    } 
    if (temp != NULL) {
      newNode = (struct node * ) malloc(sizeof(struct node));
      newNode -> data = data;
      newNode -> next = temp -> next; // Connect new node with n + 1th node
      newNode -> prev = temp; // Connect new node with n - 1th node
      if (temp -> next != NULL) {
        /* Connect pos+1th node with new node */
        temp -> next -> prev = newNode;
      }
      /* Connect pos-1th node with new node */
      temp -> next = newNode;
    } else {
      printf("Error, Invalid position\n");
    }
  }
}
