#include <stdio.h>
#include <string.h>

void main()
{

    typedef struct
    {
        int month;
        int day;
        int year;
    } date;
    typedef struct
    {
        char name[10];
        int age;
        double salary;
        date dob;
    } humanbeing;
    humanbeing person1;
    strcpy(person1.name, "james");
    person1.age = 10;
    person1.salary = 35000;
    person1.dob.month = 2;
    person1.dob.day = 11;
    person1.dob.year = 1944;
    printf("\n details of the person");
    printf("\n name=%s age=%d salary=%f dob=%d-%d-%d\n\n\n", person1.name,
           person1.age, person1.salary, person1.dob.day, person1.dob.month, person1.dob.year);
     
}