
// 0324MFC2.h : 0324MFC2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0324MFC2App:
// �йش����ʵ�֣������ 0324MFC2.cpp
//

class CMy0324MFC2App : public CWinAppEx
{
public:
	CMy0324MFC2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0324MFC2App theApp;
