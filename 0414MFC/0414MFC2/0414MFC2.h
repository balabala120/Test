
// 0414MFC2.h : 0414MFC2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0414MFC2App:
// �йش����ʵ�֣������ 0414MFC2.cpp
//

class CMy0414MFC2App : public CWinAppEx
{
public:
	CMy0414MFC2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0414MFC2App theApp;
