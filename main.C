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
    return(row>=0 && row<ROWS && col>=0 && col<COLS);
}

void drawRectangle(int row,int col,int height,int width,char ch)
{
    int i;
    for(i=col;i<col+width && isValid(row,i) && isValid(row+height-1,i);i++)
{
      if(isValid(row,i))
canvas[row][i]=ch;
      if(isValid(row+height-1,i))canvas[row+height-1][i]=ch;
}

for(i=row;i<row + height && isValid(i,col + width - 1);i++)
     {
          if(isValid(i,col)) canvas[i][col+width-1]=ch;
          if(isValid(i,col + width - 1))canvas[i][col+width-1]=ch;
      }
}

void drawFilledRectangle(int row,int col,int height,int width,char ch)
{
   int i,j;
   for(i=row;i<row+height && i<ROWS;i++)
   {
    
