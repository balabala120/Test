
// 0420MFC1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy0420MFC1App: 
// �йش����ʵ�֣������ 0420MFC1.cpp
//

class CMy0420MFC1App : public CWinApp
{
public:
	CMy0420MFC1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy0420MFC1App theApp;