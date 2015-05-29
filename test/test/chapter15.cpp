#include <stdio.h>
#include <iostream>
#include <string.h>

#define LINE_MAX_LENGTH 8

void exercise1()
{
	int ch;
	while((ch=getchar())!=EOF)
	{
		putchar(ch);
	}
}

void exercise2()
{
	char buf[LINE_MAX_LENGTH+1];
	
	while(gets(buf)!=NULL)
	{
		puts(buf);
	}
}

void exercise3(FILE* in,FILE* out)
{
	char buf[LINE_MAX_LENGTH+1];

	while((fgets(buf,LINE_MAX_LENGTH+1,in)))
	{
		fputs(buf,out);
	}
}

void exercise3_1(FILE* in,FILE* out)
{
	char buf[LINE_MAX_LENGTH+1];
	bool is_new_line = true;
	int sum = 0,x = 0;

	while((fgets(buf,LINE_MAX_LENGTH+1,in)))
	{
		if (is_new_line)
		{
			if(sscanf(buf,"%d",&x) == 1)
			{
				sum+=x;
			}
		}
		if(strlen(buf)== LINE_MAX_LENGTH && buf[LINE_MAX_LENGTH] != '\n')
		{
			is_new_line = false;
		}
		else
		{
			is_new_line = true;
		}
		fputs(buf,out);
	}
	fprintf(out,"\n%d",sum);
}

void exercise4()
{
	char file_name[FILENAME_MAX];
	FILE *pfile_in,*pfile_out;

	puts("please enter input file name.\n");
	gets(file_name);
	pfile_in = fopen(file_name,"r");
	if(pfile_in == NULL)
	{
		printf("%s file open failed.\n",file_name);
		return;
	}

	puts("please enter output file name.\n");
	gets(file_name);
	pfile_out = fopen(file_name,"w");
	if(pfile_out == NULL)
	{
		fclose(pfile_in);
		printf("%s file open failed.\n",file_name);
		return;
	}
	//exercise3(pfile_in,pfile_out);//exercise4
	exercise3_1(pfile_in,pfile_out);//exercise5
	fclose(pfile_in);
	fclose(pfile_out);
}

int numeric_palindrome(int value) //exercise6
{
	int m,n;
	
	m = value % 10;
	n = value / 10;
	while(n > 0)
	{
		m = m*10 + n%10;
		n /= 10;
	}

	return (value == m)?true:false;
}

void exercise7()
{
	FILE * pfile;
	char buf[100];
	int n,a[10];
	float average;

	pfile = fopen("age.txt","r");
	if(pfile == NULL) 
	{
		perror("exe7");
		return;
	}

	while(fgets(buf,100,pfile))
	{
		a[0]=0;
		n = sscanf(buf,"%d%d%d%d%d%d%d%d%d%d",a,a+1,a+2,a+3,a+4,a+5,a+6,a+7,a+8,a+9);
		if(n==0) continue;
		for (int i = 1 ; i<n; i++)
		{
			a[0]+=a[i];
		}
		average = (float)a[0] / n;
		printf("%5.2f\n",average);
	}

	fclose(pfile);
}

void exercise8(char* filename)
{
	FILE * pfile;
	int row = 0,ch,i;
	char buf[0x10];
	bool eof=false;
	if(filename!=NULL && *filename !='\n')
	{
		pfile = fopen(filename,"r");
		if(pfile == NULL) return;
	}
	else
	{
		pfile = stdin;
	}

	while(!eof)
	{
		for(i = 0 ; i < 16 ; i++)
		{
			buf[i] = ch = fgetc(pfile);
			if(ch == EOF)
			{
				eof = true;
				buf[i] = '\0';
			}
		}
		printf("%06X  ",row);
		printf("%08X ",*(unsigned int *)buf);
		printf("%08X ",*(unsigned int *)(buf+4));
		printf("%08X ",*(unsigned int *)(buf+8));
		printf("%08X  ",*(unsigned int *)(buf+12));
		printf("*");
		for (i = 0 ; i < 16; i++)
		{
			isprint(buf[i])?putchar(buf[i]):putchar('.');
		}
		printf("*");
		printf("\n");
		row += 0x10;
	}
}

void search(char *string,FILE *file,char *filename)
{
	char buf[511];
	int l=0;

	while(fgets(buf,511,file))
	{
		l++;
		if(strstr(buf,string))
		{
			printf("%s:%d\n",*filename,l);
		}
	}
}

void fgrep(int ac, char **av)
{
	char *string;
	FILE *pfile;
	
	if(++av == NULL)
	{
		fprintf(stderr,"No string to search.\n");
		return;
	}

	string = *av++;
	if(*av++ == NULL)
	{
		search(string,stdin,NULL);
	}
	while(*av++ != NULL)
	{
		pfile = fopen(*av,"r");
		if(pfile == NULL)
		{
			printf("file %s open failed.\n",*av);
			continue;
		}
		search(string,pfile,*av);
		fclose(pfile);
	}
}
