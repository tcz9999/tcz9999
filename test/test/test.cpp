#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

void fill_longs(
    unsigned int *buf,    /* pointer to buffer              */
    unsigned int nlongs, /* number of longs to fill        */
    unsigned int val /* char with which to fill buffer */	
	)
{
	unsigned int * bufend = buf + nlongs;
	unsigned int nchunks;
	for (nchunks= nlongs/8;nchunks;--nchunks)
	{
		*buf++=val;
		*buf++=val;
		*buf++=val;
		*buf++=val;
		*buf++=val;
		*buf++=val;
		*buf++=val;
		*buf++=val;
	}
	while(buf<bufend)
		*buf++ = val;
}

void test_fill_longs()
{
	unsigned int *buf;
	buf = (unsigned int *)malloc(31*sizeof(unsigned int));
	if (buf != NULL)
	{
		fill_longs(buf,34,1);
	}
}

void test7()
{
#define MAX_COLS 20
#define MAX_INPUT 1000
	
	char input[MAX_INPUT];
	char output[MAX_INPUT];
	int columns[MAX_COLS];
	int n_column;

	n_column = read_column_numbers(columns,MAX_COLS);
	
	while(gets(input)!=NULL)
	{
		printf("Original input:%s\n",input);
		rearrange(output,input,n_column,columns);
		printf("Rearrange line:%s",output);
	}
}

int read_column_numbers(int columns[],int max)
{
	int num = 0;
	int ch;

	while(num<max && scanf("%d",&columns[num])==1 && columns[num]>=0)
	{
		num++;
	}

	if(num % 2 != 0)
	{
		puts("Last column number is not paired.");
		exit(EXIT_FAILURE);
	}

	while((ch = getchar()) != EOF && ch != '\n');

	return num;
}

void rearrange(char *output,char const *input,int n_columns,int columns[])
{
	int len,nchar,output_col=0;
	len = strlen(input);
	for (int i = 0;i<n_columns;i+=2)
	{
		nchar = columns[i+1]-columns[i]+1;
		if (output_col > MAX_INPUT||columns[i]>len)
		{
			break;
		}
		if (nchar+output_col>MAX_INPUT-1)
		{
			nchar = MAX_INPUT-output_col-1;
		}
		strncpy(output+output_col,input+columns[i],nchar);
		output_col += nchar;
		output[output_col]='\0';
	}
}