#include "functor.h"
#include <functional>
#include <iostream>

#include <algorithm>
#include <vector>
using namespace std;

functor::functor(void)
{
	printf("File %s is compiled at %s.\n",__FILE__,__TIME__);
}

functor::~functor(void)
{

}

void test3()
{
	functor f;
	double a = 3.1,b=4;
	printf("f(%f,%f)=%d\n",a,b,f(a,b));
	int c = 5,d=4;
	printf("f(%d,%d)=%d\n",c,d,f(c,d));
	printf("f(%f,%f)=%d\n",2.1,3.1,f(2.1,(double)3));
	printf("Press Enter key to continue...\n");
	getchar();
}

void test4() {
   vector <MyStruct> v1;
   vector <MyStruct>::iterator Iter1;

   int i;
   for ( i = 0 ; i < 7 ; i++ )     
       v1.push_back( MyStruct(rand()));

   cout << "Original vector v1 = ( " ;
   for ( Iter1 = v1.begin() ; Iter1 != v1.end() ; Iter1++ ) 
cout << Iter1->m_i << " ";
   cout << ")" << endl;

   // To sort in ascending order,
   sort( v1.begin( ), v1.end( ), less<MyStruct>());

   cout << "Sorted vector v1 = ( " ;
   for ( Iter1 = v1.begin() ; Iter1 != v1.end() ; Iter1++ ) 
cout << Iter1->m_i << " ";
   cout << ")" << endl;
 }


