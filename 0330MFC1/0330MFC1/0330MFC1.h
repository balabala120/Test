
// 0330MFC1.h : 0330MFC1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0330MFC1App:
// �йش����ʵ�֣������ 0330MFC1.cpp
//

class CMy0330MFC1App : public CWinAppEx
{
public:
	CMy0330MFC1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0330MFC1App theApp;
