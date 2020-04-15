
// 0408MFC3View.cpp : CMy0408MFC3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0408MFC3.h"
#endif

#include "0408MFC3Doc.h"
#include "0408MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0408MFC3View

IMPLEMENT_DYNCREATE(CMy0408MFC3View, CView)

BEGIN_MESSAGE_MAP(CMy0408MFC3View, CView)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMy0408MFC3View 构造/析构

CMy0408MFC3View::CMy0408MFC3View()
{
	// TODO: 在此处添加构造代码
	cr.top = 100;
	cr.left = 100;
	cr.bottom = 200;
	cr.right = 200;
	flag = 0;
	rl = 0;
}

CMy0408MFC3View::~CMy0408MFC3View()
{
}

BOOL CMy0408MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0408MFC3View 绘制

void CMy0408MFC3View::OnDraw(CDC* pDC)
{
	CMy0408MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	SetTimer(1, 500, NULL);
	pDC->Ellipse(cr);
	
}


// CMy0408MFC3View 诊断

#ifdef _DEBUG
void CMy0408MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0408MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0408MFC3Doc* CMy0408MFC3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0408MFC3Doc)));
	return (CMy0408MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0408MFC3View 消息处理程序


void CMy0408MFC3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1)
	{
		CRect cc;
		GetClientRect(&cc);//取得客户区给cc
		if (cr.right >= cc.right) rl = 1;//小球触碰右边则改变方向   向左移动
		if (cr.left <= cc.left) rl = 0;//小球触碰左边则改变方向   向右移动
		if (rl==0)//向右移动
		{
			cr.left += 30;
			cr.right += 30;
		}
		if (rl==1)//向左移动
		{
			cr.left-= 30;
			cr.right -= 30;
		}
		Invalidate();
	}
	CView::OnTimer(nIDEvent);
}


void CMy0408MFC3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMy0408MFC3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 0;
	CView::OnLButtonDblClk(nFlags, point);
}
