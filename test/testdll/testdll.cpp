// testdll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"


//extern "C" 
//	__declspec(dllexport) void __stdcall dll_fun1(void);

	void __stdcall dll_fun1(void)
	{
		MessageBox(NULL,L"hello!",L"dll_fun1",MB_OK);
	}
