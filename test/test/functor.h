#pragma once

class functor
{
public:
	functor(void);
	~functor(void);
	template <class T> int operator()(T a,T b)
	{
		return a<b;
	};
};

struct MyStruct {
   MyStruct(int i) : m_i(i){}
   
   bool operator < (const MyStruct & rhs) const {
      return m_i < rhs.m_i;
   }   

   int m_i;
};

