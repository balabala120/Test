
// 0316MFC.h : 0316MFC Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0316MFCApp:
// �йش����ʵ�֣������ 0316MFC.cpp
//

class CMy0316MFCApp : public CWinAppEx
{
public:
	CMy0316MFCApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0316MFCApp theApp;
