#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct
{
    char name[10];
    int age;
    float salary;
} humanbeing;

int humansEqual(humanbeing p1, humanbeing p2)
{

    if (strcmp(p1.name, p2.name))
        return FALSE;
    if (p1.age != p2.age)
        return FALSE;
    if (p1.salary != p2.salary)
        return FALSE;

    else

        return TRUE;
}
void main()
{

    humanbeing p1, p2;

    strcpy(p1.name, "aab");
    p1.age = 12;
    p1.salary = 12000;
    strcpy(p2.name, "aa");
    p2.age = 12;
    p2.salary = 12000;
    if (humansEqual(p1, p2))

        printf("\n persons are same \n\n\n");

    else
        printf("\n persons are not same\n\n\n");
}
