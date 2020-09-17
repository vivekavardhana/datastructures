#include<stdio.h>

int main()
{
    int *p;         // pointer to int
    int (*parr)[5]; // pointer to an array of 5 integers
    int my_arr[5];  // an array of 5 integers

    p = my_arr; 
    parr = (int *) my_arr;

    printf("Address of p = %u\n", p );
    printf("Address of parr = %u\n", parr );

    p++;
    parr++;

    printf("\nAfter incrementing p and parr by 1 \n\n");
    printf("Address of p = %u\n", p );
    printf("Address of parr = %u\n", parr );
 
    // signal to operating system program ran fine
    return 0;
}
