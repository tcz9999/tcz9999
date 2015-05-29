
#include "usrAppInit.h"
#include <stdio.h>

namespace my_test
{

	U_int DriverInit  (PlcIODef* in, U_int n_in, PlcIODef* out, U_int n_out);
	U_int DriverOpen  (PlcIODef* in, U_int n_in, PlcIODef* out, U_int n_out);
	U_int DriverClose (PlcIODef* in, U_int n_in, PlcIODef* out, U_int n_out);
	U_int DriverRead  (void* tthis, PlcIODef* in, U_int n_in);
	U_int DriverWrite (void* tthis, PlcIODef* out, U_int n_out);
	U_int DriverControl (void* tthis, int controlCode, PlcIODef* in, U_int n_in, PlcIODef* out, U_int n_out);
	U_int DriverInfo  (U_long  requestID,  U_long **confirmation_data, U_long *confirmationData);

	static IODrv iodrvtest = {
			"MYIODRV",
			DriverInit,
			DriverOpen,
			DriverClose,
			DriverRead,
			DriverWrite,
			DriverControl,
			DriverInfo,
	};

	void IODRVinstall(void)
	{
		if (ProCon_iodrv_install(&iodrvtest)== 0 )
			logMsg("IODRVinstall sucessful!\n",0,0,0,0,0,0);
		else
			logMsg("IODRVinstall failure!\n",0,0,0,0,0,0);
	}

	U_int DriverInit  (PlcIODef* in, U_int n_in, PlcIODef* out, U_int n_out)
	{
		logMsg("DriverInit OK!\n",0,0,0,0,0,0);
		return (0);
	}
	U_int DriverOpen  (PlcIODef* in, U_int n_in, PlcIODef* out, U_int n_out)
	{
		logMsg("DriverOpen OK!\n",0,0,0,0,0,0);
		return(0);
	}
	U_int DriverClose (PlcIODef* in, U_int n_in, PlcIODef* out, U_int n_out)
	{
		logMsg("DriverClose OK!\n",0,0,0,0,0,0);	
		return (0);
	}
	U_int DriverRead  (void* tthis, PlcIODef* in, U_int n_in)
	{	int i,j;
		unsigned int *p = 0;
		for (i=0;i<n_in;i++)
		{
			p =(unsigned int*)in[i].data;
			if (in[i].userPar1==0)
			{
				for(j=0;j<in[i].userPar2;j++)
				{
					if (in[i].size>= (j*4+4))
					{
						p[j] = pci_read_dword(0,2,j);
						logMsg("DriverRead: Index%d,data=%d OK\n",j,p[j],0,0,0,0);
					}
				}
			}
		}

		logMsg("DriverRead OK!\n",0,0,0,0,0,0);
		return (0);
	}
	U_int DriverWrite (void* tthis, PlcIODef* out, U_int n_out)
	{
		int i,j;
		unsigned int *p=0;
		for(i=0;i<n_out;i++)
		{
			p = (unsigned int*)out[i].data;
			if (out[i].userPar1==0)
			{
				for(j=0;j<out[i].userPar2;j++)
				{
					if (out[i].size>=(j*4+4))
					{
						pci_write_dword(0,2,j,p[j]);
						logMsg("DriverWrite: Index=%d,data=%d OK\n",j,p[j],0,0,0,0);				
					}
				}
			}
		}
		logMsg("DriverWrite OK!\n",0,0,0,0,0,0);
		return (0);
	}
	U_int DriverControl (void* tthis, int controlCode, PlcIODef* in, U_int n_in, PlcIODef* out, U_int n_out)
	{
		logMsg("DriverControl OK!\n",0,0,0,0,0,0);
		return (0);
	}
	U_int DriverInfo  (U_long  requestID,  U_long **confirmation_data, U_long *confirmationData)
	{
		logMsg("DriverInfo OK!\n",0,0,0,0,0,0);
		return (0);
	}


	int a;
	unsigned int handle;
	unsigned int array[8192];

	unsigned int pci_open_card(int index)
	{
		return (0);
	}

	unsigned int pci_read_dword(unsigned int handle,int bar,int offset )
	{
		if ((0 <= offset) && (offset<8192))
		{
			return (array[offset]);
		}
		else
		{
			return (0);
		}
	}
	void pci_write_dword(unsigned int handle,int bar,int offset,unsigned int data )
	{
		if ((0 <= offset) && (offset<8192))
		{
			array[offset] = data;
		}
	}

	int	logMsg (char *fmt, int arg1, int arg2,
				int arg3, int arg4, int arg5, int arg6)
	{
		printf(fmt,arg1,arg2,arg3,arg4,arg5,arg6);
		return (0);
	}

}