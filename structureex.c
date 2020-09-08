#include <stdio.h>
#include <string.h>
struct student
{
    int rollno;
    char name[60];
} s1; //declaring s1 variable for structure
void main()
{
    //store first employee information
    s1.rollno = 1;
    strcpy(s1.name,"Ashok");     //copying string into char array
    //printing first employee information
    printf("Rollno : %d\n", s1.rollno);
    printf("Name   : %s\n\n\n", s1.name);
}