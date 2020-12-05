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
void delete_given_position(int pos);

int main() {
  int n, pos;
  head = NULL;
  last = NULL;
  printf("\nEnter the total number of nodes in list : "); // Input the number of nodes
  scanf("%d", & n);
  createList(n);
  printf("\n\nTHE DOUBLY LINKED LIST IS :\n\n");
  displayList();
  printf("\n\nEnter the position : ");
  scanf("%d", & pos);
  delete_given_position(pos);
  printf("\n\nAFTER DELETION, THE DOUBLY LINKED LIST IS :\n\n");
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
    // Print the list
    while (temp != NULL) {
      printf("%d\t", temp -> data);
      n++;
      /* Move the current pointer to next node */
      temp = temp -> next;
    }
  }
}

/* Function to delete a node at the given position in the list */
void delete_given_position(int position) {
  struct node * temp;
  int i;
  temp = head;
  for (i = 0; i < position && current != NULL; i++) {
    temp = temp -> next;
  }
  if (temp != NULL) {
    temp -> prev -> next = temp -> next; // Assign the next pointer of node to be deleted to its previous node's prev pointer
    temp -> next -> prev = temp -> prev; // Assign the prev pointer of the node to be deleted to its next node's next pointer
    free(temp); // Delete the temp node
  } else {
    printf("Invalid position!\n");
  }
}
