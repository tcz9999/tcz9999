#include "Builder.h"

using namespace DesignPattern_Builder ;

void testBuilder()
{
	Director director ;

	// 创建第一种对象
	ConcreteBuilder1 *pBuilder1 = new ConcreteBuilder1() ;
	director.Construct(pBuilder1) ;
	Product1 *product1 = pBuilder1->GetProduct1() ;
	// 创建第二种对象
	ConcreteBuilder2 *pBuilder2 = new ConcreteBuilder2() ;
	director.Construct(pBuilder2) ;
	Product2 *product2 = pBuilder2->GetProduct2() ;


}
