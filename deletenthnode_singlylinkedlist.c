/*File: test.c*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

/*Delete the N-th node of a linked list.*/
void delete_nth_node(struct node **head, int n) {
  struct node *tmp = NULL;
  struct node *del_node = NULL;

  /*Linked list does not exist or the list is empty*/
  if(head == NULL || *head == NULL) return;
  
  /*Storing the head to a temporary variable*/
  tmp = *head;
  
  /*Special case: we have to delete the first node.*/
  if (n == 0) {
    *head = (*head)->next;
    free(tmp);
    return;
  }
  
  /*Go to the (n-1)-th node.*/
  while(--n > 0 && tmp->next) tmp = tmp->next;
  
  /*List does not have enough nodes.*/
  if(tmp->next == NULL) return;
  
  /*Node to be deleted.*/
  del_node = tmp->next;
  
  /*De-link the n-th node*/
  tmp->next = tmp->next->next;
  
  free(del_node);
}

/*Print the linked list*/
void print_list(struct node *head) {
    
    printf("H->");

    while(head)
    {
        printf("%d->", head->val);
        head = head->next;
    }

    printf("|||\n");
}

/*Insert a node at the end of the list*/
void insert_end(struct node **head, int value) {
    
    struct node* new_node = NULL;
    struct node* tmp = *head;

    /*Allocating memory for the new node...*/
    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
    }

    new_node->val = value;
    new_node->next = NULL;

    /*If the list is empty, the new node becomes the first node.*/
    if (*head == NULL) {
      *head = new_node;
      return;
    }
    
    /*Reaching to the last node...*/
    while(tmp->next) tmp = tmp->next;
    
    tmp->next = new_node;
}

void main()
{
    int count = 0, i, val, n;
    struct node* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++)
    {
        printf("Enter %d-th element: ", i);
        scanf("%d", &val);
        insert_end(&head, val);
    }

    printf("Initial Linked List: ");
    print_list(head);
    
    printf("Enter a position: ");
    scanf("%d", &n);
    
    delete_nth_node(&head, n);
    
    printf("Linked List after deleting %d-th node: ", n);
    print_list(head);
}
