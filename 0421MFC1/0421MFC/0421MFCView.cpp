
// 0421MFCView.cpp : CMy0421MFCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0421MFC.h"
#endif

#include "0421MFCDoc.h"
#include "0421MFCView.h"
#include "MyDlg1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include<fstream>
#include<iostream>
#include<string>
using namespace std;

// CMy0421MFCView

IMPLEMENT_DYNCREATE(CMy0421MFCView, CView)

BEGIN_MESSAGE_MAP(CMy0421MFCView, CView)
	ON_COMMAND(ID_Save, &CMy0421MFCView::OnSave)
	ON_COMMAND(ID_Show, &CMy0421MFCView::OnShow)
END_MESSAGE_MAP()

// CMy0421MFCView 构造/析构

CMy0421MFCView::CMy0421MFCView()
{
	// TODO: 在此处添加构造代码

}

CMy0421MFCView::~CMy0421MFCView()
{
}

BOOL CMy0421MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0421MFCView 绘制

void CMy0421MFCView::OnDraw(CDC* pDC)
{
	CMy0421MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s1, s2;
	s1 = "点击  菜单-保存路径，弹出CFileDialog,选择一个jpg文件，将其路径存入abc.txt文件中。";
	s2 = "点击  菜单-显示图片，弹出对话框，点击显示图片按钮，读取abc.txt文件, 得到jpg文件的路径名，然后在对话框上的图片控件上居中显示该图像";
	pDC->TextOutW(100, 70, s1);
	pDC->TextOutW(100, 100, s2);

}


// CMy0421MFCView 诊断

#ifdef _DEBUG
void CMy0421MFCView::AssertValid() const
{
	CView::AssertValid();
}

void CMy0421MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0421MFCDoc* CMy0421MFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0421MFCDoc)));
	return (CMy0421MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy0421MFCView 消息处理程序


void CMy0421MFCView::OnSave()
{
	// TODO: 在此添加命令处理程序代码

	CFileDialog cfd(true);
	int r = cfd.DoModal();                        //弹出文件窗口
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();       //获取jpg文件的路径，保存到filename
		ofstream ofs(_T("C:\\Users\\18045\\Documents\\abc.txt"));
		ofs << CT2A(filename.GetString()) << endl;       //将filename转化后存入abc.txt文件中
	}
}


void CMy0421MFCView::OnShow()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg1 dlg;
	dlg.DoModal();
}
