#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;struct node *next;
              }node;
typedef node *list; 
list top=NULL;
list ptr;

void push()
{
  printf("enter elements\n");
  ptr=(node*)malloc(sizeof(node));
  if(top==NULL)
      {
      top=(node*)malloc(sizeof(node));
      scanf("%d",&top->data);
      top->next=NULL;
      }
      else
      {
        scanf("%d",&ptr->data);ptr->next=top;top=ptr;
      }
}

void pop()
{
  if(top==NULL)
    printf("Underflow\n");
  else
  {
    printf("popped element is %d\n",top->data);top=top->next;
    }
}

void display()
{ 
  ptr=top;
  if(top==NULL)
    printf("Underflow\n");
  else
  {
    printf("elements are\n");
    while(ptr!=NULL)
    { 
      printf("%d ",ptr->data);ptr=ptr->next;
    }
  }
}


void peep()
{
  if(top==NULL)
  printf("Underfloe\n");
  else
  { 
    printf("elements ts: %d\n",top->data);
    }
}

int main()
{
  int ch;
  do
  {
    printf("Enter switch: ");
    printf("1 : Push\n ");
    printf("2 : Display\n ");
    printf("3 : Pop\n ");
    printf("4 : Peep\n ");
    scanf("%d",&ch);
    switch(ch)
    {        
      case 1:
        push();
        break;
      case 2:
        display();
        break;
      case 3:
        pop();
        break;
      case 4:
        peep();
        break;
    }
  }while(ch!=0);
}
