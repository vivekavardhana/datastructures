#include <stdio.h> 
#include<stdlib.h>
// structure for a node 
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
// Function to insert a node at the end of 
// a Circular linked list 
void Insert(struct Node** head, int data) 
{ 
    struct Node* current = *head; 
    // Create a new node 
    struct Node* newNode = (struct Node * ) malloc(sizeof(struct Node));
  
    // check node is created or not 
    if (!newNode) { 
        printf("\nMemory Error\n"); 
        return; 
    } 
  
    // insert data into newly created node 
    newNode->data = data; 
  
    // check list is empty 
    // if not have any node then 
    // make first node it 
    if (*head == NULL) { 
        newNode->next = newNode; 
        *head = newNode; 
        return; 
    }  
  
    // if list have already some node 
    else { 
  
        // move first node to last node 
        while (current->next != *head) { 
            current = current->next; 
        } 
  
        // put first or head node address 
        // in new node link 
        newNode->next = *head; 
  
        // put new node address into last 
        // node link(next) 
        current->next = newNode; 
    } 
} 
  
// Function print data of list 
void Display(struct Node* head) 
{ 
    struct Node* current = head; 
  
    // if list is empty, simply show message 
    if (head == NULL) { 
        printf("\nDisplay List is empty\n"); 
        return; 
    } 
  
    // traverse first to last node 
    else { 
        do { 
            printf("%d ", current->data); 
            current = current->next; 
        } while (current != head); 
    } 
} 
  
// Function return number of nodes present in list 
int Length(struct Node* head) 
{ 
    struct Node* current = head; 
    int count = 0; 
  
    // if list is empty simply return length zero 
    if (head == NULL) { 
        return 0; 
    } 
  
    // traverse forst to last node 
    else { 
        do { 
            current = current->next; 
            count++; 
        } while (current != head); 
    } 
    return count; 
} 
  
// Function delete First node of Circular Linked List 
void DeleteFirst(struct Node** head) 
{ 
    struct Node *previous = *head, *next = *head; 
  
    // check list have any node 
    // if not then return 
    if (*head == NULL) { 
        printf("\nList is empty\n"); 
        return; 
    } 
  
    // check list have single node 
    // if yes then delete it and return 
    if (previous->next == previous) { 
        *head = NULL; 
        return; 
    } 
  
    // traverse second to first 
    while (previous->next != *head) { 
  
        previous = previous->next; 
        next = previous->next; 
    } 
  
    // now previous is last node and 
    // next is first node of list 
    // first node(next) link address 
    // put in last node(previous) link 
    previous->next = next->next; 
  
    // make second node as head node 
    *head = previous->next; 
    //free(next); 
  
    return; 
} 
  
// Function to delete last node of 
// Circular Linked List 
void DeleteLast(struct Node** head) 
{ 
    struct Node *current = *head, *temp = *head, *previous; 
  
    // check if list doesn't have any node 
    // if not then return 
    if (*head == NULL) { 
        printf("\nList is empty\n"); 
        return; 
    } 
  
    // check if list have single node 
    // if yes then delete it and return 
    if (current->next == current) { 
        *head = NULL; 
        return; 
    } 
  
    // move first node to last 
    // previous 
    while (current->next != *head) { 
        previous = current; 
        current = current->next; 
    } 
  
    previous->next = current->next; 
    *head = previous->next; 
    //free(current); 
  
    return; 
} 
  
// Function delete node at a given poisition 
// of Circular Linked List 
void DeleteAtPosition(struct Node** head, int index) 
{ 
    // Find length of list 
    int len = Length(*head); 
    int count = 1; 
    struct Node *previous = *head, *next = *head; 
  
    // check list have any node 
    // if not then return 
    if (*head == NULL) { 
        printf("\nDelete Last List is empty\n"); 
        return; 
    } 
  
    // given index is in list or not 
    if (index >= len || index < 0) { 
        printf("\nIndex is not Found\n"); 
        return; 
    } 
  
    // delete first node 
    if (index == 0) { 
        DeleteFirst(head); 
        return; 
    } 
  
    // traverse first to last node 
    while (len > 0) { 
  
        // if index found delete that node 
        if (index == count) { 
            previous->next = next->next; 
            //free(next); 
            return; 
        } 
        previous = previous->next; 
        next = previous->next; 
        len--; 
        count++; 
    } 
    return; 
} 
  
// Driver Code 
int main() 
{ 
    struct Node* head = NULL; 
    Insert(&head, 99); 
    Insert(&head, 11); 
    Insert(&head, 22); 
    Insert(&head, 33); 
    Insert(&head, 44); 
    Insert(&head, 55); 
    Insert(&head, 66); 
  
    // Deleting Node at position 
    printf("Initial List: "); 
    Display(head); 
    printf("\nAfter Deleting node at index 4: "); 
    DeleteAtPosition(&head, 4); 
    Display(head); 
  
    // Deleting first Node 
    printf("\n\nInitial List: "); 
    Display(head); 
    printf("\nAfter Deleting first node: "); 
    DeleteFirst(&head); 
    Display(head); 
  
    // Deleting last Node 
    printf("\n\nInitial List: "); 
    Display(head); 
    printf("\nAfter Deleting last node: "); 
    DeleteLast(&head); 
    Display(head); 
  
    return 0; 
} 