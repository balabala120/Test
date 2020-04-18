// Mydlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "0414MFC2.h"
#include "Mydlg1.h"
#include "afxdialogex.h"


// Mydlg1 对话框

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


// Mydlg1 消息处理程序


void Mydlg1::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void Mydlg1::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
