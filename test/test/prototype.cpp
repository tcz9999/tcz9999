#include "prototype.h"

using namespace DesignPattern_Prototype;

Prototype* ConcretePrototype1::Clone()
{
	ConcretePrototype1 *p = new ConcretePrototype1();
	*p = *this;
	return p;
}

Prototype* ConcretePrototype2::Clone()
{
	ConcretePrototype2 *p = new ConcretePrototype2();
	*p = *this;
	return p;
}

void testPrototype()
{
	ConcretePrototype1 *cp1= new ConcretePrototype1();
	ConcretePrototype2 *cp2= new ConcretePrototype2();

	Prototype *newcp1 = cp1->Clone();
	Prototype *newcp2 = cp2->Clone();

}