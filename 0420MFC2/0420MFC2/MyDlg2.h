#pragma once


// MyDlg2 �Ի���

class MyDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg2)

public:
	MyDlg2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int red;
	int green;
	int blue;
	afx_msg void OnBnClickedButton1();
};
