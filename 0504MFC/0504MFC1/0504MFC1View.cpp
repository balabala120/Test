
// 0504MFC1View.cpp : CMy0504MFC1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0504MFC1.h"
#endif

#include "0504MFC1Doc.h"
#include "0504MFC1View.h"
#include "lib1.h"
#include "Win32Dll.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0504MFC1View

IMPLEMENT_DYNCREATE(CMy0504MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0504MFC1View, CView)
END_MESSAGE_MAP()

// CMy0504MFC1View 构造/析构

CMy0504MFC1View::CMy0504MFC1View()
{
	// TODO: 在此处添加构造代码

}

CMy0504MFC1View::~CMy0504MFC1View()
{
}

BOOL CMy0504MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0504MFC1View 绘制

void CMy0504MFC1View::OnDraw(CDC* pDC)
{
	CMy0504MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s1,s2,s3,s4;
	s1.Format(_T("静态库的使用：%d的阶乘等于%d"), 5,factorial(5));
	pDC->TextOutW(200,100,s1);

	Fac a;
	s2.Format(_T("静态库的使用：%.2lf的弧度值为%lf"),30.0,a.convert(30.0));
	pDC->TextOutW(200,150,s2);

	s3.Format(_T("动态库的使用：%d的阶乘等于%d"),6, fac(6));
	pDC->TextOutW(200, 200, s3);

	FAC b;
	s4.Format(_T("动态库的使用：%.2lf的弧度值为%lf"), 60.0, b.convert(60.0));
	pDC->TextOutW(200, 250, s4);
}


// CMy0504MFC1View 诊断

#ifdef _DEBUG
void CMy0504MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0504MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0504MFC1Doc* CMy0504MFC1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0504MFC1Doc)));
	return (CMy0504MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0504MFC1View 消息处理程序
