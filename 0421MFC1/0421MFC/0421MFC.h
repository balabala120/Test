
// 0421MFC.h : 0421MFC Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0421MFCApp:
// �йش����ʵ�֣������ 0421MFC.cpp
//

class CMy0421MFCApp : public CWinAppEx
{
public:
	CMy0421MFCApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0421MFCApp theApp;
