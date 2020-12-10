#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int insq( int queue[MAX], int qno, int rear[], int limit[], int *ele)
{
      if( rear[qno] == limit[qno] ) 
            return(-1);
      else
      {
            rear[qno]++; //... rear[qno] = rear[qno] + 1;
            queue[ rear[qno] ] = *ele;
            return(1);
      }
}
int delq( int queue[MAX], int qno, int front[], int rear[], int *ele)
{
      if( front[qno] == rear[qno] )
            return(-1);
      else
      {
            front[qno]++; //... front[qno] = front[qno] + 1;
            *ele = queue[ front[qno] ];
            return(1);
      }
}
int main()
{
      int queue[MAX],ele;
      int bott[10], limit[10], f[10], r[10];
      int i, n,qno,size,ch,reply;
      printf("How many queues you want to enter? : ");
      scanf("%d", &n);
      size = MAX / n; //Get maximum size for each queue
      //Initialize bottom for each Queue
      bott[0] = -1; //Bottom of first queue is -1
      for(i = 1; i < n; i++)
            bott[i] = bott[i-1] + size; //Initialize limit of each queue
      for(i = 0; i < n; i++)
      {
            limit[i] = bott[i] + size; //Initialize Front & Rear of each Queue
      }
      //Initial value of Front & Rear of each queue is same as its Bottom Value
      for(i = 0; i < n; i++)
            f[i] = r[i] = bott[i];
      printf("-------------------------------------\n");
      printf("\tMenu");
      printf("\n------------------------------------");
      printf("\n 1. Insert in element Queue");
      printf("\n 2. Delete element from a Queue");
      printf("\n 3. Exit \n");
      printf("------------------------------------\n");
      while(1)
      {
            printf("Choose operation : ");
            scanf("%d", &ch);
            switch(ch)
            {
                  case 1 : //... Insert
                        printf("\nEnter logical queue number (0 to %d) : ", n-1);
                        scanf("%d", &qno);
                        printf("Element to be entered in queue number %d : ",qno);
                        scanf("%d", &ele);
                        reply = insq(queue, qno, r, limit, &ele);
                        if( reply == -1)
                              printf("Queue %d is full \n", qno);
                        else
                              printf("%d is inserted in queue number %d.\n\n", ele, qno);
                        break;
                  case 2 : //... Delete
                        printf("\nEnter logical queue number (0 to %d) : ", n-1);
                        scanf("%d", &qno);
                        reply = delq(queue, qno, f, r, &ele);
                        if( reply == -1)
                              printf("\n Queue %d is empty. \n", qno);
                        else
                              printf("%d is deleted from queue number %d \n\n",ele, qno);
                        break;
                  case 3 : exit(0);
                  default: printf("Invalid operation \n");
            }
      }
      return 0;
}
