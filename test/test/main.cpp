#include <stdio.h>
#include <iostream>
#include "test.h"
#include "functor.h"
#include <vector>
#include <algorithm>
#include <functional>
#include "usrAppInit.h"
#include <string.h>
#include <time.h>
#include "chapter08.h"
#include "chapter09.h"
#include "chapter15.h"

using namespace std;
using namespace my_test;

#define SET_BIT(s,m,d,n) if(0!=(s&m)) d|=n; else d&=~n;

void test();
void test3();
void test4();
void test5();
void test6();

void test()
{
	int b,c;
	unsigned int s=0x0110;
	unsigned int d=0xefffF;
	SET_BIT(s,Bit(10),d,Bit(3));
	printf("%x!\n",s);
	puts("bye!\n");
	while(1)
	{
		try 
		{
			cin>>b;
			cin>>c;
			if(cin.fail()||b<0 ||b>10 ||c<0||c>10)
			{
				cin.clear();
				throw("wrong!\n");
			}
			SET_BIT(s,Bit(b),d,Bit(c));
			printf("%x\n",d);
		}
		catch(char i[100])
		{
			char s[100];
			printf("%s\n",i);
			cout<<s<<endl;
			break;
		}
	}
}

template <class T> struct A {
   T m_t;
   public:
      A(T t){};
	  A(){};
	  void f(T t){};
};

void test5() {
   A<int> a(2.0);
   less<int> Less;
   if(Less(1,3))
   {
	   printf("Less(1,3) is true!\n");
   }
   else
   {
		printf("Less(1,3) is false!\n");   
   }
   getchar();
}

void test6()
{
	printf("__TIME__ is %s\n",__TIME__);
	printf("__DATE__ is %s\n",__DATE__);
	printf("__FILE__ is %s\n",__FILE__);
	printf("__LINE__ is %d\n",__LINE__);
	printf("__TIMESTAMP__ is %s\n",__TIMESTAMP__);
#ifdef __STDC__
	printf("__STDC__ is %s\n",__STDC__);
#else
	printf("__STDC__ is not define!\n");
#endif
#ifdef _ATL_VER
	printf("_ATL_VER is %s.\n",_ATL_VER);
#else
	printf("_ATL_VER is not define.\n");
#endif
#ifdef _CHAR_UNSIGNED
	printf("_CHAR_UNSIGNED is %s.\n",_CHAR_UNSIGNED");
#else
	printf("_CHAR_UNSIGNED is not define.\n");
#endif
#ifdef __cplusplus_cli
	printf("__cplusplus_cli is %d\n", __cplusplus_cli);
#else
	printf("__cplusplus_cli is not defined\n");
#endif
#ifdef __cplusplus
	printf("__cplusplus is %d\n", __cplusplus);
#else
	printf("__cplusplus is not defined\n");
#endif
#ifdef _CPPLIB_VER
	printf("_CPPLIB_VER is %d\n", _CPPLIB_VER);
#else
	printf("_CPPLIB_VER is not defined\n");
#endif
#ifdef _CPPRTTI
	printf("_CPPRTTI is %d\n", _CPPRTTI);
#else
	printf("_CPPRTTI is not defined\n");
#endif
#ifdef __FUNCDNAME__
	printf("__FUNCDNAME__ is %d\n", __FUNCDNAME__);
#else
	printf("__FUNCDNAME__ is not defined\n");
#endif
}

int func()
{
	static int counter = 1;
	
	return ++counter;
}

unsigned int reverse_bits(unsigned int value)
{
	int count = sizeof(int)*8;
	int i=0;
	unsigned int ret=0;

	while(value!=0)
	{
		i++;
		ret = ret << 1;
		if(value&1)ret++;
		value = value >> 1;
	}
	while(i<count)
	{
		i++;
		ret = ret << 1;
	}

	return ret;
}


#include <Windows.h>

void test_dll()
{
	void (*fun)();
	HMODULE hDll = NULL;
	hDll = LoadLibrary("testDll.Dll");
	if (hDll)
	{
		fun = (void (*)())GetProcAddress(hDll,"dll_fun1");
		if(fun)
		{
			fun();
		}else
		{
			DWORD dwErr =  GetLastError();
			dwErr = 1;
		}
	}
}

void binary_to_ascii(unsigned int value)
{
	unsigned int quotient;
	
	quotient = value /10;
	if (quotient != 0)
	{
		binary_to_ascii(quotient);
	}
	putchar(value % 10 + '0');
}

#include <stdarg.h>

float average(int n_values,...)
{
	va_list var_arg;
	int count;
	float sum = 0;
	
	va_start(var_arg,n_values);

	for(count = 0; count < n_values; count++)
	{
		printf("%08X\n",*var_arg);
		printf("%08X\n",*(unsigned int *)var_arg);
		sum += va_arg(var_arg,double);
	}

	va_end(var_arg);

	return sum / n_values;
}


#include "tree.h"

void visit(TREE_TYPE value)
{
	printf("%02d  ",value);
}

void main(int argc,char **argv)
{
	int m;
	for(int i = 0; i<100;i++)
	{
		m = rand()%20;
		insert_tree(m);
	}
	while(scanf("%d",&m))
	{
		delete_tree(m);
		pre_order_traverse(visit);
		putchar('\n');
		in_order_traverse(visit);
		putchar('\n');
		post_order_traverse(visit);
		printf("\n is_balance : %d \n",is_balance());
	};
	pre_order_traverse(visit);
	putchar('\n');
	in_order_traverse(visit);
	putchar('\n');
	post_order_traverse(visit);


	fflush(stdin);
	int ch;
	while((ch=getchar())!=EOF && ch != '\n')
	{
		printf("%d\n",ch);
	}
}
