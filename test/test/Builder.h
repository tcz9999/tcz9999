#ifndef BUILDER_H
#define BUILDER_H

#include <stdio.h>

namespace DesignPattern_Builder
{
	class Product1 { } ;
	class Product2 { } ;

	// class Builder
	class Builder //�������
	{
	public:
		virtual void BuilderPartA() {} //�ṩȱʡʵ��
		virtual void BuilderPartB() {}
		virtual void BuilderPartC() {}
	protected:
		Builder() {}
	} ;

	// class ConcreteBuilder1
	class ConcreteBuilder1 : public Builder //����Product1
	{
	public:
		ConcreteBuilder1() : _product(NULL) {}
		virtual void BuilderPartA() { /*...*/ } 
		virtual void BuilderPartB() { /*...*/ }
		virtual void BuilderPartC() { /*...*/ }
		virtual Product1* GetProduct1() { return _product ; } //���ش�����Product1����
	private:
		Product1 *_product ;
	} ;
	// class ConcreteBuilder2
	class ConcreteBuilder2 : public Builder //����Product2
	{
	public:
		ConcreteBuilder2() : _product(NULL) {}
		virtual void BuilderPartA() { /*...*/ } 
		virtual void BuilderPartB() { /*...*/ }
		virtual void BuilderPartC() { /*...*/ }
		virtual Product2* GetProduct2() { return _product ; } //���ش�����Product2����
	private:
		Product2 *_product ;
	} ;
	// class Director
	class Director
	{
	public:
		//��������(Director����֪�����崴�������Ķ�����ʲô���ģ�ֻ�е��øú�����client֪��)
		void Construct(Builder *builder)
		{
			builder->BuilderPartA() ;
			builder->BuilderPartB() ;
			builder->BuilderPartC() ;
		}
	} ;

}

#endif