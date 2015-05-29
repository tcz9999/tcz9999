
#include <stdlib.h>
#include "test.h"
#include "usrAppInit.h"

namespace my_test
{
	IODrv* dev=NULL;

	U_int	ProCon_iodrv_install(IODrv* d)
	{
		dev = d;
		return (0);
	}
}