
// 0414MFC1.h : 0414MFC1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0414MFC1App:
// �йش����ʵ�֣������ 0414MFC1.cpp
//

class CMy0414MFC1App : public CWinAppEx
{
public:
	CMy0414MFC1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0414MFC1App theApp;
