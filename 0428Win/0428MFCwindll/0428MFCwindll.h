
// 0428MFCwindll.h : 0428MFCwindll Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0428MFCwindllApp:
// �йش����ʵ�֣������ 0428MFCwindll.cpp
//

class CMy0428MFCwindllApp : public CWinAppEx
{
public:
	CMy0428MFCwindllApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0428MFCwindllApp theApp;
