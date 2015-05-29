#ifndef BUILDER_H
#define BUILDER_H

#include <stdio.h>

namespace DesignPattern_Builder
{
	class Product1 { } ;
	class Product2 { } ;

	// class Builder
	class Builder //抽象基类
	{
	public:
		virtual void BuilderPartA() {} //提供缺省实现
		virtual void BuilderPartB() {}
		virtual void BuilderPartC() {}
	protected:
		Builder() {}
	} ;

	// class ConcreteBuilder1
	class ConcreteBuilder1 : public Builder //创建Product1
	{
	public:
		ConcreteBuilder1() : _product(NULL) {}
		virtual void BuilderPartA() { /*...*/ } 
		virtual void BuilderPartB() { /*...*/ }
		virtual void BuilderPartC() { /*...*/ }
		virtual Product1* GetProduct1() { return _product ; } //返回创建的Product1对象
	private:
		Product1 *_product ;
	} ;
	// class ConcreteBuilder2
	class ConcreteBuilder2 : public Builder //创建Product2
	{
	public:
		ConcreteBuilder2() : _product(NULL) {}
		virtual void BuilderPartA() { /*...*/ } 
		virtual void BuilderPartB() { /*...*/ }
		virtual void BuilderPartC() { /*...*/ }
		virtual Product2* GetProduct2() { return _product ; } //返回创建的Product2对象
	private:
		Product2 *_product ;
	} ;
	// class Director
	class Director
	{
	public:
		//创建对象(Director并不知道具体创建出来的对象是什么样的，只有调用该函数的client知道)
		void Construct(Builder *builder)
		{
			builder->BuilderPartA() ;
			builder->BuilderPartB() ;
			builder->BuilderPartC() ;
		}
	} ;

}

#endif