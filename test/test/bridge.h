#ifndef BRIDGE_H
#define BRIDGE_H

#include <assert.h>

namespace DesignPattern_Bridge
{
	//class Implementor
	class Implementor 
	{
	public:
		virtual void OperationImp() = 0 ;
	protected:
		Implementor(){};
	};

	//class concreteImplementorA
	class ConcreteImplementorA : public Implementor
	{
	public: 
		virtual void OperationImp()
		{}
	};

	//class ConcreteImplementorB
	class ConcreteImplementorB : public Implementor
	{
	public:
		virtual void OperationImp(){}
	};

	//class Abstraction
	class Abstraction 
	{
	public:
		virtual void Operation(Implementor* Imp)
		{
			assert(Imp);
			Imp->OperationImp();
		}
	};
}

#endif