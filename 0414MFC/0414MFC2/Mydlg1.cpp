// Mydlg1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "0414MFC2.h"
#include "Mydlg1.h"
#include "afxdialogex.h"


// Mydlg1 �Ի���

IMPLEMENT_DYNAMIC(Mydlg1, CDialogEx)

Mydlg1::Mydlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, fname(_T(""))
{

}

Mydlg1::~Mydlg1()
{
}

void Mydlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, fname);
}


BEGIN_MESSAGE_MAP(Mydlg1, CDialogEx)
	ON_BN_CLICKED(IDOK, &Mydlg1::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &Mydlg1::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Mydlg1 ��Ϣ�������


void Mydlg1::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void Mydlg1::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
