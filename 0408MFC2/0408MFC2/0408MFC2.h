
// 0408MFC2.h : 0408MFC2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0408MFC2App:
// �йش����ʵ�֣������ 0408MFC2.cpp
//

class CMy0408MFC2App : public CWinAppEx
{
public:
	CMy0408MFC2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0408MFC2App theApp;
