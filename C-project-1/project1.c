#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<windows.h>


// create matrix 4*4
void  createMatrix(int arr[][4])
{
    int n=15;
    int num[n],i,j;
    for(i=0;i<15;i++)        
    num[i]=i+1;

    srand(time(NULL));           

    int lastIndex=n-1,index;

    for(i=0;i<4;i++)
    for(j=0;j<4;j++)
  {
    if(lastIndex>=0)
    {  index=rand()%(lastIndex+1); 
       arr[i][j]=num[index];       
       num[index]=num[lastIndex--]; 
    }                               
  }
       arr[i-1][j-1]=0;         

}

// showing matrix
void showMatrix(int arr[][4])
{
    int i,j;
    printf("--------------------\n");
    for(i=0;i<4;i++)
   { printf("|");
       for(j=0;j<4;j++)
    {   if(arr[i][j]!=0)
        printf("%-2d | ",arr[i][j]);
        else
        printf("   | ");
    }
    printf("\n");
   }

    printf("--------------------\n");
}

// winning check by this function
int winner(int arr[][4])
{
    int i,j,k=1;
    for(i=0;i<4;i++)
   { for(j=0;j<4;j++,k++)
        if(arr[i][j]!=k && k!=16)
        break;
    if(j<4)
    break;
   }
        if(j<4)
        return 0;
        return 1;
}

// swap function to swap two numbers
void swap(int *x,int *y)
{
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
    printf("");
}


int readEnteredKey()
{
        char c;
            c=_getch();
            if(c==-32)
            c=_getch();

    return c;
}

// shift up function
int MoveUp(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(i==3)                 
        return 0;
        swap(&arr[i][j],&arr[i+1][j]);
        return 1;               
}

int MoveDown(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(i==0)                 
        return 0;
         swap(&arr[i][j],&arr[i-1][j]);    

        return 1;             
}

int MoveRight(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(j==0)                
        return 0;
             swap(&arr[i][j],&arr[i][j-1]);

        return 1;               
}

int MoveLeft(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(j==3)                 
        return 0;
                swap(&arr[i][j],&arr[i][j+1]);
        return 1;               
}

// Game rules
void gameRule(int arr[][4])
{
    system("cls");

    int i,j,k=1;
    printf("                <============ RULE OF THIS GAME =============>                \n");
    printf("\n ==>1.You can move only 1 step at a time by arrow key ");
    printf("\n ==>Move Up   : by Up arrow key ");
    printf("\n ==>Move Down : by Down arrow key");
    printf("\n ==>Move Left : by Left arrow key");
    printf("\n ==>Move Right: by Right arrow key");

    printf("\n ==>2.You can move number at empty position only ");
    printf("\n");
    printf("\n ==>3.For each valid move : your total number of move will decreased by 1 \n");
    printf(" -->4.Wining situation : ");
    printf(" ==>number in a 4*4 matrix should be in order from 1 to 15 ");
    printf("\n\n            ----winning situation-----         \n");

    printf("---------------------\n");
    for(i=0;i<4;i++)
   { printf("| ");
       for(j=0;j<4;j++)
    {   if(arr[i][j]!=0)
        printf("%-2d | ",4*i+j+1);
        else
        printf("   |");
    }
    printf("\n");
   }

    printf("---------------------\n");
    printf("\n ==>5.You can exit the game at any time by pressing 'E' or 'e' ");


    printf("\n ==>So Try to win in minimum no of move \n");
    printf("\n         Happy gaming , Good Luck\n");

    printf("\n ==>Enter any key to start.....   ");
   int x=readEnteredKey();
}

// main function
int main()
{
    int arr[4][4];       
    int maxTry=100;       
    char name[20];
    system("color 0e");
   system("cls");        
      Beep(1000 ,500);
        // return 0;
    printf("Enter Player Name:- ");
    scanf("%s",name);

       while(1)
    {             createMatrix(arr);    
                  gameRule(arr);      
          while(!winner(arr))     
        {
               system("cls");
               if(!maxTry)       
                break;

               printf("\n\n  welcome  %s  ,  Move remaining : %d\n\n",name,maxTry);

              showMatrix(arr);     


            int key=readEnteredKey();  

        switch(key)          
        {
            case 69:                  // ascii of E

            case 101:                 // ascii of e
                        printf("\a\a\a\a\a\a\n     Thanks for Playing ! \n\a");
                        printf("\n Hit 'Enter' to exit the game \n");
                        key=readEnteredKey();
                        exit(0);


            case 72:          // arrow up
                        if(MoveUp(arr))
                        maxTry--;
                        break;
            case 80:          // arrow down
                        if(MoveDown(arr))
                        maxTry--;
                        break;
            case 77:            // arrow  right
                        if(MoveRight(arr))
                        maxTry--;
                        break;
            case 75:             // arrow left
                        if(MoveLeft(arr))
                        maxTry--;
                        break;
            default:

                       printf("\n\n      \a\a Not Allowed \a");
                     
        }

        }
        // Beep(500,500);
        Beep(1000,1500);
        if(!maxTry)
         printf("\n\a          YOU LOSE !          \a\a\n");
         else
         { printf("\n\a!!!!!!!!!!!!! Congratualization !!!!!!!!!!!!!\n\a");
           printf("\a               You have Won      \a\a\a ");
         }
         char check;
        printf("\nwant to play again ? \n");
        printf("enter 'y' to play again:  ");
        scanf("%c",&check);
        if(check!='y' && check!='Y')
            break;
        maxTry=100;
    }
    return 0;
}