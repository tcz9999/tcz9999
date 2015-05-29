#ifndef USRAPPINIT_H
#define USRAPPINIT_H

namespace my_test
{
#define Bit(x)	(1<<x)

#define huge

	typedef unsigned short int U_int;
	typedef unsigned long int U_long;
	typedef unsigned char U_char;

	typedef struct PlcIODef         /* IO Descriptor */
	{
		U_int   descId    ;          /* Logical Id of the structure */
		U_int   size      ;          /* Size of the IO group in bytes */
		U_int   typ       ;          /* assigned data type IOTYP_* */
		U_int   mode      ;          /* IOMODE_* (internal use of ProConOS) */
		void   *data      ;          /* Pointer to I/O-Data-Area */
		U_long  drvPar1   ;          /* 1. Internal Parameter of the Driver */
		U_long  drvPar2   ;          /* 2. Internal Parameter of the Driver */
		U_int   drvPar3   ;          /* 3. Internal Parameter of the Driver */
		U_int   userPar1  ;          /* 1. User defined Parameter of the Driver */
		U_int   userPar2  ;          /* 2. User defined Parameter of the Driver */
		U_int   userPar3  ;          /* 3. User defined Parameter of the Driver */
		U_int   userPar4  ;          /* 4. User defined Parameter of the Driver */
		U_int   task      ;          /* associated task number (internal use of ProConOS) */
	}PlcIODef;

#define IODRIVER_NAME_SIZE 12
	typedef struct IODrv                      /* IO driver definition */
	{
		U_char drvname[IODRIVER_NAME_SIZE];                    /* drivers' name */
		U_int (huge *drvinit)  (PlcIODef* in, U_int n_in, PlcIODef* out, U_int n_out);
		U_int (huge *drvopen)  (PlcIODef* in, U_int n_in, PlcIODef* out, U_int n_out);
		U_int (huge *drvclose) (PlcIODef* in, U_int n_in, PlcIODef* out, U_int n_out);
		U_int (huge *drvread)  (void* tthis, PlcIODef* in, U_int n_in);
		U_int (huge *drvwrite) (void* tthis, PlcIODef* out, U_int n_out);
		U_int (huge *drvcntrl) (void* tthis, int controlCode, PlcIODef* in, U_int n_in, PlcIODef* out, U_int n_out);
		U_int (huge *drvinfo)  (U_long  requestID,  U_long **confirmation_data, U_long *confirmationData);
	}IODrv;

	int	logMsg (char *fmt, int arg1, int arg2,
		int arg3, int arg4, int arg5, int arg6);

	U_int	ProCon_iodrv_install(IODrv*);
	unsigned int pci_read_dword(unsigned int handle,int bar,int offset );
	void pci_write_dword(unsigned int handle,int bar,int offset,unsigned int data );
}

#endif