#pragma once


// MyDlg1 �Ի���

class MyDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg1)

public:
	MyDlg1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit1();
	CString s1;
	int a;
	CString s2;
	afx_msg void OnBnClickedButton1();
};