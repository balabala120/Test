
// 0414MFC3.h : 0414MFC3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0414MFC3App:
// �йش����ʵ�֣������ 0414MFC3.cpp
//

class CMy0414MFC3App : public CWinAppEx
{
public:
	CMy0414MFC3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0414MFC3App theApp;
