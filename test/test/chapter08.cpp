#include <stdlib.h>
#include <stdio.h>
#include "chapter08.h"

#define NUM_QUEEN 8

void print_queens(int arr[])
{
	int i;
	for(i = 0; i < NUM_QUEEN; i++)
	{
		printf("(%d,%d),",arr[i]+1,i+1);
	}
	printf("\n");
}

void eight_queens(int cols[],int col)
{
	int row,j;
	int kill;
	for (row = 0; row < NUM_QUEEN; row++)
	{
		kill = 0;
		for(j = 0; j<col; j++)
		{
			if( (abs(row-cols[j])==abs(col-j)) || (row==cols[j]))//»Êºó³åÍ»
			{
				kill = 1;
				break;
			}
		}
		if(kill == 0)
		{
			cols[col] = row;
			if(col==NUM_QUEEN-1)
			{
				print_queens(cols);
			}
			else
			{
				eight_queens(cols,col+1);
			}
		}
	}
}

void test_eight_queens()
{
	int cols[NUM_QUEEN];

	eight_queens(cols,0);
}