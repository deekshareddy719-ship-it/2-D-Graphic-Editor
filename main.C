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
   for(i=0;i<ROWS;i++)
   {
        for(j=0;j<COLS;j++)
        {
           printf("%c",canvas[i][j]);
          }
      printf("\n");
}
}

int isValid(int row,int col)
{
    return(row>=0 && row<ROWS && col>=0 && col<COLS);
}

void drawRectangle(int row,int col,int height,int width,char ch)
{
    int i;
    for(i=col;i<col+width && isValid(row,i) && isValid(row + height - 1,i);i++)
{
      if(isValid(row,i))
canvas[row][i]=ch;
      if(isValid(row + height - 1,i))canvas[row + height - 1][i]=ch;
}

for(i=row;i<row + height && isValid(i,col + width - 1);i++)
     {
          if(isValid(i,col)) canvas[i][col + width - 1]=ch;
          if(isValid(i,col + width - 1))canvas[i][col + width - 1]=ch;
      }
}

void drawFilledRectangle(int row,int col,int height,int width,char ch)
{
   int i,j;
   for(i=row;i<row+height && i<ROWS;i++)
   {
      for(j=col;j<col+width && j<COLS;j++)
        {
            if(isValid(i,j))
            canvas[i][j]=ch;
         }
     }
}

void drawLine(int row,int starCol,int endCol,char ch)
{
    int i;
    for(i=starCol;i<endCol;i++)
    {
      if(isValid(row,i))
     canvas[row][i]=ch;
  }
}

void drawTriangle(int row,int col,int height,char ch)
{
     int i;
     int baseStart,baseEnd;
     for(i=0;i<height;i++)
      {
          int left=col-i;
          int right=col+i;
         if(isValid(row+i,left))
         canvas[row+i][left]=ch;
         if(isValid(row+i,right))
         canvas[row+i][right]=ch;
}
baseStart=col - height + 1;
baseEnd=col + height - 1;
for(i=baseStart;i<=baseEnd;i++)
{
    if(isValid(row + height - 1,i))canvas[row + height - 1][i]=ch;
 }
}

void drawCircle(int xc,int yc,int radius,char ch);
{
     int angle;
     double pi=(3.14159265359);
     for(angle=0;angle<360;angle++)
     {
        double cos_val=cos(angle*pi/180);
        double sin_val=sin(angle*pi/180);

      int x=xc+(int)(radius*sin_val);
       int y=yc+(int)(radius*cos_val);
       if(isValid(x,y))
        {
           canvas[x][y]=ch;
         }
     }
}

int main()
{
    int choice;
     initializeCanvas();
   do
   {
        printf("==== 2D GRAPHICS EDITOR ====\n");
        printf("1.Draw Rectangle(Outline)\n");
        printf("2.Draw Filled Rectangle\n");
        printf("3.Draw Line\n");
        printf("4.Draw Triangle\n");
        printf("5.Draw Circle\n");
        printf("6.Delete Rectangle\n");
        printf("7.Delete Line\n");
        printf("8.Delete Canvas\n");
        printf("9.Clear Canvas\n");
        printf("10.Exit\n");
      printf("Enter Choice:\n");
      scanf("%d",&Choice);

    switch(choice)
    {
       case 1:
       {
           int r,c,h,w;
           printf("Enter Row Col Height Width:");
           scanf("%d%d%d%d",&r,&c,&h,&w);
            if(h<=0 || w<=0)
           {
               printf("Error: Height and width must be positive!");
            }
          else
              {
              drawRectangle(r,c,h,w,'*');
               printf("Rectangle drawn!\n");
               }
                break;
              }
   case 2:
     {
        int r,c,h,w;
      printf("Enter Row COl Height Width:");
      scanf("%d%d%d%d",&r,&c,&h,&w);
      if(h<=0 || w<=0){
       printf("Error: Height and Width must be positive!");
      }
      else{
     drawFilledRectangle(r,c,h,w,'*');
       printf("Filled rectangle drawn!\n");
       }
      break;
}

case 3:
   {
     int row,start,end;
   printf("Enter Row StartCol EndCol:");
   scanf("%d%d%d",&row,&start,&end);
   if(start>end)
{
    printf("Error: StartCol must be <=EndCol!");
   }
  else{
    drawLine(row,start,end,'*');
    printf("Line drawn!\n");
   } 
   break;
}
case 4: 
{
   int row,col,height;
   printf("Enter TopRow CenterCol Height:");
    scanf("%d%d%d",&row,&col,&height);
    if(height<=0){
        printf("Error: Height must be positive!");
      else{
       drawTriangle(row,col,height,'*');
       printf("Triangle drawn!\n");
      }
    break;
    }
case 5: 
    {
       int x,y,r;
       printf("Enter CenterRow CenterCol Radius:");
       scanf("%d%d%d",&x,&y,&r);
        if(r<=0){
         printf("Error:Radius must be positive!");
         }
      else{
        drawCircle(x,y,r,'*');
         printf("Circle drawn!\n");
       }
     break;
   }

case 6:
{
     int r,c,h,w;
     printf("Enter Row Col Height Width:");
     scanf("%d%d%d%d",&r,&c,&h,&w);
      if(h<=0 || w<=0){
         printf("error: height and Width must be positive!");
        }
      else{
     drawRectangle(r,c,h,w,'_');
     printf("Rectangle deleted!\n");
  }
break;
}

case 7: 
{
  int row,start,end;
 printf("Enter Row StartCol EndCol:");
scanf("%d%d%d",&row,&start,&end);
    if(start>end){
       printf("Error: StartCol must be <= EndCol!");
       }
     else{
       drawLine(row,start,end,'_');
        printf("Line deleted!\n");
        }
      break;
   }

case 8:
   displayCanvas();
    break;

case 9:
   initializeCanvas();
   printf("Canvas cleared successfully!\n");
   break;

case 10:
   printf("Exiting... Thank you for using 2D Graphics Editor!\n");
   break;
   default:
      printf("Invalid Chocie! Please enter 1-10.");
   }
}while(choice !=10);
return 0;
}
