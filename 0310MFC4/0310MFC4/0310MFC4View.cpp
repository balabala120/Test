
// 0310MFC4View.cpp : CMy0310MFC4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0310MFC4.h"
#endif

#include "0310MFC4Doc.h"
#include "0310MFC4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0310MFC4View

IMPLEMENT_DYNCREATE(CMy0310MFC4View, CView)

BEGIN_MESSAGE_MAP(CMy0310MFC4View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0310MFC4View 构造/析构

CMy0310MFC4View::CMy0310MFC4View()
{
	// TODO: 在此处添加构造代码

}

CMy0310MFC4View::~CMy0310MFC4View()
{
}

BOOL CMy0310MFC4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0310MFC4View 绘制

void CMy0310MFC4View::OnDraw(CDC* /*pDC*/)
{
	CMy0310MFC4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy0310MFC4View 诊断

#ifdef _DEBUG
void CMy0310MFC4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0310MFC4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0310MFC4Doc* CMy0310MFC4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0310MFC4Doc)));
	return (CMy0310MFC4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0310MFC4View 消息处理程序


void CMy0310MFC4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect cr;
	this->GetClientRect(&cr);
	CClientDC dc(this);
	if(cr.bottom -cr.top > cr.right -cr.left )
		dc.Ellipse (0,0,cr.right -cr.left , cr.right - cr.left);
	else  dc.Ellipse(0, 0, cr.bottom - cr.top, cr.bottom - cr.top);
	CView::OnLButtonDown(nFlags, point);
}
