
// 0310MFC4.h : 0310MFC4 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0310MFC4App:
// �йش����ʵ�֣������ 0310MFC4.cpp
//

class CMy0310MFC4App : public CWinApp
{
public:
	CMy0310MFC4App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0310MFC4App theApp;
