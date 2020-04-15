
// 0408MFC1View.cpp : CMy0408MFC1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0408MFC1.h"
#endif

#include "0408MFC1Doc.h"
#include "0408MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0408MFC1View

IMPLEMENT_DYNCREATE(CMy0408MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0408MFC1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy0408MFC1View 构造/析构

CMy0408MFC1View::CMy0408MFC1View()
{
	// TODO: 在此处添加构造代码
	cr.top = 100;
	cr.left = 100;
	cr.bottom = 300;
	cr.right = 300;
	mouse = 0;
	flag = 0;
}

CMy0408MFC1View::~CMy0408MFC1View()
{
}

BOOL CMy0408MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0408MFC1View 绘制

void CMy0408MFC1View::OnDraw(CDC* pDC)
{
	CMy0408MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy0408MFC1View 诊断

#ifdef _DEBUG
void CMy0408MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0408MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0408MFC1Doc* CMy0408MFC1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0408MFC1Doc)));
	return (CMy0408MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0408MFC1View 消息处理程序


void CMy0408MFC1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if ((cr.left <= point.x)&& (point.x <= cr.right) && (cr.top <= point.y)&&(point.y <= cr.bottom))
		//判断鼠标左键是否在矩形内按下
	{
		flag = 1;
		mouse = point;
	}
	
	CView::OnLButtonDown(nFlags, point);
}


void CMy0408MFC1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1)//只有鼠标左键按下时才重绘
	{
		cr.top += point.y - mouse.y;
		cr.bottom += point.y - mouse.y;
		cr.left += point.x - mouse.x;
		cr.right += point.x - mouse.x;
		mouse = point;
		Invalidate();
	}
	
	CView::OnMouseMove(nFlags, point);
}


void CMy0408MFC1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 0;
	CView::OnLButtonUp(nFlags, point);
}
