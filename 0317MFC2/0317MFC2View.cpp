
// 0317MFC2View.cpp : CMy0317MFC2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0317MFC2.h"
#endif

#include "0317MFC2Doc.h"
#include "0317MFC2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0317MFC2View

IMPLEMENT_DYNCREATE(CMy0317MFC2View, CView)

BEGIN_MESSAGE_MAP(CMy0317MFC2View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0317MFC2View 构造/析构

CMy0317MFC2View::CMy0317MFC2View()
{
	// TODO: 在此处添加构造代码

}

CMy0317MFC2View::~CMy0317MFC2View()
{
}

BOOL CMy0317MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0317MFC2View 绘制

void CMy0317MFC2View::OnDraw(CDC* pDC)
{
	CMy0317MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->cr);
}


// CMy0317MFC2View 诊断

#ifdef _DEBUG
void CMy0317MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0317MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0317MFC2Doc* CMy0317MFC2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0317MFC2Doc)));
	return (CMy0317MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0317MFC2View 消息处理程序


void CMy0317MFC2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy0317MFC2Doc* pDoc = GetDocument();
	CRect cc;
	GetClientRect(&cc);//取得客户区给cc
	switch (nChar)
	{
	case VK_UP:
		if (pDoc->cr.top > 0)
		{
			pDoc->cr.top -= 10;
			pDoc->cr.bottom -= 10;
		}
		break;
		
	case VK_DOWN:
		if (pDoc->cr.bottom <= (cc.bottom-cc.top))
		{
			pDoc->cr.top += 10;
			pDoc->cr.bottom += 10;
		}
		break;

	case VK_LEFT:
		if (pDoc->cr.left > 0)
		{
			pDoc->cr.left -= 10;
			pDoc->cr.right -= 10;
		}
		break;

	case VK_RIGHT:
		if (pDoc->cr.left <= (cc.right-cc.left))
		{
			pDoc->cr.left += 10;
			pDoc->cr.right += 10;
		}
		break;

	case VK_HOME:
		if ((pDoc->cr.top > 0)&(pDoc->cr.left > 0))
		{
			pDoc->cr.top -= 10;
			pDoc->cr.left -= 10;
		}
		break;

	case VK_END:
		pDoc->cr.top += 10;
		pDoc->cr.left += 10;
		break;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy0317MFC2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy0317MFC2Doc* pDoc = GetDocument();
	pDoc->cr.top = 300; pDoc->cr.left = 500;
	pDoc->cr.bottom = 400; pDoc->cr.right = 600;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
