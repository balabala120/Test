
// 0310MFC2_2.h : 0310MFC2_2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0310MFC2_2App:
// �йش����ʵ�֣������ 0310MFC2_2.cpp
//

class CMy0310MFC2_2App : public CWinAppEx
{
public:
	CMy0310MFC2_2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0310MFC2_2App theApp;
