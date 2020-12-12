#include<stdio.h>
#include<stdlib.h>
int count=0;
//structure of a single node 
//we are also creating two nodes start and header

struct node{
 int data;
 struct node* next;
}*start,*header;

//function to print the list
void print()
{
 struct node *p=start;
 while(p!=NULL)
 {
  printf("%d->",p->data);
  p=p->next;
 }
 printf("\n");
}

//insertion at the front of the header linked list
//we can see that we don't need to check whether
//start is null or not because there will always be a
//header node

void insert_at_front(int node_data)
{
 struct node *p;
 p=(struct node *)malloc(sizeof (struct node));
 p->data=node_data;
 p->next=header->next;
 start=p;
 //header will always point to start
 header->next=start;
 //increase the node counter
 count++;
 //store the count value in header
 header->data=count;
 
 printf("after inserting at the front=\n");
 print();
}



void insert_at_end(int node_data)
{
 struct node *p=start,*q;
 //create a new node to insert at last
 q=(struct node *)malloc(sizeof (struct node));
 q->data=node_data;
 q->next=NULL;
 //store header->data in temp for while loop
 int temp=header->data; 
 //loop to reach last node
 //we can see that we are directly using header node's data
 //to reach the last node
 while(temp>1)
 {
  p=p->next;
  temp--;
 }
 p->next=q;
 count++;
 header->data=count;
 printf("after inserting at the end=\n");
 print();
}

//function to insert after given position
void insert_after(int pos,int node_data)
{
 //we can see that we don't need to check the whole list
 //whether position is valid or not, we can directly use header data
 if(pos>header->data)
  printf("we can not found the position\n");
 else{
  struct node *p,*q=start;
  p=(struct node *)malloc(sizeof (struct node));
  p->data=node_data;
  p->next=NULL;
  while(pos>1)
  {
   q=q->next;
   pos--;
  }
  p->next=q->next;
  q->next=p;
  count++;
  header->data=count;
 }
 printf("after inserting after given position=\n");
 print();
}
int main()
{
 header=(struct node *)malloc(sizeof (struct node));
 start=(struct node *)malloc(sizeof (struct node));
 //initially header node conatains no data
 header->data=count;
 header->next=NULL;
 insert_at_front(3);
 insert_at_front(4);
 insert_at_end(5);
 insert_at_end(8);
 insert_after(2,7);
return 0;
}
