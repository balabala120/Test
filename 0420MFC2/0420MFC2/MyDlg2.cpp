// MyDlg2.cpp : 实现文件
//

#include "stdafx.h"
#include "0420MFC2.h"
#include "MyDlg2.h"
#include "afxdialogex.h"
#include "0420MFC2View.h"
#include "MainFrm.h"

// MyDlg2 对话框

IMPLEMENT_DYNAMIC(MyDlg2, CDialogEx)

MyDlg2::MyDlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, red(0)
	, green(0)
	, blue(0)
{

}

MyDlg2::~MyDlg2()
{
}

void MyDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, red);
	DDV_MinMaxInt(pDX, red, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, green);
	DDV_MinMaxInt(pDX, green, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, blue);
	DDV_MinMaxInt(pDX, blue, 0, 255);
}


BEGIN_MESSAGE_MAP(MyDlg2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg2::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg2 消息处理程序

void MyDlg2::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	
}
