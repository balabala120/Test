
// 0327MFC3.h : 0327MFC3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0327MFC3App:
// �йش����ʵ�֣������ 0327MFC3.cpp
//

class CMy0327MFC3App : public CWinApp
{
public:
	CMy0327MFC3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0327MFC3App theApp;
