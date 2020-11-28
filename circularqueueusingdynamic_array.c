#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct Q
{
    int elements[MAX], front, rear;
};

void enq(struct Q *);
void display(struct Q *);
main()
{
    int n, i;
    struct Q *qptr = (struct Q *)malloc(sizeof(struct Q *));
    qptr->front = -1;
    qptr->rear = -1;
    printf("enter the number of elements");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        enq(qptr);
    display(qptr);
}
void enq(struct Q *qptr)
{
    int val;
    if ((qptr->front == 0 && qptr->rear == MAX - 1) || (qptr->front == qptr->rear + 1))
    {
        printf("Queue full");
        return;
    }
    else if (qptr->front == -1 && qptr->rear == -1)
    {
        qptr->front = 0;
        qptr->rear = 0;
    }
    else if (qptr->rear == MAX - 1)
        qptr->rear == 0;
    else
        qptr->rear = qptr->rear + 1;
    printf("enter the data to be entered\n");
    scanf("%d", &val);
    qptr->elements[qptr->rear] = val;
}

void display(struct Q *qptr)
{
    int i;
    for (i = qptr->front; i <= qptr->rear; i++)
        printf("%d\t", qptr->elements[i]);
}
