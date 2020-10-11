#include <stdio.h>

#define MAX 4

int stack[MAX], item;
int ch, top = -1, count = 0, status = 0;

/*PUSH FUNCTION*/
void push(int stack[], int item)
{
    if (top == (MAX - 1))
        printf("\n\nStack is Overflow");
    else
    {
        stack[++top] = item;
        status++;
    }
}

/*POP FUNCTION*/
int pop(int stack[])
{
    int ret;
    if (top == -1)
        printf("\n\nStack is Underflow");
    else
    {
        ret = stack[top--];
        status--;
        printf("\nPopped element is %d", ret);
    }
    return ret;
}

/* FUNCTION TO CHECK STACK IS PALINDROME OR NOT */
void palindrome(int stack[])
{
    int i, temp;
    temp = status;
    for (i = 0; i < temp; i++)
    {
        if (stack[i] == pop(stack))
            count++;
    }
    if (temp == count)
        printf("\nStack contents are Palindrome");
    else
        printf("\nStack contents are not palindrome");
}
/*FUNCTION TO DISPLAY STACK*/
void display(int stack[])
{
    int i;
    printf("\nThe stack contents are:");
    if (top == -1)
        printf("\nStack is Empty");
    else
    {
        for (i = top; i >= 0; i--)
            printf("\n ------\n| %d |", stack[i]);
        printf("\n");
    }
}
/*MAIN PROGRAM*/
void main()
{
    do
    {
        printf("\n\n----MAIN MENU----\n");
        printf("\n1. PUSH (Insert) in the Stack\n");
        printf("\n2. POP (Delete) from the Stack");
        printf("\n3. PALINDROME check using Stack");
        printf("\n4. Exit (End the Execution)");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter a element to be pushed: ");
            scanf("%d", &item);
            push(stack, item);
            display(stack);
            break;

        case 2:
            item = pop(stack);
            display(stack);
            break;
        case 3:
            palindrome(stack);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("\nEND OF EXECUTION");
        } //end switch
    } while (ch != 4);
}