
// 0310MFC2_1View.cpp : CMy0310MFC2_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0310MFC2_1.h"
#endif

#include "0310MFC2_1Doc.h"
#include "0310MFC2_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0310MFC2_1View

IMPLEMENT_DYNCREATE(CMy0310MFC2_1View, CView)

BEGIN_MESSAGE_MAP(CMy0310MFC2_1View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0310MFC2_1View 构造/析构

CMy0310MFC2_1View::CMy0310MFC2_1View()
{
	// TODO: 在此处添加构造代码
	ca.SetSize(256);


}

CMy0310MFC2_1View::~CMy0310MFC2_1View()
{
}

BOOL CMy0310MFC2_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0310MFC2_1View 绘制

void CMy0310MFC2_1View::OnDraw(CDC* pDC)
{
	CMy0310MFC2_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca.GetAt(i));
}


// CMy0310MFC2_1View 诊断

#ifdef _DEBUG
void CMy0310MFC2_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0310MFC2_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0310MFC2_1Doc* CMy0310MFC2_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0310MFC2_1Doc)));
	return (CMy0310MFC2_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0310MFC2_1View 消息处理程序


void CMy0310MFC2_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int a = rand() % 150 + 5;
	int b = rand() % 150 + 5;
	CRect cr(point.x-a,point.y-b,point.x+a,point.y +b);
	ca.Add(cr);
	this->Invalidate();

	//CClientDC dc(this);
	//dc.Ellipse(cr );

	CView::OnLButtonDown(nFlags, point);
}
