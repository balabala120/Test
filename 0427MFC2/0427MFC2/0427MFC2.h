
// 0427MFC2.h : 0427MFC2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0427MFC2App:
// �йش����ʵ�֣������ 0427MFC2.cpp
//

class CMy0427MFC2App : public CWinAppEx
{
public:
	CMy0427MFC2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0427MFC2App theApp;
