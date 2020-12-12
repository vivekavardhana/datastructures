#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{

    int data;

    struct node *next;

} * head, *temp, *p;

    void push();
    void pop();

int main()
{

    int n, i;

    char ch;

    printf("how many nodes ?:");

    scanf("%d", &n);

    head = (struct node * ) malloc(sizeof(struct node));
 
    printf("Enter a value for node->data:");

    scanf("%d", &head->data);

    head->next = NULL;

    for (i = 0; i < n - 1; i++) 
    { 

        push(); 

    } 

        printf("\n\n"); 

        printf("Top = %d \n\n ", head-> data);

        printf("Do you wish to Pop:y/n:");

        scanf("%s", & ch);

    if (ch == 'y')
    {

        pop();

        printf("\n\n");

        printf("new top = %d\n", head->data);

        printf("\n\n");

    }

    

    return 0;

}

void push()

{

    temp = (struct node * ) malloc(sizeof(struct node));

    printf("Enter a value for node->data:");

    scanf("%d", &temp->data);

    temp->next =  head = temp;

}

void pop()

{

    head = head->next;

}
