#pragma once


// Mydlg1 �Ի���

class Mydlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(Mydlg1)

public:
	Mydlg1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Mydlg1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	CString fname;
};
