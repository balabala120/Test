
// 0407MFC2.h : 0407MFC2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0407MFC2App:
// �йش����ʵ�֣������ 0407MFC2.cpp
//

class CMy0407MFC2App : public CWinAppEx
{
public:
	CMy0407MFC2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0407MFC2App theApp;
