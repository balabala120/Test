// Win32Dll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Win32Dll.h"


// ���ǵ���������һ��ʾ��
WIN32DLL_API int nWin32Dll=0;

// ���ǵ���������һ��ʾ����
WIN32DLL_API int fnWin32Dll(void)
{
    return 42;
}

WIN32DLL_API int fac(int n)
{
	if (n == 0 || n == 1) return 1;
	else return fac(n - 1)*n;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� Win32Dll.h
CWin32Dll::CWin32Dll()
{
    return;
}

 float FAC::convert(float deg)
{
	return (3.14 / 180) * deg;
}