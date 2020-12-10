#include<stdio.h>
#include<stdlib.h> 

typedef struct
{
      short int vert;
      short int horiz;
}Offsets;

Offsets move[8];

typedef struct
{
       short int row;
       short int col;
       short int dir;
}Element;

Element Stack[50];
int maze[10][10];
int mark[10][10];
int top=-1;
int exit_row,exit_col;

void readMaze()
{
         int r, c;
         int i, j;

         printf("\nEnter the no of rows in the matrix: ");
         scanf("%d", &r);

         printf("\nEnter the no of cols in the matrix:   ");
         scanf("%d",&c);

         printf("\nEnter the elements of the matrix:   ");
         for(i=0;i<r;i++)
        {
                 for(j=0;j<c;j++)
                 {
                          scanf("%d",&maze[i][j]);
                  }
        }
        exit_row = r-2;
        exit_col = c-2;
}

void setMoveTable()
{
          move[0].vert = -1,  move[0].horiz = 0;
          move[1].vert = -1,  move[1].horiz = 1;
          move[2].vert = 0,   move[2].horiz = 1;
          move[3].vert = 1,   move[3].horiz = 1;
          move[4].vert = 1,   move[4].horiz = 0;
          move[5].vert = 1,   move[5].horiz = -1;
          move[6].vert = 0,   move[6].horiz = -1;
          move[7].vert = -1,  move[7].horiz = -1;
}

void push(Element ele)
{
          top = top+1;
          Stack[top].row = ele.row;
          Stack[top].col = ele.col;
          Stack[top].dir = ele.dir;
          return;
}

Element pop()
{
          Element delItem;
          delItem.row = Stack[top].row;
          delItem.col = Stack[top].col;
          delItem.dir = Stack[top].dir;
          top = top-1;
          return delItem;
}

void findpath()
/* function to search for path in the maze */
{
          int i,row,col,nextRow,nextCol,dir,found=0;
          Element position;
          mark[1][1] = 1,top=0;
          Stack[0].row = 1;
          Stack[0].col = 1;
          Stack[0].dir = 0;

          while(top>-1 && !found)
         {
                   position = pop();

                   row = position.row;
                   col = position.col;
                   dir = position.dir;

                   while(dir<8 && !found)
                   {
                             nextRow = row + move[dir].vert;
                             nextCol = col + move[dir].horiz;

                             if(nextRow == exit_row && nextCol == exit_col)
                                           found = 1;

                             else if(!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
                             {
                                           mark[nextRow][nextCol] = 1;
                                           position.row = row;
                                           position.col = col;
                                           position.dir = ++dir;
                                           push(position);
                                           row = nextRow;
                                           col = nextCol;
                                           dir = 0;
                             }
                            else
                                       ++dir;
                  }
          }
          if(found)
          {
                     printf("\nThe path is:\n");
                     printf("row \t col \n");
                     for(i=0;i<=top;i++)
                             printf("%2d%5d \n",Stack[i].row,Stack[i].col);
               
                     printf("%2d%5d\n",row,col);
                     printf("%2d%5d\n",exit_row,exit_col);
            }
            else
                     printf("\nThe given maze does not have a path");
}

int main()
{
           readMaze();
           setMoveTable();
           findpath();
           return 1;
}
