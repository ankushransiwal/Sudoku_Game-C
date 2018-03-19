#include<conio.h>
#include<stdio.h>
#include<math.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int array[9][9]={{5,3,4,6,7,8,9,1,2},
		 {6,7,2,1,9,5,3,4,8},
		 {1,9,8,3,4,2,5,6,7},
		 {8,5,9,7,6,1,4,2,3},
		 {4,2,6,8,5,3,7,9,1},
		 {7,1,3,9,2,4,8,5,6},
		 {9,6,1,5,3,7,2,8,4},
		 {2,8,7,4,1,9,6,3,5},
		 {3,4,5,2,8,6,1,7,9}};

int Question[9][9]={{5,3,0,0,7,0,0,0,0},
		 {6,0,0,1,9,5,0,0,0},
		 {0,9,8,0,0,0,0,6,0},
		 {8,0,0,0,6,0,0,0,3},
		 {4,0,6,8,0,3,0,0,1},
		 {7,0,0,0,2,0,0,0,6},
		 {0,6,0,0,0,0,2,8,0},
		 {0,0,0,4,1,9,0,0,5},
		 {0,0,0,0,8,0,0,7,9}};

int copy[9][9]={{5,3,0,0,7,0,0,0,0},
		 {6,0,0,1,9,5,0,0,0},
		 {0,9,8,0,0,0,0,6,0},
		 {8,0,0,0,6,0,0,0,3},
		 {4,0,6,8,0,3,0,0,1},
		 {7,0,0,0,2,0,0,0,6},
		 {0,6,0,0,0,0,2,8,0},
		 {0,0,0,4,1,9,0,0,5},
		 {0,0,0,0,8,0,0,7,9}};


void main()
{

  int spaces=50,r,c,row[10],i,j=0,col[10],flag;
  int region[10],regionrow,regioncol,actr,actc,num;
  printf("\n  Welcome to Sudoku \n");
		for ( i = 1; i<=9; i++)
		{
		if(i==1)
		{
				
				printf("\n");
				printf(ANSI_COLOR_YELLOW"   ---------+---------+--------- "ANSI_COLOR_RESET);
				printf("\n");
		}
	

		 for ( j = 1; j<=9; j++)
		 {
		   if(j==1)printf(ANSI_COLOR_YELLOW"  |"ANSI_COLOR_RESET);
		   if(Question[i-1][j-1]!=0)
			printf(ANSI_COLOR_GREEN" %d "ANSI_COLOR_RESET,Question[i-1][j-1]);
		   else
			printf(ANSI_COLOR_CYAN" . "ANSI_COLOR_RESET);
		   if(j%3==0 )printf(ANSI_COLOR_YELLOW"|"ANSI_COLOR_RESET);
			
		   

		 }
		 printf("\n");
		 if(i%3==0 )
			{
				printf(ANSI_COLOR_YELLOW"  |---------+---------+---------|"ANSI_COLOR_RESET);
				printf("\n");
			}
		
		
		 }


  do
  {




	flag=0;
	printf("\n You have %d spaces",spaces);
	spaces=0;
	printf("\n Choose the square by entering its row and coloumn ");
	scanf("%d%d",&r,&c);
	actr=r-1;//making the row entered interms of array
	actc=c-1;//making the col entered interms of array
	printf("\n Please add number.. ");
	scanf("%d",&num);
	//copying the contents of r row to row array
	for(i=0;i<9;i++)
	{
	    row[i]=Question[actr][i];
	}
	//copying the contents of c col to col array
	for(i=0;i<9;i++)
	{
	    col[i]=Question[i][actc];
	}
	//assigning region number
	if(actr==0||actr==1||actr==2)
	{
	  regionrow=0;
	}
	else if(actr==3||actr==4||actr==5)
	{
	  regionrow=3;
	}
	else if(actr==6||actr==7||actr==8)
	{
	  regionrow=6;
	}


	if(actc==0||actc==1||actc==2)
	{
	  regioncol=0;
	}
	else if(actc==3||actc==4||actc==5)
	{
	  regioncol=3;
	}
	else if(actc==6||actc==7||actc==8)
	{
	  regioncol=6;
	}
	//copying the contents of region
	for(i=regionrow;i<(regionrow+3);i++)
	{
	    for(j=regioncol;j<(regioncol+3);j++)
	    {
		region[i]=Question[i][j];
	    }
	}



	//checking if the number entered is present or not
	if(copy[actr][actc]==0)
	{
		goto jump;
	}

	flag=1;
	printf(ANSI_COLOR_RED"\n You cannot change predefined values"ANSI_COLOR_RESET);

	jump:

	for(i=0;i<9;i++)
	{
	    if(row[i]==num)
	    {
	    printf(ANSI_COLOR_RED"\n The number already exist in the row"ANSI_COLOR_RESET);
	    flag=1;
	    }

	    if(col[i]==num)
	    {
	    printf(ANSI_COLOR_RED"\n The number already exist in the colounm"ANSI_COLOR_RESET);
	    flag=1;
	    }

	    if(region[i]==num)
	    {
	    printf(ANSI_COLOR_RED"\n The number already exist in the cell"ANSI_COLOR_RESET);
	    flag=1;
	    }


	}
	if(flag==0)
	{
		Question[actr][actc]=num;}
		for ( i = 1; i<=9; i++)
		{
		if(i==1)
		{
				
				printf("\n");
				printf(ANSI_COLOR_YELLOW"   ---------+---------+--------- "ANSI_COLOR_RESET);
				printf("\n");
		}
	

		 for ( j = 1; j<=9; j++)
		 {
		   if(j==1)printf(ANSI_COLOR_YELLOW"  |"ANSI_COLOR_RESET);
		   
		   if(copy[i-1][j-1]!=0)
		   {
		 	if(Question[i-1][j-1]!=0)
				printf(ANSI_COLOR_GREEN" %d "ANSI_COLOR_RESET,Question[i-1][j-1]);
		   	else
				printf(ANSI_COLOR_CYAN" . "ANSI_COLOR_RESET);
		   }
		   else
		   {
			if(Question[i-1][j-1]!=0)
				printf(" %d ",Question[i-1][j-1]);
		   	else
				printf(ANSI_COLOR_CYAN" . "ANSI_COLOR_RESET);
		   }
		   
		   if(j%3==0 )printf(ANSI_COLOR_YELLOW"|"ANSI_COLOR_RESET);
			
		   

		 }
		 printf("\n");
		 if(i%3==0 && i!=9)
			{
				printf(ANSI_COLOR_YELLOW"  |---------+---------+---------|"ANSI_COLOR_RESET);
				printf("\n");
			}
		 if(i==9)
		{
				
				printf(ANSI_COLOR_YELLOW"   ---------+---------+--------- "ANSI_COLOR_RESET);
				printf("\n");
		}
		
		 }

for ( i = 0; i<9; i++)
{
for ( j = 0; j<9; j++)
{
if(Question[i][j]==0)
spaces++;
}
}
}while(spaces!=0);
if(spaces==0)
	printf(ANSI_COLOR_GREEN" Congratulations You have Completed the Game Sucessfully "ANSI_COLOR_RESET);

getch();
}