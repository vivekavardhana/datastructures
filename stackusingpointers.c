#include<stdio.h>
#include<stdlib.h>
struct stackarr;
typedef struct stackarr * Stack;

struct stackarr
{
	int Capacity;
	int TopOfStack;
	int *Array;
};

void MakeEmpty(Stack s)
{
	s->TopOfStack = -1;
}

Stack CreateStack(int MaxElements)
{
	Stack s;
	s = (struct stackarr*) malloc(sizeof(struct stackarr));
	s->Array = (int *)malloc(sizeof(int) * MaxElements);
	s->Capacity = MaxElements;
	MakeEmpty(s);
	return s;
}

void DisposeStack(Stack s)
{
	if(s != NULL)
	{
		free(s->Array);
		free(s);
	}
}

int isFull(Stack s)
{
	return s->TopOfStack == s->Capacity - 1;
}

int isEmpty(Stack s)
{
	return s->TopOfStack == -1;
}

void Push(int x, Stack s)
{
	if(isFull(s))
		printf("Full Stack\n\n");
	else
		s->Array[++s->TopOfStack] = x;
}

void Pop(Stack s)
{
	if(isEmpty(s))
		printf("Empty Stack\n\n");
	else
		s->TopOfStack--;
}

int Top(Stack s)
{
	if(isEmpty(s))
		printf("Empty Stack\n\n");
	else
		return s->Array[s->TopOfStack];
}

int TopAndPop(Stack s)
{
	if(isEmpty(s))
		printf("Empty Stack\n\n");
	else
		return s->Array[s->TopOfStack--];
}

void Display(Stack s)
{
	int i;
	if(isEmpty(s))
		printf("Empty Stack\n\n");
	else
	{
		printf("The Stack Elements are :: ");
		for(i=s->TopOfStack; i >= 0; i--)
			printf("%d  ",s->Array[i]);
		printf("\n\n");
	}
}



void main()
{
	int n, x, ch, i;
	Stack s;
	printf("Enter the maximum number of elements in the stack :: ");
	scanf("%d", &n);
	s = CreateStack(n);
	printf("ARRAY IMPLEMENTATION OF STACK ADT\n\n");
	do
	{
		printf("\n\n1. PUSH\t 2. POP\t 3.TOP \t 4. TOPANDPOP\t 5. PRINT\t 6. QUIT\n\nEnter the choice :: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element to be pushed :: ");
				scanf("%d",&x);
				Push(x,s);
				break;

			case 2:
				Pop(s);
				break;

			case 3:
				printf("The Top element in the stack :: %d\n\n", Top(s));
				break;

			case 4:
				printf("The popped top element in the stack :: %d\n\n", TopAndPop(s));
				break;

			case 5:
				Display(s);
				break;
		}
	}while(ch<6);
	DisposeStack(s);
 
}
