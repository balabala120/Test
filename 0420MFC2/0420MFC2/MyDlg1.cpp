// MyDlg1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "0420MFC2.h"
#include "MyDlg1.h"
#include "afxdialogex.h"


// MyDlg1 �Ի���

IMPLEMENT_DYNAMIC(MyDlg1, CDialogEx)

MyDlg1::MyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, a(0)
	, b(0)
{

}

MyDlg1::~MyDlg1()
{
}

void MyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, a);
	DDX_Text(pDX, IDC_EDIT4, b);
}


BEGIN_MESSAGE_MAP(MyDlg1, CDialogEx)
	ON_BN_CLICKED(IDC_MFCLINK1, &MyDlg1::OnBnClickedMfclink1)
	ON_BN_CLICKED(IDOK, &MyDlg1::OnBnClickedOk)
END_MESSAGE_MAP()


// MyDlg1 ��Ϣ�������


void MyDlg1::OnBnClickedMfclink1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void MyDlg1::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
