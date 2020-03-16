
// 0310MFC3View.cpp : CMy0310MFC3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0310MFC3.h"
#endif

#include "0310MFC3Doc.h"
#include "0310MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0310MFC3View

IMPLEMENT_DYNCREATE(CMy0310MFC3View, CView)

BEGIN_MESSAGE_MAP(CMy0310MFC3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0310MFC3View 构造/析构

CMy0310MFC3View::CMy0310MFC3View()
{
	// TODO: 在此处添加构造代码

}

CMy0310MFC3View::~CMy0310MFC3View()
{
}

BOOL CMy0310MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0310MFC3View 绘制

void CMy0310MFC3View::OnDraw(CDC* pDC)
{
	CMy0310MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);

}


// CMy0310MFC3View 打印

BOOL CMy0310MFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0310MFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0310MFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0310MFC3View 诊断

#ifdef _DEBUG
void CMy0310MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0310MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0310MFC3Doc* CMy0310MFC3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0310MFC3Doc)));
	return (CMy0310MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0310MFC3View 消息处理程序


void CMy0310MFC3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy0310MFC3Doc* pDoc = GetDocument();
	CString s;
	CClientDC dc(this);
	
	if (pDoc->A.PtInRect(point))
	{
		pDoc->a = rand() % 150 + 5;
		s.Format(_T("a=%d"), pDoc->a);
		dc.TextOutW(point.x, point.y, s);
	}
	else
	{
		if (pDoc->B.PtInRect(point))
		{
			pDoc->b = rand() % 150 + 5;
			s.Format(_T("b=%d"), pDoc->b);
			dc.TextOutW(point.x, point.y, s);
		}//if
		else
		{
			s.Format(_T("点击无效"));
			dc.TextOutW(point.x, point.y, s);
		}//else
	}//else
	CView::OnLButtonDown(nFlags, point);
}


void CMy0310MFC3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy0310MFC3Doc* pDoc = GetDocument();
	CString s;
	CClientDC dc(this);
	if (pDoc->C.PtInRect(point))
	{
		s.Format(_T("a+b=%d"), pDoc->a+pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	else
	{
		s.Format(_T("点击无效"));
		dc.TextOutW(point.x, point.y, s);
	}

	CView::OnRButtonDown(nFlags, point);
}
