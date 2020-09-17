#include<stdlib.h>
#include<stdio.h>
#define MAX_TERMS 100

typedef struct
{
            float coef;
            int exp;
}polynomial;

polynomial terms[MAX_TERMS];
int avail=0;

void pread(int num,int *start,int *finish)
{
            int i;
            *start=avail;
            for(i=0;i<num;i++)
            {
                        printf("Enter the coefficient and the exponent:\n");
                        scanf("%f%d",&terms[avail].coef,&terms[avail].exp);
                        avail++;
            }
            *finish=avail-1;
}

void attach(float coefficient,int exponent)
{
            if(avail>=MAX_TERMS)
            {
                        printf("\nToo many terms, So invalid\n");
                        exit(EXIT_FAILURE);
            }
            terms[avail].coef=coefficient;
            terms[avail++].exp=exponent;
}

int compare(int exp1,int exp2)
{
            if(exp1<exp2)
                        return -1;
            else if(exp2<exp1)
                        return 1;
            else
                        return 0;
}

void padd(int startA,int finishA,int startB,int finishB,int *startD,int *finishD)
{
            float coefficient;
            *startD=avail;
            while(startA<=finishA&&startB<=finishB)
                        switch(compare(terms[startA].exp,terms[startB].exp))
                        {
                                    case -1:
                                                attach(terms[startB].coef,terms[startB].exp);
                                                startB++;
                                                break;
                                    case 0:
                                                coefficient=terms[startA].coef+terms[startB].coef;
                                                if(coefficient)
                                                            attach(coefficient,terms[startB].exp);
                                                startA++;
                                                startB++;
                                                break;
                                    case 1:
                                                attach(terms[startA].coef,terms[startA].exp);
                                                startA++;
                        }
            for(;startA<=finishA;startA++)
                        attach(terms[startA].coef,terms[startA].exp);
            for(;startB<=finishB;startB++)
                        attach(terms[startB].coef,terms[startB].exp);
            *finishD=avail-1;
}
void pprint(int start,int finish)
{
            int i;
            for(i=start;i<=finish;i++)
            {
                        printf("%fX^%d",terms[i].coef,terms[i].exp);
                        if(i<finish)
                                    printf("  +  ");
            }
            printf("\n");
}
void main()
{
            int num;
            int startA,finishA,startB,finishB,startD,finishD;
            printf("\nEnter the number of terms in first polynomial\n");
            scanf("%d",&num);
            pread(num,&startA,&finishA);
            printf("\nEnter the number of terms in second polynomial\n");
            scanf("%d",&num);
            pread(num,&startB,&finishB);
            padd(startA,finishA,startB,finishB,&startD,&finishD);
            printf("\nFirst polynomial is:\n");
            pprint(startA,finishA);
            printf("\nSecond polynomial is:\n");
            pprint(startB,finishB);
            printf("\nFinal polynomial is:\n");
            pprint(startD,finishD);
}