#include<stdio.h>
#include<conio.h>


int row, col;
SolveSudoku();
int grid();
int sudokuSolver();
int possibility(int grow, int gcol, int num);
void displaysudoku();



int sudoku[6][6]={{0, 0, 0, 1, 0, 6},
                  {6, 0, 4, 0, 0, 0},
                  {1, 0, 2, 0, 0, 0},
                  {0, 0, 0, 5, 0, 1},
                  {0, 0, 0, 6, 0, 3},
                  {5, 0, 6, 0, 0, 0}};

int main(){

int i, j, solution=0;
 char ch;
    printf("Sudoku 6x6: \n");
displaysudoku();
    printf("Press any 'e' to exit, or enter 's' to get solution.  \n");
    ch=getch();
    switch(ch){
    case 'e':
       break;
   case 's':

solution=sudokuSolver();


 printf("Solved Sudoku: \n");
 displaysudoku();

    break;
   default:
    printf("No Solution! \n");
    getch();
    }



return 0;
}
void displaysudoku(){
 int i,j;

 printf("\t----------------\n");
 for(i=0;i<6;i++){
    printf("\t");

    for(j=0;j<6;j++){
       if(j==3 || j==0)
    printf("| ");

       if(sudoku[i][j]==0)
    printf(". ");
       else
    printf("%d ",sudoku[i][j]);
  if(j==5)
        printf("|");
   }

   if(i==1 || i==3 || i==6)
       printf("\n\t-----------------");

   printf("\n");

 }
}
int grid(){
 int i,j;

 for(i=0;i<=5;i++)
     for(j=0;j<=5;j++){
  if(sudoku[i][j]==0)
   {
   row=i;col=j;
   return 1;

   }

     }
   return 0;

}
int possibility(int grow, int gcol, int num){
   int i,j,trow,tcol,trow1,tcol1;

     int rowStart = (grow/2) *3;
    int colStart = (gcol/3) *3;


   for(j=0;j<=5;j++){
       if(sudoku[grow][j]==num)
    return 0;
       if(sudoku[j][gcol]==num)
    return 0;

   }
    return 1;
}
int sudokuSolver(){

     int digit;
     int prevRow,prevCol;


     if(!grid())
 return 1;

     for(digit=1;digit<7;digit++){
  if(possibility(row,col,digit)){
  sudoku[row][col]=digit;
  prevRow=row;prevCol=col;
 if(sudokuSolver()
    )
   return 1;

  row=prevRow;col=prevCol;
  sudoku[row][col]=0;
  }

    }

    return 0;

}
