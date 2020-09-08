#include <stdio.h>

struct employee
{
    char ename[10];
    int sal;
};
struct employee emp[5];
int i, j;
void ask()
{
    for (i = 0; i < 3; i++)
    {
        printf("\nEnter %dst employee record\n", i + 1);
        printf("\nEmployee name\t");
        scanf("%s", emp[i].ename);
        printf("\nEnter employee salary\t");
        scanf("%d", &emp[i].sal);
    }
    printf("\nDisplaying Employee record\n");
    for (i = 0; i < 3; i++)
    {
        printf("\nEmployee name is %s", emp[i].ename);
        printf("\nSlary is %d", emp[i].sal);
    }
}
void main()
{
    ask();
}