// testdll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"


//extern "C" 
//	__declspec(dllexport) void __stdcall dll_fun1(void);

	void __stdcall dll_fun1(void)
	{
		MessageBox(NULL,L"hello!",L"dll_fun1",MB_OK);
	}
