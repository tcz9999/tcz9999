#include "Builder.h"

using namespace DesignPattern_Builder ;

void testBuilder()
{
	Director director ;

	// ������һ�ֶ���
	ConcreteBuilder1 *pBuilder1 = new ConcreteBuilder1() ;
	director.Construct(pBuilder1) ;
	Product1 *product1 = pBuilder1->GetProduct1() ;
	// �����ڶ��ֶ���
	ConcreteBuilder2 *pBuilder2 = new ConcreteBuilder2() ;
	director.Construct(pBuilder2) ;
	Product2 *product2 = pBuilder2->GetProduct2() ;


}
