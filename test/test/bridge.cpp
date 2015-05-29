#include "bridge.h"

using namespace DesignPattern_Bridge; 

void testBridge()
{
	ConcreteImplementorA *impA = new ConcreteImplementorA();
	ConcreteImplementorB *impB = new ConcreteImplementorB();

	Abstraction obj;
	obj.Operation(impA);
	obj.Operation(impB);
}