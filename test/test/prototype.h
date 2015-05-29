
#ifndef PROTOTYPE_H
#define PROTOTYPE_H

namespace DesignPattern_Prototype
{
	// class prototype
	class Prototype
	{
	public:
		virtual Prototype* Clone() = 0;
	protected:
		Prototype(){};
	} ;

	// concrete prototype
	class ConcretePrototype1: public Prototype
	{
	public:
		virtual Prototype* Clone();
	} ;

	// concrete prototype
	class ConcretePrototype2: public Prototype
	{
	public:
		virtual Prototype* Clone();
	} ;
}

#endif