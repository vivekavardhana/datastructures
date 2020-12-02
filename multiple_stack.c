#include <stdio.h>

#include <malloc.h>

#define MAX 10
int stack[MAX], topA = -1, topB = MAX;
void pushA(int val) {
  if (topA == topB - 1)
    printf("\n Overflow");
  else {
    topA += 1;
    stack[topA] = val;
  }
}
int popA() {
  int val;
  if (topA == -1) {
    printf("\n Underflow");
    val = -999;
  } else {
    val = stack[topA];
    topA--;
  }
  return val;
}
void display_stackA() {
  int i;
  if (topA == -1)
    printf("\n Stack A is empty");
  else {
    for (i = topA; i >= 0; i--)
      printf("\t %d", stack[i]);
  }
}
void pushB(int val) {
  if (topB - 1 == topA)
    printf("\n Overflow");
  else {
    topB -= 1;
    stack[topB] = val;
  }
}
int popB() {
  int val;
  if (topB == MAX) {
    printf("\n Underflow");
    val = -999;
  } else {
    val = stack[topB];
    topB++;
  }
}
void display_stackB() {
  int i;
  if (topB == MAX)
    printf("\n Stack B is Empty");
  else {
    for (i = topB; i < MAX; i++)
      printf("\t %d", stack[i]);
  }
}
int main() {
  int option, val;
  do {
    printf("\n -----Menu----- ");
    printf("\n 1. PUSH a element into Stack A");
    printf("\n 2. PUSH a element into Stack B");
    printf("\n 3. POP a element from Stack A");
    printf("\n 4. POP a element from Stack B");
    printf("\n 5. Display the Stack A");
    printf("\n 6. Display the Stack B");
    printf("\n 7. Exit");
    printf("\n Enter your choice");
    scanf("%d", & option);
    switch (option) {
    case 1:
      printf("\n Enter the value to push on stack A :");
      scanf("%d", & val);
      pushA(val);
      break;
    case 2:
      printf("\n Enter the value to push on stack B:");
      scanf("%d", & val);
      pushB(val);
      break;
    case 3:
      if (val != -999)
        printf("\n The value popped from Stack A = %d", val);
      break;
    case 4:
      if (val != -999)
        printf("\n The value popped from Stack B = %d", val);
      break;
    case 5:
      printf("\n The contents of Stack A are :\n");
      display_stackA();
      break;
    case 6:
      printf("\n The contents of Stack B are :\n");
      display_stackB();
      break;
    }
  } while (option != 7);
  return 0;
}
