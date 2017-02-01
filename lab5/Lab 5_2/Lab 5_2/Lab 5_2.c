#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define NUMBER_OF_DICE 3
#define WIDTH_OF_DICE 13
#define HIGHT_OF_ONE_DICE 6
#define POSSIBLE_DICE_VALUES 6


void display( char dice [] [HIGHT_OF_ONE_DICE] [WIDTH_OF_DICE],
	int three_different_throws[]);
int check_for_doubles(int three_different_throws[]);

int check_for_triplets(int three_different_throws[]);
void main()
{
	int count_triple=0,count_double=0;
	int *p1=&count_triple;
	
	char dice [POSSIBLE_DICE_VALUES][HIGHT_OF_ONE_DICE][WIDTH_OF_DICE]=
	{
		{                               
			{" _________ \0"},
			{"|         |\0"},
			{"|         |\0"},
			{"|    O    |\0"},
			{"|         |\0"},
			{"|_________|\0"}},

		{
			{" _________ \0"},
			{"|         |\0"},
			{"| O       |\0"},
			{"|         |\0"},
			{"|       O |\0"},
			{"|_________|\0"}},

		{
			{" _________ \0"},
			{"|         |\0"},
			{"| O       |\0"},
			{"|    O    |\0"},
			{"|       O |\0"},
			{"|_________|\0"}},

		{
			{" _________ \0"},
			{"|         |\0"},
			{"| O     O |\0"},
			{"|         |\0"},
			{"| O     O |\0"},
			{"|_________|\0"}},

		{
			{" _________ \0"},
			{"|         |\0"},
			{"| O     O |\0"},
			{"|    O    |\0"},
			{"| O     O |\0"},
			{"|_________|\0"}},

		{
			{" _________ \0"},
			{"|         |\0"},
			{"| O  O  O |\0"},
			{"|         |\0"},
			{"| O  O  O |\0"},
			{"|_________|\0"}},
	};

	int three_different_throws[NUMBER_OF_DICE]={0};
	while(1)
	{

		// throw three times and display result on screen using display function
		display(dice, three_different_throws);
		
		
		count_double=count_double+check_for_doubles(three_different_throws);
		printf("*** double %i ",count_double);
		count_triple=count_triple+check_for_triplets(three_different_throws);
		printf("*** triplets %i ***\n",count_triple);





		Sleep(1000);
	}
}

void display( char dice [] [HIGHT_OF_ONE_DICE] [WIDTH_OF_DICE],
	int three_different_throws[])
{
	int i,j,k;
	three_different_throws[0]=rand()%6;
	three_different_throws[1]=rand()%6;
	three_different_throws[2]=rand()%6;



	for (j=0;j<HIGHT_OF_ONE_DICE;j++)
	{
		for (i=0;i<3;i++)
		{
		for (k=0;k<WIDTH_OF_DICE;k++)
		{
			printf ("%c",dice[three_different_throws[i]][j][k]);
			
    	}
		printf("  ");
			
		}
		printf("\n");
	}


}


int check_for_triplets(int three_different_throws[] ) 
{



return (three_different_throws[0]==three_different_throws[1])&&(three_different_throws[1]==three_different_throws[2]);
}

int check_for_doubles(int three_different_throws[])
{
	return (three_different_throws[0]==three_different_throws[1])||(three_different_throws[0]==three_different_throws[2])||(three_different_throws[1]==three_different_throws[2]);
}






	


























