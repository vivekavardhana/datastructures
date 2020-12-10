#include <stdio.h>

#include <stdlib.h>

struct node {
  int val;
  struct node * next;
};

void print_list(struct node * head) {
  printf("H->");

  while (head) {
    printf("%d->", head -> val);
    head = head -> next;
  }

  printf("|||\n\n");
}

void insert_front(struct node ** head, int value) {
  struct node * new_node = NULL;

  new_node = (struct node * ) malloc(sizeof(struct node));

  if (new_node == NULL) {
    printf("Failed to insert element. Out of memory");
  }

  new_node -> val = value;
  new_node -> next = * head;

  * head = new_node;
}

void insert_end(struct node ** head, int value) {
  struct node * new_node = NULL;
  struct node * last = NULL;

  new_node = (struct node * ) malloc(sizeof(struct node));

  if (new_node == NULL) {
    printf("Failed to insert element. Out of memory");
  }

  new_node -> val = value;
  new_node -> next = NULL;

  if ( * head == NULL) {
    * head = new_node;
    return;
  }

  last = * head;
  while (last -> next) last = last -> next;

  last -> next = new_node;
}

void insert_after(struct node * head, int value, int after) {
  struct node * new_node = NULL;
  struct node * tmp = head;

  while (tmp) {

    if (tmp -> val == after) {
      /*found the node*/

      new_node = (struct node * ) malloc(sizeof(struct node));

      if (new_node == NULL) {
        printf("Failed to insert element. Out of memory");
      }

      new_node -> val = value;
      new_node -> next = tmp -> next;
      tmp -> next = new_node;
      return;
    }

    tmp = tmp -> next;
  }
}

void insert_before(struct node ** head, int value, int before) {
  struct node * new_node = NULL;
  struct node * tmp = * head;

  new_node = (struct node * ) malloc(sizeof(struct node));

  if (new_node == NULL) {
    printf("Failed to insert element. Out of memory");
    return;
  }

  new_node -> val = value;

  if (( * head) -> val == before) {
    new_node -> next = * head;
    * head = new_node;
    return;
  }

  while (tmp && tmp -> next) {

    if (tmp -> next -> val == before) {
      new_node -> next = tmp -> next;
      tmp -> next = new_node;
      return;
    }

    tmp = tmp -> next;
  }

  /*Before node not found*/
  free(new_node); 
}

void main() {
  int count = 0, i, val, after, before;
  struct node * head = NULL;

  printf("Enter number of elements: ");
  scanf("%d", & count);

  for (i = 0; i < count; i++) {
    printf("Enter %dth element: ", i);
    scanf("%d", & val);
    insert_front( & head, val);
  }

  printf("Initial List: ");
  print_list(head);

  printf("Enter a value to enter at the front of the list: ");
  scanf("%d", & val);
  insert_front( & head, val);

  printf("List after insertion: ");
  print_list(head);

  printf("Enter a value to enter at the end of the list: ");
  scanf("%d", & val);
  insert_end( & head, val);

  printf("List after insertion: ");
  print_list(head);

  printf("Enter a value to insert in the list: ");
  scanf("%d", & val);

  printf("Insert after: ");
  scanf("%d", & after);

  insert_after(head, val, after);

  printf("List after insertion: ");
  print_list(head);

  printf("Enter a value to insert in the list: ");
  scanf("%d", & val);

  printf("Insert before: ");
  scanf("%d", & before);

  insert_before( & head, val, before);

  printf("List after insertion: ");
  print_list(head);
}
