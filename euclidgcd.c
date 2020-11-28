#include <stdio.h>

int gcd(int, int);

int main()
{
    int num1, num2;

    printf("Enter two integers: ");
    scanf("%d%d", &num1, &num2);

    printf("The greatest common divisor of %d and %d is %d", num1, num2, gcd(num1, num2));
    return 0;
}

int gcd(int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}