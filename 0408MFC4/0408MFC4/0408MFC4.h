
// 0408MFC4.h : 0408MFC4 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0408MFC4App:
// �йش����ʵ�֣������ 0408MFC4.cpp
//

class CMy0408MFC4App : public CWinAppEx
{
public:
	CMy0408MFC4App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0408MFC4App theApp;
