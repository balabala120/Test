// MyDlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "0421MFC.h"
#include "MyDlg1.h"
#include "afxdialogex.h"

#include<fstream>
#include<iostream>
#include<string>
using namespace std;

// MyDlg1 对话框

IMPLEMENT_DYNAMIC(MyDlg1, CDialogEx)

MyDlg1::MyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlg1::~MyDlg1()
{
}

void MyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlg1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg1::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg1 消息处理程序


void MyDlg1::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

		ifstream ifs(_T("C:\\Users\\18045\\Documents\\abc.txt"));
		string s;
		ifs >> s;                          //读取abc.txt文件  将其文件内容（保存下来的jpg文件路径）写入到s

		CImage img;
		img.Load(CString(s.c_str()));
		if (!img.IsNull())
		{
			int sx, sy, w, h;
			foo(img, sx, sy, w, h);
			//CString ss;
			//ss.Format(_T("x=%d,,y=%d"), sx, sy);
			CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
			pDC->SetStretchBltMode(HALFTONE);      //图像不失真
			img.Draw(pDC->m_hDC, sx, sy, w, h);// 0, 0, img.GetWidth(), img.GetHeight());//
			ReleaseDC(pDC);
		}
		else
		{
			MessageBox(_T("Load Error"));
		}


}


void MyDlg1::foo(CImage &img, int &sx, int &sy, int &w, int &h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);            //取得客户区
	float rect_ratio = 1.0*rect.Width() / rect.Height();     //计算客户区的宽高比
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();   //计算图片的宽高比
	if (rect_ratio > img_ratio)                             //如果客户区宽高比更大（同样高度时图片控件更宽）
	{
		h = rect.Height();                                 //以客户区高度为高度
		w = img_ratio*h;                                   //按比例缩放图片的宽度
		sx = (rect.Width() - w) / 2;                      //左上角坐标计算
		sy = 0;                                          //相对于客户区来讲   y=0
	}
	else
	{
		w = rect.Width();                             //以客户区宽度为宽度
		h = w / img_ratio;                             //按比例缩放图片的高度
		sx = 0;                                     //相对于客户区来讲   x=0
		sy = (rect.Height() - h) / 2;                //左上角坐标计算
	}

}
