
// 0427MFC1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy0427MFC1App: 
// �йش����ʵ�֣������ 0427MFC1.cpp
//

class CMy0427MFC1App : public CWinApp
{
public:
	CMy0427MFC1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy0427MFC1App theApp;