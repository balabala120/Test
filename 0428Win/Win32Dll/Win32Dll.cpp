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

WIN32DLL_API int GetInt()
{
	return 2020;
}

int CWin32Dll:: Sum(int a)
{
	int sum=0;
	for (int i = 1; i <= a; i++)
		sum += i;
	return sum;
}


// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� Win32Dll.h
CWin32Dll::CWin32Dll()
{
    return;
}
