
// 0407MFC1.h : 0407MFC1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0407MFC1App:
// �йش����ʵ�֣������ 0407MFC1.cpp
//

class CMy0407MFC1App : public CWinAppEx
{
public:
	CMy0407MFC1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0407MFC1App theApp;
