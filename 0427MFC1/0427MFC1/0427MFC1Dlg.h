
// 0427MFC1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMy0427MFC1Dlg �Ի���
class CMy0427MFC1Dlg : public CDialogEx
{
// ����
public:
	CMy0427MFC1Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CMy0427MFC1Dlg();//�ֶ������������
	CArray<CString, CString&> ca;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY0427MFC1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
