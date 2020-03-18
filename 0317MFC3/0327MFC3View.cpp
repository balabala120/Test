
// 0327MFC3View.cpp : CMy0327MFC3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0327MFC3.h"
#endif

#include "0327MFC3Doc.h"
#include "0327MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0327MFC3View

IMPLEMENT_DYNCREATE(CMy0327MFC3View, CView)

BEGIN_MESSAGE_MAP(CMy0327MFC3View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy0327MFC3View 构造/析构

CMy0327MFC3View::CMy0327MFC3View()
{
	// TODO: 在此处添加构造代码

}

CMy0327MFC3View::~CMy0327MFC3View()
{
}

BOOL CMy0327MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0327MFC3View 绘制

void CMy0327MFC3View::OnDraw(CDC* pDC)
{
	CMy0327MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	SetTimer(1,500,NULL);
	// TODO: 在此处为本机数据添加绘制代码

	pDC->Ellipse(pDoc->cr);
}


// CMy0327MFC3View 诊断

#ifdef _DEBUG
void CMy0327MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0327MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0327MFC3Doc* CMy0327MFC3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0327MFC3Doc)));
	return (CMy0327MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0327MFC3View 消息处理程序


void CMy0327MFC3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect cc;
	GetClientRect(&cc);//取得客户区给cc
	CMy0327MFC3Doc* pDoc = GetDocument();
	
	if(pDoc->cr.bottom < cc.bottom)
	{
		pDoc->cr.top += 30;
		pDoc->cr.bottom += 30;
	}
	else while (pDoc->cr.top > 0)
	{
		pDoc->cr.top -= 30;
		pDoc->cr.bottom -= 30;
	}

	Invalidate();

	CView::OnTimer(nIDEvent);
}
