
// 0427MFC1Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMy0427MFC1Dlg 对话框
class CMy0427MFC1Dlg : public CDialogEx
{
// 构造
public:
	CMy0427MFC1Dlg(CWnd* pParent = NULL);	// 标准构造函数
	~CMy0427MFC1Dlg();//手动添加析构函数
	CArray<CString, CString&> ca;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY0427MFC1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox LBox;
	CString sname;
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	int count;
	afx_msg void OnLbnSelchangeList1();
};
