
// 0317MFC2.h : 0317MFC2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0317MFC2App:
// �йش����ʵ�֣������ 0317MFC2.cpp
//

class CMy0317MFC2App : public CWinAppEx
{
public:
	CMy0317MFC2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0317MFC2App theApp;
