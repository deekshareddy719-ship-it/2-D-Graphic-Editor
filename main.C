#include<stdio.h>
#include<math.h>
#define ROWS 25
#define COLS 60
char canvas[ROWS][COLS];
void initializeCanvas()
{
   int i,j;
   for(i=0;i<ROWS;i++) 
   {
       for(j=0;j<COLS;j++)
       {
           canvas[i][j]='_';
        }
    }
}
void displayCanvas()
{
    int i,j;
    printf("
");
   for(i=0;i<ROWS;i++)
   {
        for(j=0;j<COLS;j++)
        {
           printf("%c",canvas[i][j]);
          }
      printf("
");
}
 printf("
");
}

int isValid(int row,int col)
{
    return(row>=0 && row<ROWS && col
