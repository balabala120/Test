
// 0324MFC3View.cpp : CMy0324MFC3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0324MFC3.h"
#endif

#include "0324MFC3Doc.h"
#include "0324MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0324MFC3View

IMPLEMENT_DYNCREATE(CMy0324MFC3View, CView)

BEGIN_MESSAGE_MAP(CMy0324MFC3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDM_LINE, &CMy0324MFC3View::OnLine)
	ON_COMMAND(IDM_RECTANGLE, &CMy0324MFC3View::OnRectangle)
	ON_COMMAND(IDM_ELLIPSE, &CMy0324MFC3View::OnEllipse)
END_MESSAGE_MAP()

// CMy0324MFC3View 构造/析构

CMy0324MFC3View::CMy0324MFC3View()
{
	// TODO: 在此处添加构造代码
	flag = 0;
	cr.top = 0; cr.left = 0;
	cr.bottom = 0; cr.right = 0;

}

CMy0324MFC3View::~CMy0324MFC3View()
{
}

BOOL CMy0324MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0324MFC3View 绘制

void CMy0324MFC3View::OnDraw(CDC* pDC)
{
	CMy0324MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (flag==1)
	{
		pDC->MoveTo(point1);
		pDC->LineTo(point2);
	}
	if (flag == 2)
	{
		pDC->Rectangle(point1.x,point1.y,point2.x,point2.y );
	}
	if (flag == 3)
	{
		pDC->Ellipse(point1.x,point1.y,point2.x,point2.y);
	}
}


// CMy0324MFC3View 打印

BOOL CMy0324MFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0324MFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0324MFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0324MFC3View 诊断

#ifdef _DEBUG
void CMy0324MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0324MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0324MFC3Doc* CMy0324MFC3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0324MFC3Doc)));
	return (CMy0324MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0324MFC3View 消息处理程序


void CMy0324MFC3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	point1 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMy0324MFC3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	point2 = point;
	Invalidate(FALSE);
	CView::OnLButtonUp(nFlags, point);
}


void CMy0324MFC3View::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	flag = 1;
	
}


void CMy0324MFC3View::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	flag = 2;
	
}


void CMy0324MFC3View::OnEllipse()
{
	// TODO: 在此添加命令处理程序代码
	flag = 3;
	

}
