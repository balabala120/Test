
// 0323MFC1_1.h : 0323MFC1_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0323MFC1_1App:
// �йش����ʵ�֣������ 0323MFC1_1.cpp
//

class CMy0323MFC1_1App : public CWinAppEx
{
public:
	CMy0323MFC1_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0323MFC1_1App theApp;
