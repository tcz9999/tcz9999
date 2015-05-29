#include <iostream>
#include <string.h>
#include <stdio.h>
#include "chapter09.h"

#define MAX_KEY_NUM 26
int prepare_key(char *key)
{
	char tmp[MAX_KEY_NUM+1],ch,*pch;
	int i = 0;

	if(key == NULL)
	{
		return 0;
	}

	memset(tmp,0,MAX_KEY_NUM+1);
	pch=key;
	while(*pch != '\0')
	{
		if(isalpha(*pch))
		{
			ch=tolower(*pch);
			if(strchr(tmp,ch))
			{
				pch++;
				continue;
			}
			tmp[i++]=ch;
		}
		else
		{
			return 0;
		}
		pch++;
	}
	ch = 'a'-1;
	while(ch++ < 'z')
	{
		if(strchr(tmp,ch))
		{
			continue;
		}
		tmp[i++]=ch;
	}
	strcpy(key,tmp);
	return 1;
}

void encrypt(char *data, char const *key)
{
	char *ch;
	
	ch = data;
	while(*ch != '\0')
	{
		if(isalpha(*ch))
		{
			*ch = *ch + key[tolower(*ch)-'a']-tolower(*ch);
		}
		ch++;
	}
}

void decrypt(char *data, char const *key)
{
	char *ch;
	char decrypt_key[MAX_KEY_NUM+1];
	
	for(int i = 0; i<MAX_KEY_NUM; i++)
	{
		decrypt_key[i] = 'a'+ strchr(key,'a'+i)-key;
	}

	ch = data;
	while(*ch != '\0')
	{
		if(isalpha(*ch))
		{
			*ch = *ch + decrypt_key[tolower(*ch)-'a']-tolower(*ch);
		}
		ch++;
	}
}

void test_encrypt(void)
{
	char abc[] = "abcdefghigklmnopqrstuvwxyz";
	char key[MAX_KEY_NUM+1]="wellcomerhr";
	char data[] = "fq3h4fnq 4rg230nV"; 
	if(prepare_key(key))
	{
		encrypt(data,key);
		puts(data);
		putchar('\n');
		decrypt(data,key);
		puts(data);
		putchar('\n');
	}
}
